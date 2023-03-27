#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



//////////////////
/// CREATE NODES

struct Node {
    int int_value;
    int index_value;
    int final_position;
    struct Node* next;
};

void addNode(struct Node** head, int int_value, int index_value, int final_position) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->int_value = int_value;
    newNode->index_value = index_value;
    newNode->final_position = final_position;
    newNode->next = NULL;

    // If the list is empty, set the new node as the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Find the last node in the list
    struct Node* lastNode = *head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    // Add the new node to the end of the list
    lastNode->next = newNode;
}

//////////////////



int has_duplicate(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return 1; // Found a duplicate
            }
        }
    }
    return 0; // No duplicates found
}


void sort_int_array(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int ft_atoi(char *str) {
    int num = 0;
    int sign = 1;

    // Check for optional sign
    if (*str == '+' || *str == '-') {
        if (*str == '-') {
            sign = -1;
        }
        str++;
    }

    // Convert digits to integer value
    while (*str) {
        num = num * 10 + (*str - '0');
        str++;
    }

    // Apply sign and return result
    return sign * num;
}


int check_list_ints(char *list) {
    while (*list != '\0') {
        if (!isdigit(*list) && *list != ' ' && *list != '-') {
            return 0;
        }
        list++;
    }
    return 1;
}






int main(int argc, char **argv) {

    int numberofvalues = argc;
    int i = 1;
    int values_list[argc];

    // read all values and send them to values_list and Node
    struct Node* head = NULL;

    while (argv[i] != NULL)
    {
        if (!check_list_ints(argv[i])) {
            printf("Error: List contains non-integer values\n");
            return 1;
        }
        values_list[i-1] = ft_atoi(argv[i]);
        addNode(&head, ft_atoi(argv[i]), i-1, 0);
        //printf("number %d = %d\n", i, ft_atoi(argv[i]));
        i++;
    }

    // Check for duplicates
    if(has_duplicate(values_list,argc-1)){
        printf("Error, there are values with duplicates");
        return 0;
    }

    // Sort the values by list
    sort_int_array(values_list,argc-1);
    i = 0;

    // print the values
    while (i <= argc-2)
    {
        printf("%d, ", values_list[i]);
        i++;
    }

    // print Node Values
    printf("\nprinting Node Values \n");

    struct Node* currentNode = head;
    while (currentNode != NULL) {
        // look for final_position before printing values
        int k = 0;
        while(currentNode->int_value != values_list[k]){
            k++;
        }
        currentNode->final_position = k;
        printf("int_value: %d, index_value: %d, final_position: %d\n", currentNode->int_value, currentNode->index_value, currentNode->final_position);
        currentNode = currentNode->next;
    }

    /// Write stack actions and possibilities (understand if its near top or bottom) (calculate steps to right position in B) (It would be nice to get a cost for several moves) (Maybe have preprocesser for the numbers that would define wich will be the best process to use)

    /// Write a preprossecer that get the index and desired postions, (This will analyse the best way to approach this exercise)

    /// Here you should understand how your algo will begin and calculate your costs:


    /// Need to make push and swap to transform nodes to right positions

    // END
    printf("The List is clean :)");
    return 0;
}
