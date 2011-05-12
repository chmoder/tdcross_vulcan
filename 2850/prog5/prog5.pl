#!/usr/bin/perl

use warnings; 
use strict;

#name: Thomas Cross
#class: CSCI 2850-001
#prog number: 1
#due date: 1.18.11

#Honor Pledge:
#On my honor as a student of the University of Nebraska at Omaha,
#I have neither given nor recieved unauthorized help on this homework
#assignment.

#name: Thomas Cross
#nuid: 1337
#email: tdcross@mail.unomaha.edu

#partners:
#extra:
#convert a binary number 1 - 20 digits in length to base 10.

print'Please enter a binary number up to 20 digits: ';
chomp(my $input = <>);

my $save_input = $input;
my $counter = 0;
my $temp;
my $base10 = 0;

#make the array
while(($temp = chop($input)) ne '')
{
	if($temp == 1)
	{
		$base10 += (2 ** $counter);
	}
	++$counter;
}
print $save_input.' is '. $base10.' in decimal.'."\n";
