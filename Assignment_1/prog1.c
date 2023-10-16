//Nicholas Domingue & Bryce Olivier
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 512

// sample comparison function for qsort():

int cmp(const void *p1, const void *p2) {
    const char *s1 = *(const char **)p1;
    const char *s2 = *(const char **)p2;
    
    return strcmp(s1, s2);
}

int main(int argc, char *argv[]) {
    char **strings = NULL;  
    int i, n;
    char buf[BUFSIZE + 1];

    printf("Enter # of strings: ");
    fflush(stdout);
    fgets(buf, BUFSIZE, stdin);
    n = atoi(buf);
    strings = (char **)malloc(n * sizeof(char *));

    for (i = 0; i < n; i++) {
        printf("Enter string # %d\n", i+1);
        strings[i] = (char *)malloc(BUFSIZE + 1);
        fgets(strings[i], BUFSIZE, stdin);

        int size = strlen(strings[i]);
        if (size > 0 && strings[i][size - 1] == '\n') {
            strings[i][size - 1] = '\0';
        } else {
            // For invalid strings, get rid of extra characters
            while (getchar() != '\n');
        }
    }

    qsort(strings, n, sizeof(char *), cmp);

    printf("Sorted strings:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
        free(strings[i]);
    }

    free(strings);
  
    return 0;
}


