// THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
// BY HAND!!
//
// Generated by lcm-gen

#include <string.h>
#include "lcmtest_node_t.h"

static int __lcmtest_node_t_hash_computed;
static int64_t __lcmtest_node_t_hash;

int64_t __lcmtest_node_t_hash_recursive(const __lcm_hash_ptr *p)
{
    const __lcm_hash_ptr *fp;
    for (fp = p; fp != NULL; fp = fp->parent)
        if (fp->v == __lcmtest_node_t_get_hash)
            return 0;

    __lcm_hash_ptr cp;
    cp.parent =  p;
    cp.v = (void*)__lcmtest_node_t_get_hash;
    (void) cp;

    int64_t hash = (int64_t)0x98ff4a363aeb7273LL
         + __int32_t_hash_recursive(&cp)
         + __lcmtest_node_t_hash_recursive(&cp)
        ;

    return (hash<<1) + ((hash>>63)&1);
}

int64_t __lcmtest_node_t_get_hash(void)
{
    if (!__lcmtest_node_t_hash_computed) {
        __lcmtest_node_t_hash = __lcmtest_node_t_hash_recursive(NULL);
        __lcmtest_node_t_hash_computed = 1;
    }

    return __lcmtest_node_t_hash;
}

int __lcmtest_node_t_encode_array(void *buf, int offset, int maxlen, const lcmtest_node_t *p, int elements)
{
    int pos = 0, thislen, element;

    for (element = 0; element < elements; element++) {

        thislen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &(p[element].num_children), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __lcmtest_node_t_encode_array(buf, offset + pos, maxlen - pos, p[element].children, p[element].num_children);
        if (thislen < 0) return thislen; else pos += thislen;

    }
    return pos;
}

int lcmtest_node_t_encode(void *buf, int offset, int maxlen, const lcmtest_node_t *p)
{
    int pos = 0, thislen;
    int64_t hash = __lcmtest_node_t_get_hash();

    thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    thislen = __lcmtest_node_t_encode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int __lcmtest_node_t_encoded_array_size(const lcmtest_node_t *p, int elements)
{
    int size = 0, element;
    for (element = 0; element < elements; element++) {

        size += __int32_t_encoded_array_size(&(p[element].num_children), 1);

        size += __lcmtest_node_t_encoded_array_size(p[element].children, p[element].num_children);

    }
    return size;
}

int lcmtest_node_t_encoded_size(const lcmtest_node_t *p)
{
    return 8 + __lcmtest_node_t_encoded_array_size(p, 1);
}

int __lcmtest_node_t_decode_array(const void *buf, int offset, int maxlen, lcmtest_node_t *p, int elements)
{
    int pos = 0, thislen, element;

    for (element = 0; element < elements; element++) {

        thislen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &(p[element].num_children), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].children = (lcmtest_node_t*) lcm_malloc(sizeof(lcmtest_node_t) * p[element].num_children);
        thislen = __lcmtest_node_t_decode_array(buf, offset + pos, maxlen - pos, p[element].children, p[element].num_children);
        if (thislen < 0) return thislen; else pos += thislen;

    }
    return pos;
}

int __lcmtest_node_t_decode_array_cleanup(lcmtest_node_t *p, int elements)
{
    int element;
    for (element = 0; element < elements; element++) {

        __int32_t_decode_array_cleanup(&(p[element].num_children), 1);

        __lcmtest_node_t_decode_array_cleanup(p[element].children, p[element].num_children);
        if (p[element].children) free(p[element].children);

    }
    return 0;
}

int lcmtest_node_t_decode(const void *buf, int offset, int maxlen, lcmtest_node_t *p)
{
    int pos = 0, thislen;
    int64_t hash = __lcmtest_node_t_get_hash();

    int64_t this_hash;
    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &this_hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
    if (this_hash != hash) return -1;

    thislen = __lcmtest_node_t_decode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int lcmtest_node_t_decode_cleanup(lcmtest_node_t *p)
{
    return __lcmtest_node_t_decode_array_cleanup(p, 1);
}

int __lcmtest_node_t_clone_array(const lcmtest_node_t *p, lcmtest_node_t *q, int elements)
{
    int element;
    for (element = 0; element < elements; element++) {

        __int32_t_clone_array(&(p[element].num_children), &(q[element].num_children), 1);

        q[element].children = (lcmtest_node_t*) lcm_malloc(sizeof(lcmtest_node_t) * q[element].num_children);
        __lcmtest_node_t_clone_array(p[element].children, q[element].children, p[element].num_children);

    }
    return 0;
}

lcmtest_node_t *lcmtest_node_t_copy(const lcmtest_node_t *p)
{
    lcmtest_node_t *q = (lcmtest_node_t*) malloc(sizeof(lcmtest_node_t));
    __lcmtest_node_t_clone_array(p, q, 1);
    return q;
}

void lcmtest_node_t_destroy(lcmtest_node_t *p)
{
    __lcmtest_node_t_decode_array_cleanup(p, 1);
    free(p);
}

int lcmtest_node_t_publish(lcm_t *lc, const char *channel, const lcmtest_node_t *p)
{
      int max_data_size = lcmtest_node_t_encoded_size (p);
      uint8_t *buf = (uint8_t*) malloc (max_data_size);
      if (!buf) return -1;
      int data_size = lcmtest_node_t_encode (buf, 0, max_data_size, p);
      if (data_size < 0) {
          free (buf);
          return data_size;
      }
      int status = lcm_publish (lc, channel, buf, data_size);
      free (buf);
      return status;
}

struct _lcmtest_node_t_subscription_t {
    lcmtest_node_t_handler_t user_handler;
    void *userdata;
    lcm_subscription_t *lc_h;
};
static
void lcmtest_node_t_handler_stub (const lcm_recv_buf_t *rbuf,
                            const char *channel, void *userdata)
{
    int status;
    lcmtest_node_t p;
    memset(&p, 0, sizeof(lcmtest_node_t));
    status = lcmtest_node_t_decode (rbuf->data, 0, rbuf->data_size, &p);
    if (status < 0) {
        fprintf (stderr, "error %d decoding lcmtest_node_t!!!\n", status);
        return;
    }

    lcmtest_node_t_subscription_t *h = (lcmtest_node_t_subscription_t*) userdata;
    h->user_handler (rbuf, channel, &p, h->userdata);

    lcmtest_node_t_decode_cleanup (&p);
}

lcmtest_node_t_subscription_t* lcmtest_node_t_subscribe (lcm_t *lcm,
                    const char *channel,
                    lcmtest_node_t_handler_t f, void *userdata)
{
    lcmtest_node_t_subscription_t *n = (lcmtest_node_t_subscription_t*)
                       malloc(sizeof(lcmtest_node_t_subscription_t));
    n->user_handler = f;
    n->userdata = userdata;
    n->lc_h = lcm_subscribe (lcm, channel,
                                 lcmtest_node_t_handler_stub, n);
    if (n->lc_h == NULL) {
        fprintf (stderr,"couldn't reg lcmtest_node_t LCM handler!\n");
        free (n);
        return NULL;
    }
    return n;
}

int lcmtest_node_t_subscription_set_queue_capacity (lcmtest_node_t_subscription_t* subs,
                              int num_messages)
{
    return lcm_subscription_set_queue_capacity (subs->lc_h, num_messages);
}

int lcmtest_node_t_unsubscribe(lcm_t *lcm, lcmtest_node_t_subscription_t* hid)
{
    int status = lcm_unsubscribe (lcm, hid->lc_h);
    if (0 != status) {
        fprintf(stderr,
           "couldn't unsubscribe lcmtest_node_t_handler %p!\n", hid);
        return -1;
    }
    free (hid);
    return 0;
}

