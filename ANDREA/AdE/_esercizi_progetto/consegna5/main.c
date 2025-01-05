#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Get filename with no extension to generate the output file
 *
 * @param filename The name of the file received as input.
 *                 This should not include directory paths.
 * @param basename A pointer to the array that will include the filename for the new file.
 *                 There are no size checks, the array should be big enough to hold the string.
 * @note If the filename does not contain a dot, the entire filename will be copied.
 */
void get_file_name_without_extension(const char *filename, char *basename) {
    const char *dot = strrchr(filename, '.'); // find last dot in the filename
    if (dot) {
        // copy the filename to generate the output file
        strncpy(basename, filename, dot - filename);
        basename[dot - filename] = '\0';
    } else {
        // edge case: no dot found, copy all the filename
        strcpy(basename, filename);
    }
}