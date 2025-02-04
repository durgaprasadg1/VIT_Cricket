#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int runrate(float total1, float overs)
{
    return (total1 / overs) + 0.3;
}

int isBreaking(int inputrun, int totalruns, int compRun, int num)
{
    if (inputrun == 5 || inputrun > 6 || inputrun < 0)
    {
        printf("\n\nInvalid Input !! Your score is 0.\n\n");
        totalruns = 0;
    }
    else if (compRun == inputrun)
    {
        totalruns = 0;
        printf("\n\nThe score of player %d is %d.", num, totalruns);
    }
    else
    {
        totalruns += inputrun;
        printf("\n\nThe score of player %d is %d.", num, totalruns);
    }
    return totalruns;
}

int superover()
{
    srand(time(0));
    int totalRuns1 = 0, totalRuns2 = 0;

    int arr[6] = {0, 1, 2, 3, 4, 6};

    printf("\n\nRULE :- Only one ball will be given to play.\n");

    int compRun = arr[(rand() % 6)];
    int urRun1, urRun2;

    printf("\n\nPlayer 1, give your run : ");
    scanf("%d", &urRun1);

    printf("\nComputer's choice: %d.\n", compRun);

    urRun1 = isBreaking(urRun1, totalRuns1, compRun, 1);

    printf("\n\n\nPlayer 2, give your run : ");
    scanf("%d", &urRun2);
    printf("\nComputer's choice: %d.\n", compRun);

    urRun2 = isBreaking(urRun2, totalRuns2, compRun, 2);

    if (urRun1 == urRun2)
    {
        printf("\nThe scores of both the players are same.\nSo, its the time for Super Over.");
        printf("\n\n==========================\n");
        printf("    S U P E R B A L L");
        printf("\n==========================\n");
        superover();
    }
    else if (urRun1 > urRun2)
    {
        printf("\nCongratulation Player 1 , You Won.");
    }
    else
    {
        printf("\nCongratulation Player 2 , You Won.");
    }
    return 0;
}

int play(int wickets, int overs, int k)
{
    srand(time(0));

    int totalRuns = 0;
    int ball = 0;
    int urRun, cnt = 0;
    int arr[6] = {0, 1, 2, 3, 4, 6};
    int ballSpeed[6] = {133, 93, 144, 95, 143, 97};
    char *ballType[6] = {"Pace", "Off-Spin", "In-Swing", "Googly", "Out-Swing", "Carrom-Ball"};
    char *outType[4] = {"Catch", "Bowled", "Run-Out", "Stumping"};
    int thisOver[6];

    while (wickets > 0 && overs > 0)
    {
        for (int i = 0; i < overs; i++)
        {
            if (ball < 6)
            {
                int random = (rand() % 6);
                int compRun = arr[random];
                int balVel = ballSpeed[random];
                int Out_rand = (rand() % 4);

                printf("\n\n\nEnter your run: ");
                scanf("%d", &urRun);
                printf("\nBall Speed : %d km/hr with %s \n", balVel, ballType[random]);

                if (urRun < 0 || urRun > 6 || urRun == 5)
                {
                    printf("Invalid runs input.\n");
                    continue;
                }

                printf("Computer's choice: %d\n", compRun);
                printf("Your choice: %d\n", urRun);

                if (compRun == urRun)
                {
                    thisOver[ball] = 0;
                    wickets--;
                    ball++;
                    printf("\nTotal Score :- %d\n", totalRuns);
                    printf("\n======================\n");
                    printf("     W I C K E T");
                    printf("\n   What a %s !!", outType[Out_rand]);
                    printf("\n======================\n");
                    printf("\nTotal Score :- %d  Wickets in hands :- %d \n", totalRuns, wickets);
                    printf("\nball :- %d\n", ball);

                    if (wickets == 0)
                    {
                        return totalRuns;
                    }
                }

                else if (urRun == 6)
                {
                    int randomO = (rand() % 2);
                    thisOver[ball] = urRun;

                    if (compRun == 1)
                    {
                        totalRuns += urRun;
                        ball++;
                        printf("\nball :- %d\n", ball);
                        printf("\n===========");
                        printf("\n   Sixer\n");
                        printf("===========\n\n\n");
                    }
                    else
                    {
                        thisOver[ball] = 0;
                        wickets--;
                        ball++;
                        printf("\nTotal Score :- %d\n", totalRuns);

                        printf("\n======================\n");
                        printf("     W I C K E T");
                        printf("\n   What a %s !!", outType[Out_rand]);
                        printf("\n======================\n");
                        printf("\nTotal Score :- %d  Wickets in hands :- %d \n", totalRuns, wickets);
                        printf("\nball :- %d\n", ball);

                        if (wickets == 0)
                        {
                            return totalRuns;
                        }
                    }
                }

                else
                {
                    thisOver[ball] = urRun;
                    totalRuns += urRun;
                    ball++;
                    printf("\nball :- %d\n", ball);

                    if (urRun == 4)
                    {
                        printf("\n======================");
                        printf("\n   Down The Ground\n");
                        printf("======================\n\n\n");
                    }
                }
                if (k < totalRuns)
                {
                    return totalRuns;
                }
            }

            else
            {
                ball = 0;
                overs--;
                printf("This Over :-  ");
                for (int i = 0; i < 6; i++)
                {
                    printf("%d ", thisOver[i]);
                }
                int i = 0;
                printf("\n\n----------------------------");
                printf("\n      New over started.\n");
                printf("----------------------------\n");
            }
        }
    }
    return totalRuns;
}

void toss(int choice)
{
    srand(time(0));
    int compTossRand = rand() % 2;

    if (compTossRand == choice)
    {

        printf("\n\nThe Toss Result is as same your choice.\n");
        printf("\n\nYou Won the toss & now you can proceed.\n\n");
        printf("\n\nLET'S PLAY\n\n");
    }

    else
    {
        printf("The Toss Result is not as same choice.\n");
        printf("\n\nYou lost the toss & it is now another player's turn.\n\n");
        printf("\n\nLET'S PLAY\n\n");
    }
}

int main()
{
    printf("= = = = = = = = = = = = = = = =  V I T  C R I C K E T = = = = = = = = = = = = = = = = = \n\n");
    printf("\n+ + + + + + + + + + + + R U L E S + + + + + + + + + + + +  \n\n");
    printf("1. Keep no. of players  in the standard manner i.e. <=11.\n");
    printf("2. Keep no. of overs  in the standard manner.\n");
    printf("3. Every ball is a random ball (Either spin or pace).\n");
    printf("4. The Probability of getting out is 1/2 one hitting SIXER.\n");
    printf("5. IF COMPUTER'S RUN IS AS SAME AS YOU CHOOSEN THEN THE PLAYER IS OUT\n\n");

    printf("\n= = = = = = = = = = = = = = = =  V I T  C R I C K E T = = = = = = = = = = = = = = = = = \n\n");

    int wkt, overs, fakeWkt, fakeOvr, k = __INT_MAX__;
    printf("\nEnter the number of players : ");
    scanf("%d", &wkt);
    if (wkt < 0)
    {
        printf("Invalid Input. Run the code again.");
        return 0;
    }

    fakeWkt = wkt;
    printf("\nEnter the number of overs : ");
    scanf("%d", &overs);
    fakeOvr = overs;
    if (overs < 0)
    {
        printf("Invalid Input. Run the code again.");
        return 0;
    }

    int choice;
    printf("Press 1 to move to toss \n");
    printf("Press 2 to exit \n");
    scanf("%d", &choice);
    char ch;
    switch (choice)
    {
    case 1:

        printf("Press H for HEADS or Press T for TAILS\n");
        scanf("%s", &ch);

        if (ch == 'H' || ch == 'h')
        {
            printf("\nYou chosen HEADS\n");
            toss(0);
        }
        else if (ch == 'T' || ch == 't')
        {
            printf("\nYou chosen TAILS\n");
            toss(1);
        }
        else
        {
            printf("INVALID INPUT, RUN THE CODE AGAIN.\n");
            return 0;
        }
        break;

    case 2:
        printf("Exit Done Successfully.\n");
        return 0;
        break;

    default:
        printf("Invalid Choice");
        return 0;
        break;
    }

    int score1 = play(wkt, overs, k);
    printf("This Inning is over now.\n");
    printf("\nTotal score of player 1 is %d \n\n", score1);

    k = score1;
    printf("======================\n");
    printf("======================\n");
    printf("  New Inning Started.\n");
    printf("      Target : %d\n", score1 + 1);
    printf("======================\n");
    printf("======================\n\n");

    printf("\n\nThe minimum run-rate required to win is %f\n\n", (float)runrate(k, overs));

    printf("Player!! Play your inning.\n ");
    int score2 = play(fakeWkt, fakeOvr, k);
    printf("This Inning is over now.\n\n");
    printf("Total score of player 2 is %d \n\n", score2);

    if (score1 == score2)
    {

        printf("The scores of both the players are same.\nSo, its the time for Super Over.");
        printf("\n\n==========================\n");
        printf("    S U P E R O V E R");
        printf("\n==========================\n");
        superover();
    }
    else if (score1 > score2)
    {
        printf("\n\nCongratulation Player 1 , You Won.");
    }
    else
    {
        printf("\n\nCongratulation Player 2 , You Won.");
    }
    return 0;
}
