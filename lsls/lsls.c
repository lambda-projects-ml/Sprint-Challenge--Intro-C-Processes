#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
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

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}