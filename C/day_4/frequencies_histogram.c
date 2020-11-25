#include <stdio.h>

/* Prints a histogram of the frequencies of different characters in its input. */

#define ASCII_CHARACTER_SET_COUNT 128

int main()
{
    int c; 
    int histogram[ASCII_CHARACTER_SET_COUNT];

    for (int i = 0; i < ASCII_CHARACTER_SET_COUNT; ++i)
        histogram[i] = 0;

    int max_frequency_count = histogram[0];

    while ((c = getchar()) != EOF)
    {
        if (c != ' ' && c != '\n' && c != '\t')
        {
            ++histogram[c - '0'];

            max_frequency_count = histogram[c - '0'] > max_frequency_count ? histogram[c - '0'] : max_frequency_count;
        }
    }

    printf("\nDRAWING HORIZONTAL HISTOGRAM\n");
    for (int i = 0; i < ASCII_CHARACTER_SET_COUNT; ++i)
    {
        for (int j = 0; j < histogram[i]; ++j)
            if (histogram[i] != 0)
                printf("%c", '-');

        if (histogram[i] != 0)
            printf("\n");
    }

    printf("\nDRAWING VERTICAL HISTOGRAM\n");
    printf("MAX FREQUENCY COUNT: %d\n", max_frequency_count);

    for (int i = max_frequency_count; i >= 1; --i)
    {
        for (int j = 0; j <= ASCII_CHARACTER_SET_COUNT; ++j)
        {
            if (histogram[j] != 0)
            {
                if (i <= histogram[j])
                    putchar('*');
                else
                    putchar(' ');
            }
        }
        putchar('\n');
    }


    return 0;
}


