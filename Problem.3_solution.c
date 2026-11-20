int lengthOfLongestSubstring(char* s) {
    int lastIndex[128];
    for (int i = 0; i < 128; i++) {
        lastIndex[i] = -1;
    }
    
    int maxLength = 0;
    int left = 0;
    
    for (int right = 0; s[right] != '\0'; right++) {
        char currentChar = s[right];
        
        // If the character is already in the current window, move left pointer
        if (lastIndex[currentChar] >= left) {
            left = lastIndex[currentChar] + 1;
        }
        
        // Update the last seen index of the current character
        lastIndex[currentChar] = right;
        
        // Calculate current window length and update maxLength
        int currentLength = right - left + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }
    
    return maxLength;
}
