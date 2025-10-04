#include <string.h>

void computeLPS(char* pat, int m, int lps[]) {
    int len = 0;
    lps[0] = 0;

    for (int i = 1; i < m; i++) {
        while (len > 0 && pat[i] != pat[len])
            len = lps[len - 1];
        if (pat[i] == pat[len])
            len++;
        lps[i] = len;
    }
}

int KMP(char* text, char* pat) {
    int n = strlen(text), m = strlen(pat), j = 0;
    int lps[m];

    computeLPS(pat, m, lps);

    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pat[j])
            j = lps[j - 1];

        if (text[i] == pat[j])
            j++;

        if (j == m)
            return i - m + 1;
    }
    return -1;
}
