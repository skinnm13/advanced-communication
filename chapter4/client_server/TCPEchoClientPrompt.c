#include <stdio.h>      /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket(), connect(), send(), and recv() */
#include <arpa/inet.h>  /* for sockaddr_in and inet_addr() */
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */

#define RCVBUFSIZE 32   /* Size of receive buffer */

void DieWithError(char *errorMessage);  /* Error handling function */

int main(int argc, char *argv[])
{
  int sock;                        /* Socket descriptor */
  struct sockaddr_in echoServAddr; /* Echo server address */
  unsigned short echoServPort;     /* Echo server port */
  char *servIP;                    /* Server IP address (dotted quad) */
  char* inputStr;                  /* String to send to echo server */
  size_t inputStrBufferLen = 0;    /* Length of input string buffer. */  
  int inputStrLen;                 /* Length of input string. */
  char echoBuffer[RCVBUFSIZE];     /* Buffer for echo string */
  int bytesRcvd, totalBytesRcvd;   /* Bytes read in single recv() 
				      and total bytes read */

  if ((argc < 2) || (argc > 3))    /* Test number of arguments. */
    {
      fprintf(stderr, "Usage: %s <Server IP> [<Echo Port>]\n", argv[0]);
      exit(1);
    }

  servIP = argv[1];                /* First arg: server IP address (dotted quad) */

  if (argc == 3)
    echoServPort = atoi(argv[2]); /* Use given port, if any */
  else
    echoServPort = 7;  /* 7 is the well-known port for the echo service */

  /* Create a reliable, stream socket using TCP. */
  if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    DieWithError("socket() failed");

  /* Construct the server address structure. */
  memset(&echoServAddr, 0, sizeof(echoServAddr));     /* Zero out structure */
  echoServAddr.sin_family      = AF_INET;             /* Internet address family */
  echoServAddr.sin_addr.s_addr = inet_addr(servIP);   /* Server IP address */
  echoServAddr.sin_port        = htons(echoServPort); /* Server port */

  /* Establish the connection to the echo server */
  if (connect(sock, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr)) < 0)
    DieWithError("connect() failed");

  /* Read from the console forever. */
  for(;;) {

    /* Clean up the echo buffer. */
    totalBytesRcvd = 0;
    memset(echoBuffer, 0, sizeof(echoBuffer));

    /* Reset the input string variables for getline.*/
    inputStr = NULL;
    inputStrBufferLen = 0;

    /* Read console input forever and send it to the echo server. */
    printf("Input: ");
    inputStrLen = getline(&inputStr, &inputStrBufferLen, stdin);

    /* If we get an end-of-file, e.g., ctrl-d, exit and close the
       connection. */
    if(inputStrLen == -1) break;
      
    /* Send the string to the server */
    if (send(sock, inputStr, inputStrLen, 0) != inputStrLen)
      DieWithError("send() sent a different number of bytes than expected");

    /* Receive the same string back from the server */
    printf("Received: ");                /* Setup to print the echoed string */
    while (totalBytesRcvd < inputStrLen)
      {
	/* Receive up to the buffer size (minus 1 to leave space for
	   a null terminator) bytes from the sender */
	if ((bytesRcvd = recv(sock, echoBuffer, RCVBUFSIZE - 1, 0)) <= 0)
	  DieWithError("recv() failed or connection closed prematurely");
	totalBytesRcvd += bytesRcvd;   /* Keep tally of total bytes */
	echoBuffer[bytesRcvd] = '\0';  /* Terminate the string! */
	printf("%s", echoBuffer);      /* Print the echo buffer */
      }

    free(inputStr);
    printf("\n");    /* Print a final linefeed */

  }

  /* Free input string buffer. */
  free(inputStr);

  /* Close the client socket. */
  close(sock);

  /* Exit successfully. */
  exit(0);
}



