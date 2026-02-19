
#include <stdio.h>      /* for printf() and fprintf() */
#include <sys/socket.h> /* for recv() and send() */
#include <unistd.h>     /* for close() */
#include <arpa/inet.h>

#define RCVBUFSIZE 1024  /* Size of receive buffer */

void ReadIntFromClient(int clntSocket)
{

  // Read three integers of different sizes, from the client.

  short int si;
  int i;
  long int li;

  /*****************************************/

  recv(clntSocket, &si, sizeof(si), 0);
  recv(clntSocket, &i,  sizeof(i),  0);
  recv(clntSocket, &li, sizeof(li), 0);

  // Output received integers directly.
  printf("Short int: %hd\n", si);
  printf("int: %d\n", i);
  printf("Long int: %li\n", li);

  /*****************************************/
  
  close(clntSocket);    /* Close client socket */
}

