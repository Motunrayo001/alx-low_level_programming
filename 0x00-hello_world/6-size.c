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
printf("Size of a char: %i byte(s)\n", sizeof(char));
printf("Size of a int: %i  byte(s)\n", sizeof(int));
printf("Size of a long int: %i byte(s)\n", sizeof(long int));
printf("Size of a long long int: %i byte(s)\n", sizeof(long long int));
printf("Size of a float: %i byte(s)\n", sizeof(float));
return (0);
}
