#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace  std;


typedef struct Data
{
    int value;
}ElemType;

typedef struct ListNode
{
    ElemType data;
    ListNode *next;
}ListNode;

//typedef struct Node* linkList;

int initList(ListNode **head)
{
    (*head) = (ListNode*)malloc(sizeof(ListNode));
    (*head)->next = NULL;
    return 1;
}

int createListHead(ListNode **head,int num)
{
    ListNode *p = NULL;

    for(int i = 0; i < num; i++)
    {
        p = (ListNode*)malloc(sizeof(ListNode));
        p->data.value = i;
        p->next = (*head)->next;
        (*head)->next = p;
    }
    printf("head insert success!\n");
    return 1;
}

int createListTail(ListNode **head,int num)
{
    ListNode *p = NULL;
    ListNode *tmp = (*head);
    for(int i = 0; i < num; i++)
    {
        p = (ListNode*)malloc(sizeof(ListNode));
        p->data.value = i;
        p->next = NULL;

        tmp->next = p;
        tmp = p;

    }
    printf("tail insert success!\n");
    return 1;
}

int createListTail2(ListNode **head,int num)
{
    ListNode *p = NULL;
    ListNode *tmp = (*head);
    for(int i = 0; i < num; i++)
    {
        p = (ListNode*)malloc(sizeof(ListNode));
        p->data.value = i;
        p->next = NULL;
        if((*head) == NULL)
        {
            *head = p;
        }
        else
        {
            tmp->next = p;
        }
        tmp = p;

    }
    printf("tail insert success!\n");
    return 1;
}

int getLength(ListNode *head)
{
    int length = 0;
    ListNode *tmp = head->next;
    while(tmp)
    {
        length++;
        tmp = tmp->next;
    }
    return length;
}


int printList(ListNode *head)
{
    ListNode *tmp = head;
    if(tmp == NULL)
    {
        printf("null listlink!\n");
    }
    while(tmp)
    {
        printf("data_value = %d\n",tmp->data.value);
        tmp = tmp->next;
    }
    return 1;
}

ListNode *findKthNode(ListNode *head, int k)
{
//    if(getLength(head) < k)//时间复杂度的问题
//        return NULL;
    if(k == 0)
    {
        return NULL;
    }
    if(head == NULL)
    {
        return NULL;
    }
    ListNode *p1 = head;
    ListNode *p2 = head;

    for(int i = 1; i < k; i++)//链表的倒数第0个结点为链表的尾指针 i = 0
    {
        if(p1->next == NULL)
        {
            return NULL;
        }
        p1 = p1->next;
    }

    while(p1->next != NULL)//保持p1和p2是k-1的距离
    {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p2;
}

int main(int argc,char *argv[])
{
    ListNode *head = NULL;
    //initList(&head);
    //createListHead(&head,5);
    //createListTail(&head,5);
    createListTail2(&head,5);
    printList(head);
    ListNode *kth =  findKthNode(head,2);
    cout << kth->data.value << endl;
    return 1;
}


/*
 * 单链表的反转
 * 链表中环的检测
 * 两个有序列表的合并
 * 删除链表倒数第n个节点
 * 求链表的中间节点
 * /
