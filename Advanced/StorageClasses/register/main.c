#include <stdio.h>

int main()
{
    register int x;
    
    for(x=1; x<=15; x++)
        printf("%d\n", x);
    return 0;
}
