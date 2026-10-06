#include <stdio.h>
#include <string.h>
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
    char text[100];
    int a, b, i, p, c;
    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter value of a: ");
    scanf("%d", &a);
    printf("Enter value of b: ");
    scanf("%d", &b);
    if (gcd(a, 26) != 1)
    {
        printf("Invalid value of a.\n");
        printf("a must be relatively prime to 26.\n");
        return 0;
    }
    b = b % 26;
    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            p = text[i] - 'A';
            c = (a * p + b) % 26;
            text[i] = c + 'A';
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            p = text[i] - 'a';
            c = (a * p + b) % 26;
            text[i] = c + 'a';
        }
    }
    printf("Encrypted text: %s", text);
    return 0;
}
