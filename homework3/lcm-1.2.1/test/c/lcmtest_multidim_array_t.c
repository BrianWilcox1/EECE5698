// THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
// BY HAND!!
//
// Generated by lcm-gen

#include <string.h>
#include "lcmtest_multidim_array_t.h"

static int __lcmtest_multidim_array_t_hash_computed;
static int64_t __lcmtest_multidim_array_t_hash;

int64_t __lcmtest_multidim_array_t_hash_recursive(const __lcm_hash_ptr *p)
{
    const __lcm_hash_ptr *fp;
    for (fp = p; fp != NULL; fp = fp->parent)
        if (fp->v == __lcmtest_multidim_array_t_get_hash)
            return 0;

    __lcm_hash_ptr cp;
    cp.parent =  p;
    cp.v = (void*)__lcmtest_multidim_array_t_get_hash;
    (void) cp;

    int64_t hash = (int64_t)0x1e012473deb4cfbbLL
         + __int32_t_hash_recursive(&cp)
         + __int32_t_hash_recursive(&cp)
         + __int32_t_hash_recursive(&cp)
         + __int32_t_hash_recursive(&cp)
         + __string_hash_recursive(&cp)
        ;

    return (hash<<1) + ((hash>>63)&1);
}

int64_t __lcmtest_multidim_array_t_get_hash(void)
{
    if (!__lcmtest_multidim_array_t_hash_computed) {
        __lcmtest_multidim_array_t_hash = __lcmtest_multidim_array_t_hash_recursive(NULL);
        __lcmtest_multidim_array_t_hash_computed = 1;
    }

    return __lcmtest_multidim_array_t_hash;
}

int __lcmtest_multidim_array_t_encode_array(void *buf, int offset, int maxlen, const lcmtest_multidim_array_t *p, int elements)
{
    int pos = 0, thislen, element;

    for (element = 0; element < elements; element++) {

        thislen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &(p[element].size_a), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &(p[element].size_b), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &(p[element].size_c), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        { int a;
        for (a = 0; a < p[element].size_a; a++) {
            { int b;
            for (b = 0; b < p[element].size_b; b++) {
                thislen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, p[element].data[a][b], p[element].size_c);
                if (thislen < 0) return thislen; else pos += thislen;
            }
            }
        }
        }

        { int a;
        for (a = 0; a < 2; a++) {
            thislen = __string_encode_array(buf, offset + pos, maxlen - pos, p[element].strarray[a], p[element].size_c);
            if (thislen < 0) return thislen; else pos += thislen;
        }
        }

    }
    return pos;
}

int lcmtest_multidim_array_t_encode(void *buf, int offset, int maxlen, const lcmtest_multidim_array_t *p)
{
    int pos = 0, thislen;
    int64_t hash = __lcmtest_multidim_array_t_get_hash();

    thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    thislen = __lcmtest_multidim_array_t_encode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int __lcmtest_multidim_array_t_encoded_array_size(const lcmtest_multidim_array_t *p, int elements)
{
    int size = 0, element;
    for (element = 0; element < elements; element++) {

        size += __int32_t_encoded_array_size(&(p[element].size_a), 1);

        size += __int32_t_encoded_array_size(&(p[element].size_b), 1);

        size += __int32_t_encoded_array_size(&(p[element].size_c), 1);

        { int a;
        for (a = 0; a < p[element].size_a; a++) {
            { int b;
            for (b = 0; b < p[element].size_b; b++) {
                size += __int32_t_encoded_array_size(p[element].data[a][b], p[element].size_c);
            }
            }
        }
        }

        { int a;
        for (a = 0; a < 2; a++) {
            size += __string_encoded_array_size(p[element].strarray[a], p[element].size_c);
        }
        }

    }
    return size;
}

int lcmtest_multidim_array_t_encoded_size(const lcmtest_multidim_array_t *p)
{
    return 8 + __lcmtest_multidim_array_t_encoded_array_size(p, 1);
}

int __lcmtest_multidim_array_t_decode_array(const void *buf, int offset, int maxlen, lcmtest_multidim_array_t *p, int elements)
{
    int pos = 0, thislen, element;

    for (element = 0; element < elements; element++) {

        thislen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &(p[element].size_a), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &(p[element].size_b), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &(p[element].size_c), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].data = (int32_t***) lcm_malloc(sizeof(int32_t**) * p[element].size_a);
        { int a;
        for (a = 0; a < p[element].size_a; a++) {
            p[element].data[a] = (int32_t**) lcm_malloc(sizeof(int32_t*) * p[element].size_b);
            { int b;
            for (b = 0; b < p[element].size_b; b++) {
                p[element].data[a][b] = (int32_t*) lcm_malloc(sizeof(int32_t) * p[element].size_c);
                thislen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, p[element].data[a][b], p[element].size_c);
                if (thislen < 0) return thislen; else pos += thislen;
            }
            }
        }
        }

        p[element].strarray = (char***) lcm_malloc(sizeof(char**) * 2);
        { int a;
        for (a = 0; a < 2; a++) {
            p[element].strarray[a] = (char**) lcm_malloc(sizeof(char*) * p[element].size_c);
            thislen = __string_decode_array(buf, offset + pos, maxlen - pos, p[element].strarray[a], p[element].size_c);
            if (thislen < 0) return thislen; else pos += thislen;
        }
        }

    }
    return pos;
}

int __lcmtest_multidim_array_t_decode_array_cleanup(lcmtest_multidim_array_t *p, int elements)
{
    int element;
    for (element = 0; element < elements; element++) {

        __int32_t_decode_array_cleanup(&(p[element].size_a), 1);

        __int32_t_decode_array_cleanup(&(p[element].size_b), 1);

        __int32_t_decode_array_cleanup(&(p[element].size_c), 1);

        { int a;
        for (a = 0; a < p[element].size_a; a++) {
            { int b;
            for (b = 0; b < p[element].size_b; b++) {
                __int32_t_decode_array_cleanup(p[element].data[a][b], p[element].size_c);
                if (p[element].data[a][b]) free(p[element].data[a][b]);
            }
            }
            if (p[element].data[a]) free(p[element].data[a]);
        }
        }
        if (p[element].data) free(p[element].data);

        { int a;
        for (a = 0; a < 2; a++) {
            __string_decode_array_cleanup(p[element].strarray[a], p[element].size_c);
            if (p[element].strarray[a]) free(p[element].strarray[a]);
        }
        }
        if (p[element].strarray) free(p[element].strarray);

    }
    return 0;
}

int lcmtest_multidim_array_t_decode(const void *buf, int offset, int maxlen, lcmtest_multidim_array_t *p)
{
    int pos = 0, thislen;
    int64_t hash = __lcmtest_multidim_array_t_get_hash();

    int64_t this_hash;
    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &this_hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
    if (this_hash != hash) return -1;

    thislen = __lcmtest_multidim_array_t_decode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int lcmtest_multidim_array_t_decode_cleanup(lcmtest_multidim_array_t *p)
{
    return __lcmtest_multidim_array_t_decode_array_cleanup(p, 1);
}

int __lcmtest_multidim_array_t_clone_array(const lcmtest_multidim_array_t *p, lcmtest_multidim_array_t *q, int elements)
{
    int element;
    for (element = 0; element < elements; element++) {

        __int32_t_clone_array(&(p[element].size_a), &(q[element].size_a), 1);

        __int32_t_clone_array(&(p[element].size_b), &(q[element].size_b), 1);

        __int32_t_clone_array(&(p[element].size_c), &(q[element].size_c), 1);

        q[element].data = (int32_t***) lcm_malloc(sizeof(int32_t**) * q[element].size_a);
        { int a;
        for (a = 0; a < p[element].size_a; a++) {
            q[element].data[a] = (int32_t**) lcm_malloc(sizeof(int32_t*) * q[element].size_b);
            { int b;
            for (b = 0; b < p[element].size_b; b++) {
                q[element].data[a][b] = (int32_t*) lcm_malloc(sizeof(int32_t) * q[element].size_c);
                __int32_t_clone_array(p[element].data[a][b], q[element].data[a][b], p[element].size_c);
            }
            }
        }
        }

        q[element].strarray = (char***) lcm_malloc(sizeof(char**) * 2);
        { int a;
        for (a = 0; a < 2; a++) {
            q[element].strarray[a] = (char**) lcm_malloc(sizeof(char*) * q[element].size_c);
            __string_clone_array(p[element].strarray[a], q[element].strarray[a], p[element].size_c);
        }
        }

    }
    return 0;
}

lcmtest_multidim_array_t *lcmtest_multidim_array_t_copy(const lcmtest_multidim_array_t *p)
{
    lcmtest_multidim_array_t *q = (lcmtest_multidim_array_t*) malloc(sizeof(lcmtest_multidim_array_t));
    __lcmtest_multidim_array_t_clone_array(p, q, 1);
    return q;
}

void lcmtest_multidim_array_t_destroy(lcmtest_multidim_array_t *p)
{
    __lcmtest_multidim_array_t_decode_array_cleanup(p, 1);
    free(p);
}

int lcmtest_multidim_array_t_publish(lcm_t *lc, const char *channel, const lcmtest_multidim_array_t *p)
{
      int max_data_size = lcmtest_multidim_array_t_encoded_size (p);
      uint8_t *buf = (uint8_t*) malloc (max_data_size);
      if (!buf) return -1;
      int data_size = lcmtest_multidim_array_t_encode (buf, 0, max_data_size, p);
      if (data_size < 0) {
          free (buf);
          return data_size;
      }
      int status = lcm_publish (lc, channel, buf, data_size);
      free (buf);
      return status;
}

struct _lcmtest_multidim_array_t_subscription_t {
    lcmtest_multidim_array_t_handler_t user_handler;
    void *userdata;
    lcm_subscription_t *lc_h;
};
static
void lcmtest_multidim_array_t_handler_stub (const lcm_recv_buf_t *rbuf,
                            const char *channel, void *userdata)
{
    int status;
    lcmtest_multidim_array_t p;
    memset(&p, 0, sizeof(lcmtest_multidim_array_t));
    status = lcmtest_multidim_array_t_decode (rbuf->data, 0, rbuf->data_size, &p);
    if (status < 0) {
        fprintf (stderr, "error %d decoding lcmtest_multidim_array_t!!!\n", status);
        return;
    }

    lcmtest_multidim_array_t_subscription_t *h = (lcmtest_multidim_array_t_subscription_t*) userdata;
    h->user_handler (rbuf, channel, &p, h->userdata);

    lcmtest_multidim_array_t_decode_cleanup (&p);
}

lcmtest_multidim_array_t_subscription_t* lcmtest_multidim_array_t_subscribe (lcm_t *lcm,
                    const char *channel,
                    lcmtest_multidim_array_t_handler_t f, void *userdata)
{
    lcmtest_multidim_array_t_subscription_t *n = (lcmtest_multidim_array_t_subscription_t*)
                       malloc(sizeof(lcmtest_multidim_array_t_subscription_t));
    n->user_handler = f;
    n->userdata = userdata;
    n->lc_h = lcm_subscribe (lcm, channel,
                                 lcmtest_multidim_array_t_handler_stub, n);
    if (n->lc_h == NULL) {
        fprintf (stderr,"couldn't reg lcmtest_multidim_array_t LCM handler!\n");
        free (n);
        return NULL;
    }
    return n;
}

int lcmtest_multidim_array_t_subscription_set_queue_capacity (lcmtest_multidim_array_t_subscription_t* subs,
                              int num_messages)
{
    return lcm_subscription_set_queue_capacity (subs->lc_h, num_messages);
}

int lcmtest_multidim_array_t_unsubscribe(lcm_t *lcm, lcmtest_multidim_array_t_subscription_t* hid)
{
    int status = lcm_unsubscribe (lcm, hid->lc_h);
    if (0 != status) {
        fprintf(stderr,
           "couldn't unsubscribe lcmtest_multidim_array_t_handler %p!\n", hid);
        return -1;
    }
    free (hid);
    return 0;
}

