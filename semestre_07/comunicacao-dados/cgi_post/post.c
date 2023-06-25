#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXQELEMENTS 16

struct {
  char name[128];
  char val[128];
} elements[MAXQELEMENTS];

void splitword(char *out, char *in, char stop) {
  int i;
  int j;

  while(*in == ' ') {
    in++;
  }

  for(i = 0; in[i] && (in[i] != stop); i++) {
    out[i] = in[i];
  }
  out[i] = '\0';
  if(in[i])
    {
    ++i;
    }
  while(in[i] == ' ')
    {
    i++;
    }
  for(j = 0; in[j]; )
    {
    in[j++] = in[i++];
    }
}

char x2c(char *x) {
  register char c;

  c = (x[0] >= 'A' ? ((x[0] & 0xdf) - 'A') + 10 : (x[0] - '0'));
  c *= 16;
  c += (x[1] >= 'A' ? ((x[1] & 0xdf) - 'A') + 10 : (x[1] - '0'));

  return(c);
}

void unescape_url(char *url) {
  register int i, j;

  for(i = 0, j = 0; url[j]; ++i, ++j)
    {
    if(url[i] = url[j] == '%')
      {
      url[i] = x2c(&url[j + 1]);
      j += 2;
      }
    else if(url[i] == '+')
	   {
	   url[i] = ' ';
	   }
    }
  url[i] = '\0';
  }

int main() {
  char *ct;
  char *cl;
  int icl;
  char *qs;
  int rc;
  int i;

  printf("Content-type: text/html\n\n");
 
  ct = getenv("CONTENT_TYPE");
  cl = getenv("CONTENT_LENGTH");
  if(cl == NULL)
    {
    printf("content-length is undefined\n");
    exit(1);
    }
  icl = atoi(cl);
  printf("CONTENT-TYPE: %s<br>\n", ct);
  printf("CONTENT-LENGTH: %d<br>\n", icl);

  if(strcmp(ct, "application/x-www-form-urlencoded"))
    {
    printf("I don't undestand the content-type: \n");
    exit(1);
    }
  else if(icl == 0)
         {
	 printf("content-length is zero\n");
	 exit(1);
	 }

  if((qs = malloc(icl + 1)) == NULL)
    {
    printf("cannot allocate memory, contact the webmaster\n");
    exit(1);
    }
  if((rc = fread(qs, icl, 1, stdin)) != 1)
    {
    printf("cannot read the input stream (%d)! Contact the webmaster\n", rc);
    exit(1);
    }
  qs[icl] = '\0';

  printf("QUERY_STRING = %s\n", qs);

  return(0);
  }
