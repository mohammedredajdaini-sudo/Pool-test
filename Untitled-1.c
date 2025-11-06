#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}node;

typedef struct {
    int len;
    node *head;
}list;

list *init(int value) {
    list *list = malloc(sizeof(*list));
    node *newnode = malloc(sizeof(*newnode));
    if(list==NULL || newnode==NULL)
    {
        exit(EXIT_FAILURE);
    }
    newnode->data = value;
    newnode->next = NULL;
    list->head = newnode;
    list->len = 1;
    return list;
}

void add_head (list *list, int value) {
    node *newnode = malloc(sizeof(*newnode));
    if(list==NULL || newnode==NULL) {
        exit(EXIT_FAILURE);
    }
    newnode->data = value;
    newnode->next = list->head;
    list->head = newnode;
    list->len++;
}


void append(list *list, int value) {
    node *newnode = malloc(sizeof(*newnode));
    if(list==NULL || newnode==NULL){
        exit(EXIT_FAILURE);
    }
    newnode->data = value;
    newnode->next = NULL;
    if(list->head == NULL) {
        list->head = newnode;
        return;
    }
    node *temp = list->head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    list->len++;
}

void delete_head(list *list) {
    if(list==NULL) {
        exit(EXIT_FAILURE);
    }
    if(list->head!=NULL) {
        node *todelete = list->head;
        list->head = list->head->next;
        free(todelete);
        list->len--;
    }
}

void delete_tail(list *list) {
    if(list==NULL) {
        exit(EXIT_FAILURE);
    }
    if(list->head == NULL) return;
    if(list->head->next == NULL) {
        delete_head(list);
        return;
    }
    else {
        node *temp = list->head;
        while(temp->next->next!=NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        list->len--;
    }
}

void print_list(list *list) {
    if(list==NULL) {
        exit(EXIT_FAILURE);
    }
    node *temp = list->head;
    while(temp!=NULL) {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL \n");
}