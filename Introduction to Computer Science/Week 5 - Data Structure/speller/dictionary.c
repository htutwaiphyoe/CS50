// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>


#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;
// total words
unsigned int totalWords = 0;
// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{

    // get node value
    node *cursor = table[hash(word)];

    // loop until no node
    while (cursor != NULL)
    {
        // compare word and node word case-insensitve
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }

        // change to next node
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // this is from stackoverflow
    unsigned long hash = 5381;
    int c;

    while ((c = tolower(*word++)))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }


    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // open file
    FILE *inputFile = fopen(dictionary, "r");

    // return false if file not exist
    if (inputFile == NULL)
    {
        return false;
    }

    // declare for each word
    char word[LENGTH + 1];

    // loop for reading file until the end which is EOF
    while (fscanf(inputFile, "%s", word) != EOF)
    {
        // initialize node
        node *n = malloc(sizeof(node));

        // check node is valid
        if (n == NULL)
        {
            return false;
        }

        // copy word to node
        strcpy(n->word, word);

        // point to head with new node
        n->next = table[hash(word)];

        // store head with node
        table[hash(word)] = n;

        totalWords++;
    }

    // close input file
    fclose(inputFile);

    // done loading file
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return totalWords;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // loop for hash table
    for (int i = 0; i < N; i++)
    {
        // get array of linkedlist
        node *cursor = table[i];

        // loop until array is empty
        while (cursor)
        {
            // temp for free
            node *temp = cursor;

            // change cursor to next
            cursor = cursor->next;

            // free memory
            free(temp);
        }

        // check if table end and cursor is null
        if (i == N - 1 && cursor == NULL)
        {
            return true;
        }


    }
    return false;
}
