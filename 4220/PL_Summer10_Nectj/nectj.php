<?php
//Write
//Read
//if

function tokenizer($line, &$token_array)
{
        $line = preg_replace('/^[ \t]+/','',$line);
        //$line = strtolower($line);
        //echo $line;

        //Destroy Comments
        if(preg_match('/\/\/.*/', $line, $matches))
        {
        }

        //Tokenize Functions
        else if(preg_match('/^func( )*[a-zA-Z]+\((( )*.*[a-zA-Z]*,* )*\)/i', $line, $matches))
        {
                $tok = strtok($matches[0], " \n\t");

                while ($tok !== false)
                {
                        if(preg_match('/.*[a-zA-Z]*\(\)/',$tok))
                        {
                                $token_array[] = strtolower(substr($tok, 0, (strlen($tok)-2)));
                                $token_array[] = strtolower(substr($tok,(strlen($tok)-2),1));
                                $token_array[] = strtolower(substr($tok,(strlen($tok)-1),1));

                        }
                        else if(preg_match('/.*[a-zA-Z]*\(/',$tok))
                        {
                                $token_array[] = strtolower(substr($tok,0, (strlen($tok)-1)));
                                $token_array[] = strtolower(substr($tok,(strlen($tok)-1),1));

                        }
                        else if(preg_match('/.*[a-zA-Z]*,/',$tok))
                        {
                                $token_array[] = strtolower(substr($tok,0, (strlen($tok)-1)));
                        }
                        else
                                $token_array[] = strtolower($tok);
                        $tok = strtok(" \n\t");
                }
        }

        //Call Function
        else if(preg_match('/^(?!(( )*func|( )*eq|( )*ge|( )*if|( )*write|( )*read))( )*[0-9a-zA-Z]+\((( )*[0-9a-zA-Z]*,*( )*)*\)/i', $line, $matches))
        {
                $tok = strtok($matches[0], " \n\t");

                while ($tok !== false)
                {
                        if(preg_match('/.*[a-zA-Z]*\(\)/',$tok))
                        {
                                $token_array[] = strtolower(substr($tok, 0, (strlen($tok)-2)));
                                $token_array[] = strtolower(substr($tok,(strlen($tok)-2),1));
                                $token_array[] = strtolower(substr($tok,(strlen($tok)-1),1));

                        }
                        else if(preg_match('/.*[a-zA-Z]*\(/',$tok))
                        {
                                $token_array[] = strtolower(substr($tok,0, (strlen($tok)-1)));
                                $token_array[] = strtolower(substr($tok,(strlen($tok)-1),1));

                        }
                        else if(preg_match('/.*[a-zA-Z]*,/',$tok))
                        {
                                $token_array[] = strtolower(substr($tok,0, (strlen($tok)-1)));
                        }
                        else
                                $token_array[] = strtolower($tok);
                        $tok = strtok(" \n\t");
                }
                if(preg_match('/;/',$line,$matches))
                        $token_array[] = ';';

        }
        //(
        else if(preg_match('/^\(/', $line, $matches))
        {
                //echo 'In Here!';
                $token_array[] = '(';
                $line = preg_replace('/^[(]/', '',$line);
                                tokenizer($line, $token_array);
                                }
                                //)
        else if(preg_match('/^\)/', $line, $matches))
        {
                $token_array[] = ')';
                $line = preg_replace('/^\)/', '',$line);
                tokenizer($line,$token_array);
        }
        //again:
        else if(preg_match('/^again:.*/', $line, $matches))
        {
                $token_array[] = 'again:';
                $line = preg_replace('/^again:/', '', $line);
                tokenizer($line, $token_array);
        }

        //If
        else if(preg_match('/[ ]*if[ ]*[(]+.*[)]+/i', $line, $matches))
        {
                $token_array[] = 'if';
                $line = preg_replace('/^[ ]*if/i', '', $line);
                tokenizer($line, $token_array);
        }
        //GE
        else if(preg_match('/ge[ ]*\(.+/i', $line, $matches))
        {
                $token_array[] = 'ge';
                $line = preg_replace('/^ge/i', '', $line);
                tokenizer($line, $token_array);
        }
        //EQ
        else if(preg_match('/eq[ ]*\(.+\)/i', $line, $matches))
        {
                $token_array[] = 'eq';
                $line = preg_replace('/^eq/i', '', $line);
                tokenizer($line, $token_array);
        }

        //NE
        else if(preg_match('/ne[ ]*\(.+\)/i', $line, $matches))
        {
                $token_array[] = 'ne';
                $line = preg_replace('/^ne/i', '', $line);
                tokenizer($line, $token_array);
        }

        //LT
        else if(preg_match('/lt[ ]*\(.+\)/i', $line, $matches))
        {
                $token_array[] = 'lt';
                $line = preg_replace('/^lt/i', '', $line);
                tokenizer($line, $token_array);
        }

        //LE
        else if(preg_match('/le[ ]*\(.+\)/i', $line, $matches))
        {
                $token_array[] = 'le';
                $line = preg_replace('/^le/i', '', $line);
                tokenizer($line, $token_array);
        }

        //GE
        else if(preg_match('/gt[ ]*\(.+\)/i', $line, $matches))
        {
                $token_array[] = 'gt';
                $line = preg_replace('/^gt/i', '', $line);
                tokenizer($line, $token_array);
        }

        //endit:
        else if(preg_match('/^endit:/', $line, $matches))
        {
                $token_array[] = 'endit:';
                $line = preg_replace('/endit:/', '', $line);
                tokenizer($line, $token_array);
        }

        //to endit:
        else if(preg_match('/^to endit;.*/', $line, $matches))
        {
                $token_array[] = 'to endit';
                $line = preg_replace('/to endit;/', '', $line);
                tokenizer($line, $token_array);
        }

        //to again:
        else if(preg_match('/^to again;.*/', $line, $matches))
        {
                $token_array[] = 'to again';
                $line = preg_replace('/to again;/', '', $line);
                tokenizer($line, $token_array);
        }

        //Write String
        else if(preg_match('/(write|Write)\(( )*".*"( )*\)/i', $line, $matches))
        {
                $token_array[] = 'writes';
                preg_match('/".*"/',$line,$matches_temp);
                $token_array[] = trim($matches_temp[0], '"');
        }

        //Write Var
        else if(preg_match('/(write|Write)\(( )*.*( )*\)/i', $line, $matches))
        {
                $token_array[] = 'writev';
                preg_match('/\(( )*.*( )*\)/',$line,$matches_temp);
                $token_array[] = trim($matches_temp[0], '() ');
        }

        //Read
        else if(preg_match('/(read|Read)\(( )*.*( )*\)/i', $line, $matches))
        {
                $token_array[] = 'read';
                preg_match('/\(( )*.*( )*\)/',$line,$matches_temp);
                $token_array[] = trim($matches_temp[0], '() ');
        }

        //Tokenize Assignment with Function
        else if(preg_match('/.*= [0-9a-zA-Z ]+\(.*\).*/',$line,$matches))
        {
                $token_array[] = '=';
                preg_match('/[ ]*.*[ ]*=/',$line,$matches_temp);
                $token_array[] = trim($matches_temp[0], '= ');
                $line = preg_replace('/.*=/', '', $line);
                tokenizer($line, $token_array);
        }

        //Var = Something
        else if(preg_match('/[0-9a-zA-Z]+[ ]+=[ ]+[(0-9a-zA-Z]+[ ]*/',$line, $matches))
                        {
                        $token_array[] = '=';
                        preg_match('/[ ]*.*[ ]*=/', $line, $matches_temp);
                        $token_array[] = trim($matches_temp[0], '= ');
                        preg_match('/=.*/',$line,$matches_temp);
                        $line = preg_replace('/.*=/', '', $line);
                        tokenizer($line, $token_array);
                        //$token_array[] = trim($matches_temp[0], '= ;');
                        }
                        //Something after an =
                        else if(preg_match('/=[ ]*[0-9a-zA-Z]+/',$line,$matches))
                        {
                        $token_array[] = trim($matches[0], '= ');
                        $line = preg_replace('/^.*=/', '',$line);
                        tokenizer($line, $token_array);
                        }

                        //MATH_HP MULT
                        else if(preg_match('/^[*][ ]+[0-9a-zA-Z]+/',$line,$matches))
                        {
                                $token_array[] = '*';
                                $line = preg_replace('/^[*]/', '',$line);
                                //preg_match('/[ ]*.*[ ]*[*]/',$line,$matches_temp);
                                //$token_array[] = ($matches_temp[0]);
                                tokenizer($line, $token_array);
                                //preg_match('/=.*/',$line,$matches_temp);
                        }

        //MATH_HP DIV
        else if(preg_match('/^\/[ ]+[0-9a-zA-Z]+/',$line,$matches))
        {
                $token_array[] = '/';
                $line = preg_replace('/^\//', '',$line);
                tokenizer($line, $token_array);
                //preg_match('/[ ]*.*[ ]*\//',$line,$matches_temp);
                //$token_array[] = ($matches_temp[0]);
                //echo 'this is what we got '.$matches_temp[0];
                //preg_match('/=.*/',$line,$matches_temp);
        }

        //MATH_HP DIV
        else if(preg_match('/^%[ ]+[0-9a-zA-Z]+/',$line,$matches))
        {
                $token_array[] = '/';
                $line = preg_replace('/^%/', '',$line);
                tokenizer($line, $token_array);
                //preg_match('/[ ]*.*[ ]*\//',$line,$matches_temp);
                //$token_array[] = ($matches_temp[0]);
                //echo 'this is what we got '.$matches_temp[0];
                //preg_match('/=.*/',$line,$matches_temp);
        }

        //MATH_LP ADD
        else if(preg_match('/^(\\+)[ ]+[(0-9a-zA-Z]+/',$line,$matches))
                        {
                        $token_array[] = '+';
                        $line = preg_replace('/^(\\+)/', '',$line);
                        tokenizer($line, $token_array);
                        //preg_match('/[ ]*.*[ ]*[+]/',$line,$matches_temp);
                        //$token_array[] = ($matches_temp[0]);
                        //echo 'this is what we got plus '.$matches_temp[0];
                        //preg_match('/=.*/',$line,$matches_temp);
                        }

                        //MATH_LP MINUS
                        else if(preg_match('/^[-][ ]+[0-9a-zA-Z]+/',$line,$matches))
                        {
                        $token_array[] = '-';
                        $line = preg_replace('/^[-]/', '',$line);
                        tokenizer($line, $token_array);
                        //preg_match('/[ ]*.*[ ]*[-]/',$line,$matches_temp);
                        //$token_array[] = ($matches_temp[0]);
                        //echo 'this is what we got minus '.$matches_temp[0];
                        //preg_match('/=.*/',$line,$matches_temp);
                        }

        //Number or variable
        else if(preg_match('/^([ ]*[0-9a-zA-Z])+[ ]*/', $line, $matches))
        {
                preg_match('/^(\b[0-9a-zA-Z]+)/', $line, $matches_temp);
                $token_array[] = strtolower(trim($matches_temp[0],' ;'));
                $line = preg_replace('/^'.$matches_temp[0].'/', '',$line);
                tokenizer($line, $token_array);
        }
        else if(preg_match('/^,/', $line, $matches))
        {
                $token_array[] = ',';
                $line = preg_replace('/^,/', '',$line);
                tokenizer($line, $token_array);
        }
        else if(preg_match('/^[ ]*;[ ]*/', $line, $matches))
        {
                $token_array[] = ';';
                $line = preg_replace('/^;/', '',$line);
                tokenizer($line, $token_array);
        }
        else
        {
                //echo 'Default '.$line."\n";

        }
}

$token_array = array();
$file_handle = fopen($argv[1], 'r');
while (!feof($file_handle)) 
{
        $line = fgets($file_handle);
        tokenizer($line, $token_array);
}

fclose($file_handle);
echo"Tokenized Array:\n";
print_r($token_array);

$symbol_table = array( 
                'func' => 'function', 
                'endfunc' => '}', 
                'read' => 'trim(fgets(STDIN));', 
                'writes' => 'echo', 
                'writev' => 'echo',
                'to endit' => 'goto endit;',
                'to again' => 'goto again;',
                'true' => 'true',
                'if' => 'if',
                'eq' => '==', 
                'ne' => '!=', 
                'true' => 'true',
                'endit:' => 'endit:',
                'again:' => 'again:',
                '=' => '=',
                '(' => '(',
                ')' => ')',
                'lt' => '<', 
                'le' => '<=', 
                'gt' => '>',
                'ge' => '>=',
                '*' => '*',
                '/' => '/',
                '%' => '%',
                '+' => '+',
                '-' => '-',
                ',' => ',',
                ';' => ';'
                );

function getSymbol($token, &$symbol_table)
{
        $retval = false;
        foreach($symbol_table as $symbol => $value)
        {
                if($token == $symbol)
                {
                        $retval = $value;
                }
        }
        return $retval;
}

function parser(&$token_array, &$symbol_table, $token, $value)
{
        if($token == 'func')
        {
                echo $value.' ';
                list($number, $token) = each($token_array);
                echo $token;
                $symbol_table[$token] = $token;
                list($number, $token) = each($token_array);
                echo $token;
                while(list($number, $token) = each($token_array))
                {
                        list($number2, $next_token) = each($token_array);
                        if($token == ')')
                        {
                                echo $token.' '.'{ ';
                                prev($token_array);
                                break;
                        }
                        else if($next_token == ')')
                        {
                                echo '$'.$token.$next_token.'{ ';
                                break;
                        }
                        else 
                        {
                                echo '$'.$token.', ';
                                prev($token_array);
                        }
                }
        }
                else if($token == '=')
                {
                        list($number, $next_token) = each($token_array);
                        echo '$'.strtolower($next_token).' '.$value.' ';
                }
                else if($token == 'if')
                {
                        echo $value.' ';
                }
                else if($token == '(')
                {
                        echo $value.' ';
                }
                else if($token == ')')
                {
                        echo $value.' ';
                }
                else if($token == 'eq')
                {
                        echo 'eq ';
                }
                else if($token == 'ne')
                {
                        echo 'ne ';
                }
                else if($token == 'ge')
                {
                        echo 'ge ';
                }
                else if($token == 'le')
                {
                        echo 'le ';
                }
                else if($token == 'gt')
                {
                        echo 'gt ';
                }
                else if($token == 'lt')
                {
                        echo 'lt ';
                }
                else if($token == ',')
                {
                        echo $value.' ';
                }
                else if($token == 'writes')
                {
                        list($number, $next_token) = each($token_array);
                        echo $value."'".$next_token."'; ";
                }
                else if($token == 'writev')
                {
                        list($number, $next_token) = each($token_array);
                        echo $value." $".strtolower($next_token)."; ";
                }
                else if($token == 'read')
                {
                        list($number, $next_token) = each($token_array);
                        echo '$'.strtolower($next_token).' = '.$value.' ';
                }
                else if($token == 'to endit')
                {
                        echo $value.' ';
                }
                else if($token == 'to again')
                {
                        echo $value.' ';
                }
                else if($token == 'again:')
                {
                        echo $value.' ';
                }
                else if($token == 'endit:')
                {
                        echo $value.' ';
                }
                else if($token == 'true')
                {
                        echo $value.' ';
                }
                else if($token == '/')
                {
                        echo $value.' ';
                }
                else if($token == '%')
                {
                        echo $value.' ';
                }
                else if($token == '*')
                {
                        echo $value.' ';
                }
                else if($token == '+')
                {
                        echo $value.' ';
                }
                else if($token == '-')
                {
                        echo $value.' ';
                }
                else if($token == ';')
                {
                        echo $value.' ';
                }
                else if($token == 'endfunc')
                {
                        echo $value.' ';
                }
                else if($value === false)
                {
                        if(is_numeric($token))
                        {
                                echo strtolower($token).' ';
                        }
                        else if(ctype_alnum($token))
                        {
                                echo '$'.strtolower($token).' ';
                        }
                }
                else
                {
                        //echo 'Default '.$token."\n";
                        echo $token.' ';
                }


                //Recursion and Regular Expressions :) Thanks for the practice!
                if(list($number, $token) = each($token_array))
                {
                        $value = getSymbol($token, $symbol_table);
                        parser($token_array, $symbol_table, $token, $value);
                }

}
        echo'<?php
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
        ';
        if(list($number, $token) = each($token_array))
        {
                $value = getSymbol($token, $symbol_table);
                parser($token_array, $symbol_table, $token, $value);
        }

        echo "?>\n";


        ?>
