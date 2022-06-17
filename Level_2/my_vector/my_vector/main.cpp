#include "my_vector.h"
#include <stdio.h>

int main()
{
    My_vector* a = create_my_vector();
    push_back(a, 42);
    printf("%d \n", get_my_vector(a, 0));
    destroy_my_vector(a);
    return 0;
}
