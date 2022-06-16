#include <iostream>



//  this is edit by workstation



const int MAXSIZE = 20;
typedef int ElemType;

struct myList
{
    ElemType data[MAXSIZE];
    int length;
};
// 按1-n建立表
myList Create(myList &L)
{
    for (int i = 0; i != MAXSIZE; ++i)
    {
        L.data[i] = i;
        ++L.length;
    }
    return L;
}

// 返回顺序线性表第i个数据元素 (from i = 0)
bool GetElem(myList L, int i, ElemType &e)
{
    if (i < 0 || L.length == 0 || i > (L.length -1))
        return false;
    e = L.data[i];
    return true;
}

// 在第i个位置前插入元素
bool ListInsert(myList *L, int i, ElemType e)
{
    if (i < 0 || i > L->length)
        return false;
    if (i <= (L->length - 1))
    {
        for (int k = (L->length - 1); k != i - 1; --k)
            L->data[k + 1] = L->data[k];
    }
    L->data[i] = e;
    ++L->length;
    return true;
}

// 删除第i个位置的元素
bool ListDelete(myList *L, int i, ElemType &e)
{
    if (i < 0 || i > (L->length - 1))
        return false;
    e = L->data[i];
    if (i < (L->length - 1))
    {
        for (int k = i; k != (L->length - 1); ++k)
            L->data[k] = L->data[k + 1];
    }
    --L->length;
    return true;
}

int main()
{
    myList lst;
    Create(lst);
    for (int i = 0; i != MAXSIZE; ++i)
        std::cout << lst.data[i] << " ";
    std::cout << std::endl;

    ElemType e = 0;
    ElemType e1 = 0;
    ElemType e2 = 0;

    GetElem(lst, 3, e);
    printf(" %d ", e);
    std::cout << std::endl;

    ListInsert(&lst, 5, e1);
    for (int i = 0; i != MAXSIZE; ++i)
        std::cout << lst.data[i] << " ";
    std::cout << std::endl;

    ListDelete(&lst, 7, e2);
    printf(" %d ", e2);
    std::cout << std::endl;
    for (int i = 0; i != MAXSIZE; ++i)
        std::cout << lst.data[i] << " ";

    return 0;
}