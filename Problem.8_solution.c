#include <limits.h>

int myAtoi(char* s) {
    int i = 0;
    int sign = 1;
    int result = 0;

    // 1. Skip leading whitespace
    while (s[i] == ' ') {
        i++;
    }

    // 2. Check optional '+' or '-' sign
    if (s[i] == '+' || s[i] == '-') {
        if (s[i] == '-') {
            sign = -1;
        }
        i++;
    }

    // 3. Read digits and 4. Clamp on 32-bit overflow
    while (s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';

        // Check overflow against INT_MAX (2147483647)
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;
        i++;
    }

    return result * sign;
}
