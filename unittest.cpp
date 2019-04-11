//
//
//
//Author: Gordon Griesel
//Date: April 7, 2019
//Purpose: Framework for a coding exam
//
//See instructions on assignment web page to produce a unit-test
//for the vec_length function.
//
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//type defines
typedef double Flt;
typedef Flt Vec[3];

//prototype
Flt vec_length(Vec v);

//Array of vector values
const Flt arr[] = {
-3.77983,  -8.11711,
-6.19391,  -7.48675,
0.46671,    7.98604,
-3.78165,   9.45696,
-1.08659 , -4.13340,
-1.09663,  -4.13138,
-0.42783,  -3.57757,
9.33954,   -1.55691,
0.07000,    3.31899,
0.0, 0.0
};
const Flt data [] = { 
-0.42214, 	-0.90653, 	8.945631,
 -0.63744,  -0.77050, 	9.715759,
0.05834, 	0.99830, 	8.014661,
-0.37129, 	0.92852, 	10.200031,
-0.25424, 	-0.96714, 	4.269271,
-0.25655, 	-0.96653, 	4.273677,
-0.11874, 	-0.99293, 	3.609497,
0.98639, 	-0.16443, 	9.477810,
0.02109, 	0.99978, 	3.31913,
0.0, 0,0, 0.0
};


int main(int argc, char *argv[])
{
    //Program to calculate vector normalization and length.
	//
    printf("                                    \n");
    printf("3350 software engineering           \n");
    printf("                                    \n");
    printf("Calculation of vector lengths:      \n");
    printf("                                    \n");
    printf("     x         y         length     \n");
    printf("     --------  --------  ---------- \n");
    //read until sentinel found.
    int i=0;
    Vec v = { arr[i*2+0], arr[i*2+1] };
    Vec d = {data [i*2+0], data[i*2+1]};
   /* while (!(v[0] == 0.0 && v[1] == 0.0)){
        printf("%f\n",d[i]);
   }*/
    do {
        Flt ret = vec_length(v);
       // printf("%8.5lf, %8.5lf\n", d[i]);
        printf("%f\n",d[i]);
       // i++;
   
        printf("%3i  %8.5lf  %8.5lf  %10.5lf\n", i+1, v[0], v[1], ret);
        ++i;
        v[0] = arr[i*2+0];
        v[1] = arr[i*2+1];
    } while (!(v[0]==0.0 && v[1]==0.0));
    //
    printf("\nProgram complete.\n\n");
    return 0;
}

Flt vec_length(Vec v)
{
    //Normalize a vector.
    //Return the original length of the vector.
    //
    //input: the 2 components of a vector
    //output: the pre-normalized vector length is returned
    //        the vector argument is scaled to a length of 1.0
    //
    //A degenerate vector causes an error condition.
    //It will return a length of 0.0
    //and an arbitrary vector with length 1.0.
    //
    //calculate the vector dot product with itself...
    Flt dot = v[0]*v[0] + v[1]*v[1];
    //check for degenerate vector...
    if (dot == 0.0) {
        //set an arbitrary vector of length 1.0
        //printf("ERROR vector magnitude is zero.\n");
        v[0] = 1.0;
        v[1] = 0.0;
        return 0.0;
    }
    //vector has a magnitude so continue.
    Flt len = sqrt(dot);
    Flt oolen = 1.0 / len;
    v[0] *= oolen;
    v[1] *= oolen;
    return len;
}

