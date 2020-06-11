#pragma warning(disable: 4996)
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*
 * Name: Trevor Benyack
 * Date: 2020-06-13
 * Class: CIT-145-Z01B
 * Assignment: Chapter 06
 * Notes: This program uses an implementation of the Sieve of Eratosthenes to print the prime numbers from 2 up to
 * the limit entered by the user. The number of columns is dynamically determined by the character length of the limit
 * entered by the user.
 */

int main() {

    unsigned int limit = 0;
    printf("%s", "Enter the limit: ");
    scanf("%d", &limit);
    printf("%s%d", "Primes up to ", limit);
    puts("");puts("");
    bool numArray[limit + 1];
    unsigned int count = 0;

    // initializes all numArray elements to true
    for (int i = 0; i < limit; ++i) {
        numArray[i] = true;
    }

    // marks non-prime numbers in numArray as false
    // Algorithm obtained from https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
    for (int i = 2; i <= pow(limit, 0.5); ++i) {
        if (numArray[i] == true) {
            for (int j = pow(i, 2); j <= limit ; j += i) {
                numArray[j] = false;
            }
        }
    }

    // determines how many columns (with the max width of limit) can be created given a screen max width of 80 characters
    int limitLength = snprintf( NULL, 0, "%lu", limit );
    int columnSize = limitLength + 1;
    int columns = 80 / columnSize;

    // prints the prime numbers
    for (int i = 2; i <= limit; ++i) {

        // if the current index position is marked "true", then print the index number
        if (numArray[i] == true){
            printf("%*d", columnSize, i);
            count++;

            // inserts return character when the max number of columns is reached
            if (count % columns == 0){
                printf("%s", "\n");
            }
        }
    }

    puts("");
    puts("");
    printf("%s%d", "Number of primes: ", count);
    puts("");

    // UNCOMMENT THIS BEFORE SUBMITTING
    // system("pause");
    return 0;
}
