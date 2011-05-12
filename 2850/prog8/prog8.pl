#!/usr/bin/perl

use warnings; 
use strict;
use feature ":5.10";
use Data::Dumper;
use Mail::Sendmail;

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
#this is a web teplate for scraping web pages.  
#Specificly rotten tomatoes rotten data.
$Data::Dumper::Indent = 3;


my $email;
if(scalar(@ARGV) == 1)
{
	$email = $ARGV[0];
}
else
{
	print "\n\n".'Usage: ./prog8 email'."\n\n";
	exit();
}

my $page_to_grab = 'http://www.rottentomatoes.com/movies/box_office.php';
my $command = '/usr/bin/lynx -dump -width=120 '.$page_to_grab;
my $page_file = `$command`;
$page_file =~ /\[\d*\]Theater Average \[\d*\]# Of Theaters(.*?)\[Last Weekend\.\]/sm;
$page_file = $1;
$page_file =~ s/\x{00E8}/e/g;
#print $page_file;
#print "\n";

my @line;


@line = ($page_file =~ /(\S+)\s+(\S+)\s+(\S+)\s+\[\d+\](([A-Za-z0-9:\-_+='()]+\s+)+)\s*(\S+)\s+(\S+)\s+(\S+)\s+(\S+)/mg);

	#print Dumper(@line);
	#@data = push(@data, @line);
	#$page_file =~ (/.*\n/);
	#print $page_file."\n";
	#exit();

my $counter = 0;
my @temp;
my @data;
foreach my $token (@line)
{
	push(@temp, $token);
	++$counter;

	if($counter > 8 && $counter % 9 == 0)
	{
		push(@data, [@temp]);
		$#temp = -1;
	}
}
#print $data[5][7]."\n";
#foreach my $row(@data)
#{
#	my $one;
#	if(substr(@$row[6], -1) eq 'M')
#	{
#		$one = substr(@$row[6], 1, -2);
#		$one *= 1000000;
#		print 'one'.@$row[6]."\n";
#	}
#	elsif(substr(@$row[6], -1) eq 'k')
#	{
#		$one = substr(@$row[6], 1, -2);
#		$one *= 1000;
#		print 'two'.@$row[6]."\n";
#	}
#	else
#	{
#		print 'error'."\n";
#		foreach my $temp (@$row)
#		{
#			print $temp."\n"
#		}
#	}
#++$counter;
#}

my $body = '<pre>Data scraped from '.$page_to_grab."\n\n\n";
$body .= sprintf("%-2s %-2s %-35s %-7s %-5s %-3s \n\n", '##', '##', 'Movie Title', 'Weekend', 'Cume', 'T-Meter');

foreach my $row(@data)
{
	while(@$row[3] =~ /\s+$/)
	{
		chop(@$row[3]);
	}
	while(@$row[3] =~ /\d+$/)
	{
		chop(@$row[3]);
	}
	while(@$row[3] =~ /\s+$/)
	{
		chop(@$row[3]);
	}
	#@$row[3] = substr(@$row[3], 0, -2);
	$body .= sprintf("%-2d %-2s %-35s %-7s %-7s %-3s\n", @$row[0], @$row[1], substr(@$row[3], 0, 35), @$row[5], @$row[6], @$row[2]);
}

my $b_dbt = 0;
my $b_dbt_d = 0;
my $w_dbt = 0;
my $w_dbt_d = 0;
my $b_g = 0;
my $b_g_c = 0;
my $w_g = 0;
my $w_g_c = 0;

$body .= "\n\n";

$counter = 0;
foreach my $row(@data)
{
	if(@$row[8] > $b_dbt_d)
	{
		$b_dbt_d = @$row[8];
		$b_dbt = $counter; 
	}
	$counter++;
}
$body .= 'Biggest Debut: '.$data[$b_dbt][3].' ('.$data[$b_dbt][0].')'."\n";

$counter = 0;
foreach my $row(@data)
{
	if(@$row[8] < $w_dbt_d || $w_dbt_d == 0)
	{
		$w_dbt_d = @$row[8];
		$w_dbt = $counter; 
	}
	$counter++;
}
$body .= 'Worst Debut: '.$data[$w_dbt][3].' ('.$data[$w_dbt][0].')'."\n";

$counter = 0;
foreach my $row(@data)
{
	if(@$row[1] ne '--')
	{
		if((@$row[1] - @$row[0]) > $b_g || $b_g == 0)
		{
			$b_g = @$row[1] - @$row[0];
			$b_g_c = $counter; 
		}
	}
	$counter++;
}
$body .= 'Biggest Gain: '.$data[$b_g_c][3].' ('.$b_g.' places)'."\n";

$counter = 0;
foreach my $row(@data)
{
	if(@$row[1] ne '--')
	{
		if((@$row[1] - @$row[0]) < $w_g || $w_g == 0)
		{
			$w_g = @$row[1] - @$row[0];
			$w_g_c = $counter;
		}
	}
	$counter++;
}
$body .= 'Biggest Loss: '.$data[$w_g_c][3].' ('.($w_g *= -1).' places)'."\n";



$body .= '</pre>';

my $from = 'tdcross@unomaha.edu';
my $subject = 'Weekend Box Office Report';

my %mail = (
	To => $email,
	From => $from,
	Subject => $subject,
	Message => $body,
	'Content-Type' => 'text/html; charset="iso-8859-1"'
);

if(sendmail %mail)
{
	print 'The email was successfully sent to '.$email.'.'."\n";
}
else
{
	print 'The email failed to send to '.$email.'.'."\n";
}

