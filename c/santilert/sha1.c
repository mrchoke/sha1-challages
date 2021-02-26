
/*
  Author: Santi Lertpichitkul
*/

#include <openssl/sha.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

static void
to_hex (unsigned char *data, int dlen, unsigned char *hex)
{
   static char hex_char[] = "0123456789abcdef";
   while (dlen-- > 0)
   {
      *hex++ = hex_char[(data[0]>>4)&0x0F];
      *hex++ = hex_char[ data[0]    &0x0F];
      ++data;
   }
}

int
main (int argc, char **argv)
{
   char start[] = "clubhouse";
   unsigned char msg[2*SHA_DIGEST_LENGTH];
   unsigned char hash[SHA_DIGEST_LENGTH];
   int64_t rounds = 5555555555;

   SHA1 ((unsigned char *)start, strlen (start), hash);
   to_hex (hash, SHA_DIGEST_LENGTH, msg);

   while (--rounds > 0)
   {
      SHA1 (msg, 2*SHA_DIGEST_LENGTH, hash);
      to_hex (hash, SHA_DIGEST_LENGTH, msg);
   }

   printf ("[%.*s]\n", 2*SHA_DIGEST_LENGTH, msg);

   return 0;
}
