/*
  Author: Kamthorn Krairaksa
  Github: https://github.com/kamthorn
*/

#include <stdio.h>
#include <openssl/sha.h>
#include <string.h>

#define hhbyte(x) h[x >> 4]
#define lhbyte(x) h[x & 15]
int main()
{
  uint8_t a[42] = "clubhouse";
  uint8_t c[21];
  long int rounds = 5555555555;
  uint8_t h[] = "0123456789abcdef";

  SHA1(a, strlen((char *)a), c);
  a[40] = 0;

  for (long int j = 1; j <= rounds; j++)
  {
    for (uint8_t k = 0; k < 20; k++)
    {
      a[k * 2] = hhbyte(c[k]);
      a[k * 2 + 1] = lhbyte(c[k]);
    }

    SHA1(a, 40, c);
  }

  printf("%s\n", a);
}
