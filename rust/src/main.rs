use hex;
//use hex_literal::hex;
use sha1::{Sha1, Digest};

fn main() {
    let mut bytes = [0u8; 40];
    hex::encode_to_slice(Sha1::digest(b"clubhouse"), &mut bytes).unwrap();
    for _ in 1..5_555_555_555u64 {
	hex::encode_to_slice(Sha1::digest(&bytes), &mut bytes).unwrap();
    }
    println!("{:}", String::from_utf8_lossy(&bytes));
}
