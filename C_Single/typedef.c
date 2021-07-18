#include<stdio.h>
int main(){
    struct student{
        int stdnum;
        char sname[3];
    }s1;

    typedef struct student s;

    scanf("%d",&s1.stdnum);
    printf("%d",s1.stdnum);
    
    return 0;
}