/*************************************************************************
	> File Name: singly_linked_list.c
	> Author: 
	> Mail: 
	> Created Time: Wed 23 Sep 2020 09:33:49 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *tail;

void create()
{
    head = tail = NULL;
}

int is_empty()
{
    if(head == NULL)
    {
        return 1;
    }

    return 0;
}

int insert(int data)
{
    struct node *p_node;

    p_node = (struct node*)malloc(sizeof(struct node));

    if(p_node == NULL)
    {
        printf("no memory for new node!!!\n");

        return 0;
    }

    p_node->data = data;

    if(is_empty())
    {
        head = p_node;
        tail = p_node;
    }
    else
    {
        tail->next = p_node;
        tail = p_node;
    }

    return 1;
}

int delete(int data)
{
    struct node *p_node, *s_node;

    if(head == NULL)
    {
        printf("the linked list is null!!!\n");

        return 0;
    }

    p_node = head;

    while(p_node != NULL)
    {
        if(p_node->data == data)
        {
            break;
        }

        s_node = p_node;
        p_node = p_node->next;
    }

    if(p_node == NULL)
    {
        printf("the element is not exist in the linked list!!!\n");
        
        return 0;
    }

    s_node->next = p_node->next;
    p_node = NULL;
    
    return 1;
}

void search(int index)
{
    int i = 0;
    struct node *p_node;

    if(head == NULL)
    {
        printf("the linked list is null!!!\n");

        return;
    }

    p_node = head;

    while(p_node != NULL)
    {
        if(i == index)
        {
            break;
        }
        
        p_node = p_node->next;
        i++;
    }

    if(p_node == NULL)
    {
        printf("out of bound!!!\n");

        return;
    }

    printf("the element[%d] is %d\n", index, p_node->data);
}

int update(int index, int new_data)
{
    int i = 0;
    struct node *p_node;

    if(head == NULL)
    {
        printf("the linked list is null!!!\n");

        return 0;
    }

    p_node = head;

    while(p_node != NULL)
    {
        if(i == index)
        {
            break;
        }

        p_node = p_node->next;
        i++;
    }

    if(p_node == NULL)
    {
        printf("out of bound!!!\n");

        return 0;
    }

    p_node->data = new_data;

    return 1;
}

void show()
{
    int index = 0;
    struct node *p_node;

    if(head == NULL)
    {
        printf("the linked list is null!!!\n");

        return;
    }

    p_node = head;

    while(p_node != NULL)
    {
        printf("element[%d]: %d\n", index, p_node->data);

        p_node = p_node->next;
        index++;
    }
}

void destory()
{
    head = tail = NULL;
}

int main()
{

    char ch;

    while(ch != 'F')
    {
        printf("please input your choice:\n");
        printf("A.insert    B.remove    C.update    D.search    E.show    F.exit");
        printf("your choice:\n\n");
        printf("\n");
        ch = getchar();
        getchar();

        switch(ch)
        {
            case 'A':
            {
                int data,ret;
                printf("please input element:");
                scanf("%d", &data);
                getchar();

                if(insert(data))
                {
                    printf("insert successfully\n");
                }
                else
                {
                    printf("insert failed\n");
                }
            }
            break;

            case 'B':
            {
                int data,ret;
                printf("please input the element you want to delete:");
                scanf("%d", &data);
                getchar();

                if(delete(data))
                {
                    printf("delete successfully\n");
                }
                else
                {
                    printf("delete failed\n");
                }
            }
            break;

            case 'C':
            {
                int index, new_data;

                printf("please input the index:");
                scanf("%d", &index);
                getchar();

                printf("please input the data you want to update:");
                scanf("%d", &new_data);
                getchar();

                if(update(index,new_data))
                {
                    printf("update successfully\n");
                }
                else
                {
                    printf("update failed\n");
                }
            }
            break;

            case 'D':
            {
                int index;

                printf("please input the index:");
                scanf("%d", &index);
                getchar();

                search(index);
            }
            break;
            
            case 'E':
            {
                show();
            }
            break;

            case 'F':
            {
                destory();

                goto exit;
            }
            break;

            default:
                printf("input invalid!!!\n");
        }
    }

    exit:
        return 0;
}




