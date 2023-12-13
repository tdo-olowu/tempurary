#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


/* modes */
int interactive_mode(void);
int file_mode(int, char**, char**);


/* important variables */
char *PROMPT = "($) ";
typedef struct node path_list;
struct node {
	char *dir;
	path_list *next;
};


/* input acquisition */
void prompt(char*);
ssize_t readcmd(char**, size_t*, FILE*);

/* process control */
int execute(char*, char**, char**);

/* input parsing */
char **tokenify(char*, char*);
char *pathify(char*, char*);
path_list *path_chain(char *paths);

/* memory management */
void free_table(char**);
void free_list(path_list*);
void cleanup(char*, char**, path_list*);

/* builtins */
/* file and directory navigation */


#endif /* MAIN_H */
