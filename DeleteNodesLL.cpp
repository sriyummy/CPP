#include <iostream>
#include <cstdlib>

struct node
{
    int data;
    node* next;
};
node* head = nullptr;

int createLinkedList()
{
    node* ptr, * current;
    char ch;
    int count;
    ptr = nullptr; current = nullptr;
    
    std::cout << "Creating a Linked List now: " << std::endl;

    do
    {
        ptr = (node*)malloc(sizeof(node));

        if (ptr == nullptr)
        {
            std::cout << "Memory Allocation Failed!";
            return 0;
        }

        std::cout << "Enter data: ";
        std::cin >> ptr->data;

        ptr->next = nullptr;

        if (head == nullptr)
        {
            head = ptr;
            current = ptr;
        }
        else
        {
            current->next = ptr;
            current = ptr;
        }
        
        count++;
        std::cout << "Insert another node? (Y/N): ";
        std::cin >> ch;

    } while (ch == 'y' || ch == 'Y');

    return count;
}

void displayLinkedList(node* head)
{
    node* p=head;

    if (head = nullptr)
    {
        std::cout << "Empty Linked List!";
        return;
    }
    else
    {
        while (p != nullptr)
        {
            std::cout << p->data << std::endl;
            p = p->next;
        }
    }
}

node* deleteAtBeginning(node* head)
{
    node* p_del;
    p_del = head;
    head = head->next;
    free(p_del);

    return head;
}

node* deleteAtIndex(node* head, int index)
{
    node* p_del, * q_del;
    p_del = head;
    q_del = head->next;
    int i=0;

    while (i<index-1)
    {
        p_del = p_del->next;
        q_del = q_del->next;

        i++;
    }

    p_del->next = q_del->next;
    free (q_del);
    
    return head;
}

node* deleteAtEnd(node* head)
{
    node* p_del, * q_del;
    p_del = head;
    q_del = head->next;

    while (q_del != nullptr)
    {
        p_del = p_del->next;
        q_del = q_del->next;
    }

    p_del = nullptr;
    free(q_del);

    return head;
}

void freeLL()
{
    struct node* current = head;
    struct node* next;

    while (current != nullptr)
    {
        next = current->next;
        free(current);
        current = next;
    }

    head = nullptr;
}

int main()
{
    int ind, nodes;
    
    nodes = createLinkedList();
    displayLinkedList(head);

    do
    {
        std::cout << "Enter the index you want to delete \n[index numbering starts from 0]:\nEnter '-1' to exit ";
        std::cin >> ind;

        
        if (ind == 0)
        {
            head = deleteAtBeginning(head);
            displayLinkedList(head);
        }
        else if (ind == nodes)
        {
            deleteAtEnd(head);
            displayLinkedList(head);
        }
        else if (ind == -1)
        {
            return 0;
        }
        else
        {
            deleteAtIndex(head, ind);
            displayLinkedList(head);
        }
    } while (ind != nodes+1 || ind > 0);
    
    
    freeLL();
    
    return 0;   
}
