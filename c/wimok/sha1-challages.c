/*
 * Wimok Nopphiboon
 * Custom SHA1 for message "clubhouse"
 */

#include <stdint.h>
#include <stdio.h>
#include <string.h>

char message[] = "clubhouse\0";
size_t rounds = 5555555555;

void sha1(uint32_t* message, size_t len, int isUint32)
{
	uint32_t block[16] = { 0 };

	uint32_t state[5];
	state[0] = 0x67452301;
	state[1] = 0xEFCDAB89;
	state[2] = 0x98BADCFE;
	state[3] = 0x10325476;
	state[4] = 0xC3D2E1F0;

	// https://www.nayuki.io/page/fast-sha1-hash-implementation-in-x86-assembly
#define ROTL32(x, n)  (((0U + (x)) << (n)) | ((x) >> (32 - (n))))  // Assumes that x is uint32_t and 0 < n < 32

#define LOADSCHEDULE(i)  \
		schedule[i] = block[i];

#define SCHEDULE(i)  \
		temp = schedule[(i - 3) & 0xF] ^ schedule[(i - 8) & 0xF] ^ schedule[(i - 14) & 0xF] ^ schedule[(i - 16) & 0xF];  \
		schedule[i & 0xF] = ROTL32(temp, 1);

#define R0(a, b, c, d, e, i)   LOADSCHEDULE(i)  ROUNDTAIL(a, b, e, ((b & c) | (~b & d))         , i, 0x5A827999)
#define R1(a, b, c, d, e, i)   SCHEDULE(i)      ROUNDTAIL(a, b, e, ((b & c) | (~b & d))         , i, 0x5A827999)
#define R2(a, b, c, d, e, i)   SCHEDULE(i)      ROUNDTAIL(a, b, e, (b ^ c ^ d)                  , i, 0x6ED9EBA1)
#define R3(a, b, c, d, e, i)   SCHEDULE(i)      ROUNDTAIL(a, b, e, ((b & c) ^ (b & d) ^ (c & d)), i, 0x8F1BBCDC)
#define R4(a, b, c, d, e, i)   SCHEDULE(i)      ROUNDTAIL(a, b, e, (b ^ c ^ d)                  , i, 0xCA62C1D6)

#define ROUNDTAIL(a, b, e, f, i, k)  \
		e = 0U + e + ROTL32(a, 5) + f + UINT32_C(k) + schedule[i & 0xF];  \
		b = ROTL32(b, 30);

	const char hex[] = "0123456789abcdef";

	uint32_t a = state[0];
	uint32_t b = state[1];
	uint32_t c = state[2];
	uint32_t d = state[3];
	uint32_t e = state[4];

	uint32_t schedule[16];
	uint32_t temp;

	if (isUint32)
	{
		block[0] |= hex[((message[0] >> 24) >> 4) & 0xf] << 24;
		block[0] |= hex[(message[0] >> 24) & 0xf] << 16;
		block[0] |= hex[((message[0] >> 16) >> 4) & 0xf] << 8;
		block[0] |= hex[((message[0] >> 16) & 0xf)];
		R0(a, b, c, d, e, 0);
		block[1] |= hex[((message[0] >> 8) >> 4) & 0xf] << 24;
		block[1] |= hex[(message[0] >> 8) & 0xf] << 16;
		block[1] |= hex[(message[0] >> 4) & 0xf] << 8;
		block[1] |= hex[message[0] & 0xf];
		R0(e, a, b, c, d, 1);

		block[2] |= hex[((message[1] >> 24) >> 4) & 0xf] << 24;
		block[2] |= hex[(message[1] >> 24) & 0xf] << 16;
		block[2] |= hex[((message[1] >> 16) >> 4) & 0xf] << 8;
		block[2] |= hex[((message[1] >> 16) & 0xf)];
		R0(d, e, a, b, c, 2);
		block[3] |= hex[((message[1] >> 8) >> 4) & 0xf] << 24;
		block[3] |= hex[(message[1] >> 8) & 0xf] << 16;
		block[3] |= hex[(message[1] >> 4) & 0xf] << 8;
		block[3] |= hex[message[1] & 0xf];
		R0(c, d, e, a, b, 3);

		block[4] |= hex[((message[2] >> 24) >> 4) & 0xf] << 24;
		block[4] |= hex[(message[2] >> 24) & 0xf] << 16;
		block[4] |= hex[((message[2] >> 16) >> 4) & 0xf] << 8;
		block[4] |= hex[((message[2] >> 16) & 0xf)];
		R0(b, c, d, e, a, 4);
		block[5] |= hex[((message[2] >> 8) >> 4) & 0xf] << 24;
		block[5] |= hex[(message[2] >> 8) & 0xf] << 16;
		block[5] |= hex[(message[2] >> 4) & 0xf] << 8;
		block[5] |= hex[message[2] & 0xf];
		R0(a, b, c, d, e, 5);

		block[6] |= hex[((message[3] >> 24) >> 4) & 0xf] << 24;
		block[6] |= hex[(message[3] >> 24) & 0xf] << 16;
		block[6] |= hex[((message[3] >> 16) >> 4) & 0xf] << 8;
		block[6] |= hex[((message[3] >> 16) & 0xf)];
		R0(e, a, b, c, d, 6);
		block[7] |= hex[((message[3] >> 8) >> 4) & 0xf] << 24;
		block[7] |= hex[(message[3] >> 8) & 0xf] << 16;
		block[7] |= hex[(message[3] >> 4) & 0xf] << 8;
		block[7] |= hex[message[3] & 0xf];
		R0(d, e, a, b, c, 7);

		block[8] |= hex[((message[4] >> 24) >> 4) & 0xf] << 24;
		block[8] |= hex[(message[4] >> 24) & 0xf] << 16;
		block[8] |= hex[((message[4] >> 16) >> 4) & 0xf] << 8;
		block[8] |= hex[(message[4] >> 16) & 0xf];
		R0(c, d, e, a, b, 8);
		block[9] |= hex[((message[4] >> 8) >> 4) & 0xf] << 24;
		block[9] |= hex[(message[4] >> 8) & 0xf] << 16;
		block[9] |= hex[(message[4] >> 4) & 0xf] << 8;
		block[9] |= hex[message[4] & 0xf];
		R0(b, c, d, e, a, 9);

		block[10] |= 0x80 << 24;
		block[15] = (len & 0x1F) << 3;
		len >>= 5;
		block[15] |= (len & 0xFF) << 8;
	}
	else
	{
		memcpy(block, &message[0], len + 4);
		block[len / 4] |= 0x80 << (24 - (len % 4 * 8));
		block[15] = (len & 0x1F) << 3;
		len >>= 5;
		block[15] |= (len & 0xFF) << 8;
		R0(a, b, c, d, e, 0);
		R0(e, a, b, c, d, 1);
		R0(d, e, a, b, c, 2);
		R0(c, d, e, a, b, 3);
		R0(b, c, d, e, a, 4);
		R0(a, b, c, d, e, 5);
		R0(e, a, b, c, d, 6);
		R0(d, e, a, b, c, 7);
		R0(c, d, e, a, b, 8);
		R0(b, c, d, e, a, 9);
	}

	R0(a, b, c, d, e, 10);
	R0(e, a, b, c, d, 11);
	R0(d, e, a, b, c, 12);
	R0(c, d, e, a, b, 13);
	R0(b, c, d, e, a, 14);
	R0(a, b, c, d, e, 15);

	R1(e, a, b, c, d, 16); R1(d, e, a, b, c, 17); R1(c, d, e, a, b, 18); R1(b, c, d, e, a, 19);
	R2(a, b, c, d, e, 20); R2(e, a, b, c, d, 21); R2(d, e, a, b, c, 22); R2(c, d, e, a, b, 23);
	R2(b, c, d, e, a, 24); R2(a, b, c, d, e, 25); R2(e, a, b, c, d, 26); R2(d, e, a, b, c, 27);
	R2(c, d, e, a, b, 28); R2(b, c, d, e, a, 29); R2(a, b, c, d, e, 30); R2(e, a, b, c, d, 31);
	R2(d, e, a, b, c, 32); R2(c, d, e, a, b, 33); R2(b, c, d, e, a, 34); R2(a, b, c, d, e, 35);
	R2(e, a, b, c, d, 36); R2(d, e, a, b, c, 37); R2(c, d, e, a, b, 38); R2(b, c, d, e, a, 39);
	R3(a, b, c, d, e, 40); R3(e, a, b, c, d, 41); R3(d, e, a, b, c, 42); R3(c, d, e, a, b, 43);
	R3(b, c, d, e, a, 44); R3(a, b, c, d, e, 45); R3(e, a, b, c, d, 46); R3(d, e, a, b, c, 47);
	R3(c, d, e, a, b, 48); R3(b, c, d, e, a, 49); R3(a, b, c, d, e, 50); R3(e, a, b, c, d, 51);
	R3(d, e, a, b, c, 52); R3(c, d, e, a, b, 53); R3(b, c, d, e, a, 54); R3(a, b, c, d, e, 55);
	R3(e, a, b, c, d, 56); R3(d, e, a, b, c, 57); R3(c, d, e, a, b, 58); R3(b, c, d, e, a, 59);
	R4(a, b, c, d, e, 60); R4(e, a, b, c, d, 61); R4(d, e, a, b, c, 62); R4(c, d, e, a, b, 63);
	R4(b, c, d, e, a, 64); R4(a, b, c, d, e, 65); R4(e, a, b, c, d, 66); R4(d, e, a, b, c, 67);
	R4(c, d, e, a, b, 68); R4(b, c, d, e, a, 69); R4(a, b, c, d, e, 70); R4(e, a, b, c, d, 71);
	R4(d, e, a, b, c, 72); R4(c, d, e, a, b, 73); R4(b, c, d, e, a, 74); R4(a, b, c, d, e, 75);
	R4(e, a, b, c, d, 76); R4(d, e, a, b, c, 77); R4(c, d, e, a, b, 78); R4(b, c, d, e, a, 79);

	state[0] += a;
	state[1] += b;
	state[2] += c;
	state[3] += d;
	state[4] += e;

	memcpy(message, &state[0], 20);
}

int main(void)
{
	size_t len = strlen(message);

	uint32_t msg_in[16] = { 0 };
	int i = 0;
	for (size_t j = 0; j < len; j += 4)
	{
		msg_in[i] = message[i * 4 + 0] << 24  \
			| message[i * 4 + 1] << 16  \
			| message[i * 4 + 2] << 8  \
			| message[i * 4 + 3] << 0;
		i++;
	}

	sha1(msg_in, len, 0);

	for (size_t i = 1; i < rounds; i++)
		sha1(msg_in, 40, 1);

	printf("%08x%08x%08x%08x%08x\n", msg_in[0], msg_in[1], msg_in[2], msg_in[3], msg_in[4]);

	return 0;
}