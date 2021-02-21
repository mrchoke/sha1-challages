let crypto = require('crypto')
var msg = "clubhouse"
let rounds = 5_555_555_555

for (let i=1; i<=rounds; i++)
{
  var shasum = crypto.createHash('sha1')
  msg=shasum.update(msg).digest("hex")
}

console.log(msg)
