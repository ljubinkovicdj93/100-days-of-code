#include <stdio.h>

/* Count digits, white space, others. */

#define BUFFER 100

int main()
{
    int c, i, nwhite, nother;
    int ndigit[10]; // declares ndigit to be an array of 10 integers.
    int histogram[BUFFER];

    for (int i = 0; i < BUFFER; ++i)
        histogram[i] = 0;

    nwhite = nother = 0;

    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    int word_index = 0;
    int max_word_length = histogram[word_index];

    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9') // determines whether the character in `c` is a digit.
        {            
            ++ndigit[c-'0']; // numeric value of that digit. This works only if '0', '1', ..., '9' have consecutive increasing values. Fortunately, this is true for all character sets.
            ++histogram[word_index]; 
        }

        else if (c == ' ' || c == '\n' || c == '\t')
        {
            ++word_index;
            max_word_length = histogram[word_index - 1] > histogram[word_index] ? histogram[word_index - 1] : histogram[word_index];
            
            ++nwhite;
        }
        else
        {
            ++histogram[word_index]; 
            ++nother;
        }
    }

    printf("digits =");

    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);

    printf(", white space = %d, other = %d\n", nwhite, nother);

    

    printf("\nDRAWING HORIZONTAL HISTOGRAM\n");
    for (int i = 0; i < word_index; ++i)
    {
        for (int j = 0; j < histogram[i]; ++j)
            printf("%c", '-');

        printf("\n");
    }

    printf("\nDRAWING VERTICAL HISTOGRAM\n");
    printf("MAX WORD LENGTH: %d\n", max_word_length);

    for (int i = max_word_length; i >= 1; --i)
    {
        for (int j = 0; j <= word_index; ++j)
        {
            if (i <= histogram[j])
                putchar('*');
            else
                putchar(' ');
        }
        putchar('\n');
    }


    return 0;
}


