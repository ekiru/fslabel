#include "dir.h"
#include "error.h"
#include "file.h"

#include <libgen.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	char *dir, *labelbase, *dir_copy;
	if (argc != 2) {
		create_usage_error();
		goto error;
	}

	if ((dir = fslabel_dir(argv[1])) == NULL) {
		goto error;
	}

	if (directory_exists(dir)) {
		label_already_exists_error();
		free(dir);
		goto error;
	}

	if ((dir_copy = strdup(dir)) == -1) {
		free(dir);
		goto error;
	}

	if ((labelbase = dirname(dir_copy)) == NULL) {
		allocation_error();
		free(dir);
		goto error;
	}

	if (ensure_directory(labelbase) == -1) {
		goto error;
	}

	if (ensure_directory(dir) == -1) {
		goto error;
	}

	return 0;

	error:
	error_print(argv[0]);
	return error_code();
}
