
/* This file gives a simple example of C code padding and
alignment. First, structs are defined that each contain a single basic
int type. Then a struct is defined that contains all three types. The
size and starting address of each is output. 
*/

#include <stdio.h>

int main()
{

  /* Create a struct type containing a short int member (2 bytes). */
  struct short_int_data
  {
    short int si;
  };

  /* Create a struct type containing an int member (4 bytes). */
  struct int_data
  {
    int i;
  };

  /* Create a struct type containing a long int member (8 bytes). */
  struct long_int_data
  {
    long int li;
  };

  /* Create a struct type with all of the above member types. */
  struct three_int_data 
  {
    char c;
    short int si;
    // long int li;
    int i;
  } three_int_data_instance;

  printf("size of struct containing one short int member = %ld bytes \n", 
	 sizeof(struct short_int_data));

  printf("size of struct containing one int member = %ld bytes \n",
	 sizeof(struct int_data));

  printf("size of struct containing one long int member = %ld bytes \n",
	 sizeof(struct long_int_data));

  printf("\n");

  printf("size of struct containing short int, int, and long int members = %ld\n",
	 sizeof(struct three_int_data));

  printf("\n");

  printf("%p\n", &three_int_data_instance.c);
  printf("%p\n", &three_int_data_instance.si);
  printf("%p\n", &three_int_data_instance.i);

}


