#include<stdio.h>
#include<string.h>


typedef struct list {
    int value;
    struct list* next;
}Node;

typedef struct List {
    Node* head;
}List;


void init(List* list, int value) {

    list->head = (Node*)malloc(sizeof(Node));
    list->head->value = value;
    list->head->next = NULL;
}

Node* adress(List* list, int index) {
    Node* p;
    p = list->head;
    for (int i = 0; i < index; i++) {
        p = p->next;
    }
    return p;
}


void insert(List* list, int index, int value) {

    Node* elem = (Node*)malloc(sizeof(Node));
    elem->value = value;
    elem->next = adress(list, index);

    if (index != 0) {
        adress(list, index - 1)->next = elem;
    }
    else {
        list->head = elem;
    }
}


void remove(List* list, int index) {

    if (index != 0) {
        Node* g;
        g = adress(list, index);
        adress(list, index - 1)->next = adress(list, index + 1);
        free(g);
    }
    else {
        Node* f;
        f = adress(list, index + 1);
        free(list->head);
        list->head = f;
    }
}


int get(List* list, int index) {
    return adress(list, index)->value;
}


int find(List* list, int value) {

    int count = 0;
    Node* k;
    k = list->head;
    while (k != NULL) {

        if (k->value == value) {
            return count;
        }
        k = k->next;
        count++;
    }
    return -1;
}

void print_list(Node* list) {
    Node* p;
    p = list;
    while (p != NULL) {
        printf_s("%d\n", p->value);
        p = p->next;
    }
}

int main() {

    List list;

    int coun = 1;

    init(&list, 145);
    for (int i = 1; i < 50; i++) {
        insert(&list, coun, i);
        coun++;
    }

    print_list(list.head);


    return 0;
}
