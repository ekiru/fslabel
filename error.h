#ifndef FSLABEL_ERROR_H
#define FSLABEL_ERROR_H

void allocation_error(void);
void directory_could_not_be_created_error(void);
void label_already_exists_error(void);
void no_home_directory_error(void);

void create_usage_error(void);
void dir_usage_error(void);

int error_code(void);
void error_print(char *program_name);

#endif
