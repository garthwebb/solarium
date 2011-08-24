#!/usr/bin/perl -w

use strict;

my ($file) = @ARGV;

my @maps;

# [
#   [r, g, b], [r, g, b], ...
#   [r, g, b], ...
#   ...
# ]
#typedef struct {
#        int red;
#        int green;
#        int blue;
#} color_t;
#
#color_t palette[2][4] = {
#{{1,2,3}, {2,2,3}, {3,2,3}, {4,2,3}},
#{{3,2,1}, {3,2,1}, {3,2,3}, {3,2,4}},
#};

open(FH, $file) or die "Can't open '$file': $!\n";
while (my $line = <FH>) {
	chomp($line);

	my @m;
	foreach my $rgb (split('\s*,\s*', $line)) {
		push @m, [split('\s*/\s*', $rgb)];
	} 

	push @maps, \@m;
}
close(FH);

my $num_maps = scalar(@maps);
my $num_colors = 181;

print qq(
#ifndef __COLORMAP_H__
#define __COLORMAP_H__

typedef struct {
        int red;
        int green;
        int blue;
} color_t;

#define NUM_MAPS $num_maps
#define COLOR_MAP_SIZE $num_colors

);

print 'color_t color_map['.scalar(@maps)."][181] = {\n";

my $out = '';
foreach my $map (@maps) {
	$out .= '{';
	foreach my $rgb (@$map) {
		$out .= '{'.join(',', @$rgb).'},';
	}
	chop($out);
	$out .= "}\n";
}
print $out;

print qq(
};

#endif
);
