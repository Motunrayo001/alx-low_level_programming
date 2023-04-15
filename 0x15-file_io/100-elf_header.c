#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

/**
 * main - info about the elf header at the start of the elf file
 * @argc: count arguments
 * @argv: arguments
 * Return: 0
 */
int main(int __attribute__((__unused__))argc, char *argv[])
{
	Elf64_Ehdr *header;
	int a, b;

	a = open(argv[1], O_RDONLY);
	if (a == -1)
	{
		dprintf(STDERR_FILENO,  "Error: Can't read file%s\n", argv[1]);
		exit(98);
	}
void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_os/abi(unsigned char *e_ident);
void print_abi_version(unsigned char *e_ident);
void print_type(unsigned int e_type,unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * print_magic - print the magic number for elf header
 * @e_ident: a pointer of an array
 */
void print_magic(unsigned char *e_ident)
{
	int index;

	printf("Magic: ");
	for (index = 0; index < EL_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);
		if (index != EL_NIDENT - 1)
			printf(" ");
		else
			printf("\n");
	}
}

/**
 * print_class - print the class of the elf header
 * @e_ident: a pointer of the array
 */
void print_class(unsigned char *e_ident)
{
	printf("Class: ");
	switch (e_ident[EL_CLASS])
	{
		case ELFCLASS0:
			printf("none\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EL_CLASS]);
	}
}

/**
 * print_data - print the data of the elf header
 * @e_ident: a pointer to the array
 */
void print_data(unsigned char *e_ident)
{
	printf("Data: ");
	switch (e_ident[EL_DATA])
	{
		case ELFDATA0:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EL_CLASS]);
	}
}

/**
 * print_version - print the version of the elf header
 * @e_ident: a pointer to the array
 */
void print_version(unsigned char *e_ident)
{
	printf("Version: ");
	switch (e_ident[EL_VERSION])
	{
		case EL_CURRENT:
			printf("current\n");
			break;
		default:
			printf("\n");
	}
}

/**
 * print_os/abi - print the os/abi of the elf header
 * @e_ident: a pointer to the array
 */
void print_os/abi(unsigned char *e_ident)
{
	printf("OS/ABI: ");
	switch (e_ident[EL_OS/ABI])
	{
		case ELFOS/ABI0:
			printf("UNIX - SYSTEM V\n");
			break;
		case ELFOS/ABIHPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOS/ABINETBSD:
			printf("UNIX - NETBSD\n");
			break;
		case ELFOS/ABILINUX:
			printf("UNIX - LINUX\n");
			break;
		case ELFOS/ABISOLARIS:
			printf("UNIX - SOLARIS\n");
			break;
		case ELFOS/ABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOS/ABI_FREEBSD:
			printf("UNIX - FREEBSD\n");
			break;
		case ELFOS/ABI_ARM:
			printf("UNIX - ARM\n");
			break;
		case ELFOS/ABI_STANDALONE:
			printf("UNIX - Standalone App\n");
			break;
		case ELFOS/ABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EL_OS/ABI]);
	}
}

/**
 * print_abi_version - print the abi version of the elf header
 * @e_ident: a pointer to the array
 */
void print_abi_version(unsigned char *e_ident)
{
	printf("ABI Version: %d\n", e_ident[EL_ABI_VERSION]);
}

/**
 * print_type - print the type of the elf header
 * @e_ident: a pointer to the array
 * @e_type: the elf type
 */
void print_type(unsigned int e_type,unsigned char *e_ident)
{
	if (e_ident[EL_DATA] == ELFDATA2MSB)
		e_type >>= 8;
	printf("Type: ");
	switch (e_type)
	{
		case ET0:
			printf("none\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_SOF:
			printf("SOF (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
}

/**
 * print_entry_point - print the entry point address of the elf header
 * @e_ident: a pointer to the array
 */
void print_entry_point(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("Entry point address: ");
	if (e_ident[EL_DATA] == ELFDATA2MSB)
	{
		e_entry = (e_entry << 16) | (e_entry >> 16);
		e_entry = ((e_entry << 8) & 0xFF00FF00) | ((e_entry >> 8) & 0xFF00FF);
	}
	if (e_ident[EL_CLASS] != ELFCLASS32)
		printf("%#x\n", e_entry);
	else
		printf("%#x\n", (unsigned int)e_entry);
}

/** 
 * close_elf - close the elf header file
 * @elf: the elf file
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
		exit(98);
	}
}
