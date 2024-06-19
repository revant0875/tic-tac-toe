#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define size 3
// #define underline  "\033[4m"
// #define reset "\033[0m"
// #define overline "\033[53m"


// client side print function
void printBoard(char board[3][3]) 
{
    printf("Current board:\n");
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
}
int main()
{
    char arr[size][size]={" "};
    memset(arr,' ',sizeof(arr));
    // // arr[0][1] ='s';
    // for (int i = 0; i < size; i++)
    // {
    //   for (int j = 0; j < size; j++)
    //   {
    //     // printf("__\n");
    //     printf(underline overline"|%c|"reset,arr[i][j]);
    //     // printf("__");
    //   }
    //   printf("\n");
    // }
    /**
     *  __|__|__
     *  __|__|__
     *  __|__|__
     */
    printBoard(arr);
    return 0;
}