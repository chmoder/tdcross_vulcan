/*Filename prog3.c*/
/*Thomas Cross*/
#include<stdio.h>
#include<stdlib.h>
#include <math.h>

void opt(int, int, int, int*, double*);
void fifo(int, int, int, int*, double*);
void lru(int, int, int, int*, double*);
int inFrameArr(int, int, int, int, int*);
int inFrameArrLru(int, int, int, int, int*);
int returnEmptyFrame(int, int, int, int*);
void makeOlder(int*, int);
int findOldest(int*, int);
void zeroArray(int*, int);
double sqr(double);
double rnorm(void);
double rnormms(double, double);


int main(int argc, char *argv[])
{
    int NF, NP, NR, S, M, SD;
    int case_counter = 0;

    while(scanf("%d", &NF) && NF != 0)
    {
        printf("Case %d.\n", ++case_counter);
        //scanf("%d", &NF);
        if(NF < 1 || NF > 30)
        {
            printf("Please enter the number of page frames a process is allowed to use between 1 and 30\n");
        }
        scanf("%d", &NP);
        if(NP < 1 || NF > 300)
        {
            printf("Please enter the number of pages in the process between 1 and 300\n");
        }
        scanf("%d", &NR);
        if(NR < 1 || NR > 5000)
        {
            printf("Please enter the length of the reference string between 1 and 5000\n");
        }
        int ref_str[NR];
        scanf("%d", &S);
        if(S == 0)
        {
            int i = 0;
            for(i = 0; i < NR; ++i)
            {
                scanf("%d", &ref_str[i]);
            }
        }
        else
        {
            srand(S);
            scanf("%d", &M);
            scanf("%d", &SD);
            int i = 0;
            for(i = 0; i < NR; ++i)
            {
                int pagenum = rnormms(M, SD);
                if(pagenum < 1 || pagenum > NP)
                {
                    --i;
                }
                else
                {
                    ref_str[i] = pagenum;
                }
            }
        }


        double ret_arr[2];
        opt(NF, NP, NR, ref_str, ret_arr);
        printf("    OPT: %1.0f faults, fault rate = %1.4f\n", ret_arr[0], ret_arr[1]);
        fifo(NF, NP, NR, ref_str, ret_arr);
        printf("    FIFO: %1.0f faults, fault rate = %1.4f\n", ret_arr[0], ret_arr[1]);
        lru(NF, NP, NR, ref_str, ret_arr);
        printf("    LRU: %1.0f faults, fault rate = %1.4f\n", ret_arr[0], ret_arr[1]);

        /*
        printf("NF = %d, NP = %d, NR = %d\n", NF, NP, NR);
        int i;
        for(i = 0; i < NR; ++i)
        {
            printf("%d ", ref_str[i]);
        }   
        printf("\n");
        */
    }

    return 0;
}
void opt(int NF, int NP, int NR, int* ref_str, double* ret_arr)
{

    ret_arr[0] = 0;
    int frame_arr[NF];
    
    zeroArray(frame_arr, NF);

    int i;
    for(i = 0; i < NR; ++i)
    {
        //Is this reference is allready in a PF?
        if(!inFrameArr(NF, NP, NR, ref_str[i], frame_arr))
        {
            //Does an empty frame exist?
            int empty_frame = returnEmptyFrame(NF, NP, NR, frame_arr);
            if(empty_frame != -1)
            {
                ++ret_arr[0];
                frame_arr[empty_frame] = ref_str[i];
            }
            else//Page Replacement
            {
                int rep_frame = -1;
                int distance = -1;
                int j;
                for(j = 0; j < NF; ++j)
                {
                    int temp_dist = -1;
                    int k;
                    for(k = i; k < NR; ++k)
                    {
                        if(frame_arr[j] == ref_str[k] && k - i > distance)
                        {
                            temp_dist = k - i;
                            distance = k - i;
                            rep_frame = j;
                            break;
                        }
                    }

                    if(distance == -1 || temp_dist == -1)
                    {
                        rep_frame = j;
                        break;
                    }
                }
                ++ret_arr[0];
                frame_arr[rep_frame] = ref_str[i];
            }
            /*
               printf("fram_arr:\n");
               int z;
               for(z = 0; z < NF; ++z)
               printf("%d ", frame_arr[z]);
               printf("\n"); 
             */
        }
    }
    ret_arr[1] = ret_arr[0] / NR;
}

void fifo(int NF, int NP, int NR, int* ref_str, double* ret_arr)
{
    ret_arr[0] = 0;
    int frame_arr[NF];
    zeroArray(frame_arr, NF);

    int fifo_count = 0;
    int i;
    for(i = 0; i < NR; ++i)
    {
        //Is this reference is allready in a PF?
        if(!inFrameArr(NF, NP, NR, ref_str[i], frame_arr))
        {
            //Does an empty frame exist?
            int empty_frame = returnEmptyFrame(NF, NP, NR, frame_arr);
            if(empty_frame != -1)
            {
                ++ret_arr[0];
                frame_arr[empty_frame] = ref_str[i];
            }
            else //Page Replacement
            {
                frame_arr[fifo_count % NF] = ref_str[i];
                ++fifo_count;
                ++ret_arr[0];
            }
        }
        /*
        printf("fram_arr:\n");
        int z;
        for(z = 0; z < NF; ++z)
            printf("%d ", frame_arr[z]);
        printf("\n"); 
        */
    }
    ret_arr[1] = ret_arr[0] / NR;
}

void lru(int NF, int NP, int NR, int* ref_str, double* ret_arr)
{
    ret_arr[0] = 0;
    int frame_arr[NF];
    int frame_arr_age[NF];
    zeroArray(frame_arr, NF);
    zeroArray(frame_arr_age, NF);

    int i;
    for(i = 0; i < NR; ++i)
    {
        //Is this reference allready in a PF?
        int existance_index = inFrameArrLru(NF, NP, NR, ref_str[i], frame_arr);
        if(existance_index == -1)
        {
            //Does an empty frame exist?
            int empty_frame = returnEmptyFrame(NF, NP, NR, frame_arr);
            if(empty_frame != -1)
            {
                ++ret_arr[0];
                frame_arr[empty_frame] = ref_str[i];
                makeOlder(frame_arr_age, NF);
                frame_arr_age[empty_frame] = 1;
            }
            else //Page Replacement
            {
                ++ret_arr[0];
                int oldest = findOldest(frame_arr_age, NF);
                frame_arr[oldest] = ref_str[i];
                makeOlder(frame_arr_age, NF);
                frame_arr_age[oldest] = 1;
            }
        }
        else//Does exist and we need to mark is as recently used
        {
            makeOlder(frame_arr_age, NF);
            frame_arr_age[existance_index] = 1;
        }
        /*
        printf("frame_arr_age:\n");
        int z;
        for(z = 0; z < NF; ++z)
            printf("%d ", frame_arr_age[z]);
        printf("\n"); 

        printf("frame_arr:\n");
        for(z = 0; z < NF; ++z)
            printf("%d ", frame_arr[z]);
        printf("\n"); 
        */
    }
    ret_arr[1] = ret_arr[0] / NR;
}

void makeOlder(int* frame_arr_age, int NF)
{
    int i;
    for(i = 0; i < NF; ++i)
    {
        if(frame_arr_age[i] != 0)
        {
            ++frame_arr_age[i];
        }
    }
}

int findOldest(int* frame_arr_age, int NF)
{
    int retval = 0;
    int oldest = 0;
    int i;
    for(i = 0; i < NF; ++i)
    {
        if(frame_arr_age[i] > oldest)
        {
            oldest = frame_arr_age[i];
            retval = i;
        }
    }
    return retval;
}

int inFrameArr(int NF, int NP, int NR, int query, int* frame_arr)
{
    int retval = 0;
    int i;
    for(i = 0; i < NF; ++i)
    {
        if(frame_arr[i] == query)
        {
            retval = 1;
        }
    }
    return retval;
}

int inFrameArrLru(int NF, int NP, int NR, int query, int* frame_arr)
{
    int retval = -1;
    int i;
    for(i = 0; i < NF; ++i)
    {
        if(frame_arr[i] == query)
        {
            retval = i;
            break;
        }
    }
    return retval;
}

int returnEmptyFrame(int NF, int NP, int NR, int *frame_arr)
{
    int retval = -1;
    int i;
    for(i = 0; i < NF; ++i)
    {
        if(frame_arr[i] == 0)
        {
            retval = i;
            break;
        }
    }
    return retval;
}

void zeroArray(int* arr, int NF)
{
    int i;
    for(i = 0; i < NF; ++i)
    {
        arr[i] = 0;
    }
}

double sqr(double x)
{
    return x * x;
}

double rnorm (void)
{
    double s = 0.449871;
    double t = -0.386595;
    double a = 0.19600;
    double b = 0.25472;
    double r1 = 0.27597;
    double r2 = 0.27846;
    double u, v, x, y, q;

    for(;;) {
        u = rand() / (double)RAND_MAX;		/* u in 0..1 */
        v = rand() / (double)RAND_MAX;		/* v in 0..1 */
        v = 1.7156 * (v - 0.5);

        /* Evaluate the quadratic form. */
        x = u - s;
        y = fabs(v) - t;
        q = sqr(x) + y * (a * y - b * x);

        /* Accept p if inside inner elipse */
        if (q < r1) break;
        if (q <= r2 && sqr(v) < -4.0 * log(u) * sqr(u)) break;
    }

    /* Return ratio of p's coordinates as the normal deviate. */
    return v / u;
}

double rnormms (double mean, double stdev)
{
    return rnorm() * stdev + mean;
}

