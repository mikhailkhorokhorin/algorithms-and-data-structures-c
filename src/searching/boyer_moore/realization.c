#include <string.h>

int boyer_moore(char* text, char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    if (m > n)
        return -1;

    for (int s = 0; s <= n - m;) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        if (j < 0)
            return s;

        int shift = 1;

        for (int k = j - 1; k >= 0; k--) {
            if (text[s + j] == pattern[k]) {
                shift = j - k;
                break;
            }
        }

        s += shift;
    }

    return -1;
}
