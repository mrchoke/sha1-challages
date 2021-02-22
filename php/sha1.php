#!/usr/bin/php
<?php
$rounds=5_555_555_555;
$msg="clubhouse";

for ($i = 1; $i<=$rounds; $i++)
  $msg=sha1($msg);

echo "$msg\n";
