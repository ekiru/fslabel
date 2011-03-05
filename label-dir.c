#include "dir.h"
#include "error.h"

#include <stdlib.h>

int main(int argc, char **argv) {
	char *path;
	if (argc != 2) {
		usage_error();
		goto error;
	}

	if ((path = fslabel_dir(argv[1])) == NULL) {
		goto error;
	}

	puts(path);
	return 0;

	error:
	error_print(argv[0]);
	return error_code();
}
