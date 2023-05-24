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

	if (strcmp(cmd_args[0], "env") == 0)
		  _env();
	if (strcmp(cmd_args[0], "exit") == 0)
		  exit(0);
	
	pid = fork();
	if (pid < 0) 
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	if (pid == 0) 
	{
		char *temp = NULL;
		char path[10];
		
		if (cmd_args[0][0] == '/')
			temp = cmd_args[0];
		else
		{
			strcpy(path, "/bin/");
			strcat(path, cmd_args[0]);
			temp = strdup(path);
		}
		if (execve(temp, cmd_args, environ) == -1) 
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
		if (temp != NULL)
			free(temp);
			
	} else {
		wait(&pid);
	}
	printf("%s", prompt);
}
	

	free(cmd_args);

	free(lineptr);

	return 0;
}

void _env(void)
{
	char **myenv = environ;
	
	{
		printf("%s\n", *myenv);
		myenv++;
	}
}
	
	
