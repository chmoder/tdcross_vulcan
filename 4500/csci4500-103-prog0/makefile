# This is a sample makefile for the C programs used in CSCI 4500
# With this file and prunw.c in the current working directory, you
# can give the command
#
#	make
#
# to build the executable version of the program (which is named prunw).
#
# Before the submission date, use the command
#
#	make clean
#
# to remove the executable and any object files. The ONLY files that
# should present in the submission directory are this makefile and
# your modified version of prunw.c .
#
# These files will be copied to a separate machine running a 32-bit version
# of Centos-5 Linux (vulcan uses a 64-bit version of Linux), then the
# executable version of the program will be created using the makefile you
# provide, and executed using the instructor's test data.
#
# In particular, note that your executable program (if you should leave it
# in the directory) will NOT be used for grading purposes.
#
# Makefiles basically have two types of lines. The first type begin in the
# first column and contain the name of a "target" file, a colon, and a list
# of files on which the target is dependent. We can see from the first line
# below ("prunw: prunw.c") that the file prunw (the executable version of
# the program) is dependent on the file prunw.c. If prunw does not exist,
# but prunw.c does exist, then the make utility will cause the commands
# just below the dependency line to be executed, in order, to produce
# prunw. If prunw does exist, then make checks the last modification date/time
# of the dependencies. If any of them have a time later (after) that of
# prunw, then the target must be rebuilt, since one or more of the files on
# which it is dependent have changed.
#
# The second type of line is a command. An arbitrary number of these may
# appear after a dependency line, but each must begin with a tab character.
# These are executed in sequence to build the target file.
#
# Make is recursive, so after identifing a dependency file, it will check
# if it needs to be rebuilt by looking for a target: dependencies line with
# that file as the target. This probably will not be needed for any of the
# assignments for this course.
#
# Of course, the lines that begin with a sharp sign ('#') are treated as
# comments.

prunw: prunw.c
	cc -o prunw prunw.c

clean:
	rm -f prunw
	rm -f *.o
