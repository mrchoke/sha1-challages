let crypto = require('crypto')
let msg = "clubhouse"
let rounds = 5_555_555_555

if ( process.argv[2] )
  msg = process.argv[2]
if ( process.argv[3] )
  rounds = parseInt( process.argv[3] )

for (let i=1; i<=rounds; i++)
  msg = crypto.createHash('sha1').update(msg).digest("hex")

console.log(msg)
