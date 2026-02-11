#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double 
magnitude(int vec[], int lenght) 
{   
    double ret = 0.0;

    for (int i = 0; i < lenght; i++)
    {
        ret += vec[i]*vec[i]; 
    }

    return sqrt(ret);
}

int 
dot_prod(int* vec1, int* vec2, int lenght) 
{   
    int ret = 0;

    for (int i = 0; i < lenght; i++)
    {
        ret += vec1[i]*vec2[i];
    }

    return ret;
}

double* 
projection(int dot_prod, double magnitude, int* vec, int lenght)
{
    double* res = malloc(lenght * sizeof(int));
    double scalar = (double)dot_prod/(magnitude*magnitude);

    for (int i = 0; i < lenght; i++)
    {
        res[i] = vec[i]*scalar;
    }

    return res;
}

int 
main()
{
    int u[] = { 1, 2, 3};
    int v[] = { 5, 6, 2};

    int n = sizeof(v)/sizeof(v[0]);
    double v_mag = magnitude(v, n);
    int dot = dot_prod(u, v, n);

    double* u_to_v = projection(dot, v_mag, v, n);

    printf("(%.02f, %.02f, %.02f"), u_to_v[0], u_to_v[1], u_to_v[2]);
}