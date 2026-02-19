
#include <stdio.h> 
#include <stdint.h> 


long int convert2dec(uint8_t b1, uint8_t b2, uint8_t b3, uint8_t b4, char endian) {
  long int converted = 0;

  if(endian == 'b') {
    converted += b1*256*256*256 + b2*256*256 + b3*256 + b4;
  }
  else if(endian == 'l') {
    converted += b4*256*256*256 + b3*256*256 + b2*256 + b1;
  }
  return converted;
}


int main(void)
{ 
  uint32_t a = 0x01020304; /* 16909060 (decimal) */
  char* c = (char*) &a;
  char d[] = { 1, 2, 3, 4 }; 

  printf("Integer: %x %x %x %x\n", c[0], c[1], c[2], c[3]); 
  printf("String:  %x %x %x %x\n", d[0], d[1], d[2], d[3]);
  char endian;
  uint8_t b1 = (a >> 24) & 0xFF;  // 0x01
  uint8_t b2 = (a >> 16) & 0xFF;  // 0x02
  uint8_t b3 = (a >> 8)  & 0xFF;  // 0x03
  uint8_t b4 = a & 0xFF;          // 0x04
  scanf("%c", &endian);
  long int converted = convert2dec(b1, b2, b3, b4, endian);
  printf("Converted: %ld\n", converted);

  return 0;
}



