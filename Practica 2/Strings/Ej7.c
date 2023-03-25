#include <stdio.h>
#include <string.h>

int capicuaNum(char[]);
int capicuaPtr(char[]);

int main() {
    char string[] = "nashe";

    if (capicuaNum(string) == 1) {
        printf("[%s] es capicua \n", string);
    }
    else
        printf("[%s] NO es capicua \n", string);

    if (capicuaPtr(string) == 1) {
        printf("[%s] es capicua", string);
    }
    else
        printf("[%s] NO es capicua", string);

    return 0;
}

int capicuaNum(char string[]) {
   int i=0;
   int j = strlen(string) - 1;

   while (i < j) {
        if (string[i] != string[j])
            return 0;
        i++;
        j--;
   }
   return 1;
}

int capicuaPtr(char string[]) {
    char *j = string + (strlen(string) -1);

    while(string < j) {
        if(*string != *j)
            return 0;
        string++;
        j--;
    }

    return 1;
}