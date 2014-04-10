#!/usr/pkg/bin/perl -w

if ((scalar @ARGV) <= 1)
{
    print "program size density\n";
    exit;
}

my $size = $ARGV[0];
my $density = $ARGV[1];
my $i = 0;
my $j = 0;

print $size . "\n";

while ($i < $size)
{
    $j = 0;
    while ($j < $size)
    {
        if (int(rand($size)*2) < $density)
        {
            print 'o';
        }
        else
	{
            print '.';
        }
        $j++;
    }
    print "\n";
    $i++;
}
