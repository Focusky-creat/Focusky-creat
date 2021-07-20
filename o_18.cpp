#include <cstdio>
struct NodeList
{
    int m_value;
    NodeList *m_pNext;
};

void DeleteNode(NodeList ** pListHead,NodeList *pToBeDeleted)
{
    if ( pListHead == nullptr||*pListHead == nullptr   )
    {
        return;
    }
    //1.删除的不是尾节点
    if (pToBeDeleted->m_pNext!=nullptr)
    {
        NodeList *Node = pToBeDeleted->m_pNext;
        pToBeDeleted->m_value=Node->m_value;
        pToBeDeleted->m_pNext=Node->m_pNext;
        delete Node;
        Node = nullptr;
    }
    //2.删除的是指向nullptr的头指针
    else if (*pListHead == pToBeDeleted)
    {
       delete pToBeDeleted;
       pToBeDeleted=nullptr;
       *pListHead=nullptr;
    }
    //3.删除尾节点
    else
    {
        NodeList* pNode =*pListHead;
        while (pNode->m_pNext!= pToBeDeleted)
        {
            pNode=pNode->m_pNext;
        }
        pNode->m_pNext=nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }

    
    
    
}


int main()
{
    return 0;
    // DeleteNode(NodeList ** pListHead,NodeList *pToBeDeleted)
}