// UPDATED
#include <iostream>
#include <ctime>
#include <limits>

using namespace std;

char getUserChoice();
char getComputerChoice(int difficulty, char player);
void showChoice(char choice);
void chooseWinner(char player, char computer, int& User_Score, int& Computer_Score);

// ASCII ART
void ascii();
void clear();
void delay();
int main()
{
    char player;
    char computer;
    char Play_Again;
    int difficulty;
    int User_Score = 0;
    int Computer_Score = 0;

    do
    {
        ascii();
        cout << '\n';
        cout << "\t\tRock-Paper-Scissors Game\n";
        cout << '\n';
        cout << "\t\tChoose difficulty level:\t\t\n";
        cout << '\n';
        cout << "\t 1) Easy\n";
        cout << "\t 2) Medium\n";
        cout << "\t 3) Hard\n";
        cout << '\n';

        // Error handling for char input and 4+ values ng user
        while (true) {
            cout << "\tEnter your choice: ";
            cin >> difficulty;

            // Check if input is valid
            if (difficulty >= 1 && difficulty <= 3) {
                // Input is valid, exit the loop
                break;
            }
            else {
                // Input is invalid, display error message and clear input buffer
                cout << "\tERROR: Invalid input. Please enter (1, 2, or 3).\n\n";
                // Clear the input buffer
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        clear();
        do
        {
            player = getUserChoice();
            cout << "Your Choice: ";
            cout << '\n';
            showChoice(player);

            computer = getComputerChoice(difficulty, player);
            cout << '\n';
            cout << "Computers Choice: ";
            cout << '\n';
            showChoice(computer);

            chooseWinner(player, computer, User_Score, Computer_Score);
            cout << '\n';
            cout << "Score - You: " << User_Score << " | Computer: " << Computer_Score << endl;

            cout << '\n';
            cout << "Do you want to play again? (Y/N): ";
            cout << '\n';
            cin >> Play_Again;
            

            while (Play_Again != 'Y' && Play_Again != 'y' && Play_Again != 'N' && Play_Again != 'n')
            {
                cout << '\n';
                cout << "ERROR: Invalid Input. Please Enter Y or N: ";
                cout << '\n';
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Do you want to play again? (Y/N): ";
                cout << '\n';
                cin >> Play_Again;
            }
            clear();
        } while (Play_Again == 'Y' || Play_Again == 'y');

        cout << '\n';
        cout << "Do you want to change the difficulty level? (Y/N): ";
        cout << '\n';
        cin >> Play_Again;
       

        // Validate difficulty input
        while (Play_Again != 'Y' && Play_Again != 'y' && Play_Again != 'N' && Play_Again != 'n')
        {
            cout << '\n';
            cout << "ERROR: Invalid Input. Please Enter Y or N: ";
            cout << '\n';
            cout << "Do you want to change the difficulty level? (Y/N): ";
            cout << '\n';
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> Play_Again;
        }
        clear();
    } while (Play_Again == 'Y' || Play_Again == 'y');

    cout << '\n';
    cout << "THANK YOU FOR PLAYING!!";
    cout << '\n';
    return 0;
}

char getUserChoice()
{

    char player;
    cout << '\n';
    cout << "\t\t\t    ==Rock-Paper-Scissors Game==\n";

    do
    {
        cout << "\t\t\t\t   Pick your choice\n";
        cout << "\t\t\t-------------------------------------\t\t\t\n";
        cout << "\t=====================" << "\t=====================" << " \t=====================\n";
        cout << "\t|         _______   |" << "\t|     _______       |" << " \t|     _______       |\n";
        cout << "\t|   -- - '   ____)  |" << "\t| ---'   ____)____  |" << " \t| ---'   ____)____  |\n";
        cout << "\t|          (_____)  |" << "\t|           ______) |" << " \t|            ______)|\n";
        cout << "\t|          (_____)  |" << "\t|           _______)|" << " \t|        __________)|\n";
        cout << "\t|          (____)   |" << "\t|          _______) |" << " \t|         (____)    |\n"; 
        cout << "\t|   ---.__(___)     |" << "\t| ---.__________)   |" << " \t|   ---.__(___)     |\n"; 
        cout << "\t|                   |" << "\t|                   |" << " \t|                   |\n"; 
        cout << "\t|    (R)Rock        |" << "\t|    (P)Paper       |" << " \t|   (S)Scissors     |\n";
        cout << "\t=====================" << "\t=====================" << " \t=====================\n";
        cout << "\n";
        cout << "Enter your choice: ";
        cin >> player;
        player = tolower(player);

        // error handling ng user choice
        if (player != 'r' && player != 'p' && player != 's')
        {
            cout << '\n';
            cout << "ERROR: Invalid Input. Please enter R, P, and S only. '\n ";
            cout << '\n';
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (player != 'r' && player != 'p' && player != 's');

    return player;
}

char getComputerChoice(int difficulty, char player)
{

    srand(time(0));
    int num;

    switch (difficulty) {
    case 1: // easy
        num = rand() % 3 + 1; // Equal chances for all choices
        break;
    case 2: // medium
        num = rand() % 4 + 1; // Slightly higher chances for computer
        break;
    case 3: // hard
        if (player == 'r') {
            num = rand() % 5 + 1; // Higher chances for computer to counter player's choice
        }
        else if (player == 'p') {
            num = rand() % 6 + 1; // Even higher chances for computer
        }
        else {
            num = rand() % 7 + 1; // Highest chances for computer
        }
        break;
    default:
        num = rand() % 3 + 1; // Default to medium difficulty
    }


    switch (num) {
    case 1:
        return 'r';
    case 2:
        return 'p';
    case 3:
        return 's';
    case 4:
        return 'r'; // Slightly favor rock
    case 5:
        return 'p'; // Slightly favor paper
    case 6:
        return 's'; // Slightly favor scissors
    default:
        return 'r'; // Default to rock
    }
}

void showChoice(char choice)
{
    switch (choice)
    {
    case 'r':
        cout << "\t=====================                                                                       \n";
        cout << "\t|         _______   |                                                                       \n";
        cout << "\t|   -- - '   ____)  |" << "\t=====================" << " \t=====================\n";
        cout << "\t|          (_____)  |" << "\t|     _______       |" << " \t|     _______       |\n";
        cout << "\t|          (_____)  |" << "\t| ---'   ____)____  |" << " \t| ---'   ____)____  |\n";
        cout << "\t|          (____)   |" << "\t|           ______) |" << " \t|            ______)|\n";
        cout << "\t|   ---.__(___)     |" << "\t|           _______)|" << " \t|        __________)|\n";
        cout << "\t|                   |" << "\t|          _______) |" << " \t|         (____)    |\n";
        cout << "\t|       Rock        |" << "\t| ---.__________)   |" << " \t|   ---.__(___)     |\n";
        cout << "\t=====================" << "\t|                   |" << " \t|                   |\n";
        cout << "\t\t\t        |       Paper       |" << "\t|      Scissors     |\n";
        cout << "\t\t\t        =====================" << "\t=====================\n";
        break;
    case 'p':    
        cout << "\t\t\t        =====================   \n";
        cout << "\t\t\t        |     _______       |   \n";
        cout << "\t=====================" << "\t| ---'   ____)____  |" << " \t=====================\n";
        cout << "\t|         _______   |" << "\t|           ______) |" << " \t|     _______       |\n";
        cout << "\t|   -- - '   ____)  |" << "\t|           _______)|" << " \t| ---'   ____)____  |\n";
        cout << "\t|          (_____)  |" << "\t|          _______) |" << " \t|            ______)|\n";
        cout << "\t|          (_____)  |" << "\t| ---.__________)   |" << " \t|        __________)|\n";
        cout << "\t|          (____)   |" << "\t|                   |" << " \t|         (____)    |\n";
        cout << "\t|   ---.__(___)     |" << "\t|       Paper       |" << " \t|   ---.__(___)     |\n";
        cout << "\t|                   |" << "\t=====================" << " \t|                   |\n";
        cout << "\t|       Rock        |" << "\t\t\t\t|      Scissors     |\n"; 
        cout << "\t=====================" << "\t\t\t\t=====================\n"; 
        break;
    case 's':
        cout << "\t\t\t\t\t\t        =====================\n";
        cout << "\t\t\t\t\t\t        |     _______       |\n";
        cout << "\t=====================" << "\t=====================" << " \t| ---'   ____)____  |\n";
        cout << "\t|         _______   |" << "\t|     _______       |" << " \t|            ______)|\n";
        cout << "\t|   -- - '   ____)  |" << "\t| ---'   ____)____  |" << " \t|        __________)|\n";
        cout << "\t|          (_____)  |" << "\t|           ______) |" << " \t|         (____)    |\n";
        cout << "\t|          (_____)  |" << "\t|           _______)|" << " \t|   ---.__(___)     |\n";
        cout << "\t|          (____)   |" << "\t|          _______) |" << " \t|                   |\n";
        cout << "\t|   ---.__(___)     |" << "\t| ---.__________)   |" << "   |      Scissors     |\n"; 
        cout << "\t|                   |" << "\t|                   |" << "   =====================\n";
        cout << "\t|       Rock        |" << "\t|       Paper       |\n";
        cout << "\t=====================" << "\t =====================\n";
        break;
    }
}

void chooseWinner(char player, char computer, int& User_Score, int& Computer_Score)
{
    switch (player)
    {
    case 'r':
        if (computer == 'r')
        {
            cout << "Tie\n";
            cout << '\n';
        }
        else if (computer == 'p')
        {
            cout << "HHHH YOU LOOSE\n";
            cout << '\n';
            Computer_Score++;
        }
        else
        {
            cout << '\n';
            cout << "YOU WIN!\n";
            cout << '\n';
            User_Score++;
        }
        break;
    case 'p':
        if (computer == 'r')
        {
            cout << '\n';
            cout << "YOU WIN\n";
            cout << '\n';
            User_Score++;
        }
        else if (computer == 'p')
        {
            cout << "Tie\n";
            cout << '\n';
        }
        else
        {
            cout << '\n';
            cout << "HHHH YOU LOOSE\n";
            cout << '\n';
            Computer_Score++;
        }
        break;
    case 's':
        if (computer == 'r')
        {
            cout << '\n';
            cout << "HHHH YOU LOOSE\n";
            cout << '\n';
            Computer_Score++;
        }
        else if (computer == 'p')
        {
            cout << '\n';
            cout << "YOU WIN\n";
            cout << '\n';
            User_Score++;
        }
        else
        {
            cout << '\n';
            cout << "Tie\n";
            cout << '\n';
        }
        break;
    }
}

void ascii()
{
    cout << " ____  ____   ___  ____            __   __  \n";
    cout << "(  _ \\/ ___) / __)/ ___)   ___    /  \\ / _\\ \n";
    cout << " ) _ (\\___ \\( (__ \\___ \\  (___)  (_/ //    \\\n";
    cout << "(____/(____/ \\___)(____/          (__)_/\\_/\n";
}
void clear()
{
    cout << "\nPress Enter key to continue...";
    cin.ignore();
    cin.get();

    system("cls");
}
