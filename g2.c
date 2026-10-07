#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;

}Node;
// 1. 创建
Node* mymalloc(int t)
{
    Node *p;
    p=malloc(sizeof(Node));
    p->data=t;
    p->next=NULL;
    return p;
}
#include <stdio.h>

int main() {
    Node*p;
    int x=5;
    p=mymalloc(x);
    free(p);
    return 0;
}
// 2.头插
void headInsert(Node **head,int n){
    Node *new=mymalloc(n);
    new->next=*head;
    *head=new;
}
// 3.尾插
void tailInsert(Node **head,int n){
    Node *new=mymalloc(n);
    if(*head==NULL){
        *head=new;
        return;
    }
    Node *p=*head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=new;

}
// 4.打印
void printlist(Node *head)
{
    Node*p=head;
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }

}   
// 5.查找
bool search(Node *head,int n,int *loc)
{
    Node *p = head;
    *loc = 1; 
    while(p != NULL)
    {
        if(p->data == n)
        {
            return true;
        }
        p = p->next;
        (*loc)++;
    }
    return false;
}
// 6. 删除
bool delete(Node **head, int n)
{
    if(*head==NULL || n < 1)
        return false;

    Node *del = NULL;
    if(n == 1)
    {
        del = *head;
        *head = (*head)->next;
        free(del);
        return true;
    }
  
    Node *pre = *head;
    for(int i = 1; i < n-1; i++)
    {
        pre = pre->next;
        if(pre == NULL)
            return false;
    }
    del = pre->next;
    if(del == NULL)
        return false;
    pre->next = del->next;
    free(del);
    return true;
}

//7. 反转
void reverse(Node **head)
{
    Node *pre = NULL;
    Node *cur = *head;
    Node *next = NULL;
    while(cur != NULL)
    {
        next = cur->next; 
        cur->next = pre; 
        pre = cur;
        cur = next;
    }
    *head = pre; 
}