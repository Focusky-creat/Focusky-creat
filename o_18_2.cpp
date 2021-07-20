#include <cstdio>
struct NodeList
{
    NodeList *NodeNext;
    int value;
};
void DeleteRep(NodeList**NodeHead)
{
    //step1：判断输入是否有问题，指向头结点指针的指针或者指向头结点的指针为空
    if ( NodeHead == nullptr || *NodeHead == nullptr)
    {
        return;
    }
    NodeList *pNode = *NodeHead;
    NodeList *pPreNode = nullptr;
    //step2：寻找重复数据并删除节点
    while (pNode != nullptr)
    {
        //step2.1 判断是否相邻节点见是否有相同的值
        NodeList *pNodeNext=pNode->NodeNext;
        bool ToBeDelete = false;
        if (pNodeNext!=nullptr && pNodeNext->value==pNode->value)
        {
            ToBeDelete = true;
        }
        //step2.2 若没有相同，那么继续
        if (!ToBeDelete)
        {
            pPreNode = pNode;
            pNode = pNodeNext;
            
        }
        //step2.3 如果存在重复数据，进行删除
        else
        {
            int value=pNode->value;
            NodeList * ToBeDel=pNode;
            //删除连续的重复节点
            while (ToBeDel!=nullptr && ToBeDel->value==value)
            {
                pNodeNext=ToBeDel->NodeNext;
                delete ToBeDel;
                ToBeDel=nullptr;
                ToBeDel=pNodeNext;
            }
            //如果头节点也要删除，更新NodeHead
            if (pPreNode==nullptr)
            {
                *NodeHead = pNodeNext;
            }
            else
            {
                pPreNode->NodeNext=pNodeNext;
            }
            pNode=pNodeNext;
        }
    }
}
int main()
{
    return 0;
}