#!/usr/bin/perl
use strict;

use Digest::SHA1  qw(sha1_hex);
my $msg = "clubhouse";
my $rounds = 5555555555;
for(my $i=1;$i<=$rounds;$i++){
  $msg = sha1_hex($msg);
}
print $msg,"\n";
