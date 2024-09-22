#include <stdio.h>
#include <stdlib.h>

typedef enum // enum elements are unsignet int
{
    male,
    female
} Sex;

typedef struct 
{
    Sex sex;
    int age;
    char *name;
} Person;

int is_legal(Person *person)
{
    if (person->age >= 18)
        return 1;
    return 0;
}

int main()
{
    Person p1;
    
    p1.sex = male;
    printf("Sex of p1 is %u\n", p1.sex);

    p1.age = 32;
    printf("Age of p1 is %d\n", p1.age);

    printf("Is p1 legal: %d\n", is_legal(&p1));

    p1.name = (char *) malloc(sizeof(char) * 5);
    p1.name = "Name1";
    printf("Name of p1 is %s\n", p1.name);

    // struct pointers

    Person *p2;
    p2 = (Person *) malloc(sizeof(Person));

    p2->sex = female;
    printf("Sex of p2 is %u\n", p2->sex);

    p2->age = 46;
    printf("Age of p2 is %d\n", p2->age);

    printf("Is p2 legal: %d\n", is_legal(p2));

    p2->name = (char *) malloc(sizeof(char) * 5);
    p2->name = "Name2";
    printf("Name of p1 is %s\n", p2->name);

}
