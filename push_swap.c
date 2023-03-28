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
/////////////////
/// MAKE PUSH_SWAP MOVES

void pushToStack(struct Node** stackA, struct Node** stackB, char *name) {
    if (*stackA == NULL) {
        return;
    }
    struct Node* temp = *stackA;
    *stackA = (*stackA)->next;
    temp->next = *stackB;
    *stackB = temp;
    printf("%s\n", name);
}


void rotate_move(struct Node** head, char *name) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;

    struct Node* curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = temp;
    temp->next = NULL;
    printf("%s\n", name);
}


void reverse_rotate_move(struct Node** head, char *name) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    struct Node* curr = *head;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }

    struct Node* temp = curr->next;
    curr->next = NULL;
    temp->next = *head;
    *head = temp;
    printf("%s\n", name);
}

void swap_move(struct Node** head, char *name) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    struct Node* temp = (*head)->next;
    (*head)->next = temp->next;
    temp->next = *head;
    *head = temp;
    printf("%s\n", name);
}


///////////////////
/// PRINTING MOVES


void printStacks(struct Node* stackA, struct Node* stackB) {
    printf("A | B\n");
    printf("--|---\n");

    while (stackA != NULL || stackB != NULL) {
        if (stackA != NULL) {
            printf("%d | ", stackA->int_value);
            stackA = stackA->next;
        } else {
            printf("  | ");
        }

        if (stackB != NULL) {
            printf("%d", stackB->int_value);
            stackB = stackB->next;
        }

        printf("\n");
    }
}



void print_stack(struct Node* head) {
    while (head != NULL) {
        printf("%d\n", head->int_value);
        head = head->next;
    }
}

void   print_all_stack_info(struct Node* stackA)
{
    while (stackA != NULL)
    {
        printf("\nint value = %d - > final value = %d -start index = %d \n", stackA->int_value, stackA->final_position, stackA->index_value);
        stackA = stackA->next;
    }
}


////////////

int update_stack(struct Node* head) {
    int i = 0;
    while (head != NULL) {
        head->index_value = i;
        i++;
        head = head->next;
    }
    return (i);
}

int search_stack(struct Node* head, int final)
{
    int i = 0;
    while (head != NULL) {
        if (head->final_position == final)
            return (i);
        head = head->next;
        i++;
    }
    return 0;
}

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


///////////////
////PUSH SWAP
void basic_push_swap(struct Node* stackA, struct Node* stackB, int argc)
{
    int t = 0;

        while (t < argc - 1)
        {
            while (stackA->final_position != t)
            {
                rotate_move(&stackA,"ra");
            }
            pushToStack(&stackA,&stackB,"pa");
            t++;
        }

        while (t != 0)
        {
            pushToStack(&stackB,&stackA,"pb");
            t--;
        }    
}





int main(int argc, char **argv) {

    int numberofvalues = argc;
    int i = 1;
    int values_list[argc];

    // read all values and send them to values_list and Node
    struct Node* stackA = NULL;
    struct Node* stackB = NULL;

    while (argv[i] != NULL)
    {
        if (!check_list_ints(argv[i])) {
            printf("Error: List contains non-integer values\n");
            return 1;
        }
        values_list[i-1] = ft_atoi(argv[i]);
        addNode(&stackA, ft_atoi(argv[i]), i-1, 0);
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
    while (i <= argc - 2)
    {
        //printf("%d, ", values_list[i]);
        i++;
    }

    // print Node Values
    //printf("\nprinting Node Values \n");

    struct Node* currentNode = stackA;
    while (currentNode != NULL) {
        // look for final_position before printing values
        int k = 0;
        while(currentNode->int_value != values_list[k]){
            k++;
        }
        currentNode->final_position = k;
        //printf("int_value: %d, index_value: %d, final_position: %d\n", currentNode->int_value, currentNode->index_value, currentNode->final_position);
        currentNode = currentNode->next;
    }

    ///////////////
    // TESTER PART
    


    ///////////////////////////////////////////////////
    ////////////  SIMPLE PUSH SWAP   /////////////////

    // int t = 0;
    
    // while (t < argc - 1)
    // {
    //     while (stackA->final_position != t)
    //     {
    //         rotate_move(&stackA,"ra");
    //     }
    //     pushToStack(&stackA,&stackB,"pa");
    //     t++;
    // }

    // while (t != 0)
    // {
    //     pushToStack(&stackB,&stackA,"pb");
    //     t--;
    // }    
    //basic_push_swap(stackA,stackB,argc);

    //////////////////////////////////////////////////
    ////////////         END         /////////////////
   


   ///////////////////////////////////////////////////
    //////////// NEW ALGO CRAZY  /////////////////
   
    while (stackA != NULL)
    {
        if (stackA->next != NULL)
            if (stackA->int_value > stackA->next->int_value){
                swap_move(&stackA,"sa");
            }
        pushToStack(&stackA,&stackB,"pa");


        if (stackB->next != NULL)
        {
            struct Node* temp2 = stackB->next;
            if (temp2->next != NULL)
            {
                if(stackB->int_value < temp2->next->int_value)
                {
                    rotate_move(&stackB,"rb");
                }
            }
        }

        if (stackB->next != NULL)
        {
            if (stackB->int_value < stackB->next->int_value){
                swap_move(&stackB,"sb");
            }
        }
        //printStacks(stackA,stackB);
    }

    int final = argc - 2;
    while (stackB != NULL)    
    {
        while (stackB->final_position != final)
        {
            int nb_of_values = update_stack(stackB);
            int final_number = search_stack(stackB, final);
            if (final_number < nb_of_values/2)
            {
                rotate_move(&stackB,"rb");
            }
            else 
            {
                reverse_rotate_move(&stackB,"rrb");
            }
        }
        pushToStack(&stackB,&stackA,"pb");
        final -= 1;
        //printStacks(stackA,stackB);
    }

    //while (stackB != NULL)
    //{
    //    if (stackB->next != NULL)
    //        if (stackB->int_value < stackB->next->int_value){
    //            swap_move(&stackB,"sb");
    //        }
    //    pushToStack(&stackB,&stackA,"pb");
//
    //    if (stackA->next != NULL)
    //        if (stackA->int_value > stackA->next->int_value){
    //            swap_move(&stackA,"sa");
    //        }
    //    // printStacks(stackA,stackB);
    //}
    
    



   
   
    //printStacks(stackA,stackB);
    
    //print_all_stack_info(stackA);
    //update_stack(stackA);
    //print_all_stack_info(stackA);


    /// Write stack actions and possibilities (understand if its near top or bottom) (calculate steps to right position in B) (It would be nice to get a cost for several moves) (Maybe have preprocesser for the numbers that would define wich will be the best process to use)

    /// Write a preprossecer that get the index and desired postions, (This will analyse the best way to approach this exercise)
    /// This preprossecer will evaluate costs and define wich set o actions will have the less cost to do.

    /// Here you should understand how your algo will begin and calculate your costs:


    /// Need to make push and swap to transform nodes to right positions

    // END
    // printf("The List is clean :)");
    return 0;
}



