
#include <stdio.h> 
#include <stdint.h> 


// long int convert2dec(uint8_t b1, uint8_t b2, uint8_t b3, uint8_t b4, char endian) {
//   long int converted = 0;

//   if(endian == 'b') {
//     converted += b1*256*256*256 + b2*256*256 + b3*256 + b4;
//   }
//   else if(endian == 'l') {
//     converted += b4*256*256*256 + b3*256*256 + b2*256 + b1;
//   }
//   return converted;
// }

long int from_bytes(uint32_t bytes, char endian) {
  long int converted = 0;
  uint8_t b1 = (bytes >> 24) & 0xFF;  // 0x01
  uint8_t b2 = (bytes >> 16) & 0xFF;  // 0x02
  uint8_t b3 = (bytes >> 8)  & 0xFF;  // 0x03
  uint8_t b4 = bytes & 0xFF;          // 0x04

  if(endian == 'b') {
    converted += b1*256*256*256 + b2*256*256 + b3*256 + b4;
  }
  else if(endian == 'l') {
    converted += b4*256*256*256 + b3*256*256 + b2*256 + b1;
  }
  return converted;
}

uint32_t to_int(long int num, char endian){
  uint32_t bytes = 0;
  uint8_t b1 = (num >> 24) & 0xFF;
  uint8_t b2 = (num >> 16) & 0xFF;
  uint8_t b3 = (num >> 8)  & 0xFF;
  uint8_t b4 = num & 0xFF;
  if(endian == 'b') {
    bytes = (b1 << 24) + (b2 << 16) + (b3 << 8) + b4;
  }
  else if(endian == 'l') {
    bytes = (b4 << 24) + (b3 << 16) + (b2 << 8) + b1;
  }
  return bytes;
}

int main(void)
{ 
  uint32_t a = 0x01020304; /* 16909060 (decimal) */
  char* c = (char*) &a;
  char d[] = { 1, 2, 3, 4 }; 

  printf("Integer: %x %x %x %x\n", c[0], c[1], c[2], c[3]); 
  printf("String:  %x %x %x %x\n", d[0], d[1], d[2], d[3]);
  char endian, endian2;
  scanf("%c\r\n", &endian);
  long int converted = from_bytes(a, endian);
  printf("Converted: %ld\n", converted);
  scanf("%c\r\n", &endian2);
  uint32_t bytes = to_int(converted, endian2);
  printf("Bytes: %x\n", bytes);

  return 0;
}



