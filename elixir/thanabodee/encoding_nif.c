#include <assert.h>
#include <erl_nif.h>
#include <stdio.h>

static char hextable[] = "0123456789abcdef";

static ERL_NIF_TERM hex_nif(ErlNifEnv *env, int argc,
                            const ERL_NIF_TERM argv[]) {
  int i, j;
  size_t hexlen;
  ErlNifBinary src, dst;

  assert(argc == 1);
  assert(enif_is_binary(env, argv[0]));
  assert(enif_inspect_binary(env, argv[0], &src));

  hexlen = src.size * 2;
  assert(enif_alloc_binary(hexlen, &dst));
  for (i = 0, j = 0; i < src.size; i++) {
    dst.data[j] = hextable[src.data[i] >> 4];
    dst.data[j + 1] = hextable[src.data[i] & 0x0f];
    j += 2;
  }
  return enif_make_binary(env, &dst);
}

static ErlNifFunc nif_funcs[] = {
    {"hex", 1, hex_nif},
};

ERL_NIF_INIT(Elixir.SHA1.Encoding, nif_funcs, NULL, NULL, NULL, NULL);
