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
#This program takes three integers from keyboard (one per line) and prints out the SUM, AVG, PRO, SML, LRG

print 'Enter first integer: '."\n";
chomp(my $first = <>);
my $min = $first;
my $max = $first;
print 'Enter second integer: '."\n";
chomp(my $second = <>);
($second < $min ? $min = $second:1);
($second > $max ? $max = $second:1);
print 'Enter third integer: '."\n";
chomp(my $third = <>);
($third < $min ? $min = $third:1);
($third > $max ? $max = $third:1);

my $sum = $first + $second + $third;
my $avg = $sum / 3;
my $pro = $first * $second * $third;

print 'SUM: '.$sum."\n";
print 'AVG: '.$avg."\n";
print 'PRO: '.$pro."\n";
print 'SML: '.$min."\n";
print 'LRG: '.$max."\n";
