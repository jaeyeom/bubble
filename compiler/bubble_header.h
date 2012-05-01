
#ifndef _BUBBLE_HEADER_H_
#define _BUBBLE_HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_type.h"

void int_array_assign(__int_array_t a, __int_array_t b)
{
     int i;
     a->size = b->size;
     for (i=0; i<256; i++)
          a->data[i] = b->data[i];
}

void double_array_assign(__double_array_t a, __double_array_t b)
{
     int i;
     a->size = b->size;
     for (i=0; i<256; i++)
          a->data[i] = b->data[i];
}

void str_array_assign(__str_array_t a, __str_array_t b)
{
     int i;
     a->size = b->size;
     for (i=0; i<256; i++)
          strcpy(a->data[i], b->data[i]);
}


void int_array_set(__int_array_t a, __int_t b, __int_t c)
{
     if (a->size <= b) {
          a->size = b+1;
     }
     a->data[b] = c;
}

void double_array_set(__double_array_t a, __int_t b, __double_t c)
{
     if (a->size <= b) {
          a->size = b+1;
     }
     a->data[b] = c;
}

void str_array_set(__str_array_t a, __int_t b, __str_t c)
{
     if (a->size <= b) {
          a->size = b+1;
     }
     strcpy(a->data[b], c);
}

void print_int_array(__int_array_t a)
{
     int i;
     for (i = 0; i < a->size; i++)
          printf("%d ", a->data[i]);
     printf("\n");
}

void print_double_array(__double_array_t a)
{
     int i;
     for (i = 0; i < a->size; i++)
          printf("%f ", a->data[i]);
     printf("\n");
}

void print_str_array(__str_array_t a)
{
     int i;
     for (i = 0; i < a->size; i++)
          printf("%s ", a->data[i]);
     printf("\n");
}
#endif
