#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD 50
#define MAX_TRIES 3

typedef struct word_hint 
{
        char word[MAX_WORD];
        char hint[MAX_WORD];
} word_t;

word_t secret_arr[] =
{
	{"gamma", "highest"},
	{"sunlight", "median"},
	{"radio", "lowest"}
};

int main()
{
	srand(time(NULL));
	int idx = rand() % 3;

	char* secret_word = secret_arr[idx].word;
	char* secret_hint = secret_arr[idx].hint;

	printf("%s\n", secret_hint);

	int lenght = strlen(secret_word);

	char guessed_word[50] = { 0 };
	_Bool guessed_letter[26] = { false };

	int tries = 0;

	while (tries < MAX_TRIES)
	{
		char guess;
		printf("enter a guess: ");
		scanf(" %c", &guess);

		if (guessed_letter[guess - 'a'])
		{
			puts("already guessed!\n\n");
			continue;
		}
		
		guessed_letter[guess - 'a'] = '1';

		_Bool found = false;

		for (int i = 0; i < lenght; i++)
		{
			if (guess == secret_word[i])
			{
				found = true;
				guessed_word[i] = guess;
			}
		}

		if (found)
		{
			puts("good guess!");
		} else
		{
			puts("nope!\n\n");
			tries++;
			continue;
		}

		if (!strcmp(secret_word,guessed_word))
		{
			printf("you correctly guessed %s with %d tries!\n", secret_word,tries);
			break;
		} else
		{
			continue;
		}

	}
}

