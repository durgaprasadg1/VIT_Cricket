#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

class Toss
{
public:
    void execute(int choice)
    {
        int compTossRand = rand() % 2;
        if (compTossRand == choice)
        {
            cout << "\n\nThe Toss Result matches your choice.\n";
            cout << "You Won the toss & now you can proceed.\n\n";
        }
        else
        {
            cout << "The Toss Result doesn't match your choice.\n";
            cout << "You lost the toss & it's now another player's turn.\n\n";
        }
        cout << "LET'S PLAY\n\n";
    }
};

class Innings
{
private:
    int wickets;
    int overs;
    int target;
    int totalRuns;
    int ballsBowled;
    int currentOver[6];
    bool isChase;

    int validateRun(int inputRun, int compRun)
    {
        if (inputRun == 5 || inputRun > 6 || inputRun < 0)
        {
            cout << "\n\nInvalid Input!! Your score is 0.\n\n";
            return 0;
        }
        else if (compRun == inputRun)
        {
            return 0;
        }
        return inputRun;
    }

public:
    Innings(int w, int o, int t = -1)
        : wickets(w), overs(o), target(t), totalRuns(0), ballsBowled(0), isChase(t != -1)
    {
        for (int &ball : currentOver)
            ball = 0;
    }

    int play()
    {
        const int runValues[6] = {0, 1, 2, 3, 4, 6};
        const int ballSpeed[6] = {133, 93, 144, 95, 143, 97};
        const char *ballTypes[6] = {"Pace", "Off-Spin", "In-Swing", "Googly", "Out-Swing", "Carrom-Ball"};
        const char *outTypes[4] = {"Catch", "Bowled", "Run-Out", "Stumping"};

        int ballsThisOver = 0;
        int remainingOvers = overs;

        while (wickets > 0 && remainingOvers > 0)
        {
            if (ballsThisOver < 6)
            {
                int randomIndex = rand() % 6;
                int compRun = runValues[randomIndex];
                int ballVelocity = ballSpeed[randomIndex];
                int outTypeIndex = rand() % 4;

                cout << "\n\nEnter your run: ";
                int userRun;
                cin >> userRun;

                if (userRun < 0 || userRun > 6 || userRun == 5)
                {
                    cout << "Invalid runs input.\n";
                    continue;
                }

                cout << "Ball Speed: " << ballVelocity << " km/hr with " << ballTypes[randomIndex] << "\n";
                cout << "Computer's choice: " << compRun << "\n";
                cout << "Your choice: " << userRun << "\n";

                userRun = validateRun(userRun, compRun);

                if (compRun == userRun)
                {
                    currentOver[ballsThisOver] = 0;
                    wickets--;
                    ballsThisOver++;
                    cout << "\n======================\n";
                    cout << "     W I C K E T\n";
                    cout << "   What a " << outTypes[outTypeIndex] << " !!\n";
                    cout << "======================\n";
                    cout << "Total Score: " << totalRuns << "  Wickets left: " << wickets << "\n";
                    if (wickets == 0)
                        break;
                }
                else if (userRun == 6)
                {
                    if (compRun == 1)
                    {
                        totalRuns += 6;
                        currentOver[ballsThisOver] = 6;
                        ballsThisOver++;
                        cout << "\n===========\n   Sixer\n===========\n";
                    }
                    else
                    {
                        currentOver[ballsThisOver] = -1;
                        wickets--;
                        ballsThisOver++;
                        cout << "\n======================\n";
                        cout << "     W I C K E T\n";
                        cout << "   What a " << outTypes[outTypeIndex] << " !!\n";
                        cout << "======================\n";
                        if (wickets == 0)
                            break;
                    }
                }
                else
                {
                    totalRuns += userRun;
                    currentOver[ballsThisOver] = userRun;
                    ballsThisOver++;
                    if (userRun == 4)
                    {
                        cout << "\n======================\n";
                        cout << "   Down The Ground\n";
                        cout << "======================\n";
                    }
                }

                if (isChase && totalRuns > target)
                {
                    break;
                }
            }
            else
            {
                cout << "This Over: ";
                for (int i = 0; i < 6; ++i)
                {
                    cout << currentOver[i] << " ";
                }
                cout << "\n\n-1 means Wicket\n";
                cout << "\n----------------------------\n";
                cout << "      New over started\n";
                cout << "----------------------------\n";
                ballsThisOver = 0;
                remainingOvers--;
            }
        }
        return totalRuns;
    }
};

class SuperOver
{
private:
    int validateRun(int inputRun, int compRun, int playerNum)
    {
        if (inputRun == 5 || inputRun > 6 || inputRun < 0)
        {
            cout << "\n\nInvalid Input!! Your score is 0.\n\n";
            return 0;
        }
        else if (compRun == inputRun)
        {
            cout << "\n\nThe score of player " << playerNum << " is 0.\n";
            return 0;
        }
        cout << "\n\nThe score of player " << playerNum << " is " << inputRun << ".\n";
        return inputRun;
    }

public:
    void play()
    {
        const int runValues[6] = {0, 1, 2, 3, 4, 6};
        cout << "\n\nRULE: Only one ball per player\n";

        int compRun = runValues[rand() % 6];
        int player1Run, player2Run;

        cout << "\nPlayer 1, enter your run: ";
        cin >> player1Run;
        cout << "Computer's choice: " << compRun << ".\n";
        int score1 = validateRun(player1Run, compRun, 1);

        cout << "\nPlayer 2, enter your run: ";
        cin >> player2Run;
        cout << "Computer's choice: " << compRun << ".\n";
        int score2 = validateRun(player2Run, compRun, 2);

        if (score1 == score2)
        {
            cout << "\nScores are tied! Starting SUPER OVER...\n";
            cout << "==========================\n";
            cout << "    S U P E R B A L L\n";
            cout << "==========================\n";
            play();
        }
        else if (score1 > score2)
        {
            cout << "\nPlayer 1 wins!\n";
        }
        else
        {
            cout << "\nPlayer 2 wins!\n";
        }
    }
};

class CricketGame
{
private:
    void displayRules()
    {
        cout << "= = = = = = = = = = = = = = = V I T  C R I C K E T = = = = = = = = = = = = = = =\n\n";
        cout << "+ + + + + + + + + + + + R U L E S + + + + + + + + + + + +\n\n";
        cout << "1. Standard players: <=11\n";
        cout << "2. Standard overs: Reasonable number\n";
        cout << "3. Random balls (spin/pace) each delivery\n";
        cout << "4. 50% out probability when hitting a six\n";
        cout << "5. Out if your run matches computer's choice\n\n";
        cout << "= = = = = = = = = = = = = = = V I T  C R I C K E T = = = = = = = = = = = = = = =\n\n";
    }

    float calculateRunRate(int runs, float overs)
    {
        return (runs / overs) + 0.3f;
    }

    // ⭐ ADDED: Save result to file
    void saveMatchResult(int score1, int score2)
    {
        ofstream file("match_history.txt", ios::app);
        time_t now = time(0);
        char *dt = ctime(&now);
        dt[strlen(dt) - 1] = '\0'; // remove newline
        file << "[" << dt << "]  Player1: " << score1 << " | Player2: " << score2;
        if (score1 > score2)
            file << "  -> Player 1 Won";
        else if (score2 > score1)
            file << "  -> Player 2 Won";
        else
            file << "  -> Tie (Super Over)";
        file << "\n";
        file.close();
    }

    void viewHistory()
    {
        ifstream file("match_history.txt");
        if (!file)
        {
            cout << "\nNo match history found!\n";
            return;
        }
        cout << "\n====== MATCH HISTORY ======\n";
        string line;
        while (getline(file, line))
        {
            cout << line << "\n";
        }
        cout << "===========================\n\n";
        file.close();
    }

public:
    void start()
    {
        srand(static_cast<unsigned>(time(0)));
        displayRules();

        while (true)
        {
            int menuChoice;
            cout << "1. Start New Match\n2. View Match History\n3. Exit\nChoice: ";
            cin >> menuChoice;

            if (menuChoice == 3)
            {
                cout << "Exiting game.\n";
                break;
            }
            else if (menuChoice == 2)
            {
                viewHistory();
                continue;
            }

            int wickets, overs;
            cout << "Enter number of wickets: ";
            cin >> wickets;
            if (wickets <= 0)
            {
                cout << "Invalid input! Exiting.\n";
                return;
            }

            cout << "Enter number of overs: ";
            cin >> overs;
            if (overs <= 0)
            {
                cout << "Invalid input! Exiting.\n";
                return;
            }

            int choice;
            cout << "1. Toss\n2. Exit\nChoice: ";
            cin >> choice;

            if (choice == 2)
            {
                cout << "Exiting game.\n";
                return;
            }

            char tossChoice;
            cout << "Heads (H) or Tails (T)? ";
            cin >> tossChoice;

            Toss tossObj;
            if (tossChoice == 'H' || tossChoice == 'h')
                tossObj.execute(0);
            else if (tossChoice == 'T' || tossChoice == 't')
                tossObj.execute(1);
            else
            {
                cout << "Invalid choice! Exiting.\n";
                return;
            }

            Innings firstInnings(wickets, overs);
            cout << "\n===== FIRST INNINGS START =====\n";
            int score1 = firstInnings.play();
            cout << "\nFirst innings total: " << score1 << "\n";

            int target = score1 + 1;
            cout << "\n===== SECOND INNINGS START =====\n";
            cout << "TARGET: " << target << "\n";
            cout << "Required run rate: " << calculateRunRate(score1, overs) << "\n";

            Innings secondInnings(wickets, overs, target);
            int score2 = secondInnings.play();
            cout << "\nSecond innings total: " << score2 << "\n";

            saveMatchResult(score1, score2); 

            if (score1 == score2)
            {
                cout << "\n===== SUPER OVER INITIATED =====\n";
                SuperOver super;
                super.play();
            }
            else if (score1 > score2)
            {
                cout << "\nPlayer 1 wins!\n";
            }
            else
            {
                cout << "\nPlayer 2 wins!\n";
            }
        }
    }
};

int main()
{
    CricketGame game;
    game.start();
    return 0;
}