#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

enum {
    MAX_NAME = 256, /**< Maximum length of a person's name */
    TABLE_SIZE = 10 /**< Size of the hash table */
};

/**
 * @struct person
 * @brief Structure representing a person with a name and an age.
 */
typedef struct {
    char name[MAX_NAME];
    int age;
} person;

person *hash_table[TABLE_SIZE];/**< Hash table to store persons */


/**
 * @brief Hashes the age to an index in the hash table.
 * @param[in] age The age to hash.
 * @return The index in the hash table.
 */
int hash(int age) {
    return age % TABLE_SIZE;
}

/**
 * @brief Initializes the hash table.
 */
void init_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

/**
 * @brief Inserts a person into the hash table.
 * @param[in] p Pointer to the person to insert.
 * @return true if insertion is successful, false otherwise.
 */
bool hash_install(person *p) {
    if (p == NULL) {
        return false;
    }
    int index = hash(p->age);
    if (hash_table[index] != NULL) {
        return false;
    }
    hash_table[index] = p;
    return true;
}

/**
 * @brief Looks up a person in the hash table based on age.
 * @param[in] age The age of the person to look up.
 * @return Pointer to the person if found, NULL otherwise.
 */
person *hash_lookup(int age) {
    int index = hash(age);
    if (hash_table[index] != NULL && hash_table[index]->age == age) {
        return hash_table[index];
    } else {
        return NULL;
    }
}

/**
 * @brief Deletes a person from the hash table based on age.
 * @param[in] age The age of the person to delete.
 * @return Pointer to the deleted person if found, NULL otherwise.
 */
person *hash_delete(int age) {
    int index = hash(age);
    if (hash_table[index] != NULL && hash_table[index]->age == age) {
        printf("deleted word=%s", hash_table[index]->name);
        person *tmp = hash_table[index];
        hash_table[index] = NULL;
        return tmp;
    } else {
        return NULL;
    }
}

/**
 * @brief Prints the contents of the hash table.
 */
void print_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            printf("%i\t---\n", i);
        } else {
            printf("%i\t%s\t---\n", i, hash_table[i]->name);
        }
    }
}

int main() {
    init_hash_table();

    person Jacob = {.name = "Jacob", .age = 26};
    person Kate = {.name = "Kate", .age = 27};
    person Moph = {.name = "Moph", .age = 30};
    person lilly = {.name = "lilly", .age = 19};
    person jake = {.name = "jake", .age = 24};

    hash_install(&Jacob);
    hash_install(&Kate);
    hash_install(&Moph);
    hash_install(&lilly);
    hash_install(&jake);

    print_table();
    return 0;
}

