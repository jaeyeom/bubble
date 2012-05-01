
#include <string.h>
#include "compiler_utils.h"

#define INIT_STR_CAP (32)

struct BubbleArray
{
     size_t capacity;
     size_t size;
     size_t ref_count;
     void* data;
};

typedef int __int_t;
typedef char __char_t;
typedef struct BubbleArray* __str_t;
typedef struct BubbleArray* __int_array_t;
typedef struct BubbleArray* __str_array_t;

#define STR_ELEMENT_SIZE (sizeof(__char_t))
#define INT_ARRAY_ELEMENT_SIZE (sizeof(__int_t))
#define DOUBLE_ARRAY_ELEMENT_SIZE (sizeof(__double_t))
#define STR_ARRAY_ELEMENT_SIZE (sizeof(__str_t))

/* should not be used
void new_str(__str_t this)
{
     this->capacity = INIT_STR_CAP;
     this->size = 0;
     this->ref_count = 0;
     this->data = cu_malloc(INIT_STR_CAP*STR_ARRAY_ELEMENT_SIZE);
}
*/

void *cu_realloc(void *ptr, int size)
{
     void *n = NULL;
     if (size > 0) n = cu_malloc(size);
     if (ptr != NULL) memmove(n, ptr, size);
     cu_free(ptr);
     return n;
}

__str_t new_str(__char_t* x)
{
     __str_t n;
     n = cu_malloc(sizeof(struct BubbleArray));
     n->size = n->capacity = strlen(x) + 1;
     n->data = cu_malloc(n->capacity*STR_ARRAY_ELEMENT_SIZE);
     strcpy(n->data, x);
     n->ref_count = 1;
     return n;
}

void free_str(__str_t this)
{
     cu_free(this->data);
     cu_free(this);
}

void decr_str(__str_t this)
{
     if (--this->ref_count == 0) free_str(this);
}

void free_int_array(__int_array_t this)
{
     cu_free(this->data);
     cu_free(this);
}

void free_str_array(__str_array_t this)
{
     int i;
     for (i=0; i < this->size; i++)
          decr_str(((__str_t*)this->data)[i]);
     cu_free(this->data);
     cu_free(this);
}

__str_t assign_str(__str_t *l, __str_t r)
{
     (*l)->ref_count--;
     if ((*l)->ref_count == 0) free_str(*l);
     *l = r;
     r->ref_count++;
     return *l;
}

__str_t assign_str_const(__str_t *l, __char_t* r)
{
     (*l)->ref_count--;
     if ((*l)->ref_count == 0) free_str(*l);
     *l = new_str(r);
     return *l;
}

__int_array_t assign_int_array(__int_array_t *l, __int_array_t r)
{
      (*l)->ref_count--;
     if ((*l)->ref_count == 0) free_int_array(*l);
     *l = r;
     r->ref_count++;
     return *l;
}

__str_array_t assign_str_array(__str_array_t *l, __str_array_t r)
{
      (*l)->ref_count--;
     if ((*l)->ref_count == 0) free_str(*l);
     *l = r;
     r->ref_count++;
     return *l;
}

void clone_str(__str_t *x)
{
     __str_t n;
     n = cu_malloc(sizeof(struct BubbleArray));
     memcpy(n, *x, sizeof(struct BubbleArray));
     n->data = cu_malloc(n->capacity*STR_ELEMENT_SIZE);
     memcpy(n->data, (*x)->data, n->size*STR_ELEMENT_SIZE);
     (*x)->ref_count--;
     n->ref_count = 1;
     *x = n;
}

void clone_int_array(__int_array_t *x)
{
     __int_array_t n;
     n = cu_malloc(sizeof(struct BubbleArray));
     memcpy(n, *x, sizeof(struct BubbleArray));
     n->data = cu_malloc(n->capacity*INT_ARRAY_ELEMENT_SIZE);
     memcpy(n->data, (*x)->data, n->size*INT_ARRAY_ELEMENT_SIZE);
     (*x)->ref_count--;
     n->ref_count = 1;
     *x = n;
}

void clone_str_array(__str_array_t *x)
{
     __str_array_t n;
     int i;
     n = cu_malloc(sizeof(struct BubbleArray));
     memcpy(n, *x, sizeof(struct BubbleArray));
     n->data = cu_malloc(n->capacity*STR_ARRAY_ELEMENT_SIZE);
     for (i = 0; i < n->size; i++)
          assign_str(&(((__str_t*)n->data)[i]), ((__str_t*)(*x)->data)[i]);
     (*x)->ref_count--;
     n->ref_count = 1;
     *x = n;
}

__char_t set_element_str(__str_t *A, __int_t i, __int_t x)
{
     if ((*A)->ref_count > 1) {
          clone_str(A);
     }
     if (i > (*A)->size) {
          (*A)->size = i;
          if (i > (*A)->capacity) {
               do {
                    (*A)->capacity *= 2;
               } while (i > (*A)->capacity);
               (*A)->data = cu_realloc((*A)->data, (*A)->capacity);
          }
     }
     ((__char_t*)(*A)->data)[i] = (__char_t)x;
     return ((__char_t*)(*A)->data)[i];
}

__int_t set_element_int_array(__int_array_t *A, __int_t i, __int_t x)
{
     if ((*A)->ref_count > 1) {
          clone_int_array(A);
     }
     if (i > (*A)->size) {
          (*A)->size = i;
          if (i > (*A)->capacity) {
               do {
                    (*A)->capacity *= 2;
               } while (i > (*A)->capacity);
               (*A)->data = cu_realloc((*A)->data, (*A)->capacity * sizeof(__int_t));
          }
     }
     ((__int_t*)(*A)->data)[i] = (__int_t)x;
     return ((__int_t*)(*A)->data)[i];
}

__str_t set_element_str_array(__str_array_t *A, __int_t i, __str_t x)
{
     if ((*A)->ref_count > 1) {
          clone_str_array(A);
     }
     if (i > (*A)->size) {
          (*A)->size = i;
          if (i > (*A)->capacity) {
               do {
                    (*A)->capacity *= 2;
               } while (i > (*A)->capacity);
               (*A)->data = cu_realloc((*A)->data, (*A)->capacity * sizeof(__str_t));
          }
     }
     assign_str(&(((__str_t*)(*A)->data)[i]), (__str_t)x);
     return ((__str_t*)(*A)->data)[i];
}

__str_t set_element_str_array_const(__str_array_t *A, __int_t i, __char_t* x)
{
     if ((*A)->ref_count > 1) {
          clone_str_array(A);
     }
     if (i > (*A)->size) {
          (*A)->size = i;
          if (i > (*A)->capacity) {
               do {
                    (*A)->capacity *= 2;
               } while (i > (*A)->capacity);
               (*A)->data = cu_realloc((*A)->data, (*A)->capacity * sizeof(__str_t));
          }
     }
     assign_str_const(&(((__str_t*)(*A)->data)[i]), x);
     return ((__str_t*)(*A)->data)[i];
}

__char_t get_element_str(__int_t *a, __str_t A, __int_t i)
{
     *a = ((__char_t*)A->data)[i];
     return *a;
}

__int_t get_element_int_array(__int_t *a, __int_array_t A, __int_t i)
{
     *a = ((__int_t*)A->data)[i];
     return *a;
}

__str_t get_element_str_array(__str_t *a, __str_array_t A, __int_t i)
{
     *a = ((__str_t*)A->data)[i];
     return *a;
}

size_t length_str(__str_t x)
{
     return x->size;
}

size_t length_int_array(__int_array_t x)
{
     return x->size;
}

size_t length_str_array(__str_array_t x)
{
     return x->size;
}

__int_t print_int(__int_t x)
{
     cu_print_integer(x);
     return x;
}

__str_t print_str(__str_t x)
{
     cu_print_string(x->data);
     return x;
}

__int_array_t print_int_array(__int_array_t x)
{
     int i;
     cu_print_string("[");
     for (i=0; i<x->size; i++) {
          cu_print_integer(((__int_t*)x->data)[i]);
          cu_print_string(", ");
     }
     cu_print_string("]");
     return x;
}

__str_array_t print_str_array(__str_array_t x)
{
     int i;
     cu_print_string("[");
     for (i=0; i<x->size; i++) {
          cu_print_string(((__str_t*)x->data)[i]->data);
          cu_print_string(", ");
     }
     cu_print_string("]");
     return x;
}

__int_t compare_str(__str_t a, __str_t b)
{
     return strcmp(a->data, b->data);
}
