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
printf("Size of a char: 0x%08x\n", sizeof(char));
printf("Size of a int: 0x%08x\n", sizeof(int));
printf("Size of a long int: 0x%08x\n", sizeof(long int));
printf("Size of a long long int: 0x%08x\n", sizeof(long long int));
printf("Size of a float: 0x%08x\n", sizeof(float));
return (0);
}
