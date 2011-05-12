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
#This ia program to simulate the 83rd acadamy awards
#This porgram could be much much easier to write if I just 
#used a foreach loop for each award for getting and summary.
#An associative array.
#...Think about your program before you write it :)
my $hr = "\n".'============================================================================='."\n";
my @results = ();
print 'Welcome to the 83rd Academy Awards!'."\n\n";
print $hr;

print'The nominees for Actor in a Leading Role are:'."\n\n";
my @leading_role = ();
push(@leading_role, 'Javier Barden in "Biutiful"');
push(@leading_role, 'Jeff Bridges in "True Grit"');
push(@leading_role, 'Jesse Eisenberg in "The Social Network"');
push(@leading_role, 'Colin Firth in "The King\'s Speech"');
push(@leading_role, 'James Franco in "127 Hours"');
push(@leading_role, 'Write In');


my $counter = 0;
foreach (@leading_role) 
{
	print '         ['.$counter++.'] '.$_."\n";
} 

my $input = -1;
my $write_in = '';
while(($input < 0) || ($input > $#leading_role))
{
	print "\n".'Please enter your choice for Actor in a Leading Role now: ';
	chomp ($input = <>);
	if($input < 0 || ($input > $#leading_role))
	{
		print'I\'m sorry, but '.$input.' is not a valid option.';
	}
	else
	{
		if($input == $#leading_role)
		{
			print'Please enter your write-in candidate: ';
			chomp($write_in = <>);
			push(@results, $write_in);
		}
		else
		{
			push(@results, $leading_role[$input]);
		}
	}
}
	print'Thank you for selecting '.$results[0].' as Actor in a Leading Role.';

print $hr;


my @supporting_role;
print'The nominees for Actor in a Supporting Role are:'."\n\n";
push(@supporting_role, 'Christian Bale in "The Fighter"');
push(@supporting_role, 'John Hawkes in "Winter\'s Bone"');
push(@supporting_role, 'Jeremy Renner in "The Town"');
push(@supporting_role, 'Mark Ruffalo in "The Kids Are All Right"');
push(@supporting_role, 'Geoffrey Rush in "The King\'s Speech"');
push(@supporting_role, 'Write In');

$counter = 0;
foreach (@supporting_role) 
{
	print '         ['.$counter++.'] '.$_."\n";
} 

$input = -1;
while(($input < 0) || ($input > $#supporting_role))
{
	print "\n".'Please enter your choice for Actor in a Supporting Role now: ';
	chomp ($input = <>);
	if($input < 0 || ($input > $#supporting_role))
	{
		print'I\'m sorry, but '.$input.' is not a valid option.';
	}
	else
	{
		if($input == $#supporting_role)
		{
			print'Please enter your write-in candidate: ';
			chomp($write_in = <>);
			push(@results, $write_in);
		}
		else
		{
			push(@results, $supporting_role[$input]);
		}
	}
}
	print'Thank you for selecting '.$results[1].' as Actor in a Supporting Role.';

print $hr;


my @actress_role;
print'The nominees for Actress in a Leading Role are:'."\n\n";
push(@actress_role, 'Annette Bening in "The Kids Are All Right"');
push(@actress_role, 'Nicole Kidman in "Rabbit Hole"');
push(@actress_role, 'Jennifer Lawrence in "Winter\'s Bone"');
push(@actress_role, 'Natalie Portman in "Black Swan"');
push(@actress_role, 'Michelle Williams in "Blue Valentine"');
push(@actress_role, 'Write In');

$counter = 0;
foreach (@actress_role)
{
        print '         ['.$counter++.'] '.$_."\n";
}

$input = -1;
while(($input < 0) || ($input > $#actress_role))
{
        print "\n".'Please enter your choice for Actress in a Leading Role now: ';
        chomp ($input = <>);
	if($input < 0 || ($input > $#actress_role))
	{
		print'I\'m sorry, but '.$input.' is not a valid option.';
	}
	else
	{
		if($input == $#actress_role)
		{
			print'Please enter your write-in candidate: ';
			chomp($write_in = <>);
			push(@results, $write_in);
		}
		else
		{
        		push(@results, $actress_role[$input]);
		}
	}
}
        print'Thank you for selecting '.$results[2].' as Actress in a Leading Role.';
print $hr;


my @animated_role;
print'The nominees for Animated Feature Film are:'."\n\n";
push(@animated_role, '"How to Train Your Dragon"');
push(@animated_role, '"The Illusionist"');
push(@animated_role, '"Toy Story 3"');
push(@animated_role, '"'.'Write In'.'"');

$counter = 0;
foreach (@animated_role)
{
        print '         ['.$counter++.'] '.$_."\n";
}

$input = -1;
while(($input < 0) || ($input > $#animated_role))
{
        print "\n".'Please enter your choice for Animated Feature Film now: ';
        chomp ($input = <>);
	if($input < 0 || ($input > $#animated_role))
	{
		print'I\'m sorry, but '.$input.' is not a valid option.';
	}
	else
	{
		if($input == $#animated_role)
		{
			print'Please enter your write-in candidate: ';
			chomp($write_in = <>);
			push(@results, $write_in);
		}
		else
		{
        		push(@results, $animated_role[$input]);
		}
	}
}
        print'Thank you for selecting '.$results[3].' as Animated Feature Film.';

print $hr;

my @cinematography_role;
print'The nominees for Cinematography are:'."\n\n";
push(@cinematography_role, '"Black Swan"');
push(@cinematography_role, '"Inception"');
push(@cinematography_role, '"The King\'s Speech"');
push(@cinematography_role, '"The Social Network"');
push(@cinematography_role, '"True Grit"');
push(@cinematography_role, '"'.'Write In'.'"');

$counter = 0;
foreach (@cinematography_role)
{
        print '         ['.$counter++.'] '.$_."\n";
}

$input = -1;
while(($input < 0) || ($input > $#cinematography_role))
{
        print "\n".'Please enter your choice for Cinematography now: ';
        chomp ($input = <>);
	if($input < 0 || ($input > $#cinematography_role))
	{
		print'I\'m sorry, but '.$input.' is not a valid option.';
	}
	else
	{
		if($input == $#cinematography_role)
		{
			print'Please enter your write-in candidate: ';
			chomp($write_in = <>);
			push(@results, $write_in);
		}
		else
		{
        		push(@results, $cinematography_role[$input]);
		}
	}
}
        print'Thank you for selecting '.$results[4].' as Cinematography.';
print $hr;


my @directing_role;
print'The nominees for Directing are:'."\n\n";
push(@directing_role, '"Black Swan" Darren Aronofsky');
push(@directing_role, '"The Fighter" David O. Russell');
push(@directing_role, '"The King\'s Speech" Tom Hooper');
push(@directing_role, '"The Social Network" David Fincher');
push(@directing_role, '"True Grit" Joel Coen and Ethan Coen');
push(@directing_role, '"'.'Write In'.'"');

$counter = 0;
foreach (@directing_role)
{
        print '         ['.$counter++.'] '.$_."\n";
}

$input = -1;
while(($input < 0) || ($input > $#directing_role))
{
        print "\n".'Please enter your choice for Directing now: ';
        chomp ($input = <>);
	if($input < 0 || ($input > $#directing_role))
	{
		print'I\'m sorry, but '.$input.' is not a valid option.';
	}
	else
	{
		if($input == $#directing_role)
		{
			print'Please enter your write-in candidate: ';
			chomp($write_in = <>);
			push(@results, $write_in);
		}
		else
		{
        		push(@results, $directing_role[$input]);
		}
	}
}
        print'Thank you for selecting '.$results[5].' as Directing.';
print $hr;


my @music_role;
print'The nominees for Music (Original Song) are:'."\n\n";
push(@music_role, '"Coming Home" from "Country Strong"');
push(@music_role, '"I See the Light" from "Tangled"');
push(@music_role, '"If I Rise" from "127 Hours"');
push(@music_role, '"We Belong Together" from "Toy Story 3"');
push(@music_role, '"'.'Write In'.'"');

$counter = 0;
foreach (@music_role)
{
        print '         ['.$counter++.'] '.$_."\n";
}

$input = -1;
while(($input < 0) || ($input > $#music_role))
{
        print "\n".'Please enter your choice for Music (Original Song) now: ';
        chomp ($input = <>);
	if($input < 0 || ($input > $#music_role))
	{
		print'I\'m sorry, but '.$input.' is not a valid option.';
	}
	else
	{
        	push(@results, $music_role[$input]);
	}
}
print'Thank you for selecting '.$results[6].' as Music (Original Song).';
print $hr;

my @picture_role;
print'The nominees for Best Picture are:'."\n\n";
push(@picture_role, '"Black Swan"');
push(@picture_role, '"The Fighter"');
push(@picture_role, '"Inception"');
push(@picture_role, '"The Kids Are All Right"');
push(@picture_role, '"The King\'s Speech"');
push(@picture_role, '"127 Hours"');
push(@picture_role, '"The Social Network"');
push(@picture_role, '"Toy Story 3"');
push(@picture_role, '"True Grit"');
push(@picture_role, '"Winter\'s Bone"');
push(@picture_role, '"'.'Write In'.'"');

$counter = 0;
foreach (@picture_role)
{
        print '         ['.$counter++.'] '.$_."\n";
}

$input = -1;
while(($input < 0) || ($input > $#picture_role))
{
        print "\n".'Please enter your choice for Best Picture now: ';
        chomp ($input = <>);
	if($input < 0 || ($input > $#picture_role))
	{
		print'I\'m sorry, but '.$input.' is not a valid option.';
	}
	else
	{
        	push(@results, $picture_role[$input]);
	}
}
print'Thank you for selecting '.$results[7].' as Best Picture.';

print $hr;


print"\n".'Thank you for voting.  Here is a summary of your votes:'."\n\n";
print'Actor in a Leading Role :'."\n";
print '        '.$results[0]."\n\n";
print'Actor in a Supporting Role :'."\n";
print '        '.$results[1]."\n\n";
print'Actress in a Leading Role :'."\n";
print '        '.$results[2]."\n\n";
print'Animated Feature Film :'."\n";
print '        '.$results[3]."\n\n";
print'Cinematography :'."\n";
print '        '.$results[4]."\n\n";
print'Directing :'."\n";
print '        '.$results[5]."\n\n";
print'Music (Original Song):'."\n";
print '        '.$results[6]."\n\n";
print'Best Picture :'."\n";
print '        '.$results[7]."\n\n";
