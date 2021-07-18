#include <stdio.h>
#include <string.h>
#include "stdin.h"
#define LEN 30

enum spectrum
{
    red,
    orange,
    yellow,
    green,
    blue,
    violet
};
const char *colors[] = {"red",
                        "orange",
                        "yellow",
                        "green",
                        "blue",
                        "violet"};

int main()
{
    char choice[LEN];
    enum spectrum color;
    int color_is_find = 0;

    puts("Enter a color (empty to quit):");
    while (s_gets(choice, LEN) != NULL && choice[0] != '\0')
    {
        for (color = red; color <= violet; color++)
        {
            if (strcmp(choice, colors[color]) == 0)
            {
                color_is_find = 1;
                break;
            }
        }
        if (color_is_find)
            switch (color)
            {
            case red:
                puts("Roses are red.");
                break;
            case orange:
                puts("POppies are orange.");
                break;
            case yellow:
                puts("Sunflowers are yellow.");
                break;
            case green:
                puts("Grass is green.");
                break;
            case blue:
                puts("Sky is blue.");
                break;
            case violet:
                puts("Violets are violet");
                break;
            }
        else
            printf("I don't known about the color %s\n", choice);
        color_is_find = 0;
        puts("Enter a color (empty to quit):");
    }
    puts("Good bye");
    return 0;
}
