#include<stdio.h>
#include<malloc.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;
NODE *start=NULL;
int insert_beg(int x)
{
    NODE *ptr;
    ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL)
    {
        printf("memory is full\n");
        return 0;
    }
    ptr->data=x;
    ptr->next=NULL;
    ptr->next=start;
    start=ptr;
    return 1;
}
int insert_end(int x)
{
    NODE *p;
    NODE *ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL)
    {
        printf("memory is full\n");
        return 0;
    }
    ptr->data=x;
    ptr->next=NULL;
    if(start==NULL)
        start=ptr;
    else
    {
        p=start;
        while(p->next!=NULL)
            p=p->next;
            p->next=ptr;
    }
    return 1;
}
int insert_after(int x,int key)
{
    NODE *p;
    NODE *ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL)
    {
        printf("memory is full\n");
        return 0;
    }
    if(start==NULL)
    {
        printf("LINKLIST is empty\n");
        return 0;
    }
    ptr->data=x;
    ptr->next=NULL;
    p=start;
    while(p!=NULL && p->data!=key)
        p=p->next;
    if(p==NULL)
    {
        printf("key is not present in the LINKLIST\n");
        return 0;
    }
    ptr->next=p->next;
    p->next=ptr;
}
int delete_beg()
{
    int x;
    NODE *p;
    if(start==NULL)
    {
        printf("LINKLIST IS EMPTY\n");
        return -65536;
    }
    x=start->data;
    p=start;
    start=start->next;
    p->next=NULL;
    free(p);
    return x;
}
int delete_end()
{
    int x;
    NODE *p,*q;
    if(start==NULL)
    {
        printf("LINKLIST is empty\n");
        return -65536;
    }
    p=start;
    while(p->next!=NULL)
    {
        q=p;
        p=p->next;
    }
    x=p->data;
    q->next=NULL;
    p->next=NULL;
    free(p);
    return x;
}
int delete_after(int key)
{
    int x;
    NODE *p,*temp;
    if(start==NULL)
    {
        printf("LINKLIST is empty\n");
        return -65536;
    }
    p=start;
    while(p!=NULL&&p->data!=key)
        p=p->next;
    if(p==NULL)
    {
        printf("%d IS NOT PRESENT\n",key);
        return -65536;
    }
    if(p->next==NULL)
    {
        printf(" NO NODE AFTER %d in LINKLIST, HENCE NO DELETION\n",key);
        return -65536;
    }
    temp=p->next;
    p->next=temp->next;
    temp->next=NULL;
    x=temp->data;
    free(temp);
    return x;
}
void traverse()
{
    NODE*p;
    if(start==NULL)
    {
        printf("LINKLIST IS EMPTY\n");
        return;
    }
    p=start;
    printf("THE ELEMENTS IN THE LINKLIST ARE:\n");
    while(p!=NULL)
    {
        printf(" %d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int search(int key)
{
    int pos=0;
    NODE *p;
    if(start==NULL)
    {
        printf("LINKLIST IS EMPTY\n");
        return -1;
    }
    p=start;
    while(p!=NULL && p->data!=key)
    {
        p=p->next;
        pos++;
    }
    if (p==NULL)
        return -1;
    return (pos+1);
}
void main()
{
    int op,ans,x,key;
    do
    {
        printf("ENTER YOUR CHOICE \n1.INSERT BEGINNING IN LINKLIST\n2.INSERT AT END IN LINKLIST\n3.INSERT AFTER IN LINKLIST\n4.DELETE BEGINNING IN LINKLIST\n5.DELETE AT END IN LINKLIST\n6.DELETE AFTER IN LINKLIST\n7.SEARCH\n8.TRAVERSE(DISPLAY)\nANY OTHER KEY WILL RESULT IN EXIT\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1: printf("ENTER THE ELEMENT YOU WANT TO INSERT AT BEGINNING:\n");
                    scanf("%d",&x);
                    ans=insert_beg(x);
                    if(ans==0)
                        printf("ELEMENT IS NOT INSERTED \n");
                    else
                    printf("ELEMENT INSERTED SUCCESSFULLY\n");
                    break;
            case 2: printf("ENTER THE ELEMENT YOU WANT TO INSERT AT END:\n");
                    scanf("%d",&x);
                    ans=insert_end(x);
                    if(ans==0)
                        printf("ELEMENT IS NOT INSERTED \n");
                    else
                    printf("ELEMENT INSERTED SUCCESSFULLY\n");
                    break;
            case 3: printf("ENTER THE ELEMENT and KEY YOU WANT TO INSERT AFTER:\n");
                    scanf("%d%d",&x,&key);
                    ans=insert_after(x,key);
                    if(ans==0)
                        printf("ELEMENT IS NOT INSERTED \n");
                    else
                    printf("ELEMENT INSERTED SUCCESSFULLY\n");
                    break;
            case 4: ans=delete_beg();
                    if(ans!=-65536)
                        printf("ELEMENT DELETED FROM LINKLIST IS:%d\n",ans);
                    break;
            case 5: ans=delete_end();
                    if(ans!=-65536)
                        printf("ELEMENT DELETED FROM LINKLIST IS:%d\n",ans);
                    break;
            case 6: printf("ENTER THE KEY AFTER WHICH YOU WANT TO DELETE:\n");
                    scanf("%d",&key);
                    ans=delete_after(key);
                    if(ans!=-65536)
                        printf("ELEMENT DELETED FROM LINKLIST IS:%d\n",ans);
                    break;
            case 7: printf("ENTER ELEMENT YOU WANT TO SEARCH IN LINKLIST:\n");
                    scanf("%d",&key);
                    ans=search(key);
                    if(ans==-1)
                        printf("%d IS NOT PRESENT\n",key);
                    else
                    printf(" %d IS PRESENT AT POSITION %d:\n",key,ans);
                    break;
            case 8: traverse();
                    break;
            default:printf("invalid option\n");
                    break;
        }
    }while(op>0 && op<9);
}
