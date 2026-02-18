
#include <stdio.h> 
#include <stdint.h> 

int main(void)
{ 
  uint32_t a = 0x01020304; /* 16909060 (decimal) */
  char* c = (char*) &a;
  char d[] = { 1, 2, 3, 4 }; 

  printf("Integer: %x %x %x %x\n", c[0], c[1], c[2], c[3]); 
  printf("String:  %x %x %x %x\n", d[0], d[1], d[2], d[3]);

  if(c[0] == d[0]) {
    printf("Big Endian\n");
  }
  else {
    printf("Little Endian\n");
  }

  return 0;
}



