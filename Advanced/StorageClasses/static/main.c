#include <stdio.h>

int fun()
{
    static int count = 0;
    int localVar = 0;

    printf("automatic=%d,   static=%d\n", localVar, count);

    count++;
    localVar++;
    return count;
}

int main()
{
    for(int i=0; i<5; i++)
    {
        fun();
    }
}

