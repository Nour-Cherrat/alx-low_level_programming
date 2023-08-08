#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * display_elf_header - Displays the information in the ELF header.
 * @header: Pointer to the ELF header structure.
 */
void display_elf_header(Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");
	printf("  Class:                             ");
	switch (header->e_ident[EI_CLASS])
	{
	case ELFCLASSNONE: printf("ELFCLASSNONE\n"); break;
	case ELFCLASS32: printf("ELF32\n"); break;
	case ELFCLASS64: printf("ELF64\n"); break;
	default: printf("<unknown>\n");
	}
	printf("  Data:                              ");
	switch (header->e_ident[EI_DATA])
	{
	case ELFDATANONE: printf("Unknown data format\n"); break;
	case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
	case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
	default: printf("<unknown>\n");
	}
	printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            ");
	switch (header->e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE: printf("UNIX - System V\n"); break;
	case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
	case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
	case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
	case ELFOSABI_FREEBSD: printf("UNIX - FreeBSD\n"); break;
	case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
	case ELFOSABI_OPENBSD: printf("UNIX - OpenBSD\n"); break;
	default: printf("<unknown>\n");
	}
	printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              ");
	switch (header->e_type)
	{
	case ET_NONE: printf("No file type\n"); break;
	case ET_REL: printf("REL (Relocatable file)\n"); break;
	case ET_EXEC: printf("EXEC (Executable file)\n"); break;
	case ET_DYN: printf("DYN (Shared object file)\n"); break;
	case ET_CORE: printf("CORE (Core file)\n"); break;
	default: printf("<unknown>\n");
	}
	printf("  Entry point address:               0x%lx\n", (unsigned long)header->e_entry);
}

/**
 * main - Entry point of the program.
 * @argc: Number of arguments.
 * @argv: Array of argument strings.
 *
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		dprintf(2, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Error: Cannot open file %s\n", argv[1]);
		return (98);
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		dprintf(2, "Error: Cannot read ELF header from file %s\n", argv[1]);
		close(fd);
		return (98);
	}

	if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
	    header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(2, "Error: Not an ELF file: %s\n", argv[1]);
		close(fd);
		return (98);
	}

	display_elf_header(&header);

	close(fd);
	return (0);
}

