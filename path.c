#include "path.h"

#include <stdlib.h>
#include <string.h>

#include "error.h"

char *path_join(char *directory, char *file) {
	size_t directory_len, file_len, len;
	directory_len = strlen(directory);
	file_len = strlen(file);
	len = directory_len + 1 /* for '/' */ + file_len + 1;
	char *result = calloc(len, sizeof (char));
	if (result == NULL) {
		allocation_error();
		return NULL;
	}
	strcpy(result, directory);
	result[directory_len] = '/';
	strcpy(result + directory_len + 1, file);
	result[len - 1] = '\0';
	return result;
}
