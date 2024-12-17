#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void machineBatting();
void playerBatting();
int toss();

int machineScore = 0, playerScore = 0, target = 0;

int main() {
    int choice, winner;
    srand(time(0));

    printf("Welcome to the AMUST Cricket Game!\n");
    printf("Toss to decide batting or bowling.\n");

    choice = toss();  // 1: Player bats first, 0: Machine bats first

    if (choice == 1) {
        printf("\nYou chose to bat first!\n");
        playerBatting();
        printf("\nTarget for the Machine: %d runs\n", playerScore + 1);
        machineBatting();
    } else {
        printf("\nYou chose to bowl first!\n");
        machineBatting();
        printf("\nTarget for You: %d runs\n", machineScore + 1);
        playerBatting();
    }

    // Determine winner
    if (playerScore > machineScore)
        printf("\nCongratulations! You Win!\n");
    else if (machineScore > playerScore)
        printf("\nMachine Wins! Better luck next time.\n");
    else
        printf("\nIt's a Tie!\n");

    return 0;
}

int toss() {
    int choice;
    printf("Enter 1 to Bat or 2 to Bowl: ");
    scanf("%d", &choice);
    return choice == 1 ? 1 : 0;  // 1: Player bats, 0: Machine bats
}

void machineBatting() {
    int ball, guess, machineRun;

    printf("\n--- Machine Batting ---\n");
    for (ball = 1; ball <= 6; ball++) {
        machineRun = rand() % 7;  // Runs between 0–6
        printf("Ball %d - Guess the Machine's Runs (0-6): ", ball);
        scanf("%d", &guess);

        if (guess == machineRun) {
            printf("Correct Guess! Machine is OUT!\n");
            break;
        } else {
            printf("Wrong! Machine scored %d runs.\n", machineRun);
            machineScore += machineRun;
        }
    }
    printf("Machine's Total Score: %d\n", machineScore);
}

void playerBatting() {
    int ball, guess, playerRun;

    printf("\n--- Your Batting ---\n");
    for (ball = 1; ball <= 6; ball++) {
        printf("Ball %d - Enter Your Runs (0-6): ", ball);
        scanf("%d", &playerRun);

        int machineGuess = rand() % 7;  // Machine guesses your runs
        if (playerRun == machineGuess) {
            printf("Machine Guessed Correctly! You are OUT!\n");
            break;
        } else {
            printf("Machine Guessed %d. You scored %d runs.\n", machineGuess, playerRun);
            playerScore += playerRun;
        }

        if (playerScore > machineScore)  // Early win
            break;
    }
    printf("Your Total Score: %d\n", playerScore);
}

