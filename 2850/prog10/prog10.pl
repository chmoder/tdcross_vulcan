#!/usr/bin/perl

use warnings; 
use strict;
use Net::hostent;
use Time::Local;

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
#Weblog analyzer



if(scalar(@ARGV) < 1)
{
	print "\n\n".'Usage: '.$0.' better usage statement'."\n\n";
	exit();
}


my $output;
my %log_files;
my (@ipaddy, @date, @time, @method, @url, @httpvers, @statuscode, @bytes, @referrer, @useragent);
my ($ipaddy, $g1, $g2, $date, $time, $method, $url, $httpvers, $statuscode, $bytes, $referrer, $useragent);
my %log_line = ();
foreach my $lf (@ARGV)
{
	open(FILE, $lf);
	while (my $line=<FILE>) 
	{
		my ($ipaddy, $date, $time, $method, $url, $httpvers, $statuscode, $bytes, $referrer, $useragent) = $line =~
			m/^(\S+) - - \[(\d+\/\w+\/\d+):(\d+:\d+:\d+) [\-|\+]\d{4}\] "(\S+) (\S+) ([^"]+)" (\d+) (\d+|-) "(.*?)" "([^"]+)"$/;

#			print $ipaddy."\n".
#				$date."\n".
#				$time."\n".
#				$url."\n".
#				$method."\n".
#				$httpvers."\n".
#				$statuscode."\n".
#				$bytes."\n".
#				$referer."\n".
#				$useragent."\n";

#push(@ipaddy, $ipaddy);
		push(@{$log_files{'ipaddy'} }, $ipaddy);
#push(@date, $date);
		push(@{$log_files{'date'} }, $date);
#push(@time, $time);
		push(@{$log_files{'time'} }, $time);
#push(@url, $url);
		push(@{$log_files{'url'} }, $url);
#push(@method, $method);
		push(@{$log_files{'method'} }, $method);
#push(@httpvers, $httpvers);
		push(@{$log_files{'httpvers'} }, $httpvers);
#push(@statuscode, $statuscode);
		push(@{$log_files{'statuscode'} }, $statuscode);
#push(@bytes, $bytes);
		push(@{$log_files{'bytes'} }, $bytes);
#push(@referer, $referer);
		push(@{$log_files{'referrer'} }, $referrer);
#push(@useragent, $useragent);
		push(@{$log_files{'useragent'} }, $useragent);
	}
	close(FILE);
}
foreach my $string (keys %log_files)
{
	#print $string.":\n";
	#my @array = @{ $log_files{$string} };

	if($string eq 'ipaddy')
	{
		#&printHostNames(\@array);
	}
#print "$string: @{$log_files{$string}}\n";
}

$output .= 'Web server log analyzer v1.0'."\n\n";
$output .= 'Processed '.scalar(@{ $log_files{'ipaddy'} }).' entries from '.scalar(@ARGV).' files.'."\n";
$output .= 'Processed the following logfiles:'."\n";
foreach my $temp (@ARGV)
{
	$output .= $temp."\n";
}
$output .= "\n";


&printHostNames(${ log_files{'ipaddy'} });
&printDomains(${ log_files{'ipaddy'} });
&printDates(${ log_files{'date'} });
&printHours(${ log_files{'time'} });
&printStatusCode(${ log_files{'statuscode'} });
&printUrl(${ log_files{'url'} });
&printBrowser(${ log_files{'useragent'} });
&printReferrer(${ log_files{'referrer'} });
&printReferrerDomain(${ log_files{'referrer'} });
&printBytes(${ log_files{'bytes'} });

my $username = `whoami`;
chomp($username);
open(FILE, '>'.$username.'.logsummary');
	print FILE $output;
close(FILE);

sub printHostNames
{
	my %host_hash;

	my @array = @{(shift)};
	my @host_array;
	foreach my $host (@array)
	{
		my $h = gethost($host);

		if($h)
		{
			push(@host_array, $h->name());
		}
		else
		{
			push(@host_array, $host);
		}
	}

	foreach my $val (sort { lc($a) cmp lc($b) } @host_array)
	{
		#print $val.' '."\n";
		push @{ $host_hash{$val} }, $val;
	}

	$output .= '================================================================================'."\n";
	$output .= 'HOSTNAMES'."\n";
	$output .= '================================================================================'."\n";
	$output .= '  Hits  %-age   Resource'."\n";
	$output .= '  ----  -----   --------'."\n";

	my $total_hosts = scalar(@array);
	#print $total_hosts.' '.scalar(@host_array);
	foreach my $string (sort { lc($a) cmp lc($b) } (keys %host_hash))
	{
		$output .= sprintf("  % 4d  %.2f    %s\n", scalar(@{ $host_hash{$string} }), (scalar(@{ $host_hash{$string} })/$total_hosts)*100, pop(@{ $host_hash{$string} }));
	}
	
	$output .= ' -----'."\n";
	$output .= '   '.scalar(@host_array).' entries displayed'."\n\n";

	
}

sub printDomains
{
	my %host_hash;

	my @array = @{(shift)};
	my @host_array;
	foreach my $host (@array)
	{
		my $h = gethost($host);

		if($h)
		{
			push(@host_array, $h->name());
		}
		else
		{
			push(@host_array, $host);
		}
	}

	foreach my $val (sort { lc($a) cmp lc($b) } @host_array)
	{
		#print $val.' '."\n";
		my $temp;
		if($val =~ m/\d+\.\d+\.\d+\.\d+/  || $val !~ m/\S+.*\.\S+\.\S+$/)
		{
			$temp = 'N/A (DOTTED QUAD OR OTHER)';
		}
		else
		{
			$val =~ m/\S+.*\.(\S+\.\S+$)/;
			$temp = $1;
		}

		push @{ $host_hash{$temp} }, $temp;
	}

	$output .= '================================================================================'."\n";
	$output .= 'DOMAINS'."\n";
	$output .= '================================================================================'."\n";
	$output .= '  Hits  %-age   Resource'."\n";
	$output .= '  ----  -----   --------'."\n";

	my $total_hosts = scalar(@array);
	#print $total_hosts.' '.scalar(@host_array);
	foreach my $string (sort { lc($a) cmp lc($b) } (keys %host_hash))
	{
		$output .= sprintf("  % 4d  %.2f    %s\n", scalar(@{ $host_hash{$string} }), (scalar(@{ $host_hash{$string} })/$total_hosts)*100, pop(@{ $host_hash{$string} }));
	}
	$output .= ' -----'."\n";
	$output .= '   '.scalar(@host_array).' entries displayed'."\n\n";
}

sub printDates
{
	my @passed_array = @{(shift)};
	my @array;
	my %date_hash;
	my %month_to_number = (
		Jan => 1,
		Feb => 2,
		Mar => 3,
		Apr => 4,
		May => 5,
		Jun => 6,
		Jul => 7,
		Aug => 8,
		Sep => 9,
		Oct => 10,
		Nov => 11,
		Dec => 12
		);
	
	foreach my $date (@passed_array)
	{
		my ($day, $month, $year) = $date =~ m/(\d+)\/(\S+)\/(\d+)/;
		$month = $month_to_number {$month};
		$time = $year.'/'.$month.'/'.$day;
		push @{ $date_hash{$time} }, $date;
	}

	$output .= '================================================================================'."\n";
	$output .= 'DATES'."\n";
	$output .= '================================================================================'."\n";
	$output .= '  Hits  %-age   Resource'."\n";
	$output .= '  ----  -----   --------'."\n";

	my $total_dates = scalar(@passed_array);
	#print $total_hosts.' '.scalar(@host_array);
	foreach my $string (sort (keys %date_hash))
	{
		$output .= sprintf("  % 4d  %.2f    %s\n", scalar(@{ $date_hash{$string} }), (scalar(@{ $date_hash{$string} })/$total_dates)*100, pop(@{ $date_hash{$string} }));
	}
	$output .= ' -----'."\n";
	$output .= '   '.scalar(@passed_array).' entries displayed'."\n\n";
}

sub printHours
{
	my @passed_array = @{(shift)};
	my @array;
	my %hours_hash;
	
	foreach my $time (@passed_array)
	{
		my ($hours, $minutes, $seconds) = $time =~ m/(\d+):(\d+):(\d+)/;
		push @{ $hours_hash{$hours} }, $hours;
	}

	$output .= '================================================================================'."\n";
	$output .= 'Hours'."\n";
	$output .= '================================================================================'."\n";
	$output .= '  Hits  %-age   Resource'."\n";
	$output .= '  ----  -----   --------'."\n";

	my $total_hours = scalar(@passed_array);
	#print $total_hosts.' '.scalar(@host_array);
	foreach my $string (sort (keys %hours_hash))
	{
		$output .= sprintf("  % 4d  %.2f    %s\n", scalar(@{ $hours_hash{$string} }), (scalar(@{ $hours_hash{$string} })/$total_hours)*100, pop(@{ $hours_hash{$string} }));
	}
	$output .= ' -----'."\n";
	$output .= '   '.scalar(@passed_array).' entries displayed'."\n\n";
}

sub printStatusCode
{
	my @passed_array = @{(shift)};
	my @array;
	my %hours_hash;
	
	foreach my $time (@passed_array)
	{
		my $hours = $time;
		push @{ $hours_hash{$hours} }, $hours;
	}

	$output .= '================================================================================'."\n";
	$output .= 'Status Code'."\n";
	$output .= '================================================================================'."\n";
	$output .= '  Hits  %-age   Resource'."\n";
	$output .= '  ----  -----   --------'."\n";

	my $total_hours = scalar(@passed_array);
	#print $total_hosts.' '.scalar(@host_array);
	foreach my $string (sort (keys %hours_hash))
	{
		$output .= sprintf("  % 4d  %5.2f    %s\n", scalar(@{ $hours_hash{$string} }), (scalar(@{ $hours_hash{$string} })/$total_hours)*100, pop(@{ $hours_hash{$string} }));
	}
	$output .= ' -----'."\n";
	$output .= '   '.scalar(@passed_array).' entries displayed'."\n\n";
}

sub printUrl
{
	my @passed_array = @{(shift)};
	my @array;
	my %hours_hash;
	
	foreach my $time (@passed_array)
	{
		my $hours = $time;
		push @{ $hours_hash{$hours} }, $hours;
	}

	$output .= '================================================================================'."\n";
	$output .= 'URLS'."\n";
	$output .= '================================================================================'."\n";
	$output .= '  Hits  %-age   Resource'."\n";
	$output .= '  ----  -----   --------'."\n";

	my $total_hours = scalar(@passed_array);
	#print $total_hosts.' '.scalar(@host_array);
	foreach my $string (sort (keys %hours_hash))
	{
		$output .= sprintf("  % 4d  %5.2f    %s\n", scalar(@{ $hours_hash{$string} }), (scalar(@{ $hours_hash{$string} })/$total_hours)*100, pop(@{ $hours_hash{$string} }));
	}
	$output .= ' -----'."\n";
	$output .= '   '.scalar(@passed_array).' entries displayed'."\n\n";
}

sub printBrowser
{
	my @passed_array = @{(shift)};
	my @array;
	my %hours_hash;
	
	foreach my $time (@passed_array)
	{
		my $hours = $time;
		push @{ $hours_hash{$hours} }, $hours;
	}

	$output .= '================================================================================'."\n";
	$output .= 'BROWSERS'."\n";
	$output .= '================================================================================'."\n";
	$output .= '  Hits  %-age   Resource'."\n";
	$output .= '  ----  -----   --------'."\n";

	my $total_hours = scalar(@passed_array);
	#print $total_hosts.' '.scalar(@host_array);
	foreach my $string (sort (keys %hours_hash))
	{
		$output .= sprintf("  % 4d  %5.2f    %s\n", scalar(@{ $hours_hash{$string} }), (scalar(@{ $hours_hash{$string} })/$total_hours)*100, pop(@{ $hours_hash{$string} }));
	}
	$output .= ' -----'."\n";
	$output .= '   '.scalar(@passed_array).' entries displayed'."\n\n";
}

sub printReferrer
{
	my @passed_array = @{(shift)};
	my @array;
	my %hours_hash;
	
	foreach my $time (@passed_array)
	{
		my $hours = $time;
		if(length($hours) == 1)
		{
			push @{ $hours_hash{$hours} }, 'N/A';
		}
		else
		{
			push @{ $hours_hash{$hours} }, $hours;
		}
	}

	$output .= '================================================================================'."\n";
	$output .= 'REFERRERS'."\n";
	$output .= '================================================================================'."\n";
	$output .= '  Hits  %-age   Resource'."\n";
	$output .= '  ----  -----   --------'."\n";

	my $total_hours = scalar(@passed_array);
	#print $total_hosts.' '.scalar(@host_array);
	foreach my $string (sort (keys %hours_hash))
	{
		$output .= sprintf("  % 4d  %5.2f    %s\n", scalar(@{ $hours_hash{$string} }), (scalar(@{ $hours_hash{$string} })/$total_hours)*100, pop(@{ $hours_hash{$string} }));
	}
	$output .= ' -----'."\n";
	$output .= '   '.scalar(@passed_array).' entries displayed'."\n\n";
}

sub printReferrerDomain
{
	my @passed_array = @{(shift)};
	my %hours_hash;
	
	foreach my $time (@passed_array)
	{
		my $hours = $time;
		if(length($hours) == 1 || $hours !~ m/\S+\.(\w+\.\w+)\//)
		{
			push @{ $hours_hash{'N/A'} }, 'N/A';
		}
		else
		{
			$hours =~ m/\S+\.(\w+\.\w+)\//;
			push @{ $hours_hash{$1} }, $1;
		}
	}

	$output .= '================================================================================'."\n";
	$output .= 'REFERRERS\' DOMAINS'."\n";
	$output .= '================================================================================'."\n";
	$output .= '  Hits  %-age   Resource'."\n";
	$output .= '  ----  -----   --------'."\n";

	my $total_hours = scalar(@passed_array);
	#print $total_hosts.' '.scalar(@host_array);
	foreach my $string (sort (keys %hours_hash))
	{
		$output .= sprintf("  % 4d  %5.2f    %s\n", scalar(@{ $hours_hash{$string} }), (scalar(@{ $hours_hash{$string} })/$total_hours)*100, pop(@{ $hours_hash{$string} }));
	}
	$output .= ' -----'."\n";
	$output .= '   '.scalar(@passed_array).' entries displayed'."\n\n";
}

sub printBytes
{
	my @passed_array = @{(shift)};
	my $total = 0;
	foreach my $bytes (@passed_array)
	{
		if($bytes =~ m/\d+/)
		{
			$total += $bytes;
		}
	}

	$output .= 'Total bytes served   = '.$total."\n\n";
}
