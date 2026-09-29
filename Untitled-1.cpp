#include <math.h>
#include <stdio.h>

int main()
{

    double x = 1.0; 
    double y, U, a, b;
    double hx = 1.5, hy = 0.7;
    double low_gr_x = 1.0, high_gr_x = 4.0;
    double low_gr_y = 1.0, high_gr_y = 3.0;

    while (x <= high_gr_x )
    {   
        y = low_gr_y; 
        while (y <= high_gr_y )
        {
            if (x / y < 1.0)
            {
                U = 2.0 * x + 3.0 * pow(y, 1.0 / 4.0) - exp(5.0 * x);
            }
            else
            {
                a = tan(exp(3.0) * log(x * y));
                b = 1.0 / pow((cos(x) - pow(y, 2)), 1.0 / 3.0);
                
                if (a > b)
                {
                    U = a;
                }
                else
                {
                    U = b;
                }
            }
            
            printf("x = %.1f, y = %.1f, U = %.4f\n", x, y, U);

            y = y + hy;
        }
        x = x + hx;
    }
    
    return 0;
}