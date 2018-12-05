#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;


struct ListNode
{
    int value;
    ListNode *next;
};


void InitList(ListNode **pHead)
{
    *pHead = new ListNode;
    if(*pHead != NULL)
    {
        (*pHead)->next = NULL;
    }
    cout << "InitList Success !" << endl;
}

//头插入法
int CreateListFromHead(ListNode **pHead,int num)
{
    cout << "CreateList Start !" << endl;
    ListNode *pTmp = NULL;
    for(int i = 1; i <= num; i++ )
    {
        pTmp = new ListNode;
        pTmp->value = i;
        pTmp->next = (*pHead)->next;
        (*pHead)->next = pTmp;
    }
    cout << "CreateList Success !" << endl;
    return 1;
}

ListNode *InitList1(ListNode *pHead)
{
    pHead = new ListNode;
    if(pHead != NULL)
    {
        (pHead)->next = NULL;
    }
    cout << "InitList Success !" << endl;
    return pHead;
}

ListNode *CreateListFromHead1(ListNode *pHead, int num)
{
    cout << "CreateList Start !" << endl;
    ListNode *pTmp = NULL;
    for(int i = 1; i <= num; i++ )
    {
        pTmp = new ListNode;
        pTmp->value = i;
        pTmp->next = pHead->next;
        pHead->next = pTmp;
    }
    cout << "CreateList Success !" << endl;
    return pHead;
}

ListNode * CreateListFromHead_test(int num)
{
    ListNode *pHead = new ListNode;
    if(pHead != NULL)
    {
        pHead->next = NULL;
    }
    cout << "CreateList Start !" << endl;
    ListNode *pTmp = NULL;
    for(int i = 1; i <= num; i++ )
    {
        pTmp = new ListNode;
        pTmp->value = i;
        pTmp->next = pHead->next;
        pHead->next = pTmp;
    }
    cout << "CreateList Success !" << endl;

    return pHead;
}

void DisplayList(ListNode *pHead)
{
    ListNode *list = pHead;
    while(list != NULL)
    {
        cout << list->value << endl;
        list = list->next;
    }
}

int CreateListFromTail(ListNode **pHead, int num)
{
    ListNode *tmp = *pHead;
    ListNode *p = NULL;

    for(int i = 1; i <= num; i++)
    {
        p = new ListNode;
        p->value = i;
        p->next = NULL;
        tmp->next = p;
        tmp = p;
    }
    return 1;
}

int getlength(ListNode *head)
{
    int length = 0;
    ListNode *tmp = head;
    while(tmp != NULL)
    {
        length++;
        tmp = tmp->next;
    }
    return length;
}



int insertList(ListNode **head, int pos, int value)
{
    ListNode *p = *head;

    ListNode *insertNode = new ListNode;

    //链表为空，需要在第I个位置插入新的节点
    if(p->next == NULL)
    {
        insertNode->value = value;
        insertNode->next = p->next;
        p->next = insertNode;
        cout << "Insert Success !" << endl;
        return 1;
    }

    //链表在非空的情况下
    int j = 0;
    while(p && j < pos -1)
    {
        j++;
        p = p->next;
    }
    if(p->next == NULL)
    {
        //插入到队尾
        insertNode->value = value;
        p->next = insertNode;
        insertNode->next = NULL;
    }
    insertNode->value = value;
    insertNode->next = p->next;
    p->next = insertNode;


    return 1;
}

int insertListTail(ListNode **head, int data)
{
    ListNode *p = *head;
    ListNode *tmp = NULL;
    while(p->next != NULL)
    {
        p = p->next;
    }

    tmp = new ListNode;
    tmp->value = data;
    p->next = tmp;
    tmp->next = NULL;
    return 1;

}

// -----------------在pos后插入--------------------
void InsertListNodeFromBack(ListNode *&L, int pos, int value)
{
    ListNode *tmp = new ListNode;
    tmp->value = value;
    if (L == NULL || pos == 0)
    {
        tmp->next = L;
        L = tmp;
        return;
    }

    if ( pos >= getlength(L) || pos < 0)
    {
        cout << "Error input pos."<< endl;
        return;
    }

    ListNode *pInsert = L;
    while (pos--)
    {
        pInsert = pInsert->next;
    }
    tmp->next = pInsert->next;
    pInsert->next = tmp;

    return;
}

int deleteList(ListNode **head, int pos, int *data)
{
    ListNode *p = *head;

    if(p->next == NULL)
    {
        cout << "list is null ,cant not delete!" << endl;
        return 0;
    }
    int j = 0;
    while(p->next && j < pos - 1) //定位删除的节点
    {
        j++;
        p = p->next;
    }

    if(p->next == NULL)
    {
        return 0;
    }
    ListNode *pnext = p->next;
    p->next = pnext->next;
    *data = pnext->value;
    free(pnext);

    return 1;


}

int clearList(ListNode *head)
{
    ListNode *p = head;
    ListNode *temp = NULL;
    p = p->next;
    while(p)
    {
        temp = p;
        p = p->next;
        free(temp);
    }
    head->next = NULL;
    return 1;
}

ListNode *ReverseList(ListNode *head)
{
    if(head == NULL || head->next == NULL)
    {
        cout << "head is null " <<endl;
        return head;
    }
    ListNode *pReverserdHead = NULL;
    ListNode *pNode = head;
    ListNode *pPrev = NULL;
    ListNode *pNext = NULL;
    while(pNode)
    {
        if(pNode->next == NULL)
        {
            pReverserdHead = pNode;
        }
        pNext = pNode->next;
        pNode->next = pPrev;
        pPrev = pNode;
        pNode = pNext;
    }

    return pReverserdHead;//return pPrev
}

void printReverseList(ListNode *head)
{
    if(head != NULL)
    {
        if(head->next != NULL)
        {
            printReverseList(head->next);
        }
        cout << head->value << endl;
    }
}


void printReverseList_stack(ListNode *head)
{
    stack<ListNode*> nodes;
    ListNode *pNode = head;

    while(pNode)
    {
        nodes.push(pNode);
        pNode = pNode->next;
    }

    while(!nodes.empty())
    {
        pNode = nodes.top();
        cout << "value = " << pNode->value << endl;
        nodes.pop();
    }
}

int main(int argc, char *argv[])
{


    ListNode *pHead1;
    pHead1 = InitList1(pHead1);
    pHead1 = CreateListFromHead1(pHead1,10);
    DisplayList(pHead1);



    ListNode *pHead;
    InitList(&pHead);
    CreateListFromHead(&pHead, 10);
    DisplayList(pHead);
    //ListNode *pHead = CreateListFromHead_test(10);

    ListNode *tHead;
    InitList(&tHead);
    CreateListFromTail(&tHead,10);
    DisplayList(tHead);
    int length = getlength(tHead);
    cout << "length = " << length <<endl;
    cout << "insert add" << endl;
    insertList(&tHead, 4, 30);
    DisplayList(tHead);
    cout << "tail add" << endl;
    insertListTail(&tHead,100);
    DisplayList(tHead);
    int data = -1;
    deleteList(&tHead,4,&data);
    DisplayList(tHead);
    InsertListNodeFromBack(tHead,5,105);
    DisplayList(tHead);
    cout << "Reverse List " << endl;
    ListNode *reversedHead = ReverseList(tHead);
    DisplayList(reversedHead);

    cout << "clear list " <<endl;
    clearList(tHead);
    DisplayList(tHead);

    return 0;
}
