#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
/**
 * error_exit - prints error message and exits with 98
 * @msg: error message
 */
void error_exit(const char *msg)
{
dprintf(STDERR_FILENO, "%s\n", msg);
exit(98);
}
/**
 * print_magic - prints ELF magic
 * @e_ident: ELF identification
 */
void print_magic(unsigned char *e_ident)
{
int i;
printf("  Magic:   ");
for (i = 0; i < EI_NIDENT; i++)
printf("%02x%s", e_ident[i], i == EI_NIDENT - 1 ? "\n" : " ");
}
/**
 * print_class - prints ELF class
 * @e_ident: ELF identification
 */
void print_class(unsigned char *e_ident)
{
printf("  Class:                             ");
if (e_ident[EI_CLASS] == ELFCLASS32)
printf("ELF32\n");
else if (e_ident[EI_CLASS] == ELFCLASS64)
printf("ELF64\n");
else
printf("none\n");
}
/**
 * print_data - prints ELF data encoding
 * @e_ident: ELF identification
 */
void print_data(unsigned char *e_ident)
{
printf("  Data:                              ");
if (e_ident[EI_DATA] == ELFDATA2LSB)
printf("2's complement, little endian\n");
else if (e_ident[EI_DATA] == ELFDATA2MSB)
printf("2's complement, big endian\n");
else
printf("none\n");
}
/**
 * print_version - prints ELF version
 * @e_ident: ELF identification
 */
void print_version(unsigned char *e_ident)
{
printf("  Version:                           %d (current)\n",
e_ident[EI_VERSION]);
}
/**
 * print_osabi - prints ELF OS/ABI
 * @e_ident: ELF identification
 */
void print_osabi(unsigned char *e_ident)
{
printf("  OS/ABI:                            ");
switch (e_ident[EI_OSABI])
{
case ELFOSABI_SYSV:
printf("UNIX - System V\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}
}
/**
 * print_abi - prints ABI version
 * @e_ident: ELF identification
 */
void print_abi(unsigned char *e_ident)
{
printf("  ABI Version:                       %d\n",
e_ident[EI_ABIVERSION]);
}
/**
 * print_type - prints ELF type
 * @e_type: ELF type
 * @endian: endianness
 */
void print_type(unsigned int e_type, unsigned char endian)
{
if (endian == ELFDATA2MSB)
e_type >>= 8;
printf("  Type:                              ");
if (e_type == ET_EXEC)
printf("EXEC (Executable file)\n");
else if (e_type == ET_DYN)
printf("DYN (Shared object file)\n");
else
printf("NONE\n");
}
/**
 * print_entry - prints entry point
 * @e_entry: entry address
 * @endian: endianness
 */
void print_entry(unsigned long int e_entry, unsigned char endian)
{
printf("  Entry point address:               ");
if (endian == ELFDATA2MSB)
{
e_entry = ((e_entry << 8) & 0xFF00FF00) |
((e_entry >> 8) & 0x00FF00FF);
e_entry = (e_entry << 16) | (e_entry >> 16);
}
printf("0x%lx\n", e_entry);
}
/**
 * main - displays ELF header information
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
int fd;
Elf64_Ehdr header;
if (ac != 2)
error_exit("Usage: elf_header elf_filename");
fd = open(av[1], O_RDONLY);
if (fd == -1)
error_exit("Error: Cannot open file");
if (read(fd, &header, sizeof(header)) != sizeof(header))
error_exit("Error: Cannot read ELF header");
if (header.e_ident[EI_MAG0] != ELFMAG0 ||
header.e_ident[EI_MAG1] != ELFMAG1 ||
header.e_ident[EI_MAG2] != ELFMAG2 ||
header.e_ident[EI_MAG3] != ELFMAG3)
error_exit("Error: Not an ELF file");
printf("ELF Header:\n");
print_magic(header.e_ident);
print_class(header.e_ident);
print_data(header.e_ident);
print_version(header.e_ident);
print_osabi(header.e_ident);
print_abi(header.e_ident);
print_type(header.e_type, header.e_ident[EI_DATA]);
print_entry(header.e_entry, header.e_ident[EI_DATA]);
close(fd);
return (0);
}
