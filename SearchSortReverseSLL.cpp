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
    int count = 1;
    ptr = nullptr;
    current = nullptr;

    std::cout << "creating a Linked List now: " << std::endl;

    do
    {
        ptr = (node*)malloc(sizeof(node));

        if (ptr == nullptr)
        {
            std::cout << "Memory Allocation Failed!";
            return 0;
        }

        std::cout << "Enter Data: ";
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

        std::cout << "Do you want to enter more nodes? (Y/N): ";
        std::cin >> ch;

        count++;
    } while (ch == 'Y' || ch == 'y');

    return count;
    
}

void displayLinkedList(node* head)
{
    node* p = head;

    if (head == nullptr)
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

void searchElement (node* head)
{
    int num, c=0;
    node* ptr = head;
    
    std::cout << "Enter the element you want to find in the linked list: ";
    std::cin >> num;
    
    while (ptr->next != nullptr)
    {
        if (ptr->data == num)
        {
            std::cout << "Found at index: " << c <<std::endl;
            return;
        }
        c++;
    }

    std::cout << "Element does not exist in the linked list!" << std::endl;
}

void sortLinkedList (node* head)
{
    node* ptr = head;
    int i, j;
    int count = createLinkedList();

    for (i=0; i<count; i++)
    {
        
    }
}

void freeLinkedList()
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
    int nodes;

    nodes = createLinkedList();
    displayLinkedList(head);
    searchElement(head);
    sortLinkedList(head);

    freeLinkedList();

    return 0;
}