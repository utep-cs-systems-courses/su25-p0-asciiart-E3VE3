#include <stdio.h>
#include "draw.h" // project-related declarations

int main() 
{
  puts("Welcome!");

  while (1) { // Infinite while loop

    fputs("Select which shape you want to print (Triangle = t, Square = s, Arrow = a, myName = c) or 'q' to quit\n> ", stdout);
    fflush(stdout);		/* stdout only flushes automatically on \n */
    int c;
    while ((c = getchar()) == '\n'); /* ignore newlines */
    if (c == EOF)		     /* terminate on end-of-file */
      goto done;

    // Given the user answer, select which method to call
    switch (c) {
    case 't':
      puts("You selected triangle:");
      print_triangle(5, 7);
      break;
    case 's':
      puts("You selected square:");
      print_square(5, 5);
      break;
      
    case'a':
      puts("You selected arrow:");
      print_arrow(5, 7);
      break;
      
    case 'c':{
      const char *word = "Ever";
      for (int i = 0; word[i] != '\0'; i++)
	print_char_5x7(word[i]);
      break;}
      
    case 'q':
      puts("Bye!");
      goto done; 		/* terminate */
    case '\n':
      break;
    default:
      printf("Unrecognized option '%c', please try again!\n", c);
    }
  }

 done: // To exit from program
  return 0;
}
