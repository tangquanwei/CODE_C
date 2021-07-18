#include <stdio.h>

int Add(int x, int y)
{
    if (y == 0)
        return x;
    else
        return Add(x ^ y, (x & y) << 1);
}

int main(){
    int a,b,s;
    scanf("%d%d",&a,&b);
    s=Add(a,b);
    
    printf("s = %d",s);
    return 0;
}