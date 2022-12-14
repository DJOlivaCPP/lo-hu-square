#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Lo Hu Square
int square1[3][3] =
{
    4, 9, 2,
    3, 5, 7,
    8, 1, 6
};

// non Lo Hu Square
int square2[3][3] =
{
    2, 5, 4,
    3, 9, 6,
    8, 1, 7
};

int randomSquare[3][3];

int isLoHu(int LoHu[3][3])
{
    int rowOneSum = LoHu[0][0] + LoHu[0][1] + LoHu[0][2];
    int rowTwoSum = LoHu[1][0] + LoHu[1][1] + LoHu[1][2];
    int rowThreeSum = LoHu[2][0] + LoHu[2][1] + LoHu[2][2];

    int colOneSum = LoHu[0][0] + LoHu[1][0] + LoHu[2][0];
    int colTwoSum = LoHu[0][1] + LoHu[1][1] + LoHu[2][1];
    int colThreeSum = LoHu[0][2] + LoHu[1][2] + LoHu[2][2];

    int diagOneSum = LoHu[0][0] + LoHu[1][1] + LoHu[2][2];
    int diagTwoSum = LoHu[2][0] + LoHu[1][1] + LoHu[0][2];

    if (rowOneSum == rowTwoSum && rowTwoSum == rowThreeSum && rowThreeSum == colOneSum && colOneSum == colTwoSum && colTwoSum == colThreeSum && colThreeSum == diagOneSum && diagOneSum == diagTwoSum)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    if (isLoHu(square1) == 1)
    {
        printf("Square 1 is a Lo Hu Square\n"); //expexted
    }
    else
    {
        printf("Square 1 is not a Lo Hu Square\n");
    }

    if (isLoHu(square2) == 1)
    {
        printf("Square 2 is a Lo Hu Square\n");
    }
    else
    {
        printf("Square 2 is not a Lo Hu Square\n"); //expected
    }

    int counter = 0;
    int LoHu = 0;
    while (LoHu == 0)
    {
        time_t t;
        srand((unsigned)time(&t));

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                randomSquare[i][j] = (rand()%8) + 1;
            }
        }

        counter++;

        LoHu = isLoHu(randomSquare);
    }

    printf("%d attempts to create a LoHu Square randomly\n", counter);

    printf("[ %d, %d, %d ]\n", randomSquare[0][0], randomSquare[0][1], randomSquare[0][2]);
    printf("[ %d, %d, %d ]\n", randomSquare[1][0], randomSquare[1][1], randomSquare[1][2]);
    printf("[ %d, %d, %d ]\n", randomSquare[2][0], randomSquare[2][1], randomSquare[2][2]);
    
    return 0;
}