// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct
{
	char name[MAX_NAME];
	int age;
} person;

person *hash_table[TABLE_SIZE];

unsigned int hash(int age)
{
	return age % TABLE_SIZE;
}

void init_hash_table()
{
	for(int i = 0; i < TABLE_SIZE; i++)
	{
    	hash_table[i] = NULL;
	}
}

bool hash_insert(person *p)
{
	if(p == NULL)
	{
    	return false;
	}
	int index = hash(p->age);
	if(hash_table[index] != NULL)
	{
    	return false;
	}
	hash_table[index] = p;
	return true;
}

person *hash_lookup(int age)
{
	int index = hash(age);
	if(hash_table[index] != NULL && hash_table[index]->age == age)
	{
    	return hash_table[index];
	}
	else
	{
    	return NULL;
	}
}

person *hash_delete(int age)
{
	int index = hash(age);
	if(hash_table[index] != NULL && hash_table[index]->age == age)
	{
    	printf("deleted word=%s",hash_table[index]->name);
    	person *tmp = hash_table[index];
    	hash_table[index]=NULL;
    	return tmp;
	}
	else
	{
    	return NULL;
	}
}

void print_table()
{
	for(int i = 0; i < TABLE_SIZE; i++)
	{
    	if(hash_table[i] == NULL)
    	{
        	printf("%i\t---\n", i);
    	}
    	else
    	{
        	printf("%i\t%s\t---\n", i, hash_table[i]->name);
    	}
	}
}

int main()
{
	init_hash_table();
    
	person Jacob = {.name = "Jacob", .age = 26};
	person Kate = {.name = "Kate", .age = 27};
	person Moph = {.name = "Moph", .age = 30};
	person lilly = {.name = "lilly", .age = 19};
	person jake = {.name = "jake", .age = 27};
    
	hash_insert(&Jacob);
	hash_insert(&Kate);
	hash_insert(&Moph);
	hash_insert(&lilly);
	hash_insert(&jake);
	person *tmp = hash_lookup(19);
	if(tmp == NULL)
	{
		printf("not found\n");
	}
	else
	{
		printf("found %s\n", tmp->name);
	}
    
	hash_delete(19);
	printf("\n");
	print_table();
	return 0;
}

