#include "file.h"

#include <errno.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "error.h"

int directory_exists(char *directory) {
	struct stat stat_buf;
	if (stat(directory, &stat_buf) == -1) {
		return 0;
	} else {
		return S_ISDIR(stat_buf.st_mode);
	}
}

int ensure_directory(char *directory) {
	if (!directory_exists(directory)) {
		if (mkdir(directory, 0777) == -1) {
			directory_could_not_be_created_error();
			return -1;
		}
	}
	return 0;
}
