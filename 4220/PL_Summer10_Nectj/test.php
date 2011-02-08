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
        function sqrt2($num)
        { 
                $n = 0; 
                if(eq($num , $n)) 
                {
goto endit; 
                }
                $n1 = ( $n + ( $num / $n ) ) / 2 ; 
                again: if ( ge ( $n1 , $n ) ) 
                        goto endit;

                $n = $n1 ; 
                $n1 = ( $n + ( $num / $n ) ) / 2 ; 
                if ( true ) 
                goto again; 
                endit: 
                $sqrt = $n ; 
        }
        
        function main() 
        {
                echo'enter a number:'; $x = trim(fgets(STDIN)); 
                $s = sqrt ( $x ) ; 
                echo'the sqrt is:'; 
                echo $s; 
        } 
?>

