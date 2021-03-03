// The 5,555,555,555 SHA-1 Challenge in V (https://vlang.io/)
// Author: @tonkla <tonkla@gmail.com>, https://github.com/tonkla
// Run: v run sha1.v
// Build & Run: v sha1.v && ./sha1

import crypto.sha1 { hexhash }
import time

fn main() {
	start := time.now()
	mut result := hexhash('clubhouse')
	for _ in 1..5555555555 {
		result = hexhash(result)
	}
	println('Result: $result')
	elapsed := (time.now() - start).minutes()
	println('Time: $elapsed minutes')
}
