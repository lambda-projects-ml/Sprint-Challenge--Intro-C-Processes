#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

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

// Concatination function
char *concat(const char *s1, const char *s2)
{
  char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
  // in real code you would check for errors in malloc here
  strcpy(result, s1);
  strcat(result, s2);
  return result;
}
/**
 * Main
 */
int main(int argc, char **argv)
{
  char commandline[MAX_COMMANDLINE_SIZE];
  char *args[MAX_TOKENS];
  int args_count;

  // Print a prompt on screen
  printf("%s", PROMPT);

  // Accepts user input
  fgets(commandline, sizeof(commandline), stdin);

  // Parse command line
  parse_commandline(commandline, args, &args_count);

  // Open directory
  DIR *d;
  struct stat buf;
  struct dirent *dir;

  if (args_count == 0)
  {
    printf("argscount: %d", args_count);
    d = opendir(".");
    while ((dir = readdir(d)) != NULL)
    {
      stat(dir->d_name, &buf);
      printf("%5lld bytes  %s\n", buf.st_size, dir->d_name);
    }
  }

  for (int i = 0; i < args_count; i++)
  {
    d = opendir(args[i]);
    if (d)
    {
      // Repeatly read and print entries
      while ((dir = readdir(d)) != NULL)
      {
        char *path = concat(commandline, dir->d_name);
        stat(path, &buf);
        if (strncmp(dir->d_name, ".", 2) == 0)
        {
          printf("      <DIR>  %s\n", dir->d_name);
        }
        else if (strncmp(dir->d_name, "..", 2) == 0)
        {
          printf("      <DIR>  %s\n", dir->d_name);
        }
        else
        {
          // printf("file size is %lld\n", buf.st_size);
          printf("%5lld bytes  %s\n", buf.st_size, dir->d_name);
        }
      }
      // Close directory
      closedir(d);
    }
  }

  return 0;
}