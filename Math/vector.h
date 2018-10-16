#pragma once
#include <stdlib.h>


typedef struct vector vector;
struct vector
{
    void** value;
    size_t size;
};

int vector_init(vector* v, size_t size);

int push_back(vector* v, void * value);

int pop_back(vector* v);

int resize(vector* v, size_t size);

int clear(vector* v);
