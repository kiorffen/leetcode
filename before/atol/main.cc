#include <cstdio>
#include <stdint.h>
#include <string.h>

bool atoi_64(char* ptr, int64_t& result)
{
    if (ptr == NULL) {
        return false;
    }
    if (strlen(ptr) == 0) {
        return false;
    }
    while (ptr++ && *ptr != '\0') {
        printf("%c\n", ptr[0]);
    }
    printf("%d\n", strlen(ptr));
    while(*ptr <= '0' || *ptr > '9') {
        ptr++;
    }
    if (strlen(ptr) == 0) {
        return false;
    }
    bool is_negetive = false;
    if (*ptr == '-') {
        is_negetive = true;
    }
    result = 0;
    while(*ptr >= 0 && *ptr <= 9) {
        result = result*10 + *ptr;
    }
    if (is_negetive == true) {
        result = 0 - result;
    }
    printf("here1\n");
    return true;
}

int main() {
    char* str="1234";
    int64_t ret = 0;
    printf("%d\n", atoi_64(str, ret));
    printf("%d\n", ret);
    return 0;
}
