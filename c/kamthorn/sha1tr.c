/*
  Author: Kamthorn Krairaksa
  Github: https://github.com/kamthorn
*/

#include <stdio.h>
#include <openssl/sha.h>
#include <string.h>
#include <stdlib.h>

const unsigned char hex[] = "0123456789abcdef";
#define hi_nibble(x) hex[(x >> 4) & 0x0f]
#define lo_nibble(x) hex[x & 0x0f]

void static inline hexstr( unsigned char* dst, uint8_t* d, int len)
{
  static int i;
  for (i = 0; i < len; i++)
  {
    dst[i * 2] = hi_nibble( d[i] );
    dst[i * 2 + 1] = lo_nibble( d[i] );
  }
  dst[len * 2] = 0;
}

static void shasum( long int n, unsigned char* dst, int len )
{
  static uint8_t temp[21];
  if ( n <= 0 )
    return;
  SHA1( dst, len, temp );
  hexstr( dst, temp, 20 );
  shasum( n - 1, dst, 40 );
}

int main( int argc, char *argv[] )
{
  unsigned char msg[256] = "clubhouse";
  long int rounds = 5555555555;

  if ( argc > 1 ) strcpy( (char *) msg, argv[1] );
  if ( argc > 2 ) rounds = atol( argv[2] );
  
  shasum( rounds, msg, strlen( (char *) msg) );
  printf( "%s\n", msg );
}
