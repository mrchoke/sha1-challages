import hashlib

if __name__ == "__main__":
  msg = b"clubhouse"
  for _ in range(5_555_555_555):
    msg = bytes(hashlib.sha1(msg).hexdigest(), 'utf-8')
  print(msg)