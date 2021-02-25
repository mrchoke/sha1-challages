# sha1-challenge

ติดตั้ง stackage ก่อนครับ ตามลิ้งนี้ https://docs.haskellstack.org/en/stable/README/

Unix like system

```
curl -sSL https://get.haskellstack.org/ | sh
```

or

```
wget -qO- https://get.haskellstack.org/ | sh
```

จากนั้น cd เข้ามาที่ directory นี้แล้วสั่ง

```
stack build --copy-bins --local-bin-path=$PWD
```

จากนั้น run ด้วย 

```
./sha1-challenge-exe
```
