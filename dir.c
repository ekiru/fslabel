#include "dir.h"

#include <stdlib.h>

#include "error.h"
#include "path.h"

char *fslabel_dir(char *label_name) {
	char *path;
	char *home = getenv("HOME");
	if (home == NULL) {
		no_home_directory_error();
		return NULL;
	}
	if ((path = path_join(home, label_name)) == NULL) {
		allocation_error();
		return NULL;
	}
	return path;
}
