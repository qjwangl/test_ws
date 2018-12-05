#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
}NODE,*PNODE;

typedef struct Stack
{
    struct Node *stop;
}STACK;

struct Stack init_stack()
{
    STACK sc;
    PNODE pbottom = (PNODE)malloc(sizeof(NODE));
    if(pbottom == NULL)
    {
        cout << "pbottom malloc fail " << endl;
        exit(1);
    }
    pbottom->next = NULL;
    sc.stop = pbottom;
    return sc;
}

void init_stack1(STACK *sc)
{
    PNODE pbottom = (PNODE)malloc(sizeof(NODE));
    if(pbottom == NULL)
    {
        cout << "pbottom malloc fail " << endl;
        exit(1);
    }
    pbottom->next = NULL;
    pbottom->data = -1;
    sc->stop = pbottom;
    return;
}




void stack_push(STACK *sc,int data)//
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if(pNew == NULL)
    {
        cout << "pNew malloc fail" << endl;
        exit(1);
    }
    pNew->data = data;

    pNew->next = sc->stop;
    sc->stop = pNew;
}


int is_empty(STACK *sc)
{
    PNODE p = sc->stop;
    if(p == NULL || p->next == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void trvel_stack(STACK *sc)
{
    if(is_empty(sc) == 1)
    {
        cout << "stack sc is null " << endl;
    }
    else
    {
        PNODE ptmp = sc->stop;
        //while(ptmp->next != NULL)
        while(ptmp != NULL)
        {
            cout << "stack sc data:" << ptmp->data << endl;
            ptmp = ptmp->next;
        }
    }
}


int pop(STACK *sc)
{
    int res;
    if(is_empty(sc) == 1)
    {
        cout << "stack sc is null" << endl;
        return 0;
    }
    else
    {
        PNODE ptmp = sc->stop;
        sc->stop = sc->stop->next;
        res = ptmp->data;
        free(ptmp);
        return res;
    }

}

int main(int argc,char *argv[])
{
    STACK sc;
    //sc = init_stack();
    init_stack1(&sc);
    stack_push(&sc,1);
    stack_push(&sc,2);
    stack_push(&sc,3);

    trvel_stack(&sc);
    cout << "-------------------" << endl;

    pop(&sc);

    trvel_stack(&sc);


    return 0;
}
