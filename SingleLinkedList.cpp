#include <iostream>
#include <cstdlib>

struct node
{
    int data;
    struct node* next;
};
node* head;

void inputLL()
{
    node* ptr, *current;
    char ch;
    ptr = nullptr;
    current = nullptr;

    std::cout << "Creating a linked list now: " << std::endl;
    head = nullptr;

    do
    {
        ptr = (struct node*)malloc(sizeof(struct node)); 

        if (ptr == nullptr)
        {
            std::cout << "Memory Allocation Failed :(" << std::endl;
            return;
        }

        std::cout << "Enter data: ";
        std::cin >> ptr->data;

        ptr->next = nullptr;

        if (head == NULL)
        {
            head = ptr;
            current = ptr;
        }
        else
        {
            current->next = ptr;
            current = ptr;
        }

        std::cout << "Do you want to add more nodes? (Y/N): ";
        std::cin >> ch;
    } while (ch == 'Y' || ch == 'y');
}

void displayLL()
{
    struct node* p = head;

    if (head == nullptr)
    {
        std::cout << "List is empty!";
        return;
    }
    else
    {
        while (p!=nullptr)
        {
            std::cout << p->data << " ";
            p = p->next;
        }
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
    inputLL();
    displayLL();
    freeLL();

    return 0;
}