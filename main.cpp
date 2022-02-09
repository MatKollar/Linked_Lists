#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* first;
};


Node *createNode(const int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void prependNode(List *list, const int value) {
    Node *newNode = createNode(value);
    newNode->next = list->first;
    list->first = newNode;
}

void appendNode(List *list, const int value) {
    Node *newNode = createNode(value);
    if (!list->first)
        list->first = newNode;
    else {
        Node *tmp = list->first;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}

void insertNode(List *list, const int val, int index) {
    Node *newNode = createNode(val);
    if (!list->first) {
        list->first = newNode;
    }
    else {
        Node *tmp = list->first;
        Node *prev = list->first;

        int count = 0;
        while (tmp) {

            if(count == index){
                newNode->next = prev->next;
                prev->next=newNode;
                break;
            }
            count++;
            prev = tmp;
            tmp = tmp->next;
        }
    }
}

void removeFirstNode(List *list) {
    if (list->first) {
        Node *tmp = list->first->next;
        delete list->first;
        list->first = tmp;
    }
}

Node *findNode(const List *list, const int value) {
    Node *tmp = list->first;
    while (tmp) {
        if (tmp->data == value)
            return tmp;
        tmp = tmp->next;
    }
    return nullptr;
}

void printList(const List *list) {
    Node *tmp = list->first;
    while (tmp) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void deleteNodes(List *list) {
    Node *tmp;
    while (list->first) {
        tmp = list->first->next;
        delete list->first;
        list->first = tmp;
    }
}

void deleteList(List **list) {
    deleteNodes(*list);
    delete (*list);
    (*list) = nullptr;
}

int main() {

    List *list = new List;
    list->first = nullptr;

    for (int i = 0; i < 3; i++)
        prependNode(list, i);

    for (int i = 0; i < 3; i++)
        appendNode(list, i);

    insertNode(list, 10, 3);
    removeFirstNode(list);
    findNode(list, 10);
    printList(list);
    deleteList(&list);

    return 0;
}
