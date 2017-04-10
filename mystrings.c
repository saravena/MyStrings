
/*************************************************************
* Project:   What's the Password?: mystrings.c               *
* Name:      Sabrina Aravena                                 *
* Due :      October 23, 2016                                *
**************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  /* Variables */
  int x;          /* used to assign chracters */
  int count = 0;  /* used to keep track of characters in word */
  int flag = 0;   /* T or F marker */

	/* checks for an approriate amount of parameters */
	if (argc == 2) {
		/* Open file */
		FILE *inputFile = fopen(argv[1], "r");
		/* Checks for files existence and ends program if input is invalid */
		if (inputFile == NULL) {
				printf("File Invalid: Please try running the program again.\n");
        return 0;
		}

    /* Continue if successful */
		/* size of string is at least 4 */
		char *str = (char *)malloc(4 * sizeof(char));
    /* get first character in file */
		x = fgetc(inputFile);

    /* loop until the end of file */
		while (x != EOF) {
      /* checks if character is within valid range */
			if (x > 31 && x < 127) {
				flag = 1; /* true */
        /* executes depending on length of string */
				if (count < 4) {
					str[count] = x; /* add char to word */
				} else if (count == strlen(str)) { /* print string on seperate line if length matches tracker */
					printf("\n%s", str);
					printf("%c", x);
				} else if (count > 4) {
					printf("%c", x);
				}
        /* increment count */
				count++;
			} else {
        /* flag back to false if true and reinitialize count */
				if (flag) {
					flag = 0;
					count = 0;
				}
			}
			x = fgetc(inputFile);
		} /* end while */
    /* close the file */
		fclose(inputFile);
	} else {
    /* executes when an invalid amount of arguments are input */
    printf("Invalid amount of arguments.\n");
  }
  printf("\n\n\n");
	return 0;
} /* end main */
