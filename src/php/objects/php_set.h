#ifndef PHP_DS_SET_H
#define PHP_DS_SET_H

#include "../../ds/ds_set.h"

#define Z_DS_SET_OBJ(z)   ((php_ds_set_t*) (Z_OBJ(z)))
#define Z_DS_SET_OBJ_P(z) Z_DS_SET_OBJ(*z)

#define Z_DS_SET(z)   ((Z_DS_SET_OBJ(z))->set)
#define Z_DS_SET_P(z) Z_DS_SET(*z)

#define THIS_DS_SET() Z_DS_SET_P(getThis())
#define THIS_DS_SET_OBJ() Z_DS_SET_OBJ_P(getThis())

#define ZVAL_DS_SET(z, set) ZVAL_OBJ(z, php_ds_set_create_object_ex(set))

#define RETURN_DS_SET(s)                    \
do {                                        \
    ds_set_t *_s = s;                       \
    if (_s) {                               \
        ZVAL_DS_SET(return_value, _s);      \
    } else {                                \
        ZVAL_NULL(return_value);            \
    }                                       \
    return;                                 \
} while(0)

typedef struct _php_ds_set_t {
    zend_object    std;
    ds_set_t      *set;
    zend_ulong     iteratorCount;
} php_ds_set_t;

zend_object *php_ds_set_create_object_ex(ds_set_t *set);
zend_object *php_ds_set_create_object(zend_class_entry *ce);
zend_object *php_ds_set_create_clone(ds_set_t *set);

PHP_DS_SERIALIZE_FUNCIONS(php_ds_set);

#endif
