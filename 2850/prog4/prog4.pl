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
#This program takes a 7 digit string and returns PALINDROME if it is or NOT if it is not.


print 'Please enter a 7 character phrase: ';
chomp(my $input = <>);
my $temp = '';
my @perl_array;
my $counter = 0;

while(($temp = chop($input)) ne '')
{
	$perl_array[$counter++] = $temp;	
}

if(
	($perl_array[0] eq $perl_array[6]) && 
	($perl_array[1] eq $perl_array[5]) &&
	($perl_array[2] eq $perl_array[4])
)
{
	print 'PALINDROME'."\n";
}
else
{
	print 'NOT'."\n";
}
