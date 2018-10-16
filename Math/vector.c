#include "vector.h"

int vector_init(vector* v, size_t size)
{
    v->size = size;
    v->value = malloc(v->size * sizeof(void *));
    if(v->value == NULL)
        return -1;

    return 0;
}

int push_back(vector* v, void* value)
{
    v->value = realloc(v->value, ++(v->size) * (sizeof(void *)));
    if(v->value == NULL)
        return -1;

    v->value[v->size - 1] = value;
    return 0;
}


int pop_back(vector* v)
{
    v->value = realloc(v->value, --(v->size) * (sizeof(void *)));
    if(v->value == NULL)
        return -1;

    return 0;
}

int resize(vector* v, size_t size)
{
    v->value = realloc(v->value, size * (sizeof(void *)));
    if(v->value == NULL)
        return -1;
    v->size = size;
    return 0;
}

int clear(vector* v)
{
    free(v->value);
    return 0;
}
