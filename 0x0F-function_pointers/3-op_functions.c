#include "3-calc.h"

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

/**
 * op_add - return the sum of two numbers
 * @a: first number
 * @b: second number
 * Return: sum of a and b
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - return the subtraction of two numbers
 * @a: first number
 * @b: second number
 * Return: subtraction of a and b
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - return multiplication of two numbers
 * @a: first number
 * @b: second number
 * Return: multiplication of a and b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - return division of two numbers
 * @a: first number
 * @b: second number
 * Return: division of a and b
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod- returns the remainder of division of two numbers
 * @a: first number
 * @b: second number
 * Return: the remainder of divison of a and b
 */
int op_mod(int a, int b)
{
	return (a % b);
}
