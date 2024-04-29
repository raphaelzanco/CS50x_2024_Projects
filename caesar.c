#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[10])
{
    //checking if the user inputed a key
    if(argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        //checking if the key is valid
        char* key = argv[1];
        int length = strlen(key);
        for(int i = 0; i < length; i++)
        {
            if(isdigit(key[i]) == 0 )
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }

    //getting text from the user to cipher
    char cipher[100];
    printf("plaintext:  ");
    fgets(cipher, 100, stdin);
    int n = strlen(cipher);

    printf("ciphertext: ");

    //encrypt the plaintext inputed
    for(int j = 0; j < n; j++)
    {
        if(isalpha(cipher[j]) == 0)
        {
            printf("%c", cipher[j]);
        }
        else if(isupper(cipher[j]) > 0)
        {
            int ci = (cipher[j] - 'A' + atoi(argv[1])) % 26 + 'A';
            printf("%c", ci);
        }
        else if(islower(cipher[j]) > 0)
        {
            int ci = (cipher[j] - 'a' + atoi(argv[1])) % 26 +'a';
            printf("%c", ci);
        }
    }

    printf("\n");

    return 0;
}
