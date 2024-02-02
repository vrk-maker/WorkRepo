#include <stdio.h>
#include <string.h>

// Structure to store word and its count
struct WordCount {
    char word[50];
    int count;
};

void countOccurrences(char *str, char *word) {
    char *p, *q;
    int v = -1;

    // split the string by spaces in a
    char *a[300], *b[300];
    int index = 0, k = 0;

    p = strtok(str, " ");
    while (p != NULL) {
        a[index++] = p;
        p = strtok(NULL, " ");
    }

    q = strtok(word, " ");
    while (q != NULL) {
        b[k++] = q;
        q = strtok(NULL, " ");
    }

    // Create an array of WordCount structures
    struct WordCount wordCounts[300];
    int numWords = 0;

    // Create an array to mark the status of each word
    int marked[300] = {0}; // Initialized to 0

    // Count occurrences and store in the WordCount array
    for (int l = 0; l < k; l++) {
        int c = 0;
        for (int j = 0; j < index; j++) {
            if (strcmp(b[l], a[j]) == 0 && marked[j] != 1) {
                c++;
                marked[j] = 1; // Mark the word as counted
            }
        }

        // Store word and count in the WordCount array
        if (c > 0) {
            strcpy(wordCounts[numWords].word, b[l]);
            wordCounts[numWords].count = c;
            numWords++;
        }
    }

    // Sort the WordCount array based on counts in descending order
    for (int i = 0; i < numWords - 1; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (wordCounts[i].count < wordCounts[j].count) {
                // Swap positions if counts are not in descending order
                struct WordCount temp = wordCounts[i];
                wordCounts[i] = wordCounts[j];
                wordCounts[j] = temp;
            }
        }
    }

    // Display the word count in decreasing order
    printf("Word Count in Decreasing Order:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s--->\tcount:%d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

// Driver code
int main() {
    char str[] = "A A portal portal computer science science portal";
    char word[] = "A portal computer science portal";
    countOccurrences(str, word);
    return 0;
}

