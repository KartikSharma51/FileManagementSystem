#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct node
{
    int info;
    struct node *next;  
};
struct node *start = NULL,*newnode,*ptr;
int countnode()
{
    int counter = 0;
    ptr = start;
    while(ptr!=NULL)
    {
        counter++;
        ptr = ptr->next;
    }
    return(counter);
}

// Create

void create()
{
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\n Enter the item : ");
    scanf("%d",&newnode->info);
    if(start==NULL)
    {
        newnode->next=NULL;
        start=newnode;
    }
    else{
        newnode->next=start;
        start=newnode;
    }
    printf("Node created successfully");
    getch();
}

// Read

void read()
{
    if(start==NULL)
    {
        printf("\n List is empty\n");
    }
    else{
        ptr=start;
        while(ptr!=NULL)
        {
            printf("\n%d",ptr->info);
            ptr=ptr->next;
        }
    }
    getch();
}

// Delete File

void delete_file()
{
    struct node*ptr1,*ptr2;
    if(start==NULL)
    {
        printf("List is empty\n");
        getch();
        return;
    }
    ptr1=start;
    if(start->next==NULL)
    {
        ptr=start;
        start=NULL;
        free(ptr);
    }
    else{
        while(ptr1!=NULL)
        {
            ptr2=ptr1->next;
            if (ptr2->next==NULL)
            {
                break;
            }
            ptr1=ptr1->next;
        }
        ptr1->next=NULL;
        free(ptr2);
    }
    printf("\n Node deleted successfully\n");
    getch();
}

// Update

void update()
{
    int pos,count,i=1;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\n Enter the item : ");
    scanf("%d",&newnode->info);
    printf("Enter the position : ");
    scanf("%d",&pos);
    count=countnode();
    if(pos>count)
    {
        printf("Invalid position\n");
        getch();
        return;
    }
    else if(pos==1)
    {
        newnode->next=start;
        start=newnode;
    }
    else if (pos==count)
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        newnode->next=NULL;
        ptr->next=NULL;
    }
    else
    {
        ptr=start;
        while(i<pos-1)
        {
            ptr=ptr->next;
            i++;
        }
        newnode->next=ptr->next;
        ptr->next=newnode;
    }
    printf("Node inserted successfully\n");
    getch();
}   

int main ()
{
    char ch;
    do
    {
        printf("1 Created\n2 Delete File\n3 Read\4 Update\n5 Exit\n");
        printf("Enter the choice : ");
        ch=getche();
        switch (ch)
        {
        case '1':
        create();
        break;
        
        case '2':
        delete_file();
        break;

        case '3':
        read();
        break;

        case '4':
        update();
        break;

        case '5':
        return 0;
        default:
        printf("\n Wrong choice\n");
        getch();
        }
    }    
    while (1)
    getch();
    return 0;  
}