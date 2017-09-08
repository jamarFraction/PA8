/*******************************************************************************************
* Programmer: Jamar Fraction                                                               *
* Class: CptS 121, Spring  2017; Lab Section 01											   *
* Programming Assignment: PA8															   *
* Date: April 23, 2017                                                                     *
* Description:This program fulfills the requirements for the eighth programming assignment *
********************************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct occurrences
{
	int num_occurrences;
	double frequency;
} Occurrences;


bool binary_search(int sortedList[], int targetValue, int *targetIndex);

void bubble_sort(char *list[], int numOfStrings);

void maximum_occurrences(char *string, Occurrences occurrencesStruct[], int *maxOccurrences, char *mostFrequentChar);

char* my_str_n_cat(char *destination, char *source, int charsToCopy);

int is_palindrome(char *word, int wordLength);

int sum_primes(int n);


//helper functions
int contains(char charArray[], int stringLength, char whatChar);
int check_prime(int n);