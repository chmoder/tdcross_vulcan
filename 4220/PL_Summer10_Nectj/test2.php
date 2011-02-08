<?php
                function eq($variablex, $variabley)
                {
                        if($variablex == $variabley)
                                return true;
                        else
                                return false;
                }
                function ge($variablex, $variabley)
                {
                        if($variablex >= $variabley)
                                return true;
                        else
                                return false;
                }
                function le($variablex, $variabley)
                {
                        if($variablex <= $variabley)
                                return true;
                        else
                                return false;
                }
                function gt($variablex, $variabley)
                {
                        if($variablex > $variabley)
                                return true;
                        else
                                return false;
                }
                function lt($variablex, $variabley)
                {
                        if($variablex < $variabley)
                                return true;
                        else
                                return false;
                }
                function ne($variablex, $variabley)
                {
                        if($variablex != $variabley)
                                return true;
                        else
                                return false;
                }
        function sqrt2($num)
{ 
$n = 0 ; 
if ( eq ( $num , $n ) )
$n1 = ( $n + ( $num / $n ) ) / 2 ;
if ( ge ( $n1 , $n ) ) 
$n = $n1 ; $n1 = ( $n + ( $num / $n ) ) / 2 ; 
if ( true ) 
$sqrt = $n ; 
} 
function main() 
{ 
echo'enter a number:'; 
$x = trim(fgets(STDIN)); 
$s = sqrt2 ( $x ) ; echo'the sqrt is:'; 
echo $s; } 
?>

