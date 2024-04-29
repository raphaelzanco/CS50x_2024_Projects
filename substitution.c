#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i, j, k;

    //check argc size
    if(argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //check for numbers
    for(i = 0; i <= 25; i++)
    {
        if(isalpha(argv[1][i]) == 0)
        {
            printf("Key must contain just alphabet characters\n");
            return 1;
        }
    }

    //check argv[1] length
    if(strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    //check for repeated letters
    for(i = 0; i <= 25; i++)
    {
        j = 1;
        j +=i;
        for(j; j <= 25; j++)
        {
            if(argv[1][i] == argv[1][j])
            {
                printf("Key must not contain repeated characters\n");
                return 1;
            }
        }
    }

    char cipher[100];
    int key;

    //get user plaintext
    printf("plaintext:  ");
    fgets(cipher,100,stdin);
    int len = strlen(cipher);
    printf("ciphertext: ");

    //encryptic user plaintext
    for(k = 0; k < len; k++)
    {
        if(isalpha(cipher[k]) == 0)
        {
            printf("%c", cipher[k]);
        }
        else if(isupper(cipher[k]) > 0)
        {
            key = cipher[k] - 'A';
            printf("%c", toupper(argv[1][key]));
        }
        else if(islower(cipher[k]) > 0)
        {
            key = cipher[k] - 'a';
            printf("%C", tolower(argv[1][key]));
        }
    }

    printf("\n");

    return 0;
}
