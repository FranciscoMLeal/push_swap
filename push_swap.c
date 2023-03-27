#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


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

    while (argv[i] != NULL)
    {
        if (!check_list_ints(argv[i])) {
            printf("Error: List contains non-integer values\n");
            return 1;
        }
        values_list[i-1] = ft_atoi(argv[i]);
        //printf("number %d = %d\n", i, ft_atoi(argv[i]));
        i++;
    }
    if(has_duplicate(values_list,argc-1)){
        printf("Error, there are values with duplicates");
        return 0;
    }
    sort_int_array(values_list,argc-1);
    i = 0;
    while (i <= argc-2)
    {
        printf("%d, ", values_list[i]);
        i++;
    }

    printf("The List is clean :)");
    return 0;
}
