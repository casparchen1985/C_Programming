#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 100
#define STRING_SIZE 1200

void integer_array_to_string(int source[], size_t length, char *result, size_t result_size); 

int main(int argc, char **argv)
{
	int primeArry[ARRAY_SIZE] = {2, 3};
    size_t array_count = 2;
    char primeString[STRING_SIZE];
    
    for (int num = 5; num <= 100; num += 2) {
        bool isPrime = true;
        
        for (size_t arrIndx = 0; arrIndx < array_count; ++arrIndx) {
            if (num % primeArry[arrIndx] == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            if (array_count < ARRAY_SIZE) {
                primeArry[array_count] = num;
                array_count++;
            } else {
                fprintf(stderr, "Error: Array size exceeded.\n");
                return 0;
            }
        }
    }
    
    integer_array_to_string(primeArry, array_count, primeString, STRING_SIZE);
    
    printf("Prime Numbers are:\n%s\n", primeString);
    
	return 0;
}


void integer_array_to_string(int source[], size_t length, char *result, size_t result_size) {
    
    // init some variable
    char element[12];
    result[0] = '\0';
    size_t usedSize = 0;
    
    // iterate all elements
    for (size_t indx = 0; indx < length; indx++) {
        
        // calculate the size of element
        int writtenSize = snprintf(element, sizeof(element), "%d", source[indx]);
        
        // check convert operation and memory size
        if (writtenSize < 0 || usedSize + writtenSize + 1 >= result_size) {
            fprintf(stderr, "Error: Buffer size exceeded or snprintf error.\n");
            return;
        }
        
        // add char of element
        strncat(result, element, result_size - usedSize - 1);
        usedSize += writtenSize;
        
        // add space char
        if (indx < length - 1) {
            
            // not enough memory size
            if (usedSize + 2 >= result_size) {
                fprintf(stderr, "Error: Buffer size exceeded while adding space.\n");
                return;
            }
            
            strncat(result, " ", result_size - usedSize - 1);
            usedSize += 1;
        }
    
    }
}