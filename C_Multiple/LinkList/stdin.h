#ifndef _STDIN_H_
#define _STDIN_H_

inline static char *s_gets(char *st, int n) //inline funcation
{
    char *ret_val, *isfind;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        isfind = strchr(st, '\n');
        if (isfind)
            *isfind = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

#endif
