
#include"iostream"
#include"string.h"
int main()
{

}

class CMyString
{
private:
    char* m_pData;
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);

    ~CMyString();
};

CMyString::CMyString(char* pData = nullptr)
{
}
CMyString::CMyString(const CMyString& str)
{
    m_pData = str.m_pData;
}

CMyString::~CMyString()
{
}
/**
 * 不要忘了释放内存
 */
CMyString& CMyString::operator =(const CMyString& str)
{
    if (this != &str)
    {
        CMyString strTemp(str);
        char * pTemp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = pTemp;
    }
    return *this;
    
}