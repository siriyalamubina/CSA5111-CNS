#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char text[100], key[100];
    int i, j = 0, shift;
    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter key: ");
    scanf("%s", key);
    for (i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            shift = toupper(key[j % strlen(key)]) - 'A';
            if (text[i] >= 'A' && text[i] <= 'Z')
                text[i] = (text[i] - 'A' + shift) % 26 + 'A';
            else if (text[i] >= 'a' && text[i] <= 'z')
                text[i] = (text[i] - 'a' + shift) % 26 + 'a';
            j++;
        }
    }
    printf("Encrypted text: %s", text);
    return 0;
}
