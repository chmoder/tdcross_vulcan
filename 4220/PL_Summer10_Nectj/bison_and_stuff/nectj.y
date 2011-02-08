/* Not Even Close To Java */
%{
#include <stdio.h>
#include <math.h>
%}

%%
program:        function program
        ;
function:       FUNC IDENTIFIER '('params')' slist ENDFUNC
        ;
params:
%%
          

