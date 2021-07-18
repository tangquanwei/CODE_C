#include <stdio.h>

/* 泛型选择表达式 __Generic */
#define MYTYPE(x) _Generic((x),        \   
                            int        \
                           : "int",    \
                             double    \
                           : "double", \
                             default   \
                           : "other")

int main()
{

    int d = 5;
    printf("%s\n", MYTYPE(d));
    printf("%s\n", MYTYPE(2.0 * d));
    printf("%s\n", MYTYPE((int)(2.0 * d)));
    printf("%s\n", MYTYPE((float)(2.0 * d)));

#line 1
    printf("%d The preprosess date is : %s.\n\n", __LINE__, __DATE__);
    printf("%d The file name is : %s.\n\n", __LINE__, __FILE__);
    printf("%d The version is : %ld.\n\n", __LINE__, __STDC_VERSION__);
    printf("%d The compile time is : %s.\n\n", __LINE__, __TIME__);
    printf("%d The function is : %s.\n\n", __LINE__, __func__);

#line 1 "qwer_ty.c"
    printf("%d The file name is : %s.\n\n", __LINE__, __FILE__);

    printf("%d The version is : %ld.\n\n", __LINE__, __STDC_VERSION__);

    return 0;
}