#include <stdio.h>


typedef struct Person {
    int age;
    int id;
    char name[5];
}Person;

void get_input(char* prompt[10], char* input[10]) {
    printf("\n%s", prompt);
    scanf("%10s", input);
}

int main() {
    Person person1 = {.name = "john ", .age = 14, .id = 1};
    // char* input_p = get_input("enter your age: ");
    // printf("your input: %c\n", *input_p);
    char name_input[10];
    get_input("give me a name: ", name_input);
    printf("thats a nice name: %s\n", name_input);
    
    // char* age_input = get_input("give me an age: ");
    // person1.age = (int)*age_input;
    
    return 1;
}