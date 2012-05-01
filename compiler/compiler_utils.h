#ifndef _COMPILER_UTILS__H_
#define _COMPILER_UTILS__H_

void* cu_malloc(int size);
void cu_free(void *ptr);

int cu_string_count();
const char* cu_get_string(int index);
void cu_print_string(char *string);

int cu_integer_count();
int cu_get_integer(int index);
void cu_print_integer(int integer);

#endif

