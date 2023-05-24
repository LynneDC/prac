#ifndef MAIN_H
#define MAIN_H

/*macros*/
#define BUF_SIZE 1024
#define FLUSH_BUF -1

/*header files*/
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <wait.h>
#include <stdlib.h>
#include <errno.h>

/*function prototypes*/
extern char **environ;
char *env(void);
int shellexit(char **cmd, char *lineeptr);
void free_all(char **cmd, char *lineptr, char **environ);

/*io_utils*/
int _putchar(char c);
int _puts(char *str);
int _count_char(char *str);
int _atoi(char *s);

/*str_utils*/
size_t _strlen(const char *str);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *str);
char *_strcpy(char *dest, const char *src);
int _strcmp(const char *str1, const char *str2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strncpy(char *dest, char *src, int n);
/*build ins*/
char *path_find(char **cmd);
#endif
