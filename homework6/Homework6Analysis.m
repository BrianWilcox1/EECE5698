%Author: Brian Wilcox
%Date: 2/27/107
%Class: EECE 5698
%Homework #6 Panaroma Code

%% Setup Instrinsic Structures
load('Calib_Results.mat');
IntrinsicMatrix = KK';
RadialDistortion = kc(3:end);

cameraParams = cameraParameters('IntrinsicMatrix', IntrinsicMatrix, ...
    'RadialDistortion', RadialDistortion);


%%Read in Files
buildingDir = fullfile('./');
buildingScene = imageDatastore(buildingDir);
montage(buildingScene.Files)

% Read the first image from the image set.
I = readimage(buildingScene, 1);
I = imrotate(I, -90);
A = I;

%NOTE: Images come in sideways
I = undistortImage(I, cameraParams);

%imshow(I);
% Initialize features for I(1)
grayImage = rgb2gray(I);
imshow(grayImage);
[y,x, m] = harris(grayImage,2000,'tile',[20 20],'disp');
points = [x y];
[features, points] = extractFeatures(grayImage, points);

% Initialize all the transforms to the identity matrix. Note that the
% projective transform is used here because the building images are fairly
% close to the camera. Had the scene been captured from a further distance,
% an affine transform would suffice.
numImages = numel(buildingScene.Files);
tforms(numImages) = projective2d(eye(3));

% Iterate over remaining image pairs
for n = 2:numImages

    % Store points and features for I(n-1).
    pointsPrevious = points;
    featuresPrevious = features;

    % Read I(n).
    I = readimage(buildingScene, n);
    I = imrotate(I, -90);
    I = undistortImage(I, cameraParams);

    % Detect and extract harris corners for I(n).
    grayImage = rgb2gray(I);
    [y,x, m] = harris(grayImage,2000,'tile',[20 20]);
    points = [x y];
    [features, points] = extractFeatures(grayImage, points);

    % Find correspondences between I(n) and I(n-1).
    indexPairs = matchFeatures(features, featuresPrevious, 'Unique', true);

    matchedPoints = points(indexPairs(:,1), :);
    matchedPointsPrev = pointsPrevious(indexPairs(:,2), :);

    % Estimate the transformation between I(n) and I(n-1).
    tforms(n) = estimateGeometricTransform(matchedPoints, matchedPointsPrev,...
        'projective', 'Confidence', 99.9, 'MaxNumTrials', 2000);

    % Compute T(1) * ... * T(n-1) * T(n)
    tforms(n).T = tforms(n-1).T * tforms(n).T;
end

tformArray = tforms;
imageSize = size(I);  % all the images are the same size

% Compute the output limits  for each transform
for i = 1:numel(tforms)
    [xlim(i,:), ylim(i,:)] = outputLimits(tforms(i), [1 imageSize(2)], [1 imageSize(1)]);
end

avgXLim = mean(xlim, 2);

[~, idx] = sort(avgXLim);

centerIdx = floor((numel(tforms)+1)/2);

centerImageIdx = idx(centerIdx);

Tinv = invert(tforms(centerImageIdx));

for i = 1:numel(tforms)
    tforms(i).T = Tinv.T * tforms(i).T;
end

for i = 1:numel(tforms)
    [xlim(i,:), ylim(i,:)] = outputLimits(tforms(i), [1 imageSize(2)], [1 imageSize(1)]);
end

% Find the minimum and maximum output limits
xMin = min([1; xlim(:)]);
xMax = max([imageSize(2); xlim(:)]);

yMin = min([1; ylim(:)]);
yMax = max([imageSize(1); ylim(:)]);

% Width and height of panorama.
width  = round(xMax - xMin);
height = round(yMax - yMin);

% Initialize the "empty" panorama.
close all
panorama = zeros([height width 3], 'like', I);

blender = vision.AlphaBlender('Operation', 'Binary mask', ...
    'MaskSource', 'Input port');

% Create a 2-D spatial reference object defining the size of the panorama.
xLimits = [xMin xMax];
yLimits = [yMin yMax];
panoramaView = imref2d([height width], xLimits, yLimits);
clearvars -except tformArray buildingScene tforms panoramaView blender panorama numImages cameraParams
% Create the panorama.
for i = 1:numImages

    I = readimage(buildingScene, i);
    I = imrotate(I, -90);
    I = undistortImage(I, cameraParams);
    % Transform I into the panorama.
    warpedImage = imwarp(I, tforms(i), 'OutputView', panoramaView);

    % Generate a binary mask.
    mask = imwarp(true(size(I,1),size(I,2)), tforms(i), 'OutputView', panoramaView);

    % Overlay the warpedImage onto the panorama.
    panorama = step(blender, panorama, warpedImage, mask);
    
end
offsets = size(panorama);
offsetx = round(1.1*offsets(2)/2);
offsety = round(1*offsets(1)/2);
for i = 1:numImages
    panorama = insertShape(panorama,'FilledCircle',[offsetx+tforms(i).T(3,1) offsety+tforms(i).T(3,2) ...
        100], 'Color', 'Green');
end
figure
imshow(panorama, 'InitialMagnification', 'fit');