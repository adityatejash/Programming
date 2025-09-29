#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    char copy[len];   // keep as in your code
    int count = 0;

    for (int i = 0; i < len; i++) {           // fixed loop condition
        for (int j = i + 1; j < len; j++) {   // fixed loop condition
            if (s[i] == s[j]) {
                count++;
            } else {
                copy[i] = s[i];  // keeps original logic
            }
        }
    }

    return count;  // added return, otherwise undefined behavior
}

int main() {
    char s[] = "abcabcbb";
    int length = lengthOfLongestSubstring(s);  // pass s, not &s
    printf("%d\n", length);                    // print the result
    return 0;
}
