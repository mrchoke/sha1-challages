# sha1-challenge

## โจทย์คือ

```
เริ่มต้นด้วยคำว่า "clubhouse"

นำไป sha1 ครั้งแรกจะได้ "1313994e55ed4bbe79d2b04e4529ee2f4ac288f5"

นำคำตอบไป sha1 ครั้งที่ 2 จะได้ "b42f871cff37138a6b8f53cf55a585d7d1445dfb"

นำคำตอบไป sha1 ครั้งที่ 3 จะได้ "5c7c81615ad8050363c911c7b5e5ed8661be80d6"

ทำไปเรื่อยๆ จนถึงครั้งที่ 5,555,555,555 จะได้ sha1 ลงท้ายด้วย "229a"
```

ที่มาคือ: https://www.facebook.com/dtinth/posts/10216319183326393

ขอบคุณ @dtinth https://www.facebook.com/dtinth/

## อธิบาย

การทดสอบนี้ไม่ได้บ่งบอกว่าเครื่องทดสอบรุ่นไหนดีกว่ากัน เพราะสภาพแวดล้อมการทดสอบนี้เป็นเพียงการใช้งานแบบเดียวซึ่งถือว่าน้อยมาก ๆ เมื่อเทียบกับรูปแบบการใช้งานในชีวิตจริง ดังนั้นผลการทดสอบไม่สามารถอ้างอิงถึงประสิทธิภาพโดยรวมของเครื่องต่างที่ใช้ทดสอบได้ การทำงานของโปรแกรมนี้คือ การเข้ารหัสแบบ sha1 แบบวนลูปโดยใช้ผลลัพธ์ของรอบก่อนหน้ามาใช้ต่อไปเรื่อยๆ ดังนั้นการทำงานจะเป็นเพียงหนึ่งเทรดเท่านั้น 

# ผลการทดสอบ

## C Language
---
### Kamthorn Krairaksa

|OS     |Distro         |Version    |CPU    |Arch   |Gen        |Clock (GHz) |Time (min)    |Remark         |
|:-----:|:-------------:|:---------:|:-----:|:-----:|:---------:|:----------:|:------------:|:-------------:|
|macOS  |Big Sur        |11.2.1     |Intel  |x86    |i5-10      |2.0         |6:20          |MBP2020        |
|macOS  |Big Sur        |11.2.1     |M1     |arm64  |           |3.2         |5:06          |Mac mini 2020  |
|Linux  |Ubuntu 20.04.2 |5.8.0      |Intel  |amd64  |i9-9900K   |3.6         |8:22          |               |
|Windows|Windows10      |10         |Intel  |amd64  |i9-9900K   |3.6         |11:30         |cygwin         |

### Santilert

|OS     |Distro         |Version    |CPU    |Arch   |Gen        |Clock (GHz) |Time (min)    |Remark         |
|:-----:|:-------------:|:---------:|:-----:|:-----:|:---------:|:----------:|:------------:|:-------------:|
|macOS  |Big Sur        |11.2.2     |Intel  |x86    |i5-10      |2.0         |6:29          |MBP2020        |
|macOS  |Big Sur        |11.3.0b    |M1     |arm64  |           |3.2         |5:11          |Mac mini 2020  |
|Linux  |Ubuntu 20.04.2 |5.8.0      |Intel  |amd64  |i9-9900K   |3.6         |9:06          |               |
|Windows|Windows10      |10         |Intel  |amd64  |i9-9900K   |3.6         |12:11         |cygwin         |
---

## Golang
---
### Oat Saysai

|OS     |Distro         |Version    |CPU    |Arch   |Gen        |Clock (GHz) |Time (min)    |Remark         |
|:-----:|:-------------:|:---------:|:-----:|:-----:|:---------:|:----------:|:------------:|:-------------:|
|macOS  |Big Sur        |11.2.1     |Intel  |x86    |i5-10      |2.0         |15:03         |MBP2020        |
|macOS  |Big Sur        |11.2.1     |M1     |arm64  |           |3.2         |6:46          |Mac mini 2020  |
|Linux  |Ubuntu 20.04.2 |5.8.0      |Intel  |amd64  |i9-9900K   |3.6         |12:49         |               |
|Windows|Windows10      |10         |Intel  |amd64  |i9-9900K   |3.6         |14:03         |               |

_** Go 1.16_

---
## Rust
---
### Vee Satayamas

|OS     |Distro         |Version    |CPU    |Arch   |Gen        |Clock (GHz) |Time (min)    |Remark         |
|:-----:|:-------------:|:---------:|:-----:|:-----:|:---------:|:----------:|:------------:|:-------------:|
|macOS  |Big Sur        |11.2.1     |Intel  |x86    |i5-10      |2.0         |10:11         |MBP2020        |
|macOS  |Big Sur        |11.2.1     |M1     |arm64  |           |3.2         |11:28         |Mac mini 2020  |
|Linux  |Ubuntu 20.04.2 |5.8.0      |Intel  |amd64  |i9-9900K   |3.6         |15:18         |               |

_** rustc 1.49.0_

---

## PHP
---
### Kamthorn Krairaksa

|OS     |Distro         |Version    |CPU    |Arch   |Gen        |Clock (GHz) |Time (min)    |Remark         |
|:-----:|:-------------:|:---------:|:-----:|:-----:|:---------:|:----------:|:------------:|:-------------:|
|macOS  |Big Sur        |11.2.1     |Intel  |x86    |i5-10      |2.0         |18:00         |MBP2020        |
|macOS  |Big Sur        |11.2.1     |M1     |arm64  |           |3.2         |15:40         |Mac mini 2020  |
|Linux  |Ubuntu 20.04.2 |5.8.0      |Intel  |amd64  |i9-9900K   |3.6         |13:57         |               |

_** php 8_

---

## Java
---
### Tantai Thanakanok

|OS     |Distro         |Version    |CPU    |Arch   |Gen        |Clock (GHz) |Time (min)    |Remark         |
|:-----:|:-------------:|:---------:|:-----:|:-----:|:---------:|:----------:|:------------:|:-------------:|
|macOS  |Big Sur        |11.2.2     |Intel  |x86    |i5-10      |2.0         |19:07         |MBP2020        |
|macOS  |Big Sur        |11.3.0b    |M1     |arm64  |           |3.2         |30:09         |Mac mini 2020  |
|Linux  |Ubuntu 20.04.2 |5.8.0      |Intel  |amd64  |i9-9900K   |3.6         |29:10         |               |
|Windows|Windows10      |10         |Intel  |amd64  |i7-7700HQ  |2.8         |48:02         |               |

_** Maven 3.6.3,3.8.0(win10)_

---

## Haskell
---
### Weerasak Chongnguluam

|OS     |Distro         |Version    |CPU    |Arch   |Gen        |Clock (GHz) |Time (min)    |Remark                    |
|:-----:|:-------------:|:---------:|:-----:|:-----:|:---------:|:----------:|:------------:|:------------------------:|
|macOS  |Big Sur        |11.2.1     |Intel  |x86    |i5-10      |2.0         |30:10         |MBP2020                   |
|macOS  |Big Sur        |11.2.1     |M1     |arm64  |           |3.2         |31:59*        |Mac mini 2020  x86_64 mode|
|Linux  |Ubuntu 20.04.2 |5.8.0      |Intel  |amd64  |i9-9900K   |3.6         |32:09         |                          |

_** stack 2.5.1.1 x86_64_

stack บน M1 ยังไม่มี Native การทดสอบครั้งนี้ใช้ brew install แบบ x86_64 

---

## Clojure
---
### Phondanai Khanti

|OS     |Distro         |Version    |CPU    |Arch   |Gen        |Clock (GHz) |Time (min)    |Remark                    |
|:-----:|:-------------:|:---------:|:-----:|:-----:|:---------:|:----------:|:------------:|:------------------------:|
|macOS  |Big Sur        |11.2.1     |Intel  |x86    |i5-10      |2.0         |23:52         |MBP2020 - Java 15.0.1     |
|macOS  |Big Sur        |11.2.1     |M1     |arm64  |           |3.2         |33:29         |Mac mini 2020  - Java 16  |
|Linux  |Ubuntu 20.04.2 |5.8.0      |Intel  |amd64  |i9-9900K   |3.6         |33:49         |Java 15.0.1               |

_** Leiningen 2.9.5_

---

## Perl
---
### Kamthorn Krairaksa

|OS     |Distro         |Version    |CPU    |Arch   |Gen        |Clock (GHz) |Time (min)    |Remark         |
|:-----:|:-------------:|:---------:|:-----:|:-----:|:---------:|:----------:|:------------:|:-------------:|
|macOS  |Big Sur        |11.2.1     |Intel  |x86    |i5-10      |2.0         |41:32         |MBP2020        |
|macOS  |Big Sur        |11.2.1     |M1     |arm64  |           |3.2         |39:30         |Mac mini 2020  |
|Linux  |Ubuntu 20.04.2 |5.8.0      |Intel  |amd64  |i9-9900K   |3.6         |25:21         |               |

_** Perl 5.28(Mac) and 5.30(Linux)_

---

## Python
---
### Wacharabuhm Tungketmukda

|OS     |Distro         |Version    |CPU    |Arch   |Gen        |Clock (GHz) |Time (hr )    |Remark         |
|:-----:|:-------------:|:---------:|:-----:|:-----:|:---------:|:----------:|:------------:|:-------------:|
|macOS  |Big Sur        |11.2.1     |Intel  |x86    |i5-10      |2.0         |1:36:03       |MBP2020        |
|macOS  |Big Sur        |11.2.1     |M1     |arm64  |           |3.2         |0:52:42       |Mac mini 2020  |
|Linux  |Ubuntu 20.04.2 |5.8.0      |Intel  |amd64  |i9-9900K   |3.6         |0:42:17       |               |

_** Python 3.8_

---



## Elixir
---
### Thanabodee Charoenpiriyakij

#### Pure

|OS     |Distro         |Version    |CPU    |Arch   |Gen        |Clock (GHz) |Time (hr)    |Remark         |
|:-----:|:-------------:|:---------:|:-----:|:-----:|:---------:|:----------:|:------------:|:-------------:|
|macOS  |Big Sur        |11.2.1     |Intel  |x86    |i5-10      |2.0         |2:44:43       |MBP2020        |
|macOS  |Big Sur        |11.2.1     |M1     |arm64  |           |3.2         |1:12:48       |Mac mini 2020  |
|Linux  |Ubuntu 20.04.2 |5.8.0      |Intel  |amd64  |i9-9900K   |3.6         |1:16:32       |               |


#### With C lib

|OS     |Distro         |Version    |CPU    |Arch   |Gen        |Clock (GHz) |Time (hr)     |Remark         |
|:-----:|:-------------:|:---------:|:-----:|:-----:|:---------:|:----------:|:------------:|:-------------:|
|macOS  |Big Sur        |11.2.1     |Intel  |x86    |i5-10      |2.0         |1:01:30       |MBP2020        |
|macOS  |Big Sur        |11.2.1     |M1     |arm64  |           |3.2         |0:30:50       |Mac mini 2020  |
|Linux  |Ubuntu 20.04.2 |5.8.0      |Intel  |amd64  |i9-9900K   |3.6         |0:32:58       |               |


_** Elixir 1.11.3_

---


## NodeJS
---
### Kamthorn Krairaksa

|OS     |Distro         |Version    |CPU    |Arch   |Gen        |Clock (GHz) |Time (hr)     |Remark         |
|:-----:|:-------------:|:---------:|:-----:|:-----:|:---------:|:----------:|:------------:|:-------------:|
|macOS  |Big Sur        |11.2.1     |Intel  |x86    |i5-10      |2.0         |2:51:55       |MBP2020        |
|macOS  |Big Sur        |11.2.1     |M1     |arm64  |           |3.2         |1:23:24       |Mac mini 2020  |
|Linux  |Ubuntu 20.04.2 |5.8.0      |Intel  |amd64  |i9-9900K   |3.6         |1:34:18       |               |

_** Node 14.15.5_

---



## Deno
---
### Kamthorn Krairaksa

|OS     |Distro         |Version    |CPU    |Arch   |Gen        |Clock (GHz) |Time (hr)    |Remark         |
|:-----:|:-------------:|:---------:|:-----:|:-----:|:---------:|:----------:|:------------:|:-------------:|
|macOS  |Big Sur        |11.2.1     |Intel  |x86    |i5-10      |2.0         |6:57:30       |MBP2020        |
|macOS  |Big Sur        |11.2.1     |M1     |arm64  |           |3.2         |4:52:31       |Mac mini 2020  |
|Linux  |Ubuntu 20.04.2 |5.8.0      |Intel  |amd64  |i9-9900K   |3.6         |4:42:08       |               |

_** Deno 1.7.2_

---

## Contribution

ขอเชิญเพื่อนๆ ส่ง Code และ ผลการทดสอบ โดยการ PR เข้ามาได้เลยครับ

## Contributors
* [@dtinth](https://github.com/dtinth) - Original Example
* [@kamthorn](https://github.com/kamthorn) - C Language, PHP, NodeJS, Perl, Deno
* [@Oat](https://www.facebook.com/Oat.Saysai) - Golang
* [@javadevil](https://github.com/javadevil) - Python
* [@veer66](https://github.com/veer66) - Rust
* [@wingyplus](https://github.com/wingyplus) - Elixir
* [@iporsut](https://github.com/iporsut) - Haskell
* [@phondanai](https://github.com/phondanai) - Clojure
* [@leknarm](https://github.com/leknarm) - Java
* [@santilert](https://github.com/santilert) - C Language
