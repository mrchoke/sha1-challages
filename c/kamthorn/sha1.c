/*
  Author: Kamthorn Krairaksa
  Github: https://github.com/kamthorn
*/

#include <stdio.h>
#include <openssl/sha.h>
#include <string.h>
#include <stdlib.h>

const int8_t hex[] = "0123456789abcdef";
#define hi_nibble(x) hex[(x >> 4) & 0x0f]
#define lo_nibble(x) hex[x & 0x0f]

void static inline hexstr( unsigned char* dst, uint8_t* d, int n)
{
  static int i;
  for (i = 0; i < n; i++)
  {
    dst[i * 2] = hi_nibble( d[i] );
    dst[i * 2 + 1] = lo_nibble( d[i] );
  }
  dst[n * 2] = 0;
}

int main( int argc, char *argv[] )
{
  unsigned char msg[256] = "clubhouse";
  uint8_t temp[21];
  long int rounds = 5555555555;

  if ( argc > 1 ) strcpy( (char *) msg, argv[1] );
  if ( argc > 2 ) rounds = atol( argv[2] );

  SHA1( msg, strlen( (char *) msg ), temp );
  hexstr( msg, temp, 20);

  for (long int i = 2; i <= rounds; i++)
  {
    SHA1( msg, 40, temp );
    hexstr( msg, temp, 20);
  }

  printf( "%s\n", msg );
}
