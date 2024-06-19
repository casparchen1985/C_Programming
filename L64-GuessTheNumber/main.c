#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv){
    int inputNum = 0;
    time_t t;
    srand((unsigned)time(&t));
    int ans = rand() %21;
    
    for (int quantity = 5; quantity > 0; --quantity) {
        printf("\nLet's guess the Number ( 0 - 20 ): ");
        scanf("%d", &inputNum);
        
        if(inputNum < 0 || inputNum > 20) {
            printf("%d is an illegal number\n", inputNum);
        } else if (inputNum == ans) {
            printf("Good job! The answer is %d\n", ans);
            return 0;
        } else if (inputNum > ans) {
            printf("Sorry, %d is too high. ( %d time%s left )\n", inputNum, quantity -1, quantity <= 2 ? "" : "s");
        } else {
            printf("Sorry, %d is too low. ( %d time%s left )\n", inputNum, quantity -1, quantity <= 2 ? "" : "s");
        }
    }
    printf("The answer is %d. Bye Bye!\n\n", ans);
	return 0;
}