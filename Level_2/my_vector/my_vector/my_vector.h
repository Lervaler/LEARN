#ifndef MY_VECTOR_H
#define MY_VECTOR_H
#include <stdlib.h>

typedef  int VectorType;

struct My_vector
{
    VectorType* _data;
    size_t _size;
    size_t _copasity;
};

My_vector* create_my_vector ();
void push_back(My_vector* vector, VectorType _data);
VectorType get_my_vector(My_vector* vector, size_t index);
void destroy_my_vector (My_vector* vector);

#endif // MY_VECTOR_H
