#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

int get_next_line(int fd, char **line)
{
    char buffer[1024];
    int i;
    int n;

    // Initialize line
    *line = malloc(1);
    if (!*line)
        return (-1);
    (*line)[0] = '\0';

    while ((n = read(fd, buffer, 1024)) > 0)
    {
        buffer[n] = '\0';  // Null-terminate the read buffer
        i = 0;

        // Find the first newline character or end of buffer
        while (i < n && buffer[i] != '\n')
            i++;

        // Reallocate memory for the new content of the line
        *line = realloc(*line, ft_strlen(*line) + i + 1);
        if (!*line)
            return (-1);

        // Copy the content of the buffer into the line
        ft_strlcat(*line, buffer, ft_strlen(*line) + i + 1);

        // If we found a newline, return 1 (there is more data to read)
        if (i < n)
        {
            return (1);
        }
    }

    // If we've read no more bytes, that means EOF or error
    return (n);
}

