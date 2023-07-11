#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void close_file(int fd_value);
char *read_file(char *file);
char *create_buffer(char *fb);
int main(int argc, char *argv[]);

#endif
