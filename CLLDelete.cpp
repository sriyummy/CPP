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

void deleteBegin()
{
    if (head == nullptr)
    {
        std::cout << "The Circular Linked List is empty. Nothing to delete!" << std::endl;
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = nullptr;
        return;
    }

    node* current = head;
    while (current->next != head)
    {
        current = current->next;
    }

    node* temp = head;
    head = head->next;
    current->next = head;
    free(temp);
}

void deleteAtPosition(int position)
{
    if (head == nullptr)
    {
        std::cout << "The Circular Linked List is empty. Nothing to delete!" << std::endl;
        return;
    }

    if (position <= 0)
    {
        std::cout << "Invalid position. Cannot delete node." << std::endl;
        return;
    }

    if (position == 1)
    {
        deleteBegin();
        return;
    }

    int count = 1;
    node* current = head;
    node* prev = nullptr;

    while (count < position)
    {
        prev = current;
        current = current->next;
        count++;

        if (current == head)
        {
            std::cout << "Position out of range. Cannot delete node." << std::endl;
            return;
        }
    }

    prev->next = current->next;
    free(current);
}

void freeLL()
{
    while (head != nullptr)
    {
        deleteBegin();
    }
}

int main()
{
    int count;

    count = createLinkedList();
    displayLinkedList();

    std::cout << "\nDeleting the first node:" << std::endl;
    deleteBegin();
    displayLinkedList();

    int position;
    std::cout << "\nEnter the position of the node to delete: ";
    std::cin >> position;
    deleteAtPosition(position);
    displayLinkedList();

    freeLL();

    return 0;
}
