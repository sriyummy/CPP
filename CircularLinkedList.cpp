#include <iostream>
#include <cstdlib>

struct node
{
    int data;
    node* next;
};
node* head = nullptr;

int createLinkedList(node* start)
{
    node* ptr, * current;
    ptr = nullptr;
    current = nullptr;
    char ch;
    int c=1;

    std::cout << "Creating a Linked List now:" << std::endl;

    do
    {
        ptr = (node* )malloc(sizeof(node));

        if(ptr == nullptr)
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

        std::cout << "Do you want to add more nodes?: (Y/N) ";
        std::cin >> ch;

        c++;
    } while (ch == 'y' || ch == 'Y');

    if (current != nullptr)
    {
        current->next = head;
    }
    
    return c;
}

void displayLinkedList(node* start)
{
    node* ptr = start;
    if (start == nullptr)
    {
        std::cout << "The Linked List is empty!";
        return;
    }
    else
    {
        do
        {
            std::cout << ptr->data << " ";
            ptr = ptr->next;
        }
        while (ptr->next != start);
    }
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
    int count;

    count = createLinkedList(head);
    displayLinkedList(head);
    freeLL();

    return 0;
}