#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "main.h"
/**
 * read_textfile - reads a text file and prints it to POSIX stdout
 * @filename: name of the file
 * @letters: number of letters to read and print
 *
 * Return: actual number of letters read and printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
ssize_t r, w;
char *buf;
if (filename == NULL || letters == 0)
return (0);
fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);
buf = malloc(sizeof(char) * letters);
if (buf == NULL)
{
close(fd);
return (0);
}
r = read(fd, buf, letters);
if (r == -1)
{
free(buf);
close(fd);
return (0);
}
w = write(STDOUT_FILENO, buf, r);
if (w == -1 || w != r)
{
free(buf);
close(fd);
return (0);
}
free(buf);
close(fd);
return (w);
}
