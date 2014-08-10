/* pb_common.h: Common support functions for pb_encode.c and pb_decode.c.
 * These functions are rarely needed by applications directly.
 */

#ifndef _PB_COMMON_H_
#define _PB_COMMON_H_

#include "pb.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Iterator for pb_field_t list */
typedef struct {
    const pb_field_t *start;       /* Start of the pb_field_t array */
    const pb_field_t *pos;         /* Current position of the iterator */
    unsigned required_field_index; /* Zero-based index that counts only the required fields */
    void *dest_struct;             /* Pointer to the destination structure to decode to */
    void *pData;                   /* Pointer where to store current field value */
    void *pSize;                   /* Pointer where to store the size of current array field */
} pb_field_iter_t;

/* Initialize the field iterator structure to beginning. */
void pb_field_iter_begin(pb_field_iter_t *iter, const pb_field_t *fields, void *dest_struct);

/* Advance the iterator to the next field.
 * Returns false when the iterator wraps back to the first field. */
bool pb_field_iter_next(pb_field_iter_t *iter);

/* Advance the iterator until it points at a field with the given tag.
 * Returns false if no such field exists. */
bool pb_field_iter_find(pb_field_iter_t *iter, uint32_t tag);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif

