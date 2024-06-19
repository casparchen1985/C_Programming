#include <stdio.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
    enum Companies {
        GOOGLE,
        FACEBOOK,
        XEROX,
        YAHOO,
        EBAY,
        MICROSOFT
    };
    
    enum Companies googleVar = GOOGLE;
    enum Companies xeroxVar = XEROX;
    enum Companies ebayVar = EBAY;
    
	printf("Xerox is %d\nGoogle is %d\nEbay is %d\n", xeroxVar, googleVar, ebayVar);
	printf("Is Xerox equal Google?: %s\n", (xeroxVar == googleVar) ? "true" : "false");
	// printf("%d\n", (xeroxVar == googleVar));
	return 0;
}
