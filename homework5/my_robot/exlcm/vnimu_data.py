"""LCM type definitions
This file automatically generated by lcm.
DO NOT MODIFY BY HAND!!!!
"""

try:
    import cStringIO.StringIO as BytesIO
except ImportError:
    from io import BytesIO
import struct

class vnimu_data(object):
    __slots__ = ["yaw", "pitch", "roll", "magX", "magY", "magZ", "accelX", "accelY", "accelZ", "gyroX", "gyroY", "gyroZ"]

    def __init__(self):
        self.yaw = 0.0
        self.pitch = 0.0
        self.roll = 0.0
        self.magX = 0.0
        self.magY = 0.0
        self.magZ = 0.0
        self.accelX = 0.0
        self.accelY = 0.0
        self.accelZ = 0.0
        self.gyroX = 0.0
        self.gyroY = 0.0
        self.gyroZ = 0.0

    def encode(self):
        buf = BytesIO()
        buf.write(vnimu_data._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        buf.write(struct.pack(">ffffffffffff", self.yaw, self.pitch, self.roll, self.magX, self.magY, self.magZ, self.accelX, self.accelY, self.accelZ, self.gyroX, self.gyroY, self.gyroZ))

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != vnimu_data._get_packed_fingerprint():
            raise ValueError("Decode error")
        return vnimu_data._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = vnimu_data()
        self.yaw, self.pitch, self.roll, self.magX, self.magY, self.magZ, self.accelX, self.accelY, self.accelZ, self.gyroX, self.gyroY, self.gyroZ = struct.unpack(">ffffffffffff", buf.read(48))
        return self
    _decode_one = staticmethod(_decode_one)

    _hash = None
    def _get_hash_recursive(parents):
        if vnimu_data in parents: return 0
        tmphash = (0xfbdc5ce0f5b16b5f) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff)  + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if vnimu_data._packed_fingerprint is None:
            vnimu_data._packed_fingerprint = struct.pack(">Q", vnimu_data._get_hash_recursive([]))
        return vnimu_data._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)
