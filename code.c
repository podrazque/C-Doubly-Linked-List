#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct node
{
    struct node* next;
    struct node* prev;
    int data;
} node_t;

node_t* head = NULL;
node_t* tail = NULL;

void append(int data)
{
    node_t* it = malloc(sizeof(node_t));
    tail->next = it;
    it->next = NULL;
    it->prev = tail;
    tail = it;
    it->data = data;
}

void prepend(int data)
{
    node_t* it = malloc(sizeof(node_t));
    head->prev = it;
    it->next = head;
    it->prev = NULL;
    head = it;
    it->data = data;
}

void add_head(int data)
{
    node_t* it = malloc(sizeof(node_t));
    head = it;
    tail = it;

    head->data = data;
    tail->data = data;

    head->prev = NULL;
    head->next = NULL;
    tail->prev = NULL;
    tail->next = NULL;
}

void insert_at(int data, int _1, int _2)
{
    node_t* it = head;
    node_t* _new = malloc(sizeof(node_t));
    for( ; it ; it = it->next )
    {
        if(it->data == _1 && it->next->data == _2)
        {
            node_t* next = it->next;
            it->next = _new;
            _new->prev = it;
            _new->next = next;
            _new->data = data;
            next->prev = _new;
        }
    }
}

void print_my_shit()
{
    node_t* it = head;
    for( ; it ; it = it->next )
    {
        printf(" %d ->", it->data);
    }

    printf("\n\n");
}

int main(int argc, char* argv[])
{

    for( int i = 1; i < argc; i++)
    {
        if(!head && !tail)
        {
            add_head(atoi(argv[i]));
        }
        else if(head && tail)
        {
            append(atoi(argv[i]));
        }
    }

    print_my_shit();

    prepend(19);
    append(25);
    insert_at(5, 1, 2);

    print_my_shit();

    return 0;
}