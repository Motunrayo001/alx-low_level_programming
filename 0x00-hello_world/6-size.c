#include <stdio.h>
/**
 * main- A program on size is not grandeur, and territory does not make a nation
 * this means it prints the size of various computer type
 * Return: 0
 */
int main(void)
{
char a;
int b;
long int c;
long long int d;
float f;
printf("Size of a char: %zu bytes\n", sizeof(char));
printf("Size of a int: %zu bytes\n", sizeof(int));
printf("Size of a long int: %zu bytes\n", sizeof(long int));
printf("Size of a long long int: %zu bytes\n", sizeof(long long int));
printf("Size of a float: %zu bytes\n", sizeof(float));
return (0);
}
