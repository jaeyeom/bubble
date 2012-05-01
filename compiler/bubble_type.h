
#ifndef _BUBBLE_TYPE_H_
#define _BUBBLE_TYPE_H_
typedef int __int_t;
typedef double __double_t;
typedef unsigned char __str_t[256];
typedef struct {
     __int_t size;
     __int_t data[256];
} __int_array_tt;
typedef struct {
     __int_t size;
     __double_t data[256];
} __double_array_tt;
typedef struct {
     __int_t size;
     __str_t data[256];
} __str_array_tt;
typedef __int_array_tt *__int_array_t;
typedef __double_array_tt *__double_array_t;
typedef __str_array_tt *__str_array_t;
typedef void __void_t;
#endif
