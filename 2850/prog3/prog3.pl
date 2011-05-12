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

#This program reverses the number for chop then puts the number in its 
#original order with (3) spaces inbetween each number then removes
#the extra 3 spaces and prints that number

print 'Enter a five-digit number: ';
chomp(my $input_number = <>);

my $integer = '';
my $new_number = '';
while(($integer = chop($input_number)) ne '')
{
	$new_number .= $integer;
}
while(($integer = chop($new_number)) ne '')
{
	$input_number .= $integer.'   ';
}
#remove last 3 spaces
chop($input_number);
chop($input_number);
chop($input_number);

print $input_number."\n";
