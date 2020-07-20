#include<iostream>
#include<string.h>

using namespace std;

typedef struct list {
    int value;
    struct list* next;
}Node;

class List {

    Node* head;

    Node* adress(int index) {
        Node* p;
        p = head;
        for (int i = 0; i < index; i++) {
            p = p->next;
        }
        return p;
    }
public:

    List(int value) {

        head = (Node*)malloc(sizeof(Node));
        head->value = value;
        head->next = NULL;
    }

    void insert(int index, int value) {

        Node* elem = (Node*)malloc(sizeof(Node));
        elem->value = value;
        elem->next = adress(index);

        if (index != 0) {
            adress(index - 1)->next = elem;
        }
        else {
            head = elem;
        }
    }

    void remove(int index) {

        if (index != 0) {
            Node* g;
            g = adress(index);
            adress(index - 1)->next = adress(index + 1);
            free(g);
        }
        else {
            Node* f;
            f = adress(index + 1);
            free(head);
            head = f;
        }
    }

    int get(int index) {
        return adress(index)->value;
    }


    int find(int value) {

        int count = 0;
        Node* k;
        k = head;
        while (k != NULL) {

            if (k->value == value) {
                return count;
            }
            k = k->next;
            count++;
        }
        return -1;
    }

    void print_list() {
        Node* p;
        p = head;
        while (p != NULL) {
            cout << p->value << endl;
            p = p->next;
        }
    }

};


int main() {

    List list(145);

    int coun = 1;
    for (int i = 0; i < 20; i++) {
        list.insert(coun, i);
        coun++;
    }

    list.print_list();
    return 0;
}

