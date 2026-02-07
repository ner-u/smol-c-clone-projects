#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int game(char comp, char user)
{
    if (comp == user)
    return -1;

    if (comp == 'r' && user == 'p')
        return 0;
            else if (comp == 'p' && user == 'r')
                return 1;
    
    if (comp == 'r' && user == 's')
        return 0;
            else if (comp == 's' && user == 'r')
                return 1;
    
    if (comp == 's' && user == 'p')
        return 0;
            else if (comp == 'p' && user == 's')
                return 1;
}

void main()
{
    int comp, user;

    srand(time(NULL));
    int a = rand() % 100;

    if (a <= 33)
    comp = 'r';
    else if (a > 33 && a <= 66)
    comp = 'p';
    else
    comp = 's';

    scanf(" %c", &user);

    int result = game(comp, user);

    if (result == -1)
    {
        printf("draw!");
    } else if (result == 0)
    {
        printf("you lost!");
    } else if (result == 1)
    {
        printf("you won!");
    }

    printf("\ncomputer chose %c", comp);
}
