#ifndef FSLABEL_ERROR_H
#define FSLABEL_ERROR_H

void allocation_error(void);
void no_home_directory_error(void);
void usage_error(void);

int error_code(void);
void error_print(char *program_name);

#endif
