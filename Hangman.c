#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#include<unistd.h>

void hangman(int num);
void random_word(char* word);
void waste_func(void);
void inst(void);
void now(void);
void game(void);

int main()
{
    char ch;
    do
    {
        hangman(9);
        printf("\nWELCOME TO HANGMAN!!\n\n");
        now();
        waste_func();
        system("cls");

        hangman(10);
        inst();
        waste_func();

        game();
        waste_func();
        system("cls");

        hangman(10);
        printf("\n\nDo you want to play again?\n");
        printf("Enter yes or no.\n");
        scanf(" %c", &ch);
        system("cls");
    }while((ch == 'Y') || (ch == 'y'));

    system("cls");
    hangman(10);
    printf("\n\nThank you for playing!!\n\n");

    return 0;
}

void game(void)
{
    char word[6];
    int flag = 0;
    random_word(word);
    char temp[6] = "______";
    char ans, ch[8] = "12345678";
    int count = 0, life = 8;

    while((life > 0) && (count < 6))
    {
        sleep(1);
        system("cls");
        hangman(life+1);
        if(life < 8)
        {
            for(int i = 0; i < 6; i++)
            {
                printf("%c", temp[i]);
            }
        }
        flag = 0;
        printf("\n\nEnter your guess: \n");
        scanf(" %c", &ans);
        for(int i = 0; i < 8; i++)
        {
            if(ch[i] == ans)
                {
                    life--;
                    printf("You have already entered this character!!\n");
                    if(life == 0)
                    {
                        printf("\n\nGame Over\n");
                        printf("The word was %s\n", word);
                        flag =1;
                        break;
                    }
                    printf("You have %d lives remaining.\n", life);
                    flag = 1;
                    break;
                }
        }
        if(flag == 1)
            continue;

        ch[life -1]= ans;
        for(int i = 0; i < 6; i++)
        {
            if(word[i] == ans)
                {
                    temp[i] = word[i];
                    flag = 1;
                    count++;

                }
        }
        life--;
        if(flag == 1 && life != 0)
            {
                printf("Bingo! You guessed that right!\nYou have %d lives remaining.\n\n", life);
            }
        else if(life != 0)
            {
                printf("That is a wrong guess!\nYou have %d lives remaining.\n\n", life);
            }
        if(life == 0)
        {
            if(count == 6)
            {
                printf("Congratulations you have won the game. You took %d chances to guess it.\n", 8 - life);
                printf("The word was %s\n", word);
                break;
            }
            printf("Game Over\n");
            printf("The word was %s\n", word);
            break;
        }

        printf("\n");
        flag = 0;
        if(count == 6)
        {
            printf("Congratulations you have won the game. You took %d chances to guess it.\n", 8 - life);
            printf("The word was %s\n", word);
        }
    }
}

void hangman(int num)
{
    printf("=================================================================================\n");
    printf("\t\t\t               __\n");
    printf("\t\t\t|_|  /\\  |\\ | /   |\\/|  /\\  |\\ |\n");
    printf("\t\t\t| | /--\\ | \\| \\_| |  | /--\\ | \\|\n");
    printf("=================================================================================\n");

    switch (num)
    {
        case 9:

            printf("\t\t\t\t||_______|\n");
            printf("\t\t\t\t||       \n");
            printf("\t\t\t\t||       \n");
            printf("\t\t\t\t||       \n");
            printf("\t\t\t\t||      \n");
            printf("\t\t\t\t||       \n");
            printf("\t\t\t\t||________\n");
            printf("\t\t\t\t-----------\n");
            break;
        case 8:

            printf("\t\t\t\t||_______|\n");
            printf("\t\t\t\t||       0\n");
            printf("\t\t\t\t||       \n");
            printf("\t\t\t\t||       \n");
            printf("\t\t\t\t||      \n");
            printf("\t\t\t\t||       \n");
            printf("\t\t\t\t||________\n");
            printf("\t\t\t\t-----------\n");
            break;
        case 7:

            printf("\t\t\t\t||_______|\n");
            printf("\t\t\t\t||       0\n");
            printf("\t\t\t\t||       |\n");
            printf("\t\t\t\t||       \n");
            printf("\t\t\t\t||      \n");
            printf("\t\t\t\t||       \n");
            printf("\t\t\t\t||________\n");
            printf("\t\t\t\t-----------\n");
            break;
        case 6:

            printf("\t\t\t\t||_______|\n");
            printf("\t\t\t\t||       0\n");
            printf("\t\t\t\t||      /|\n");
            printf("\t\t\t\t||       \n");
            printf("\t\t\t\t||      \n");
            printf("\t\t\t\t||       \n");
            printf("\t\t\t\t||________\n");
            printf("\t\t\t\t-----------\n");
            break;
        case 5:

            printf("\t\t\t\t||_______|\n");
            printf("\t\t\t\t||       0\n");
            printf("\t\t\t\t||      /|\\ \n");
            printf("\t\t\t\t||       \n");
            printf("\t\t\t\t||      \n");
            printf("\t\t\t\t||       \n");
            printf("\t\t\t\t||________\n");
            printf("\t\t\t\t-----------\n");
            break;
        case 4:

            printf("\t\t\t\t||_______|\n");
            printf("\t\t\t\t||       0\n");
            printf("\t\t\t\t||      /|\\ \n");
            printf("\t\t\t\t||       |\n");
            printf("\t\t\t\t||      \n");
            printf("\t\t\t\t||       \n");
            printf("\t\t\t\t||________\n");
            printf("\t\t\t\t-----------\n");
            break;
        case 3:

            printf("\t\t\t\t||_______|\n");
            printf("\t\t\t\t||       0\n");
            printf("\t\t\t\t||      /|\\ \n");
            printf("\t\t\t\t||       |\n");
            printf("\t\t\t\t||      /\n");
            printf("\t\t\t\t||       \n");
            printf("\t\t\t\t||________\n");
            printf("\t\t\t\t-----------\n");
            break;
        case 2:

            printf("\t\t\t\t||_______|\n");
            printf("\t\t\t\t||       0\n");
            printf("\t\t\t\t||      /|\\ \n");
            printf("\t\t\t\t||       |\n");
            printf("\t\t\t\t||      / \\ \n");
            printf("\t\t\t\t||       \n");
            printf("\t\t\t\t||________\n");
            printf("\t\t\t\t-----------\n");
            break;
        case 1:

            printf("\t\t\t\t||_______|\n");
            printf("\t\t\t\t||       |\n");
            printf("\t\t\t\t||       0\n");
            printf("\t\t\t\t||      /|\\ \n");
            printf("\t\t\t\t||       |\n");
            printf("\t\t\t\t||      / \\ \n");
            printf("\t\t\t\t||________\n");
            printf("\t\t\t\t-----------\n");
            break;
        default:
            break;
    }
}

void random_word(char word[6])
{
    srand(time(NULL));
    int r2 = rand()%10;
    int random = (rand() % 10 + r2)%10;
    switch(random)
    {
        case 1:
            strcpy(word, "abroad");
            break;
        case 2:
            strcpy(word, "dacoit");
            break;
        case 3:
            strcpy(word, "packed");
            break;
        case 4:
            strcpy(word, "sudden");
            break;
        case 5:
            strcpy(word, "bubble");
            break;
        case 6:
            strcpy(word, "viable");
            break;
        case 7:
            strcpy(word, "victus");
            break;
        case 8:
            strcpy(word, "winner");
            break;
        case 9:
            strcpy(word, "worker");
            break;

        default:
            strcpy(word,"bright");
            break;
    }
}

void waste_func(void)
{
    char waste;
    printf("Enter any character to continue: \n");
    scanf(" %c", &waste);
}

void inst(void)
{
    printf("INSTRUCTIONS:\n");
    printf("=============\n");
    printf("Hello there.\nThere is a six letter word I\'m thinking about\nCan you guess it?\nEnter any letter");
    printf(" you think is in the word\nIf it is a correct letter proceed to next letter\nYou have 8 lives. One life is used for each guess\n");
    printf("Save the Man before he is hanged!!!\n\n");
}

void now(void)
{
    time_t t = time(NULL);
    char* t_now = ctime(&t);
    printf("%s\n", t_now);
}
