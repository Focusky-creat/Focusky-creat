/**剪绳子：将长为n的线段剪成m段，使得所有绳子长度的乘积最大
 * 有两种方法：
 *  1.动态规划法
 *      
 *  2.贪婪算法
 * 
 */


#include"iostream"
#include"math.h"
using namespace std;

int maxProductAfterCutting_solution(int length);
int maxProductAfterCutting_solution_2(int length);


int main()
{
    int i = -5;
    int  result = 0;
    int  result_2 = 0;
    result = maxProductAfterCutting_solution(i);
    result_2 = maxProductAfterCutting_solution_2(i);
    cout<<"result = "<<result<<endl;
    cout<<"result_2 = "<<result_2<<endl;

    return 1;

}
// 动态规划法
// f(n) = max(f(i)*f(n-i))
int maxProductAfterCutting_solution(int length)
{
    if (length < 2)
        return 0;
    if (length == 2 )
        return 1;
    if (length == 3)
        return 2;

    int *products = new int[length+1];
    products[0]=0;
    products[1]=1;
    products[2]=2;
    products[3]=3;
    int max = 0;
    for (int i = 4; i <= length; i++)
    {
        max = 0;
        for (int  j = 1; j <= i/2; j++)
        {
            int product = products[j]*products[i-j];
            if (max<product)
            {
                max = product;
            }
            products[i]=max;
            
        }
    }
    max = products[length];
    delete[] products;

    return max;
    
    
}

/**贪婪算法
 * 
 */ 
int maxProductAfterCutting_solution_2(int length)
{
    if (length < 2)
        return 0;
    if (length == 2 )
        return 1;
    if (length == 3)
        return 2;

    int timesOf3 = length/3;
    if (length - timesOf3*3 == 1)
    {
        timesOf3 -= 1;
    }
    int timesof2 = (length - timesOf3*3)/2;
    return (int)(pow(3,timesOf3))*(int)(pow(2,timesof2));
    
}