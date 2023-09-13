#include <iostream>
#include <cstdlib>

struct node
{
    int data;
    struct node* next;
};
node* head;

int createLinkedList()
{
    node* ptr, * current;
    int c=0;
    char ch;
    ptr = nullptr;
    current = nullptr;

    std::cout << "Creating a Linked List: \n" << std::endl;
    head = nullptr;

    do
    {
        ptr = (node*)malloc(sizeof(node));

        if (ptr == nullptr)
        {
            std::cout << "Memory allocation failed";
        }

        std::cout << "Enter data: ";
        std::cin >> ptr->data;

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

        std::cout << "Do you want to conitue adding elements? (Y/N): ";
        std::cin >> ch;

        c++;
    } while (ch == 'Y' || ch == 'y');

    return c;
}

void displayLinkedList()
{
    node* p = head;

    if (head == nullptr)
    {
        std::cout << "Linked List is Empty!";
        return;
    }
    else
    {
        while (p != nullptr)
        {
            std::cout << p->data << " " << std::endl;
            p = p->next;
        }
    }
}

node* insertAtBeginning(node* head, int data)
{
    node* p_in = (node*)malloc(sizeof(node));
   
    p_in->data = data;
    p_in->next = head;

    return head;
}

node* insertAtEnd(node* head, int data)
{
    node* p_in = (node*)malloc(sizeof(node));
    node* p = head;

    p_in->data = data;

    while(p->next != nullptr)
    {
        p=p->next;
    }
   
    p->next = p_in;
    p_in->next = nullptr;

    return head;
}

node* insertAtPosition(node* head, int position, int data)
{
    node* p_in = (node*)malloc(sizeof(node));
    node* p = head;
    int i = 1;

    while(i!=position)
    {
        p = p->next;
        i++;
    }
    p_in->data = data;
    p_in->next = p->next;
    p->next = p_in;

    return head;
}


int main()
{   
    int nodes = createLinkedList();
    displayLinkedList();

    int pos, num;

    std::cout << "Enter the position you want to enter your data in: ";
    std::cin >> pos;
    std::cout << "Enter the data you want to enter at the position: ";
    std::cin >> num;

    while (pos>0 && pos<nodes+2)
    {
        if (pos == 1)
        {
            head = insertAtBeginning(head, num);
        }
        else if (pos == nodes+1)
        {
            head = insertAtEnd(head, num);
        }
        else
        {
            head = insertAtPosition(head, pos, num);
        }
    }

    std::cout << "Updated List: " << std::endl;
    displayLinkedList();

    void freeLL();

    return 0;
}