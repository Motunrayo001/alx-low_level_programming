#ifndef ELFMAIN_H
#define ELFMAIN_H

void magic_elf(unsigned char *e_ident);
void elf_class(unsigned char *e_ident);
void elf_data(unsigned char *e_ident);
void elf_version(unsigned char *e_ident);
void elf_abi(unsigned char *e_ident);
void elf_osiabi(unsigned char *e_ident);
void elf_type(unsigned int e_type, unsigned char *e_ident);
void elf_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);
void check_elf(unsigned char *e_ident);

#endif
