// Write a program to recognize strings under ‘a’, ‘a*b+’, ‘abb’.
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool match_a(const char *str) {
    return strcmp(str, "a") == 0;
}

bool match_ab_star(const char *str) {
    int len = strlen(str);
    if (len == 0) return true; // Empty string matches
    if (str[0] != 'a') return false;
    for (int i = 1; i < len; i++) {
        if (str[i] != 'b') return false;
    }
    return true;
}

bool match_abb(const char *str) {
    return strcmp(str, "abb") == 0;
}

int main() {
    char input[100];
    
    printf("Enter a string: ");
    scanf("%s", input);

    if (match_a(input)) {
        printf("String matches 'a'\n");
    } else if (match_ab_star(input)) {
        printf("String matches 'a*b+'\n");
    } else if (match_abb(input)) {
        printf("String matches 'abb'\n");
    } else {
        printf("String doesn't match any pattern\n");
    }

    return 0;
}
