/*******************************************************************************************
* Programmer: Jamar Fraction                                                               *
* Class: CptS 121, Spring  2017; Lab Section 01											   *
* Programming Assignment: PA8															   *
* Date: April 23, 2017                                                                     *
* Description:This program fulfills the requirements for the eighth programming assignment *
********************************************************************************************/
#include "Header.h"

/*************************************************************
* Function: binary_search
* Input parameters: int sortedList[], int targetValue, int *targetIndex
* Returns: true if the target value is contained, false if not
*************************************************************/
bool binary_search(int sortedList[], int targetValue, int *targetIndex) {


//Method:
//	Set left to 1 and right to n ... n == sizeOf(sortedList) 
//		Set found to false
//		Set targetindex to - 1
//		While found is false and left is less than or equal to right
//			Set mid to midpoint between left and right
//			If target = item at mid then set found to true and set targetindex to mid
//			If target < item then set right to mid – 1
//			If target  > item then set to left to mid + 1
//		Return the targetindex



	int left = 0, right = 0, mid = 0;
	bool found = false;

	right = sizeof(sortedList);
	

	while ((found == false) && (left <= right)) {

		mid = ((left + right) / 2);

		if (targetValue == sortedList[mid]) {
			found = true;
			*(targetIndex) = mid;
		} else if(targetValue < sortedList[mid]){

			right = mid - 1;

		}
		else if (targetValue > sortedList[mid]) {
			left = mid + 1;
		}

	}

	return found;
}

/*************************************************************
* Function: bubble_sort
* Input parameters: char *list[], int numOfStrings
* Returns: nothing, output parameter is a sorted list
*************************************************************/
void bubble_sort(char *list[], int numOfStrings) {

		/*1.      set the marker U for the unsorted section at the end of the list(U is an integer index value)
		2.      while the unsorted section has more than one element do steps 3 through 7

		3.            set the current element marker C at the second element of the list(C is an integer index value)

		4.       while C has not passed U do steps 5 and 6
		5.                if the item at position C is less than the item to its left then exchange these two items
		6.                move C to the right one position
		7.       move U left one position
		8.   stop*/


	int U = 0, C = 0;
	char *temp;

	U = numOfStrings - 1;

	while (U > 1)
	{

		C = 1;
		 
		while (C <= U) {

			

			if (strcmp(list[C - 1], list[C]) > 0) {

				//exhange C and C - 1
				temp = list[C];
				list[C] = list[C - 1];
				list[C - 1] = temp;  
				
			}

			C++;
			
		}

		U -= 1;
		
	}
	

}

/*************************************************************
* Function: maximum_occurrences
* Input parameters: char *string, Occurrences occurrencesStruct[], int *maxOccurrences, char *mostFrequentChar
* Returns: nothing, output parameters are the most frequent character and how many times it is found
*************************************************************/
void maximum_occurrences(char *string, Occurrences occurrencesStruct[], int *maxOccurrences, char *mostFrequentChar) {

	/*The function determines the frequency of each character found in the array.
	The frequency is defined as : number of one character symbol / total number
	of characters.The function should use the second array argument(of struct occurrences)
	to keep track of the frequency of each character.Also, it must return, through the pointers, the maximum 
	number of occurrences of any one character and the corresponding character for which the maximum represents.
	Thus, for a string such as “test string”, ‘t’ occurs 3 times, which is the maximum occurrences
	for any one character in the string.*/

	int length = 0, structPos = 0, j = 0, charPosition = 0, freePosition = -1, k = 0, arrayPos = 0, count = 0;
	length = strlen(string);

	char cur = '\0';
	char charArray[100];
	bool inserted = false;

	//initialize the char array used as a helper for the position of the characters in the passed in array
	for (int i = 0; i < 100; i++) {
		charArray[i] = '\0';
	}
	

	for (int i = 0; i < length; i++) {
	
		cur = string[i];

		//check and see if the character is already contained within the helper array
		charPosition = contains(charArray, length, cur);

		//if found
			//use the position it was found in to increment the count in the struct at that location
		if (charPosition > -1) {

			occurrencesStruct[charPosition].num_occurrences += 1;

		}
		//if not found
		//go through the helper array to find the next available spot in the helper array (for loop)
		else {
			//initialize the num_occurrences value in the struct
			occurrencesStruct[arrayPos].num_occurrences = 0;

			//add 1 to the count within the struct
			occurrencesStruct[arrayPos].num_occurrences += 1;

			//set the value of charArray[arrayPos] to the current character
			charArray[arrayPos] = cur;
			
			//increment the arrayPos 
			arrayPos += 1;
		}

	}

	//go through the struct array to see which 'Occurrences' within the array is the greatest
	//set the frequency of each value within the struct as well

	for (int i = 0; i < length; i++) {
		if (occurrencesStruct[i].num_occurrences >= count) {

			count = occurrencesStruct[i].num_occurrences;

			//set the value of the greatest occurrences to it's output paramenter
			*maxOccurrences = count;

			//set the value of the most frequent character to it's output parameter
			*mostFrequentChar = charArray[i];

		}

		//initialize the frequency to 0
		occurrencesStruct[i].frequency = 0.0;

		//set the frequency to it's actual value
		occurrencesStruct[i].frequency = (occurrencesStruct[i].num_occurrences / length);
	}

	
	//test to see if the occurrences values are being stored like they should

	for (int i = 0; i < length; i++) {

		if (charArray != NULL) {
			printf("Character: %c, Occurrences: %d\n", charArray[i], occurrencesStruct[i].num_occurrences);
		}
		
	}

}

/*************************************************************
* Function: contains
* Input parameters: char charArray[], int stringLength, char whatChar
* Returns: 1 if the character is within the array
*************************************************************/
int contains(char charArray[], int stringLength, char whatChar) {

	//goes through the array to see if the character is contained within the array
	//if no, return -1
	//if yes, return the position of the character

	for (int i = 0; i < stringLength; i++) {
		if (charArray[i] == whatChar) {
			return i;
		}
	}

	return -1;
}

/*************************************************************
* Function: my_str_n_cat
* Input parameters: char *destination, char *source, int charsToCopy
* Returns: pointer to the destination 
*************************************************************/
char* my_str_n_cat(char *destination, char *source, int charsToCopy) {

	char* p = destination;

	for (; (charsToCopy > 0) && (*source != '\0'); --charsToCopy) {
		*p = *source++;
	}

	return destination;

}

/*************************************************************
* Function: is_palindrome
* Input parameters: char *word, int wordLength
* Returns: 1 if palindrome, 0 if not
*************************************************************/
int is_palindrome(char *word, int wordLength) {


	//start and end variables to be used in the loop.. i think
	int start = 0, end = 0, palindrome = -1;

	//base case
	//wordLength == 1
	if (wordLength == 1) {
		return 1;
	}
	//length of 2
	else if (wordLength == 2) {
		//the two chars match, return 1
		if (word[0] == word[1]) {

			return 1;
		}
		//the 2 chars do not match, return 0;
		else {

			return 0;
		}
	}
	//recursive case
	else if (word[0] == word[wordLength -1]){
		
		
		//due to the above cases the smallest the word that will get used in this
		//loop will be of length 3

		//gonna try dynamic memory allocation :)
		char *wrd;

		//wordLength - 1 used to account for the null character at the end
		wrd = (char *)calloc(sizeof(char), (wordLength - 1));

		//chop the word down
		for (int i = 1; i < (wordLength - 1); i++) {
			
			wrd[i - 1] = word[i];

		}

		//set the new word length
		wordLength = (strlen(wrd));
	
		//pass the new word and length to the function
		palindrome = is_palindrome(wrd, wordLength);

	}
	//is not a palindrome case
	else {
		return 0;
	}

	return palindrome;
}

/*************************************************************
* Function: sum_primes
* Input parameters: int n
* Returns: the sum of primes up to number n
*************************************************************/
int sum_primes(int n) {

	if (n > 1)
	{
		n = check_prime(n) + sum_primes(n - 1);

		return n;
	}
	else
	{
		return 0;
	}

}

/*************************************************************
* Function: check_prime
* Input parameters: int n
* Returns: 0 if not prime, numbner n if it is prime
*************************************************************/
int check_prime(int n)
{
	int i = 2;
	int remainder = n % 2;

	while (i != n && remainder != 0) //Starting with 2, mod n by every number between 2 and n -1 to see if it is prime.
	{
		remainder = n % i;
		i++;
	}
	if (i == n) //i made it all the way to n which means that n is prime
	{
		return n;
	}
	else
	{
		return 0; //i did not make it to n which means that n is not prime
	}
}