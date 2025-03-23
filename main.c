#include <stdio.h>
#include <math.h>

#define DATA_POINTS 100
#define PI 3.1416
#define C 3.0e8         //Speed of light (m/s)
#define H 6.626e-34     //Planck's constant (J*s)
#define K 1.38e-23      //Boltzmann constant (J/K)

//Calculate the spectral energy density (R)
double planck(double lambda, double temp)
{
    double meterLambda = lambda * 1.0e-6; //Convert from µm to m
    double exponent = (H * C) / (meterLambda * K * temp);
    return ((2.0 * PI * pow(C, 2) * H) / pow(meterLambda, 5)) * (1.0 / (exp(exponent) - 1));
}

int main()
{
    FILE *file = fopen("blackbody.dat", "w");
    
    if (file == NULL)
    {
        printf("Eror! Could not open file for writing.\n");
        return 1;
    }
    
    double lambda;
    double temp1 = 3000, temp2 = 4000, temp3 = 5000;
    
    //Column header for the file
    fprintf(file, "# Wavelength(µm)  R(T=3000K)    R(T=4000K)    R(T=5000K)\n");
    
    //Write down all data points for GNUPlot
    for (int i = 1; i < DATA_POINTS; i++)
    {
        //Evenly spread out data points from 0.1 to 3.0 µm
        lambda = 0.1 + (2.9 / (DATA_POINTS-1)) * i;
        
        fprintf(file, "%-16lf %-13e %-13e %-13e\n", lambda, planck(lambda, temp1), planck(lambda, temp2), planck(lambda, temp3));
    }
    
    fclose(file);
    
    //Checking to see if it gets to this line
    printf("Data file generated successfully!");

    return 0;
}
