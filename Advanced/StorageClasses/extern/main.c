#include <stdio.h>

void foo(void);

int count;

extern void write_extern(void);

int main(void)
{
    count = 5;
    write_extern();
    return 0;
}
