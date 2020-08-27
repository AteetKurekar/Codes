Java:
package beginners;

import java.util.LinkedList;
import java.util.Scanner;
import java.util.Iterator;
public class Solution {

public static void main(String[] args) {
	LinkedList<Integer> ll=new LinkedList<Integer>();
	System.out.println("ENter no. of elements:");
	Scanner sc=new Scanner(System.in);
	int n=sc.nextInt();
	for(int i=0;i<n;i++) {
		int n1=sc.nextInt();
		ll.add(n1);
	}
	System.out.println("Insert data and position:");
	int data=sc.nextInt();
	int pos=sc.nextInt();
	ll.add(pos, data);
	Iterator<Integer> it=ll.iterator();
	while(it.hasNext()) {
		System.out.println(it.next());
	}
}
}

==============================================================================================
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

typedef struct SinglyLinkedListNode SinglyLinkedListNode;
typedef struct SinglyLinkedList SinglyLinkedList;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

struct SinglyLinkedList {
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;
};

SinglyLinkedListNode* create_singly_linked_list_node(int node_data) {
    SinglyLinkedListNode* node = malloc(sizeof(SinglyLinkedListNode));

    node->data = node_data;
    node->next = NULL;

    return node;
}

void insert_node_into_singly_linked_list(SinglyLinkedList** singly_linked_list, int node_data) {
    SinglyLinkedListNode* node = create_singly_linked_list_node(node_data);

    if (!(*singly_linked_list)->head) {
        (*singly_linked_list)->head = node;
    } else {
        (*singly_linked_list)->tail->next = node;
    }

    (*singly_linked_list)->tail = node;
}

void print_singly_linked_list(SinglyLinkedListNode* node, char* sep, FILE* fptr) {
    while (node) {
        fprintf(fptr, "%d", node->data);

        node = node->next;

        if (node) {
            fprintf(fptr, "%s", sep);
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int pos){
        if(head==NULL){
            if(pos>0){
                //printf("Create a list first\n");
                return head;
            }
            else if(pos<0){
                //printf("Not possible\n");
                return head;
            }
            else{
                SinglyLinkedListNode* temp=(SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
                temp->data=data;
                temp->next=NULL;
                head=temp;
                return head;
            }
            
        }
        SinglyLinkedListNode* current=head;
        SinglyLinkedListNode* prev=head;
        int count=0;
        while(current->next!=NULL && count<pos){
            prev=current;
            current=current->next;
            count++;
        }
        if(count==pos){
            SinglyLinkedListNode* temp=(SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
            temp->data=data;
            temp->next=current;
            prev->next=temp;
            return head;
        }
        else{
            //printf("Position defined is greater than size of linked list\n");
            return head;
        }
}


int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    SinglyLinkedList* llist = malloc(sizeof(SinglyLinkedList));
    llist->head = NULL;
    llist->tail = NULL;

    char* llist_count_endptr;
    char* llist_count_str = readline();
    int llist_count = strtol(llist_count_str, &llist_count_endptr, 10);

    if (llist_count_endptr == llist_count_str || *llist_count_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int i = 0; i < llist_count; i++) {
        char* llist_item_endptr;
        char* llist_item_str = readline();
        int llist_item = strtol(llist_item_str, &llist_item_endptr, 10);

        if (llist_item_endptr == llist_item_str || *llist_item_endptr != '\0') { exit(EXIT_FAILURE); }

        insert_node_into_singly_linked_list(&llist, llist_item);
    }

    char* data_endptr;
    char* data_str = readline();
    int data = strtol(data_str, &data_endptr, 10);

    if (data_endptr == data_str || *data_endptr != '\0') { exit(EXIT_FAILURE); }

    char* position_endptr;
    char* position_str = readline();
    int position = strtol(position_str, &position_endptr, 10);

    if (position_endptr == position_str || *position_endptr != '\0') { exit(EXIT_FAILURE); }

    SinglyLinkedListNode* llist_head = insertNodeAtPosition(llist->head, data, position);

    char *sep = " ";

    print_singly_linked_list(llist_head, sep, fptr);
    fprintf(fptr, "\n");

    free_singly_linked_list(llist_head);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
