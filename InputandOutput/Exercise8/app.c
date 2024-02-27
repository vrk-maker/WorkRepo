#include <stdio.h>
#include <stdarg.h>

void minscanf(char *fmt, ...);

int main()
{
  int i;
  printf("enter integer number=");
  minscanf("%d", &i); 
  printf("number= %d\n", i);
  printf("\n");
  
  float f;
  printf("enter float number=");
  minscanf("%f", &f); 
  printf("number= %f\n", f);
  printf("\n");
  
  char str[10];
  printf("enter string number=");
  minscanf("%s", &str); 
  printf("string= %s\n", str);

  return 0;
}

/**
 * @brief version of scanf analogous to minprintf
 * @param[in] fmt A format string.
 * @param[in] ... Variable number of arguments to store the input values.
 */
void minscanf(char *fmt, ...)
{
  va_list ap; /* points to each unnamed arg in turn */
  char *p;
  int *ival;
  float *fval;
  char *sval;

  va_start(ap, fmt); /* make ap point to 1st unnamed arg */

  for (p = fmt; *p; p++) {

    /* skip chars that aren't format conversions */
    if (*p != '%')
      continue;

    /* prev char was %, look for format conversion */
    switch(*++p) {
    case 'd':
      ival = va_arg(ap, int *); /* get integer pointer from args */
      scanf("%d", ival); /* read integer into int pointer */
      break;
      
    case 'f':
      fval=va_arg(ap,float *);
      scanf("%f",fval);
      break;
      
    case 's':
      sval=va_arg(ap,char *);
      scanf("%s",sval);
      break;
      
    default:
      break;
    }
  }
}


