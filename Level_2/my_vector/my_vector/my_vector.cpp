#include "my_vector.h"
#include <string.h>

My_vector* create_my_vector ()
{
    My_vector* tmp =  new My_vector;
    tmp->_data = nullptr;
    tmp->_size = 0;
    tmp->_copasity = 0;
    return tmp;
}

void push_back(My_vector* vector, VectorType _data)
{
    if(vector == nullptr)
        return;

    if(vector->_copasity - vector->_size == 0)
    {
        vector->_copasity = vector->_copasity*2 + 1;
        VectorType* tmp = new VectorType[vector->_copasity];
        memcpy(tmp, vector->_data, sizeof(VectorType)*vector->_size);
        delete[] vector->_data;
        vector->_data = tmp;
    }

    vector->_data[vector->_size] = _data;
    ++vector->_size;
}

VectorType get_my_vector(My_vector* vector, size_t index)
{
    return (index < vector->_size) ? vector->_data[index] : VectorType{};
}

void destroy_my_vector (My_vector* vector)
{
    if(vector == nullptr)
        return;
    delete[] vector->_data;
    vector->_size = 0;
    vector->_copasity = 0;
    vector->_data = nullptr;

    delete vector;
}
