#include <stdio.h>

int main(int argc, char **argv)
{
	printf("size of ... \n");
	printf("  int: %zd bytes\n", sizeof(int));
	printf("  char: %zd bytes\n", sizeof(char));
	printf("  long: %zd bytes\n", sizeof(long));
	printf("  long long: %zd bytes\n", sizeof(long long));
	printf("  double: %zd bytes\n", sizeof(double));
	printf("  long double: %zd bytes\n", sizeof(long double));
	printf("  float: %zd bytes\n", sizeof(float));
	printf("  short: %zd bytes\n\n", sizeof(short));
    
	return 0;
}
