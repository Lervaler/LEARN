//Дана строка символов. Удалить из нее все слова нечетной длины.
//Слова отделяются друг от друга одним пробелом.

#include<stdio.h>
#include<string.h>
int main()
{
    char s[50];
    int i,j,k,l;
    i=0;
    k=0;
    gets (s);
    while(s[i]!=0)
    {
        for(j=i;s[i]==' '&&s[i]!=0;i++);
        for(l=i;s[i]!=' '&&s[i]!=0;i++);
            if(((i-l)&1)==0)
            {
                for(;j<i;j++,k++)
                {
                      s[k]=s[j];
                      printf("%c",s[k]);
                }
            }
    }
    printf("\n");

    return 0;
}

