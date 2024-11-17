#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PRIME 101

int naiveSearch(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int count = 0;

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m) {
            count++;
        }
    }
    return count;
}

int rabinKarpSearch(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int patternHash = 0, textHash = 0, count = 0;
    int i, j;

    for (i = 0; i < m; i++) {
        patternHash = (patternHash * PRIME + pattern[i]) % 100000;
        textHash = (textHash * PRIME + text[i]) % 100000;
    }

    for (i = 0; i <= n - m; i++) {
        if (patternHash == textHash) {
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m) {
                count++;
            }
        }

        if (i < n - m) {
            textHash = (PRIME * (textHash - text[i] * pow(PRIME, m - 1)) + text[i + m]) % 100000;
            if (textHash < 0) textHash = (textHash + 100000);
        }
    }
    return count;
}

void computeLPSArray(char *pattern, int m, int *lps) {
    int length = 0;
    int i = 1;
    lps[0] = 0;  

    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int kmpSearch(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int lps[m];
    int i = 0, j = 0;
    int count = 0;
    computeLPSArray(pattern, m, lps);

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            count++;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return count;
}

int main() {
    char text[] = "ABABABABCABABABABC";
    char pattern[] = "ABAB";
    int choice;

    printf("Select the string matching algorithm:\n");
    printf("1. Naive String Matching\n");
    printf("2. Rabin-Karp\n");
    printf("3. Knuth-Morris-Pratt (KMP)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    int result;
    switch (choice) {
        case 1:
            result = naiveSearch(text, pattern);
            printf("Naive String Matching: Found %d occurrences\n", result);
            break;
        case 2:
            result = rabinKarpSearch(text, pattern);
            printf("Rabin-Karp: Found %d occurrences\n", result);
            break;
        case 3:
            result = kmpSearch(text, pattern);
            printf("Knuth-Morris-Pratt (KMP): Found %d occurrences\n", result);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
