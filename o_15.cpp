//输入一个整数，输出二进制中1 的个数
/**
 * Warning:
 *  1.如果选择右移输入的数字，如果该数字是负数的话，由于最左位是1，右移以后还是1，最后成了0xFFFFF，可以选择左移1
 */ 

int NumberOf1(int n);
int NumberOf1_1(int n);
int NumberOf1_2(int n);
#include"iostream"
using namespace std;
int main()
{
    int num = 10;
    int num_of_1=0;
    int num_of_2=0;
    int num_of_3=0;
    num_of_1 = NumberOf1 (num);
    num_of_2 = NumberOf1_1 (num);
    num_of_3 = NumberOf1_2 (num);
    cout<<"num_of_1=="<<num_of_1<<endl;
    cout<<"num_of_2=="<<num_of_2<<endl;
    cout<<"num_of_3=="<<num_of_3<<endl;
    return 1;
}

int NumberOf1(int n)
{
    int count=0;
    while (n)
    {
        if(n & 1)
        {
            count++;
        }
        n = n >> 1;
    }
    return count;

    
}

int NumberOf1_1(int n)
{
    int flag =1;
    int count=0;
    while (flag)
    {
        if (flag&n)
        {
            count++;
        }
        flag = flag << 1;
    }
    return count;
    
}

int NumberOf1_2(int n)
{
    int count ;
    while (n)
    {
        ++count;
        n = n&(n-1);
    }
    return count;
    
}