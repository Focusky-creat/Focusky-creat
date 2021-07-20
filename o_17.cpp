#include"stdio.h"
#include"string.h"
#include"iostream"
using namespace std;
void PrintNumber(char *number);
bool Increment(char *number);
void Print1ToMaxOfNDigits(int n);

int main()
{
    int n=3;
    Print1ToMaxOfNDigits(n);
}

void Print1ToMaxOfNDigits(int n)
{
    // step 1:验证输入是否有错
    if (n<0)
        return;
    // step 2:定义number字符串并初始化为全'0'
    char *number = new char[n+1];
    // 把前number的N个字符设置诶0
    memset(number , '0',n);
    number[n]='\0';
    // step 3:判断最高位是否存在进位的情况
    while (!Increment(number))
    {   
        // 打印数字
        PrintNumber(number);
    }
    delete [] number;
}

// 进位计算，返回值用于判断是否用于结束输出循环
bool Increment(char *number)
{

    bool isOverflow = false;
    // 进位
    int nTakeOver = 0;
    // 字符串长度
    int nLength = strlen(number);

    // 计算整个字符串每一位的值
    for (int i = nLength-1;  i >= 0; i--)
    {
        int nSum = number[i]-'0'+nTakeOver;
        // 如果是个位的话自加1，然后判断
        if (i==nLength-1)
        {
            nSum++;        
        }
        // 如果自加以后的值大于10，产生进位
        if (nSum>=10)
        {
            if (i==0)
            {
                isOverflow = true;
            }
            else 
            {
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0'+nSum;
            }
        }
        // 若没有产生进位，则赋值即可
        else
        {
            number[i] = '0'+nSum;
            break;
        }
        

    }
    return isOverflow;

}


// 打印非0数字的开始位置
void PrintNumber(char *number)
{
    bool isBeginning0 = true;
    int nLength = strlen(number);
    // 寻找第一位非0的数字然后开始打印
    for (int i = 0; i < nLength; i++)
    {
        if (isBeginning0 && number[i]!='0')
        {
            isBeginning0 = false;
        }

        if (!isBeginning0)
        {
            printf("%c",number[i]);
        }
        
        
    }
    printf("\n");
    
}
