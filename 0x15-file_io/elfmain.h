#ifndef ELFMAIN_H
#define ELFMAIN_H

void print magic (unsigned char *e_ident);
void print_class (unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version (unsigned char *e_ident)
void print_abi (unsigned char *e_ident);
void print_osabi (unsigned char *e_ident);
void print_type (unsigned int e_type, unsigned char *e_ ident);
void print_entry (unsigned long int e_entry, unsigned c har *e_ident);
void close_elf(int elf);

check_elf (header->e_ident);
printf("ELF Header: \n");
print magic (header->e_ident);
print_class (header->e_ident);
print_data(header->e_ident);
print_version (header->e_ident);
print_osabi (header->e_ident);
A print_abi (header->e_ident);
print_type (header->e_type, header->e_ident);
print_entry (header->e_entry, header->e_ident);
