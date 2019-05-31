#include <stdio.h>
#include <dirent.h>

#define MAX_COMMANDLINE_SIZE 2048
#define MAX_TOKENS 100
#define PROMPT "shell$ "

// Parse Command Line Function
char **parse_commandline(char *commandline, char **args, int *args_count)
{
  char *token;

  *args_count = 0;
  token = strtok(commandline, " \t\n\r");

  while (token != NULL)
  {
    args[*args_count] = token;
    (*args_count)++;
    token = strtok(NULL, "/");
  }

  args[*args_count] = NULL;
  return args;
}
/**
 * Main
 */
int main(int argc, char **argv)
{
  char commandline[MAX_COMMANDLINE_SIZE];
  char *args[MAX_TOKENS];
  int args_count;
  printf("%s", PROMPT);
  fgets(commandline, sizeof(commandline), stdin);
  // Parse command line
  parse_commandline(commandline, args, &args_count);
  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}