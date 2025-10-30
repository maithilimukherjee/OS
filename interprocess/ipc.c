#include <unistd.h>     // For POSIX functions like pclose()
#include <stdlib.h>     // For exit() and EXIT_SUCCESS / EXIT_FAILURE
#include <stdio.h>      // For input/output functions (printf, FILE, popen, fwrite, etc.)
#include <string.h>     // For string functions like strlen() and sprintf()

// Program: Writing to an external command using popen()
int main()
{
    FILE *write_fp;                // File pointer used to communicate with external command
    char buffer[BUFSIZ + 1];       // Buffer to store the text we want to send (BUFSIZ is a standard buffer size)

    // Write a string into 'buffer' using sprintf()
    sprintf(buffer, "The quick brown fox is sleeping.\n");

    // Open a pipe to an external command using popen()
    // "cat > newfile.txt" means: run the 'cat' command and redirect its output into 'newfile.txt'
    // "w" means we are opening the pipe for writing
    write_fp = popen("cat > newfile.txt", "w");

    // Check if the pipe was opened successfully
    if (write_fp != NULL)
    {
        // Write the contents of 'buffer' into the pipe
        // fwrite(data, size of each element, number of elements, file pointer)
        // This sends our string to the 'cat' command, which writes it into newfile.txt
        fwrite(buffer, sizeof(char), strlen(buffer), write_fp);

        // Close the pipe after writing is done
        // This also makes sure the external command finishes executing
        pclose(write_fp);

        // Exit successfully since everything worked
        exit(EXIT_SUCCESS);
    }

    // If pipe creation failed, exit with failure
    exit(EXIT_FAILURE);
}
