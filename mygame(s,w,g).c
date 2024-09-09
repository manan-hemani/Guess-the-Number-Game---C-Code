// returns 1 if you win, -1 if you lose and 0 if draw
// Condition for draw
// Cases covered:
// ss
// gg
// ww

// Non-draw conditions
// Cases covered:
// sg
// gs
// sw
// ws
// gw
// wg

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int snakeWaterGun(char you, char comp)
{
    if (you == comp)
    {
        return 0;
    }
    if (you == 's' && comp == 'g')
    {
        return -1;
    }
    else if (you == 'g' && comp == 's')
    {
        return 1;
    }

    if (you == 's' && comp == 'w')
    {
        return 1;
    }
    else if (you == 'w' && comp == 's')
    {
        return -1;
    }

    if (you == 'g' && comp == 'w')
    {
        return -1;
    }
    else if (you == 'w' && comp == 'g')
    {
        return 1;
    }
}
char CompChoice(char comp)
{
    srand(time(0));
    int number = rand() % (2 + 1); // if possible try to make it choose char s w g
    if (number == 0)
    {
        return 's';
    }
    else if (number == 1)
    {
        return 'w';
    }
    else
    {
        return 'g';
    }
}

void ShowResult(int res, int *ty, int *tc)
{
    if (res == 0)
    {
        printf("Game draw!\n");
        printf("\t\t\t\t\t SCORE\n\t\t\t\t\t You=%d Comp=%d", *ty, *tc);
    }
    else if (res == 1)
    {
        (*ty)++;
        printf("You win!\n");
        printf("\t\t\t\t\t SCORE\n\t\t\t\t\t You=%d Comp=%d", *ty, *tc);
    }
    else
    {
        (*tc)++;
        printf("You Lose!\n");
        printf("\t\t\t\t\t SCORE\n\t\t\t\t\t You=%d Comp=%d", *ty, *tc);
    }
}

int main()
{
    printf("\t\t*****Made by Anonymus*****\n");
    printf("\t*****Welcome to the Snake, Water and Gun Game*****\n");
    printf("*****Let's Play*****\n");
    printf("Please Choose:\n");
    printf("1.Best of 1\n2.Best of 3\n3.Best of 5\n4.Best of 7\n5.Custom\n");
    int choice, i = 1, custom, score;
    char you, comp, cp;
    int ty = 0, tc = 0;
    printf("Enter Your Choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter 's' for snake, 'w' for water and 'g' for gun\n");
        scanf(" %c", &you);
        you = getchar();
        cp = CompChoice(comp);
        int result = snakeWaterGun(you, cp);
        ShowResult(result, &ty, &tc);
        printf("\nYou chose %c and computer chose %c\n", you, cp);
        break;
    case 2:
        while (i < 4)
        {
            printf("Enter 's' for snake, 'w' for water and 'g' for gun\n");
            scanf("%c", &you);
            you = getchar();
            cp = CompChoice(comp);
            int result = snakeWaterGun(you, cp);
            ShowResult(result, &ty, &tc);
            printf("\nYou chose %c and computer chose %c\n", you, cp);
            i++;
        }
        break;
    case 3:
        while (i < 6)
        {
            printf("Enter 's' for snake, 'w' for water and 'g' for gun\n");
            scanf("%c", &you);
            you = getchar();
            cp = CompChoice(comp);
            int result = snakeWaterGun(you, cp);
            ShowResult(result, &ty, &tc);
            printf("\nYou chose %c and computer chose %c\n", you, cp);
            i++;
        }
        break;
    case 4:
        while (i < 8)
        {
            printf("Enter 's' for snake, 'w' for water and 'g' for gun\n");
            scanf("%c", &you);
            you = getchar();
            cp = CompChoice(comp);
            int result = snakeWaterGun(you, cp);
            ShowResult(result, &ty, &tc);
            printf("\nYou chose %c and computer chose %c\n", you, cp);
            i++;
        }
        break;
    case 5:
        printf("Enter Custom Value: ");
        scanf("%d", &custom);
        if (custom >= 10)
        {
            printf("Greater than 10 not Recommended!!!");
        }
        else
        {
            while (i <= custom)
            {
                printf("Enter 's' for snake, 'w' for water and 'g' for gun\n");
                scanf("%c", &you);
                you = getchar();
                cp = CompChoice(comp);
                int result = snakeWaterGun(you, cp);
                ShowResult(result, &ty, &tc);
                printf("\nYou chose %c and computer chose %c\n", you, cp);
                i++;
            }
        }
        break;
    default:
        printf("Invalid Choice!!!\nTry Again :(");
        break;
    }
    return 0;
}
