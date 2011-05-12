/*Thomas Cross*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void compile(int *);
void execute(int *);
void printState(int, int, int, int, int, int *);

/*
This was a fun 8 hour assignment.  If you can't tell by now, I <3 malloc.

*/
int main()
{
    int *m = (int *)malloc(100 * sizeof(int));
    compile(m);
    execute(m);

    free(m);
    return 0;
}

/*
function execute runs the compiled program living in &m - &m+100
I could go into great depth but I would just be re-writing the
assignment.
*/
void execute(int *m)
{
    int accu = 0;
    int pc = 0;
    int ir = 0;
    int opcode = 0;
    int operand = 0;

    stdin = fopen("/dev/tty", "r");

    while(opcode != 99)
    {
        ir = m[pc];
        opcode = ir / 100;
        operand = ir % 100;

        /*printf("Debug: %d %d %d\n", ir, opcode, operand);*/
        switch(opcode)
        {
            case 10:
            {
                if(operand > 99)
                {
                    fprintf(stderr, "Segmentation Fault: %d\n", operand);
                    exit(1);
                }
                scanf("%d", &m[operand]);
                ++pc;
                if(m[operand] > 9999)
                {
                    fprintf(stderr, "Word Overflow: %d\n", m[operand]);
                    exit(1);
                }
                break;
            }
            case 11:
            {
                if(operand > 99)
                {
                    fprintf(stderr, "Segmentation Fault: %d\n", operand);
                    exit(1);
                }
                printf("%d\n", m[operand]);
                ++pc;
                break;
            }
            case 12:
            {
                if(operand > 99)
                {
                    fprintf(stderr, "Segmentation Fault: %d\n", operand);
                    exit(1);
                }
                while(m[operand])
                {
					if((m[operand]/100) >= 65 || (m[operand]/100) <= 90 || (m[operand]%100) >= 65 || (m[operand]%100) <= 90 || (m[operand]/100) == 10 || (m[operand]%100) == 10)
					{
		                printf("%c%c", (m[operand]/100), (m[operand]%100));
		                ++operand;
					}
					else
					{
						fprintf(stderr, "Non-Printable Character.  Sorry.\n");
					}
                }
                ++pc;
                break;
            }
            case 20:
            {
                if(operand > 99)
                {
                    fprintf(stderr, "Segmentation Fault: %d\n", operand);
                    exit(1);
                }
                if(m[operand] > 9999)
                {
                    fprintf(stderr, "Word Overflow: %d\n", m[operand]);
                    exit(1);
                }
                accu = m[operand];
                ++pc;
                break;
            }
            case 21:
            {
                if(operand > 99)
                {
                    fprintf(stderr, "Segmentation Fault: %d\n", operand);
                    exit(1);
                }
                if(m[operand] > 9999)
                {
                    fprintf(stderr, "Word Overflow: %d\n", m[operand]);
                    exit(1);
                }
                m[operand] = accu;
                ++pc;
                break;
            }
            case 30:
            {
                if(operand > 99)
                {
                    fprintf(stderr, "Segmentation Fault: %d\n", operand);
                    exit(1);
                }
                if(m[operand] > 9999)
                {
                    fprintf(stderr, "Word Overflow: %d\n", m[operand]);
                    exit(1);
                }
                if(accu + m[operand] > 9999)
                {
                    fprintf(stderr, "Word Overflow: %d\n", m[operand]);
                    exit(1);
                }
                accu += m[operand];
                ++pc;
                break;
            }
            case 31:
            {
                if(operand > 99)
                {
                    fprintf(stderr, "Segmentation Fault: %d\n", operand);
                    exit(1);
                }
                if(m[operand] > 9999)
                {
                    fprintf(stderr, "Word Overflow: %d\n", m[operand]);
                    exit(1);
                }
                if(accu - m[operand] < -9999)
                {
                    fprintf(stderr, "Word Overflow: %d\n", m[operand]);
                    exit(1);
                }
                accu -= m[operand];
                ++pc;
                break;
            }
            case 32:
            {
                if(operand > 99)
                {
                    fprintf(stderr, "Segmentation Fault: %d\n", operand);
                    exit(1);
                }
                if(m[operand] > 9999)
                {
                    fprintf(stderr, "Word Overflow: %d\n", m[operand]);
                    exit(1);
                }
				if(!m[operand])
				{
					fprintf(stderr, "Divide by zero error: %d\n", m[operand]);
					exit(1);
				}
                if(accu / m[operand] < -9999 || accu / m[operand] > 9999)
                {
                    fprintf(stderr, "Word Overflow: %d\n", m[operand]);
                    exit(1);
                }
                accu /= m[operand];
                ++pc;
                break;
            }
            case 33:
            {
                if(operand > 99)
                {
                    fprintf(stderr, "Segmentation Fault: %d\n", operand);
                    exit(1);
                }
                if(m[operand] > 9999)
                {
                    fprintf(stderr, "Word Overflow: %d\n", m[operand]);
                    exit(1);
                }
                if(accu * m[operand] < -9999 || accu * m[operand] < 9999)
                {
                    fprintf(stderr, "Word Overflow: %d\n", m[operand]);
                    exit(1);
                }
                accu *= m[operand];
                ++pc;
                break;
            }
            case 34:
            {
                if(operand > 99)
                {
                    fprintf(stderr, "Segmentation Fault: %d\n", operand);
                    exit(1);
                }
                if(m[operand] > 9999)
                {
                    fprintf(stderr, "Word Overflow: %d\n", m[operand]);
                    exit(1);
                }
                if(accu % m[operand] < -9999 || accu % m[operand] > 9999)
                {
                    fprintf(stderr, "Word Overflow: %d\n", m[operand]);
                    exit(1);
                }
                accu %= m[operand];
                ++pc;
                break;
            }
            case 40:
            {
                if(operand > 99)
                {
                    fprintf(stderr, "Segmentation Fault: %d\n", operand);
                    exit(1);
                }
                if(m[operand] > 9999)
                {
                    fprintf(stderr, "Word Overflow: %d\n", m[operand]);
                    exit(1);
                }
                pc = operand;
                break;
            }
            case 41:
            {
                if(operand > 99)
                {
                    fprintf(stderr, "Segmentation Fault: %d\n", operand);
                    exit(1);
                }
                if(m[operand] > 9999)
                {
                    fprintf(stderr, "Word Overflow: %d\n", m[operand]);
                    exit(1);
                }
                if(accu < 0)
                {
                    pc = operand;
                }
                else
                {
                    ++pc;
                }
                break;
            }
            case 42:
            {
                if(operand > 99)
                {
                    fprintf(stderr, "Segmentation Fault: %d\n", operand);
                    exit(1);
                }
                if(m[operand] > 9999)
                {
                    fprintf(stderr, "Word Overflow: %d\n", m[operand]);
                    exit(1);
                }
                if(!accu)
                {
                    pc = operand;
                }
                else
                {
                    ++pc;
                }
                break;
            }            
            case 99:
            {
                opcode = 99;
                printState(accu, pc, ir, opcode, operand, m);
                break;
            }
            default:
            {
                fprintf(stderr, "Unknown Command: %d\n", opcode);
                exit(1);
                break;
            }
        }
    }


}

/*
Compile reads a file in using fgets and converts it from assembly to opcodes.
Durring this pocess I add it to the array generated in main called "m".
*/
void compile(int *m)
{
    char *line = (char *)malloc(100 * sizeof(char));
    int addr, operand;
    char *inst;
    char temp[5];
    int halt_flag = 0;


    while((fgets(line, 100, stdin)) != NULL )
    {
        sscanf(strtok(line," "), "%d", &addr);
        inst = strtok(NULL," ");
        operand = atoi(strtok(NULL, " "));
        /*sscanf(strtok(NULL, " "),"%d", &operand);*/

        if(strcmp(inst, "READ") == 0)
        {
            if(addr > 99 || strlen(inst) > 4 || operand > 9999)
            {
                fprintf(stderr, "Undefined use: %d  %s  %d", addr, inst, operand);
                printf("\n");
                exit(1);
            }
            sprintf(temp, "10%02d", operand);
            if(strlen(temp) < 5)
            {
                m[addr] = atoi(temp);
            }
            else
            {
                fprintf(stderr, "Word Overflow: %s\n", temp);
                exit(1);
            }
        }
        else if(strcmp(inst, "WRIT") == 0)
        {

            if(addr > 99 || strlen(inst) > 4 || operand > 9999)
            {
                fprintf(stderr, "Undefined use: %d  %s  %d", addr, inst, operand);
                printf("\n");
                exit(1);
            }
            sprintf(temp, "11%02d", operand);
            if(strlen(temp) < 5)
            {
                m[addr] = atoi(temp);
            }
            else
            {
                fprintf(stderr, "Word Overflow: %s\n", temp);
                exit(1);
            }
        }
        else if(strcmp(inst, "PRNT") == 0)
        {

            if(addr > 99 || strlen(inst) > 4 || operand > 9999)
            {
                fprintf(stderr, "Undefined use: %d  %s  %d", addr, inst, operand);
                printf("\n");
                exit(1);
            }
            sprintf(temp, "12%02d", operand);
            if(strlen(temp) < 5)
            {
                m[addr] = atoi(temp);
            }
            else
            {
                fprintf(stderr, "Word Overflow: %s\n", temp);
                exit(1);
            }
        }
        else if(strcmp(inst, "LOAD") == 0)
        {
            if(addr > 99 || strlen(inst) > 4 || operand > 9999)
            {
                fprintf(stderr, "Undefined use: %d  %s  %d", addr, inst, operand);
                printf("\n");
                exit(1);
            }
            sprintf(temp, "20%02d", operand);
            if(strlen(temp) < 5)
            {
                m[addr] = atoi(temp);
            }
            else
            {
                fprintf(stderr, "Word Overflow: %s\n", temp);
                exit(1);
            }
        }
        else if(strcmp(inst, "STOR") == 0)
        {
            if(addr > 99 || strlen(inst) > 4 || operand > 9999)
            {
                fprintf(stderr, "Undefined use: %d  %s  %d", addr, inst, operand);
                printf("\n");
                exit(1);
            }
            sprintf(temp, "21%02d", operand);
            if(strlen(temp) < 5)
            {
                m[addr] = atoi(temp);
            }
            else
            {
                fprintf(stderr, "Word Overflow: %s\n", temp);
                exit(1);
            }
        }
        else if(strcmp(inst, "SET") == 0)
        {
            if(addr > 99 || strlen(inst) > 4 || operand > 9999)
            {
                fprintf(stderr, "Undefined use: %d  %s  %d", addr, inst, operand);
                printf("\n");
                exit(1);
            }
            sprintf(temp, "%04d", operand);
            if(strlen(temp) < 5 && atoi(temp) < 10000)
            {
                m[addr] = atoi(temp);
            }
            else
            {
                fprintf(stderr, "Word Overflow: %s\n", temp);
                exit(1);
            }
        }
        else if(strcmp(inst, "ADD") == 0)
        {
            if(addr > 99 || strlen(inst) > 4 || operand > 9999)
            {
                fprintf(stderr, "Undefined use: %d  %s  %d", addr, inst, operand);
                printf("\n");
                exit(1);
            }
            sprintf(temp, "30%02d", operand);
            if(strlen(temp) < 5)
            {
                m[addr] = atoi(temp);
            }
            else
            {
                fprintf(stderr, "Word Overflow: %s\n", temp);
                exit(1);
            }
        }
        else if(strcmp(inst, "SUB") == 0)
        {

            if(addr > 99 || strlen(inst) > 4 || operand > 9999)
            {
                fprintf(stderr, "Undefined use: %d  %s  %d", addr, inst, operand);
                printf("\n");
                exit(1);
            }
            sprintf(temp, "31%02d", operand);
            if(strlen(temp) < 5)
            {
                m[addr] = atoi(temp);
            }
            else
            {
                fprintf(stderr, "Word Overflow: %s\n", temp);
                exit(1);
            }
        }
        else if(strcmp(inst, "DIV") == 0)
        {
            if(addr > 99 || strlen(inst) > 4 || operand > 9999)
            {
                fprintf(stderr, "Undefined use: %d  %s  %d", addr, inst, operand);
                printf("\n");
                exit(1);
            }
            sprintf(temp, "32%02d", operand);
            if(strlen(temp) < 5)
            {
                m[addr] = atoi(temp);
            }
            else
            {
                fprintf(stderr, "Word Overflow: %s\n", temp);
                exit(1);
            }
        }
        else if(strcmp(inst, "MULT") == 0)
        {
            if(addr > 99 || strlen(inst) > 4 || operand > 9999)
            {
                fprintf(stderr, "Undefined use: %d  %s  %d", addr, inst, operand);
                printf("\n");
                exit(1);
            }
            sprintf(temp, "33%02d", operand);
            if(strlen(temp) < 5)
            {
                m[addr] = atoi(temp);
            }
            else
            {
                fprintf(stderr, "Word Overflow: %s\n", temp);
                exit(1);
            }
        }
        else if(strcmp(inst, "MOD") == 0)
        {
            if(addr > 99 || strlen(inst) > 4 || operand > 9999)
            {
                fprintf(stderr, "Undefined use: %d  %s  %d", addr, inst, operand);
                printf("\n");
                exit(1);
            }
            sprintf(temp, "34%02d", operand);
            if(strlen(temp) < 5)
            {
                m[addr] = atoi(temp);
            }
            else
            {
                fprintf(stderr, "Word Overflow: %s\n", temp);
                exit(1);
            }
        }
        else if(strcmp(inst, "BRAN") == 0)
        {
            if(addr > 99 || strlen(inst) > 4 || operand > 9999)
            {
                fprintf(stderr, "Undefined use: %d  %s  %d", addr, inst, operand);
                printf("\n");
                exit(1);
            }
            sprintf(temp, "40%02d", operand);
            if(strlen(temp) < 5)
            {
                m[addr] = atoi(temp);
            }
            else
            {
                fprintf(stderr, "Word Overflow: %s\n", temp);
                exit(1);
            }
        }
        else if(strcmp(inst, "BRNG") == 0)
        {
            if(addr > 99 || strlen(inst) > 4 || operand > 9999)
            {
                fprintf(stderr, "Undefined use: %d  %s  %d", addr, inst, operand);
                printf("\n");
                exit(1);
            }
            sprintf(temp, "41%02d", operand);
            if(strlen(temp) < 5)
            {
                m[addr] = atoi(temp);
            }
            else
            {
                fprintf(stderr, "Word Overflow: %s\n", temp);
                exit(1);
            }
        }
        else if(strcmp(inst, "BRZR") == 0)
        {
            if(addr > 99 || strlen(inst) > 4 || operand > 9999)
            {
                fprintf(stderr, "Undefined use: %d  %s  %d", addr, inst, operand);
                printf("\n");
                exit(1);
            }
            sprintf(temp, "42%02d", operand);
            if(strlen(temp) < 5)
            {
                m[addr] = atoi(temp);
            }
            else
            {
                fprintf(stderr, "Word Overflow: %s\n", temp);
                exit(1);
            }
        }
        else if(strcmp(inst, "HALT") == 0)
        {
            if(addr > 99 || strlen(inst) > 4 || operand > 9999)
            {
                fprintf(stderr, "Undefined use: %d  %s  %d", addr, inst, operand);
                printf("\n");
                exit(1);
            }
            sprintf(temp, "99%02d", operand);
            if(strlen(temp) < 5)
            {
                m[addr] = atoi(temp);
            }
            else
            {
                fprintf(stderr, "Word Overflow: %s\n", temp);
                exit(1);
            }
            halt_flag = 1;
        }
        else
        {
            fprintf(stderr, "Unrecognized command word, they are case sensitive\n");
            exit(1);
        }
    }
    free(line);
    if(!halt_flag)
    {
        fprintf(stderr, "No HALT given.\n");
        exit(1);
    }
}


/*
Print state takes all the paramaters required to print the 
"computers" state on exit.  So it takes the accumulator, program
counter, instruction register, opcode, operand and the computers memory, m.
*/
void printState(int accu, int pc, int ir, int opcode, int operand, int *m)
{
    int n;
    printf("REGISTERS:\n");
    printf("accumulator                %+05d\n", accu);
    printf("instructionCounter            %02d\n", pc);
    printf("instructionRegister        %+04d\n", ir);
    printf("operatoinCode                 %02d\n", opcode);
    printf("operand                       %02d\n", operand);
    printf("MEMORY:\n");

    for(n = 0; n < 10; ++n)
    {
        if(!n)
            printf("% 9d", n);
        else
            printf("% 6d", n);
    }
    for(n = 0; n < 100; ++n)
    {
        if(n % 10 == 0)
        {
            printf("\n% 3d", n);
        }
        printf(" %+05d", m[n]);
    }
    printf("\n");
}

