#include "main.h"
#include "elfmain.h"

/**
 * main - Write a program that displays the information contained
 * in the ELF header at the start of an ELF file.
 * @argc: number of arguments
 * @argv: arguments
 * Usage: elf_header elf_filename
 * Displayed information: (no less, no more, do not include trailing whitespace)
 * Magic
 * class
 * Data
 * Version
 * OS/ABI
 * ABI Version
 * Type
 * Entry point address
 * Format: the same as readelf -h (version 2.26.1)
 * If the file is not an ELF file, or on error,
 * exit with status code 98 and display a comprehensive error message to stderr
 * You are allowed to use lseek once
 * You are allowed to use read a maximum of 2 times at runtime
 * You are allowed to have as many functions as you want in your source file
 * You are allowed to use printf
 * Return: nothing
 */

/**
 * check_elf - first check if the file is elf
 * @e_ident: pointer to an array that has elf magic numbers
 * if the file is not an elf file,  exit with status code 98
 * and display a comprehensive error message to stderr
 */
void check_elf(unsigned char *e_ident)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_ident[i] != 127 &&
				e_ident[i] != 'E' &&
				e_ident[i] != 'L' &&
				e_ident[i] != 'F')
		{
			dprintf(STDERR_FILENO: "Error: It's not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * magic_elf - print the magic numbers of the ELF file header
 * @e_ident: pointer to an array that has elf magic numbers
 */
void magic_elf(unsigned char *e_ident)
{
	int i;

	printf(" Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);
		if (i != EI_NIDENT - 1)
			printf(" ")
		else
			printf("\n")
	}
}

/**
 * elf_class - the class of an ELF header file
 * @e_ident: pointer to an array that has elf class
 */
void elf_class(unsigned char *e_ident)
{
	printf(" Class: ");
	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
