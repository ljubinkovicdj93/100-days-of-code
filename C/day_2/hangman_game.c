#include <stdio.h>
#include <string.h>

#define MAX_LETTER_COUNT 20
#define MAX_TRIES 5

int main()
{
    printf("\nWelcome to the Hangman Game!\n");

    char word_to_guess[MAX_LETTER_COUNT] = "Djordje";

    size_t word_count = strlen(word_to_guess);

    int user_input;
    int try_count = 0;

    char masked_word[word_count];
    for (int i = 0; i < word_count; ++i)
        masked_word[i] = '_';

    while ((user_input = getchar()) != EOF)
    {
        if (user_input != '\n') 
        {
            int found = 0;
            for (int i = 0; i < word_count; ++i)
            {
                if (word_to_guess[i] == user_input)
                {
                    ++found;
                    masked_word[i] = user_input;
                }
            }

            for (int i = 0; i < word_count; ++i)
                printf("%c ", masked_word[i]);

            if (strcmp(word_to_guess, masked_word) == 0)
            {
               printf("\n\n\nYOU HAVE WON!!!\n\n\n");
               return 0;
            }

            if (found == 0)
            {
                ++try_count;
                int tries_left = MAX_TRIES - try_count;

                if (tries_left > 0)
                    printf("\nWRONG! You have %d tries left\n", tries_left);
                else 
                {
                    printf("\nNo more tries :(. Would you like to play a new game?\n");
                    if (getchar() == 'y')
                        try_count = 0;
                    else
                        return 0;
                }
            }


            putchar('\n');
        }
    }

    return 0;
}
