#include <iostream>
#include <cstdlib>

struct node
{
    int data;
    node* next;
};

node* head = nullptr;

node* createNode(int val)
{
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode)
    {
        newNode->data = val;
        newNode->next = nullptr;
    }
    return newNode;
}

void insertEnd(int val)
{
    node* newNode = createNode(val);
    if (!newNode)
    {
        std::cout << "Memory Allocation Failed!" << std::endl;
        return;
    }

    if (head == nullptr)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        node* current = head;
        while (current->next != head)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
    }
}

void insertBegin(int val)
{
    node* newNode = createNode(val);
    if (!newNode)
    {
        std::cout << "Memory Allocation Failed!" << std::endl;
        return;
    }

    if (head == nullptr)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        node* current = head;
        while (current->next != head)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
        head = newNode; 
    }
}

void displayCircularLinkedList()
{
    node* ptr = head;

    if (head == nullptr)
    {
        std::cout << "The Circular Linked List is empty!" << std::endl;
        return;
    }
    else
    {
        do
        {
            std::cout << ptr->data << " ";
            ptr = ptr->next;
        } while (ptr != head);
        std::cout << std::endl;
    }
}

void freeLL()
{
    if (head == nullptr)
    {
        return;
    }

    node* current = head;
    node* next;

    do
    {
        next = current->next;
        free(current);
        current = next;
    } while (current != head);
}

int main()
{
    char ch;
    int value, choice, position;

    std::cout << "Creating a Circular Linked List now:" << std::endl;

    do
    {
        int data;
        std::cout << "Enter data: ";
        std::cin >> data;
        insertEnd(data);

        std::cout << "Do you want to add more nodes? (Y/N): ";
        std::cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    displayCircularLinkedList();

    std::cout << "Enter the value you want to insert in the Linked List: ";
    std::cin >> value;
    
    std::cout << "Press 1 to insert at beginning: \nPress 2 to insert at a position: \nPress 3 to insert at the end: " << std::endl;
    std::cin >> choice;

    do
    {
        std::cout << "Proceed with insertions? (Y/N): ";
        std::cin >> ch;

        switch (choice)
        {
            case 1:
                insertBegin(value);
                displayCircularLinkedList();
                break;

            case 2:
                std::cout << "Enter the position you want to insert your element in: ";
                std::cin >> position;
                break;

            case 3:
                insertEnd(value);
                displayCircularLinkedList();
                break;

            default:
                std::cout << "Enter a valid option please!";
                break;
        }

    } while (ch == 'Y' || ch == 'y');

    freeLL();

    return 0;
}