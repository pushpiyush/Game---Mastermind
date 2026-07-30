#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// structure to store history of each guess
typedef struct
{
    int guess;
    int exist;
    int position;
} try;

// functions declaration
bool valid_key(int key);
int get_key(char *prompt);
void update_try(int guess, int key, int i, try *pointer[]);
void free_memory(try *pointer[]);

// game constant
int ALLOWED_GUESS = 12;
int KEY_LENGTH = 4;

// main function
int main(void)
{
    // get the key from user initially
    int key = get_key("Key");

    // array of pointer to store history
    try *pointer[ALLOWED_GUESS];

    for (int i = 0; i < ALLOWED_GUESS; i++)
    {
        // get the guess value from user
        int guess = get_key("Guess");

        // update and print the history
        update_try(guess, key, i, pointer);

        // if it's correct guess
        if (guess == key)
        {
            printf("You guessed the key: %d\n", key);
            printf("It took you %d guesses\n", i + 1);
            free_memory(pointer);
            break;
        }

        // if it's the last allowed guess
        else if (i == ALLOWED_GUESS - 1)
        {
            printf("You have made all %d guesses and could not guess the key.\n", ALLOWED_GUESS);
            printf("The key is: %d\n", key);
            free_memory(pointer);
        }

        printf("\n");
    }

    return 0;
}

// function to get the user's input
int get_key(char *prompt)
{
    char buffer[10];
    int key;

    while (true)
    {
        // get user's input
        printf("%s: ", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            continue;
        }
        if (sscanf(buffer, "%d", &key) <= 0)
        {
            // if the input does not starts with number
            // TODO
            printf("****contains non-numbers, try again\n\n");
            continue;
        }

        // if entered key satisfies all condition, break out of loop
        if (valid_key(key))
        {
            return key;
        }
    }
}

// function to check if the key has exactly 4 digits and each digits are unique
bool valid_key(int key)
{
    // if the key has not exactly 4 digit
    if (!(key >= 1000 && key <= 9999))
    {
        printf("****guess must have length of 4, try again\n\n");
        return false;
    }

    // list declaration to contain each digit of key
    int digits[KEY_LENGTH];

    // loop to add each digit of key in list
    for (int i = 0; i < KEY_LENGTH; i++)
    {
        // for each digit in the key
        int digit = (key % (int)pow(10, i + 1)) / pow(10, i);

        digits[i] = digit;
    }

    // logic: if two digits are same, subtracting them would result 0
    for (int i = 0; i < KEY_LENGTH; i++)
    {
        int current_dig = digits[i];

        for (int j = i + 1; j < KEY_LENGTH; j++)
        {
            if (current_dig - digits[j] == 0)
            {
                printf("****no repeated digits, try again\n\n");
                return false;
            }
        }
    }

    return true;
}

// function to update the pointer array of history
void update_try(int guess, int key, int guess_count, try *pointer[])
{
    int exist = 0;
    int position = 0;

    // array to store each digit of numbers
    int guess_digits[KEY_LENGTH];
    int key_digits[KEY_LENGTH];

    // store each digit of the numbers in array
    for (int i = 0; i < KEY_LENGTH; i++)
    {
        int guess_digit = (guess % (int)pow(10, i + 1)) / pow(10, i);
        int key_digit = (key % (int)pow(10, i + 1)) / pow(10, i);
        guess_digits[i] = guess_digit;
        key_digits[i] = key_digit;
    }

    for (int i = 0; i < KEY_LENGTH; i++)
    {
        // for each digit of guess
        for (int j = 0; j < KEY_LENGTH; j++)
        {
            // for each digit of key
            if (guess_digits[i] == key_digits[j])
            {
                exist++;
                if (i == j)
                {
                    position++;
                }
            }
        }
    }

    // update the pointer
    pointer[guess_count] = malloc(sizeof(try));
    pointer[guess_count]->guess = guess;
    pointer[guess_count]->exist = exist;
    pointer[guess_count]->position = position;

    // print the guesses
    for (int i = 0; i <= guess_count; i++)
    {
        printf("%d : exist:%d, position:%d\n", pointer[i]->guess, pointer[i]->exist, pointer[i]->position);
    }
}

// free the allocated memory from pointer
void free_memory(try *pointer[])
{
    for (int i = 0; i < ALLOWED_GUESS; i++)
    {
        if (pointer[i] == NULL)
        {
            break;
        }
        free(pointer[i]);
    }
}