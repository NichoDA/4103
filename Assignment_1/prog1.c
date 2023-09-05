//Nicholas Domingue & Bryce Olivier
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 512

// Sample comparison function for qsort():

int cmp(const void *p1, const void *p2) {
    const char *str1 = *(const char **)p1;
    const char *str2 = *(const char **)p2;
    return strcmp(str1, str2);
}

int main() {
    int n;
    char buf[BUFSIZE + 1];

    printf("Enter the number of strings: ");
    fflush(stdout);
    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        perror("fgets");
        return 1;
    }

    n = atoi(buf);
    if (n <= 0) {
        printf("Invalid number of strings.\n");
        return 1;
    }

    char **strings = (char **)malloc(n * sizeof(char *));
    if (strings == NULL) {
        perror("malloc");
        return 1;
    }

    // Read and store the strings
    for (int i = 0; i < n; i++) {
        printf("Enter string #%d: ", i + 1);
        fflush(stdout);
        if (fgets(buf, sizeof(buf), stdin) == NULL) {
            perror("fgets");
            return 1;
        }

        // Remove the newline character (if present) and truncate to 512 characters
        size_t len = strlen(buf);
        if (len > 0 && buf[len - 1] == '\n') {
            buf[len - 1] = '\0';
            len--;
        }
        if (len > BUFSIZE) {
            buf[BUFSIZE] = '\0';
        }

        strings[i] = (char *)malloc((len + 1) * sizeof(char));
        if (strings[i] == NULL) {
            perror("malloc");
            return 1;
        }

        strcpy(strings[i], buf);
    }

    // Sort the strings using qsort
    qsort(strings, n, sizeof(char *), cmp);

    // Output the sorted strings
    printf("Sorted strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
        free(strings[i]);
    }

    free(strings);

    return 0;
}

