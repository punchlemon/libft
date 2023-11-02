#!/usr/bin/perl
use warnings;
use strict;
die "program x y density" unless (scalar(@ARGV) == 3);
my ($x, $y, $density) = @ARGV;
print "$y.ox\n";
for (my $i = 0; $i < $y; $i++) {
	for (my $j = 0; $j < $x; $j++) {
		if (int(rand($y) * 2) < $density) {
			print "o";
		}
		else {
			print ".";
		}
	}
	print "\n";
}




# char *filepath = "file.txt";
# int fc = open(filepath, O_RDONLY);//readをwriteにしたい
# if (fc = -1)
# 	return (NULL);
# int cap = 32
# char *buff = (char *)malloc(cap);

# int rc = read(fc, buff, cap);
# if (rc > 0)
# 	cap *= 2;
# buff = my_realloc(&buff, cap);
