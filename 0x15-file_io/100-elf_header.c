#include <elf.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "elfmain.h"

/**
 * main - Write a program that displays the information contained
 * in the ELF header at the start of an ELF file.
 * @argc: number of arguments
 * @argv: arguments
 * Usage: elf_header elf_filename
 * Displayed information: no less, no more, do not include trailing whitespace
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
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int op, rd;

	op = open(argv[1], O_RDONLY);
	if (op == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(op);
		dprintf(STDERR_FILENO,
				"Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	rd = read(op, header, sizeof(Elf64_Ehdr));
	if (rd == -1)
	{
		free(header);
		close_elf(op);
		dprintf(STDERR_FILENO,
				"Error: %s : No file like that\n", argv[1]);
		exit(98);
	}
	check_elf(header->e_ident);
	printf("ELF Header: \n");
	magic_elf(header->e_ident);
	elf_class(header->e_ident);
	elf_data(header->e_ident);
	elf_version(header->e_ident);
	elf_osabi(header->e_ident);
	elf_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	elf_entry(header->e_type, header->e_ident);
	free(header);
	close_elf(op);
	return (0);
}

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
			dprintf(STDERR_FILENO,
					"Error: It's not an ELF file\n");
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
			printf(" ");
		else
			printf("\n");
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
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * elf_data - the data of the elf
 * @e_ident: pointer to an array that has elf data
 */
void elf_data(unsigned char *e_ident)
{
	printf(" Data: ");
	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_DATA]);
	}
}

/**
 * elf_version - the elf's version
 * @e_ident: pointer to an array that has elf version
 */
void elf_version(unsigned char *e_ident)
{
	printf(" Version: %d",
			e_ident[EI_VERSION]);
	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
	}
}

/**
 * elf_osabi - the elf osi or abi
 * @e_ident: pointer to an array that has elf osi/abi
 */
void elf_osabi(unsigned char *e_ident)
{
	printf(" OSI/ABI: ");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * elf_abi - the abi of an elf
 * @e_ident: pointer of an array tha has the elf abi
 */
void elf_abi(unsigned char *e_ident)
{
	printf(" ABI Version: %d\n",
			e_ident[EI_ABIVERSION]);
}

/**
 * print_type - print the elf type
 * @e_ident: pointer to an array that has elf type
 * @e_type: the elf type
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf(" Type: ");
	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (none)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
	}
}

/**
 * elf_entry - the entry point address of elf header file
 * @e_ident: pointer to an array that has elf entry point address
 * @e_entry: the address of the entry header file
 */
void elf_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address: ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = ((e_entry << 16) | (e_entry >> 16));
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - close the elf header file
 * @elf: the elf file detector
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close elf header fd %d\n", elf);
		exit(98);
	}
}
