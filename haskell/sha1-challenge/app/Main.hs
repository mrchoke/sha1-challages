{-# LANGUAGE OverloadedStrings #-}
{-# LANGUAGE NumericUnderscores #-}

module Main where

import Crypto.Hash.SHA1
import Data.ByteString.Base16

loop 5_555_555_555 v = encode $ hash v
loop n v = loop (n+1) (encode $ hash v)

main :: IO ()
main = print $ loop 1 "clubhouse"
