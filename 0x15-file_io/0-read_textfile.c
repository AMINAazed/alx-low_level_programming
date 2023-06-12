#include "main.h"
#include <stdlib.h>
ssize_t read_textfile(const char *filename, size_t letters)
{
FILE *fp;
char buf[letters + 1];
ssize_t nread;
if (filename == NULL)
return 0;
fp = fopen(filename, "r");
if (fp == NULL)
return 0;
nread = fread(buf, sizeof(char), letters, fp);
if (nread < 0)
return 0;
buf[nread] = '\0';
fwrite(buf, sizeof(char), nread, stdout);
fclose(fp);
return nread;
}
