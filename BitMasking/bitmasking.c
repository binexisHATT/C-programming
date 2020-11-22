#include <stdio.h>

int bit(int, int);
int count(int);
int set(int);
int set(int);

int main()
{
    printf("3rd bit is set: %d\n", bit(10, 3));
    return 0;
}

int bit(int num, int i)
{
    return num & (1 << i);
}
