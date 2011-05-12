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
#soundex finger


my $cli_uname;
if(scalar(@ARGV) == 1)
{
        $cli_uname = $ARGV[0];
	print'The name you were looking for, '.$cli_uname.', converted to '.&soundex($cli_uname)."\n\n";
}
else
{
	print "\n\n".'Usage: '.$0.' possible_last_name'."\n\n";
	exit();
}


my %sndx = ( "Euler" => "E4600"	, "Gauss" => "G2000" , 
		"Hilbert" => "H4163", "Knuth" => "K5300",
		"Lloyd" => "L3000", "Lukasieicz" => "L2220" );

#print "Processing known names:\n\n"; 
my @names = sort {$a cmp $b} keys %sndx;

foreach my $nm (@names) 
{
	my $findSdx = &soundex($nm);	

	#print "The soundex for $nm should be $sndx{$nm} and is $findSdx\n"; 
	if ( $findSdx ne $sndx{$nm} ) 
	{
		#print "\tHowever, that is incorrect!\n\n";
	}
}

open (IN,"/etc/passwd");
my @wholeFile = <IN>;
close IN;

my $userid;
my $lastname;
#print "Here is the file /etc/passwd file with blank lines:\n\n";
#foreach my $line (@wholeFile)
#{
#	print $line, "\n";
#}
#print "Press ENTER to continue and use the functions to grab info:\n\n";
#<>;
foreach my $line (@wholeFile)
{
	$userid = &get_user_id($line);
	$lastname = &get_last_name($line);
	#print "$userid has a last name of $lastname!   ".&soundex($lastname).'  '. &soundex($cli_uname)."\n";
	if(&soundex($lastname) eq &soundex($cli_uname))
	{
		#print "$userid has a last name of $lastname!   ".&soundex($lastname).'  '. &soundex($cli_uname)."\n";
		my @args = ( "finger", $userid );
		system (@args);
		print "\n\n";
	}
}

sub get_user_id
{ 
	my $line = $_[0];
	my @line_arr = split(/[:]/, $line);
	return $line_arr[0];
}
sub get_last_name
{ 
	my $line = $_[0];
	my @line_arr = split(/[:,]/, $line);
	#print 'line_arr= '.$line_arr[4].'   '.length($line_arr[4])."\n";
	if(length($line_arr[4]) != 0)
	{
		@line_arr = split(/ /,$line_arr[4]);
		#print 'Last name should be '.$line_arr[-1]."\n";
	}
	else
	{
		$line_arr[4] = 'no_name';
	}
	return $line_arr[-1];
}


sub soundex 
{
	my $temp = uc shift;	# gets the name passed to the function # and uppercases it
	my $char0 = substr($temp, 0, 1);
	
	my $counter = 0;
	my $tempchar;
	$temp =~ tr/a-zA-Z/a-zA-Z/s;

	$temp =~ s/[BFPVbfpv]+/B/g;
	$temp =~ s/[BFPVbfpv]/1/g;

	$temp =~ s/[CGJKQSXZcgjkqsxz]+/z/g;
	$temp =~ s/[CGJKQSXZcgjkqsxz]/2/g;

	$temp =~ s/[DTdt]+/t/g;
	$temp =~ s/[DTdt]/3/g;

	$temp =~ s/[Ll]+/l/g;
	$temp =~ s/[Ll]/4/g;

	$temp =~ s/[MNmn]+/n/g;
	$temp =~ s/[MNmn]/5/g;

	$temp =~ s/[Rr]+/r/g;
	$temp =~ s/[Rr]/6/g;

	$temp = substr($temp,1);
	$temp =~ s/[AEHIOUWYaehiouwy]//g;
	$temp =~ s/[^A-Za-z1-6]//g;

	$char0 .= $temp;
	$temp = $char0;
	while(length($temp) < 5)
	{
		$temp .= '0';
	}
	while(length($temp) > 5)
	{
		chop($temp);
	}
	
	#my $sdxValue = "*** $temp not processed ***";
	my $sdxValue = $temp;
	return $sdxValue;
}
