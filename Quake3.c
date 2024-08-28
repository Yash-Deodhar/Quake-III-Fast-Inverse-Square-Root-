#include <stdio.h>
#include <stdlib.h>

// Function to calculate the inverse square root using the "fast inverse square root" method
float Q_rsqrt(float number)
{
    long i;                         // Variable to store the bit-level representation of the float
    float x2, y;                    // Intermediate variables for calculation
    const float threehalfs = 1.5F;  
    x2 = number * 0.5F;             
    y  = number;                    
    i  = * ( long * ) &y;           // Bitwise cast of y to a long integer
    i  = 0x5f3759df - ( i >> 1 );   // Perform the magic number operation (bit-level hack)
    y  = * ( float * ) &i;          // Bitwise cast back to float
    y  = y * ( threehalfs - ( x2 * y * y ) );  // First iteration of Newton's method
    // y  = y * ( threehalfs - ( x2 * y * y ) );  // Optionally, a second iteration 

    return y;                       
}

int main(int argc, char* argv[])
{
    float res;                      
    float N = atof(argv[1]);        
    res = Q_rsqrt(N);               
    printf("%f \n", res);           
    return 0;                       
}
