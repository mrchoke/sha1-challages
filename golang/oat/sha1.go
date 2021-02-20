/*
	Author: Oat Saysai
	FB: https://www.facebook.com/Oat.Saysai

*/

package main

import (
	"crypto/sha1"
	"encoding/hex"
	"fmt"
	"time"
)

func main() {
	startTime := time.Now()

	temp := sha1.Sum([]byte("clubhouse"))
	dst := make([]byte, hex.EncodedLen(len(temp)))

	for i := 2; i <= 5555555555; i++ {
		hex.Encode(dst, temp[:])
		temp = sha1.Sum(dst)
	}

	fmt.Printf("%x\n", temp)
	fmt.Printf("Time diff: %+v\n", time.Now().Sub(startTime))
}
