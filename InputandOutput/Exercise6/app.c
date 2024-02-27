#include <stdio.h>
#include <string.h>

/**
 * @brief Searches for a pattern in a file and prints the lines where the pattern is found.
 * @param[in] fp Pointer to the file to be searched.
 */
void mstrindex(FILE *fp)
{
    char pattern[] = "ould";
    char line[1000];
    int count = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, pattern) != NULL) {
            printf("Pattern found at line:%s",line);
            fclose(fp);
            count++;
        }
    }
    if(count ==0)
    {
        printf("Pattern not found");
        fclose(fp);
    }
}

/**
 * @brief Main function.
 * @param[in] argc Number of command-line arguments.
 * @param[in] argv Array of command-line arguments.
 * @return 0 on success.
 */
int main(int argc, char *argv[]) 
{
    FILE *fp = fopen(argv[1], "r");
    mstrindex(fp);
    return 0;
}

