# sha1-challages
## โจทย์คือ

```
เริ่มต้นด้วยคำว่า "clubhouse"

นำไป sha1 ครั้งแรกจะได้ "1313994e55ed4bbe79d2b04e4529ee2f4ac288f5"

นำคำตอบไป sha1 ครั้งที่ 2 จะได้ "b42f871cff37138a6b8f53cf55a585d7d1445dfb"

นำคำตอบไป sha1 ครั้งที่ 3 จะได้ "5c7c81615ad8050363c911c7b5e5ed8661be80d6"

ทำไปเรื่อยๆ จนถึงครั้งที่ 5,555,555,555 จะได้ aes-256-cbc decryption password 

สำหรับ challenge นี้ครับ (ลงท้ายด้วย "229a")
```

ที่มาคือ: https://www.facebook.com/dtinth/posts/10216319183326393

ขอบคุณ @dtinth https://www.facebook.com/dtinth/

# ผล

## C Language
---
### Kamthorn

|OS     |Distro         |Version    |CPU    |Arch   |Gen        |Clock (GHz) |Time (min)    |Remark         |
|:-----:|:-------------:|:---------:|:-----:|:-----:|:---------:|:----------:|:------------:|:-------------:|
|macOS  |Big Sur        |11.2.1     |Intel  |x86    |i5-10      |2.0         |6:20          |MBP2020        |
|macOS  |Big Sur        |11.2.1     |M1     |arm64  |           |3.2         |5:06          |Mac mini 2020  |
|Linux  |Ubuntu 20.04.2 |5.8.0      |Intel  |amd64  |i9-9900K   |3.6         |8:22          |               |

---

## Golang
---
### Oat Saysai

|OS     |Distro         |Version    |CPU    |Arch   |Gen        |Clock (GHz) |Time (min)    |Remark         |
|:-----:|:-------------:|:---------:|:-----:|:-----:|:---------:|:----------:|:------------:|:-------------:|
|macOS  |Big Sur        |11.2.1     |Intel  |x86    |i5-10      |2.0         |15:03         |MBP2020        |
|macOS  |Big Sur        |11.2.1     |M1     |arm64  |           |3.2         |6:46          |Mac mini 2020  |
|Linux  |Ubuntu 20.04.2 |5.8.0      |Intel  |amd64  |i9-9900K   |3.6         |12:49         |               |

_** Go 1.16_

---
## Contribution

ขอเชิญเพื่อนๆ ส่ง Code และ ผลการทดสอบ โดยการ PR เข้ามาได้เลยครับ