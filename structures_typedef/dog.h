#ifndef DOG_H
#define DOG_H
/**
 * struct dog - dog structure
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 */
typedef struct dog
{
char *name;
float age;
char *owner;
} dog_t;
/**
 * init_dog - initialize a dog structure
 * @d: pointer to struct dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 */
void init_dog(struct dog *d, char *name, float age, char *owner);
/**
 * print_dog - prints a struct dog
 * @d: pointer to struct dog
 */
void print_dog(struct dog *d);
#endif
