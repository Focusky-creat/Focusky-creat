/**
 * 找出数组中的任意重复数字
 */
#include"iostream"
using  namespace std;
bool duplicate(int numbers[],int length,int *duplication);
int main()
{
    int numbers[] = {1,2,3,4,4,5,6,7,8,9};
    int length = sizeof(numbers)/sizeof(numbers[0]);
    int dump;
    int *duplication = &dump;


    if(duplicate(numbers,length,duplication))
    {
        cout<<"重复的数据为=="<<dump<<endl;
    }
    else
    {
        cout<<"输入的数据有瑕疵||数据中不存在重复数字"<<endl;
    }    

    return 0;
}

bool duplicate(int numbers[],int length,int *duplication)
{
    // 先判断输入数据是否有错误
    if (numbers == nullptr || length <= 0)
    {
        return false;
    }
    // 判断输入的数据是否满足算法的条件
    for (int i = 0; i < length; i++)
    {
        if (numbers[i] <0 || numbers[i]>length - 1)
        {
            return false;
        }
        
    }
    // 函数的主要思想
    for ( int i = 0; i < length; i++)
    {
        //判断数组中每个数字的值是否和当前位置的值相等
        while (numbers[i] != i)
        {
            //若果当前所指向的数字等于该数字作为下标时候的值的时候，重复数字被发现
            if (numbers[i] == numbers[numbers[i]])
            {
                *duplication = numbers[i];
                return true;
            }
            //若没有发现重复数字，那么将当前指向的数字放回它的对应位置
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
        
    }

    
    return false;
    
    
}

