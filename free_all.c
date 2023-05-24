#include "main.h"
/**
 *free_all - frees allocated memory.
 * @cmd: pointer to array of commands
 * @lineptr: pointer to input
 * @environ: pointer to enviroment variables
 */
void free_all(char **cmd, char *lineptr, char **environ)
{
size_t i = 0;
/*check if command is there*/
if (cmd)
{

/*check if the value of i is not NULL*/
while (cmd[i])
{
/*free all elements until NULL */
free(cmd[i]);
i++;
}
/*free thevariable cmd*/
free(cmd);
}
/*check if lineptr is not NULL and free */
if (lineptr)
free(lineptr);

/*check if environ is not NULL*/
if (environ)
{
i = 0;
/*check if the elememnt of environ is not NULL and free */
while (environ[i])
{
free(environ[i]);
i++;
}
/*free environ variable */
free(environ);
}
}
