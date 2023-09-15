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
    ptr = nullptr;
    current = nullptr;
    char ch;
    int c = 1;

    std::cout << "Creating a Circular Linked List now:" << std::endl;

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

void displayLinkedList()
{
    node* ptr = head;
    if (head == nullptr)
    {
        std::cout << "The Circular Linked List is empty!";
        return;
    }
    else
    {
        do
        {
            std::cout << ptr->data << " ";
            ptr = ptr->next;
        } while (ptr != head);
    }
}

void freeLL()
{
    node* current = head;
    node* next;

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

    count = createLinkedList();
    displayLinkedList();
    freeLL();

    return 0;
}
