#include "error.h"

#include <stdio.h>

enum error_code {
	SUCCESS = 0,
	ALLOCATION_ERROR,
	DIRECTORY_COULD_NOT_BE_CREATED_ERROR,
	LABEL_ALREADY_EXISTS_ERROR,
	NO_HOME_DIRECTORY_ERROR,
	USAGE_ERROR,
};

static enum error_code error = SUCCESS;

static void (*error_print_function)(char *program_name);

static void allocation_error_print(char *program_name) {
	fprintf(stderr, "%s: allocation error\n", program_name);
}

void allocation_error(void) {
	error = ALLOCATION_ERROR;
	error_print_function = &allocation_error_print;
}

static void directory_could_not_be_created_error_print(char *program_name) {
	fprintf(stderr, "%s: directory creation failed\n", program_name);
}

void directory_could_not_be_created_error(void) {
	error = DIRECTORY_COULD_NOT_BE_CREATED_ERROR;
	error_print_function = &directory_could_not_be_created_error_print;
}

static void label_already_exists_error_print(char *program_name) {
	fprintf(stderr, "%s: label already exists\n", program_name);
}

void label_already_exists_error(void) {
	error = LABEL_ALREADY_EXISTS_ERROR;
	error_print_function = &label_already_exists_error_print;
}

static void no_home_directory_error_print(char *program_name) {
	fprintf(stderr, "%s: no $HOME directory\n", program_name);
}

void no_home_directory_error(void) {
	error = NO_HOME_DIRECTORY_ERROR;
	error_print_function = &no_home_directory_error_print;
}

static void create_usage_error_print(char *program_name) {
	fprintf(stderr, "Usage: %s LABEL\n", program_name);
}

void create_usage_error(void) {
	error = USAGE_ERROR;
	error_print_function = &create_usage_error_print;
}

static void dir_usage_error_print(char *program_name) {
	fprintf(stderr, "Usage: %s LABEL\n", program_name);
}

void dir_usage_error(void) {
	error = USAGE_ERROR;
	error_print_function = &dir_usage_error_print;
}

int error_code(void) {
	return error;
}

void error_print(char *program_name) {
	error_print_function(program_name);
}
