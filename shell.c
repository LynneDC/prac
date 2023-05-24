#include  "main.h"

#define BUFFER_SIZE 1024;

int main(int argc, char *argv[]) {
char *prompt = "lynne$ ";
char *lineptr = NULL;
char *user_input;
size_t n = 0;
char *word;
char *delim = " \n";
int i = 0;
char **cmd_args = malloc((i + 1) * sizeof(char *));

pid_t pid;

(void)argc, (void) argv;

printf("%s", prompt);

while ((getline(&lineptr, &n, stdin)) > 0) 
{
	user_input = strdup(lineptr);
	word = strtok(user_input, delim);
	i = 0;
	while (word != NULL) 
	{
		cmd_args[i++] = word;
		word = strtok(NULL, delim);
	}
	cmd_args[i] = NULL;

	/*if (strcmp(cmd_args[0], "cd") == 0) {
	if (i > 1) {
	if (chdir(cmd_args[1]) != 0) {
	perror("cd failed");
	}
	} else {
	chdir(getenv("HOME"));
	}*/
	
	pid = fork();
	if (pid < 0) 
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	if (pid == 0) 
	{
		if (execvp(cmd_args[0], cmd_args) == -1) 
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	} else {
		wait(NULL);
	}
}

	free(cmd_args);

	free(lineptr);

	return 0;
}
