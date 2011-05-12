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
#CLI user usage parsing program in perl

if(scalar(@ARGV) == 1)
{
	my $username = $ARGV[0];
	my $uname;
	if(length($username) >= 8)
	{  
		$uname = substr($username, 0, 8);
	}
	else
	{
		$uname = substr($username, 0, length($username));
	}
	my @capture = `last`;
	my $count = 0;
	my $hours = 0;
	my $minutes = 0;

	print 'Here is a listing of the logins for '.$username.':'."\n\n";

	foreach my $line (@capture)
	{
		my $lineuser;
		if(length($username) >= 8)
		{
			$lineuser = substr($line, 0, 8);
		}
		else
		{
			$lineuser = substr($line, 0, length($username));
		}
		
		if($lineuser eq $uname)
		{
			print ' '.++$count.'. '.$line;
			$line =~ /\((\d\d):(\d\d)\)/;
			if($1 && $2)
			{
				$hours += $1;
				$minutes += $2;
			}
		}
	}
	while ($minutes > 60)
	{
		++$hours;
		$minutes -= 60;
	}
	$hours = sprintf("%02d", $hours);
	$minutes = sprintf("%02d", $minutes);

	print "\n".'Here is a summary of the time spent on the system for '.$username.':'."\n\n";
	
	print $username.'='.$count.'='.$hours.':'.$minutes."\n";
}
else
{
	print 'Usage: lastsummary login'."\n";
}

