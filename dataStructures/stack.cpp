#include <iostream>
#include <stdlib.h>
#include <stdlib.h>

using namespace std;

typedef struct Node
{
    int data;
    int id;
    Node *next;
}NODE;

typedef struct Strack
{
    Node *pTop;
    Node *pBottom;
}STRACK;

Strack *init_strack()
{
    Strack *ps = (STRACK *)malloc(sizeof(STRACK));
    Node *test ;//= (NODE*)malloc(sizeof(NODE));

    Node *pNew = (Node*)malloc(sizeof(Node));
    if(pNew == NULL)
    {
        cout << "pTop malloc fail " << endl;
    }
    else
    {
        pNew->data  = 1;
        pNew->next = NULL;
        test = pNew;
        ps->pBottom = pNew;
        ps->pTop = pNew;
    }

    cout << "test->data:" << test->data << endl;
    cout << "ps->data:" << ps->pTop->data << endl;
    return ps;
}

int push(Strack *ps,int val)
{
    Node *pNew = (Node*)malloc(sizeof(Node));

    if(pNew == NULL)
    {
        cout << "push malloc fail" << endl;
        exit(-1);
    }
    pNew->data = val;
    pNew->next = ps->pTop;
    ps->pTop = pNew;
    return 1;
}


void traverse(Strack *ps)
{
    Node *p = ps->pTop;
    while(p != ps->pBottom)
    {
        cout << "value : " << p->data << endl;
        p = p->next;
    }
}


bool isEmpty(Strack *ps)
{
    if(ps->pTop == ps->pBottom)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool pop(Strack *ps, int *pVal)
{
    if(isEmpty(ps))
    {
        return false;
    }

    else
    {
        Node *p = ps->pTop;
        ps->pTop = p->next;
        *pVal = p->data;
        free(p);
        p = NULL;
        return true;
    }
}

int main(int argc,char *argv[])
{
    Strack *sc;
    sc = init_strack();
    //push(sc,3);
    //traverse(sc);
    return 1;
}



