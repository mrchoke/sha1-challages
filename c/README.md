## MacOS with openssl (homebrew)

```
gcc sha1.c -o sha1 -O3 -lcrypto -flto -I/opt/homebrew/Cellar/openssl@1.1/1.1.1j/include -L/opt/homebrew/Cellar/openssl@1.1/1.1.1j/lib
```

_**Check your openssl version._

## Linux

```
gcc sha1.c -o sha1 -O3 -lcrypto -flto -march=native  
```

_**Install openssl devel package before._
