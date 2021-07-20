#include"iostream"
#include <cmath>

using namespace std;

bool isequal(double a,double b);
double Power(double base,int exponent);
double PowerWithUnsignedExponent(double base,unsigned exponent_un);
bool g_InvalidInput = false;



int main()
{   
    double base=0;
    int exponent=-1;
    double result  = 0.0;
    result =Power(base,exponent);

    
    cout<<"result=="<<result<<endl;
}
/**
 * Warning：
 *  1.输入base=0；exponent = 0;
 *  2.exponent < 0
 *    exponent > 0
 *  3.base == 0.0,exponent < 0
 */ 

double Power(double base,int exponent)
{
    double result=0.0;
    if (isequal(base,0.0) && exponent < 0)
    {
        g_InvalidInput = true;
        // if (g_InvalidInput == true)
        // {
        //     throw "Bad Input!";
        // }
        return 0.0;
    }
    unsigned int exponent_un = (unsigned int)exponent;
    if (exponent < 0)
    {
        exponent_un= (unsigned int)(-exponent);
        result = 1/PowerWithUnsignedExponent(base,exponent_un);
    }
    else
    {
        result = PowerWithUnsignedExponent(base,exponent_un);
    }
    return result;
}


bool isequal(double a,double b)
{
    double k = 0.00000001;
    if (fabs(a-b)<k)
    {
        return true;
    }
    return false;
}

double PowerWithUnsignedExponent(double base,unsigned exponent_un)
{
    double result=1.0  ;
    for (int i = 0; i < exponent_un; i++)
        result *= base;
    
    return result;
}