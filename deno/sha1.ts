import { sha1 } from "https://denopkg.com/chiefbiiko/sha1/mod.ts";

let msg:string = "clubhouse"
let rounds:number = 5_555_555_555

for ( let i: number=1; i<=rounds; i++ )
  msg = sha1( msg, "utf8", "hex" ) as string

console.log( msg )
