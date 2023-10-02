#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * append_text_to_file - Appends text content to a file.
 * @filename: Name of the file to which text will be appended.
 * @text_content: Text content to append to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, bytes_written = 0;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[bytes_written] != '\0')
			bytes_written++;

		if (write(fd, text_content, bytes_written) == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}



