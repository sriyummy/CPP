#include <iostream>
#include <cstdlib>

struct node
{
    int data;
    struct node* next;
};

int main()
{
    node* head, *new_node, *temp;
    int ch = 1;
    head = nullptr;

    while (ch == 1)
    {
        new_node = (node*)malloc(sizeof(node));

        std::cout << "Enter data: ";
        std::cin >> new_node->data;

        if (head == nullptr)
        {
            head = temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
        }

        std::cout << "Do you want to continue making the Linked List?\n(0 to exit, 1 to continue)";
        std::cin >> ch;
    }

    temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    temp = head;
    while (temp != nullptr)
    {
        node* next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}
