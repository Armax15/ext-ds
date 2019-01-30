#ifndef PHP_DS_VECTOR_H
#define PHP_DS_VECTOR_H

#include "../../ds/ds_vector.h"

#define Z_DS_VECTOR_OBJ(z)   ((php_ds_vector_t*) (Z_OBJ(z)))
#define Z_DS_VECTOR_OBJ_P(z) Z_DS_VECTOR_OBJ(*z)

#define Z_DS_VECTOR(z)   ((Z_DS_VECTOR_OBJ(z))->vector)
#define Z_DS_VECTOR_P(z) Z_DS_VECTOR(*z)

#define THIS_DS_VECTOR() Z_DS_VECTOR_P(getThis())
#define THIS_DS_VECTOR_OBJ() Z_DS_VECTOR_OBJ_P(getThis())

#define ZVAL_DS_VECTOR(z, v) ZVAL_OBJ(z, php_ds_vector_create_object_ex(v))

#define RETURN_DS_VECTOR(v)                 \
do {                                        \
    ds_vector_t *_v = v;                    \
    if (_v) {                               \
        ZVAL_DS_VECTOR(return_value, _v);   \
    } else {                                \
        ZVAL_NULL(return_value);            \
    }                                       \
    return;                                 \
} while(0)

typedef struct php_ds_vector {
    zend_object      std;
    ds_vector_t     *vector;
    zend_ulong       iteratorCount;
} php_ds_vector_t;

zend_object *php_ds_vector_create_object_ex(ds_vector_t *vector);
zend_object *php_ds_vector_create_object(zend_class_entry *ce);
zend_object *php_ds_vector_create_clone(ds_vector_t *vector);

PHP_DS_SERIALIZE_FUNCIONS(php_ds_vector);

#endif
