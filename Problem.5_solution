#include <stdlib.h>
#include <string.h>

void expandAroundCenter(char* s, int n, int left, int right, int* start, int* maxLen) {
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
    
    // Length of the valid palindrome is (right - 1) - (left + 1) + 1 = right - left - 1
    int currentLen = right - left - 1;
    if (currentLen > *maxLen) {
        *maxLen = currentLen;
        *start = left + 1;
    }
}

char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n == 0) return "";
    
    int start = 0;
    int maxLen = 1;
    
    for (int i = 0; i < n; i++) {
        // Odd-length palindromes (centered at i)
        expandAroundCenter(s, n, i, i, &start, &maxLen);
        
        // Even-length palindromes (centered between i and i + 1)
        expandAroundCenter(s, n, i, i + 1, &start, &maxLen);
    }
    
    char* result = (char*)malloc((maxLen + 1) * sizeof(char));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';
    
    return result;
}
