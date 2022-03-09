//Определить местоположение элементов массива А (30), не встречающихся в массиве В (15).

//#include <time.h> - использовать при рандоме от времени
#include <stdlib.h>
#include <stdio.h>

int main()
{
    constexpr int sizeA = 30;
    int A[sizeA];
    constexpr int sizeB = 15;
    int B[sizeB];
    int E[sizeA];
    int index_E = 0;
    srand(100);

    printf("MASSIVE A: ");
    for(int i = 0; i < sizeA; ++i)
    {
        A[i] = rand()% 20;    //делаем рандом
        printf("%d ", A[i]);
    }
        printf("\n");

    printf("MASSIVE B: ");
    for(int i = 0; i < sizeB; ++i)
    {
        B[i] = rand()% 20;    //делаем рандом
        printf("%d ", B[i]);
    }
        printf("\n");

    printf("non-B numbers: \n");    // несовпадающие значения в массиве А
    printf("           ");    // это, чтобы строчки были вровень

    for(int i = 0; i < sizeA; ++i)
    {
        bool found = false;
            for(int j = 0; j < sizeB && !found; ++j)
            {
                if(A[i] == B[j])
                    found = true;
            }
                if(!found)
                {
                    E[index_E] = A[i];
                    ++index_E;
                }
    }

    for(int i = 0; i < index_E; ++i)
    {
        printf("%d ", E[i]);
    }

    printf("\n");
    printf("non-B location: \n");    // местоположение в массиве А
    printf("           ");    // это, чтобы строчки были вровень

    for(int i = 0; i < sizeA; ++i)
    {
        for(int j = 0; j < index_E; ++j)
            if(A[i]==E[j])
                printf("%d ", ++i);
    }

    printf("\n");
    return 0;
}
