#include<iostream>
#include<string>
#include <iomanip>
#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

void EraseTextCentered(const string& text, int delayMs);
void PrintCentered(const string& text);
void TypeTextCentered(const string& text, int delayMs);
const int CONSOLE_WIDTH = 100;

struct stQuestion
{
    string QuestionText;
    string OptionA, OptionB, OptionC, OptionD;
    char CorrectOption;
    int PrizeAmount;

};

char InputCentered(const string& prompt)
{
    char Answer;
    while (true)
    {
        int spaces = (CONSOLE_WIDTH - prompt.length()) / 2;
        if (spaces < 0) spaces = 0;

        cout << string(spaces, ' ') << prompt;
        cin >> Answer;
        Answer = toupper(Answer);

        if (Answer == 'A' || Answer == 'B' || Answer == 'C' || Answer == 'D')
            break;
        else
            TypeTextCentered("Invalid input. Please enter A, B, C, or D only.", 20);
    }
    return Answer;
}

bool AskQuestion(const stQuestion& Q, int QuestionNumber, int TotalEarnings)
{
    system("cls");


    string header = "Question " + to_string(QuestionNumber) + " - Prize: $" + to_string(Q.PrizeAmount);
    TypeTextCentered(header, 20);


    string moneyBar = "Current Earnings: $" + to_string(TotalEarnings);
    TypeTextCentered(moneyBar, 20);
    cout << endl;


    TypeTextCentered(Q.QuestionText, 25);
    this_thread::sleep_for(chrono::milliseconds(500));


    TypeTextCentered("A) " + Q.OptionA, 20);
    TypeTextCentered("B) " + Q.OptionB, 20);
    TypeTextCentered("C) " + Q.OptionC, 20);
    TypeTextCentered("D) " + Q.OptionD, 20);
    cout << endl;


    char Answer = InputCentered("Your answer (A/B/C/D): ");


    bool isCorrect = (Answer == Q.CorrectOption);


    string GREEN = "\033[1;32m";
    string RED = "\033[1;31m";
    string RESET = "\033[0m";

    if (isCorrect)
        TypeTextCentered(GREEN + "      Correct! You won $" + to_string(Q.PrizeAmount) + RESET, 20);
    else
        TypeTextCentered(RED + "       Wrong! The correct answer was " + string(1, Q.CorrectOption) + RESET, 20);

    this_thread::sleep_for(chrono::milliseconds(1000));

    return isCorrect;
}

vector<stQuestion> LoadQuestions()
{
    vector<stQuestion> Questions;

    Questions.push_back({
     "Which of the following is a valid way to declare a pointer to an integer?",
     "int ptr;", "int *ptr;", "int &ptr;", "pointer<int> ptr;",
     'B', 100
        });

    Questions.push_back({
        "What does the keyword 'const' mean when used with a variable?",
        "It can be changed anytime", "It must be initialized to zero", "It cannot be modified", "It is a global variable",
        'C', 200
        });

    Questions.push_back({
        "Which of the following is used to define a class in C++?",
        "struct", "object", "class", "define",
        'C', 300
        });

    Questions.push_back({
        "What is the output of: cout << 5 / 2;",
        "2.5", "2", "2.0", "Error",
        'B', 500
        });

    Questions.push_back({
        "Which STL container maintains sorted order automatically?",
        "vector", "queue", "set", "stack",
        'C', 1000
        });

    Questions.push_back({
        "What is the default access modifier for class members in C++?",
        "public", "private", "protected", "internal",
        'B', 2000
        });

    Questions.push_back({
        "Which keyword is used to inherit from a base class?",
        "extends", "inherits", "public", "base",
        'C', 4000
        });

    Questions.push_back({
        "What does the 'new' keyword do in C++?",
        "Deletes a variable", "Allocates memory", "Initializes a loop", "Ends a program",
        'B', 8000
        });

    Questions.push_back({
        "Which of the following is NOT a valid loop in C++?",
        "for", "while", "repeat", "do-while",
        'C', 16000
        });

    Questions.push_back({
        "What is the purpose of a constructor?",
        "To destroy objects", "To allocate memory", "To initialize objects", "To call functions",
        'C', 32000
        });

    Questions.push_back({
        "Which header file is needed for using 'cout'?",
        "<stdio.h>", "<iostream>", "<conio.h>", "<stdlib.h>",
        'B', 64000
        });

    Questions.push_back({
        "Which of the following is a correct way to declare a reference?",
        "int& ref = x;", "int ref = &x;", "int *ref = x;", "ref int = x;",
        'A', 125000
        });

    Questions.push_back({
        "Which keyword is used to prevent inheritance in C++?",
        "static", "final", "sealed", "private",
        'B', 250000
        });

    Questions.push_back({
        "Which of the following is used to handle exceptions?",
        "try-catch", "if-else", "switch-case", "goto",
        'A', 500000
        });

    Questions.push_back({
        "Which of the following is a smart pointer in C++?",
        "auto_ptr", "shared_ptr", "unique_ptr", "All of the above",
        'D', 1000000
        });

    Questions.push_back({
        "Which of the following is a valid way to declare a vector?",
        "vector<int> v;", "int vector v;", "v<int> vector;", "vector = int;",
        'A', 1100000
        });

    Questions.push_back({
        "Which keyword is used to define a template?",
        "define", "template", "class", "typename",
        'B', 1200000
        });

    Questions.push_back({
        "Which of the following is used to access members of a pointer to object?",
        ".", "->", "::", "[]",
        'B', 1300000
        });

    Questions.push_back({
        "Which of the following is used to overload operators?",
        "operator", "overload", "function", "method",
        'A', 1400000
        });

    Questions.push_back({
        "Which of the following is a valid file stream class?",
        "ifstream", "file", "stream", "fopen",
        'A', 1500000
        });

    Questions.push_back({
        "Which function is used to read a line from a file?",
        "getline()", "readline()", "get()", "scanline()",
        'A', 1600000
        });

    Questions.push_back({
        "Which keyword is used to define a namespace?",
        "package", "namespace", "module", "space",
        'B', 1700000
        });

    Questions.push_back({
        "Which of the following is NOT a C++ access specifier?",
        "public", "private", "protected", "internal",
        'D', 1800000
        });

    Questions.push_back({
        "Which of the following is used to define a constant?",
        "const", "#define", "constexpr", "All of the above",
        'D', 1900000
        });

    Questions.push_back({
        "Which of the following is used to terminate a loop?",
        "break", "continue", "exit", "return",
        'A', 2000000
        });

    Questions.push_back({
        "Which of the following is used to skip current iteration?",
        "break", "continue", "exit", "return",
        'B', 2100000
        });

    Questions.push_back({
        "Which of the following is used to define a macro?",
        "#macro", "#define", "#const", "#include",
        'B', 2200000
        });

    Questions.push_back({
        "Which of the following is used to include a header file?",
        "#include", "#header", "#file", "#import",
        'A', 2300000
        });

    Questions.push_back({
        "Which of the following is used to define a function?",
        "function", "def", "void", "method",
        'C', 2400000
        });

    Questions.push_back({
        "Which of the following is used to exit from a program?",
        "break", "continue", "exit()", "return",
        'C', 2500000
        });

    return Questions;
}

void TypeTextCentered(const string& text, int delayMs)
{
    int spaces = (CONSOLE_WIDTH - text.length()) / 2;
    if (spaces < 0) spaces = 0;
    cout << string(spaces, ' ');

    for (char c : text)
    {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }
    cout << endl;
}

void ShowFarewellScreen()
{
    system("cls");

    string msg = "Thank you for playing 'Who Wants to Be a Millionaire - Programmer Edition'";
    TypeTextCentered("Thank you for playing 'Who Wants to Be a Millionaire - Programmer Edition'", 20);
    TypeTextCentered("We hope you enjoyed the challenge.", 20);
    TypeTextCentered("See you next time.", 20);
    TypeTextCentered("Press any key to exit...", 20);

    system("pause >nul");
}

void ShowGameOverScreen(int totalEarnings, bool lostAfterSafePoint)
{
    system("cls");

    string title = lostAfterSafePoint ? "You lost after the safe point!" : "You failed to reach the safe point!";
    string earnings = lostAfterSafePoint ? "You lost all your earnings!" : "You earned: $" + to_string(totalEarnings);

    TypeTextCentered(title, 20);
    TypeTextCentered(earnings, 20);
    TypeTextCentered("Better luck next time!", 20);
    TypeTextCentered("Press any key to continue...", 20);

    system("pause >nul");
}

void ShowVictoryScreen(int totalEarnings, bool isHalfMillion)
{
    system("cls");

    string title = isHalfMillion ? "You walked away with HALF A MILLION!" : "CONGRATULATIONS! YOU ARE A MILLIONAIRE!";
    string earnings = "Total Earnings: $" + to_string(totalEarnings);

    TypeTextCentered(title, 20);
    TypeTextCentered(earnings, 20);
    TypeTextCentered("Thanks for playing!", 20);
    TypeTextCentered("Press any key to continue...", 20);

    system("pause >nul");
}

bool ShowSafePointScreen(int totalEarnings)
{
    system("cls");

    string msg = "Congratulations! You've reached the safe point: $" + to_string(totalEarnings);
    TypeTextCentered("Congratulations! You've reached the safe point: $" + to_string(totalEarnings), 20);
    TypeTextCentered("Do you want to continue to $1,000,000?", 20);
    TypeTextCentered("1) Yes, take the risk", 20);
    TypeTextCentered("2) No, I want to walk away", 20);
    TypeTextCentered("Your choice (1/2): ", 20);

    int choice;

    while (true)
    {
        cin >> choice;
        if (cin.fail() || (choice != 1 && choice != 2))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            PrintCentered("Invalid input. Please enter 1 or 2.");
        }
        else
            break;
    }


    return (choice == 1);
}

bool HandleCorrectAnswer(int& correctAnswers, int& totalEarnings, bool& reachedSafePoint, const stQuestion& Q)
{
    correctAnswers++;
    totalEarnings = Q.PrizeAmount;

    if (correctAnswers == 5 && !reachedSafePoint)
    {
        reachedSafePoint = true;
        return ShowSafePointScreen(totalEarnings);
    }

    if (correctAnswers == 10)
    {
        ShowVictoryScreen(totalEarnings, false);
        return false;
    }

    return true;
}

bool HandleWrongAnswer(int& wrongAttempts, bool reachedSafePoint, int totalEarnings)
{
    if (!reachedSafePoint)
    {
        wrongAttempts++;
        if (wrongAttempts >= 3)
        {
            ShowGameOverScreen(totalEarnings, false);
            return false;
        }
    }
    else
    {
        ShowGameOverScreen(totalEarnings, true);
        return false;
    }

    return true;
}

const vector<int> PrizeTable = {
    100,
    200,
    300,
    500,
    1000,
    2000,
    4000,
    8000,
    16000,
    1000000
};

void StartGame()
{
    vector<stQuestion> Questions = LoadQuestions();

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(Questions.begin(), Questions.end(), g);

    int TotalEarnings = 0;
    int CorrectAnswers = 0;
    int WrongAttempts = 0;
    bool ReachedSafePoint = false;
    string previousQuestionText = "";

    for (int i = 0; i < 10; ++i)
    {
        Questions[i].PrizeAmount = PrizeTable[i];

        if (!previousQuestionText.empty())
            EraseTextCentered(previousQuestionText, 15);

        bool isCorrect = AskQuestion(Questions[i], i + 1, TotalEarnings);

        previousQuestionText = Questions[i].QuestionText;

        bool continueGame;

        if (isCorrect)
            continueGame = HandleCorrectAnswer(CorrectAnswers, TotalEarnings, ReachedSafePoint, Questions[i]);
        else
            continueGame = HandleWrongAnswer(WrongAttempts, ReachedSafePoint, TotalEarnings);

        if (!continueGame)
            break;
    }
}

void ShowWelcomeScreen()
{
    system("cls");

    const int ConsoleWidth = 100;

    auto center = [](const string& text, int width)
        {
            int spaces = (width - text.length()) / 2;
            cout << string(spaces, ' ') << text << "\n";
        };

    TypeTextCentered("Welcome to 'Who Wants to Be a Millionaire - Programmer Edition'", 20);
    TypeTextCentered("You will face 10 programming questions.", 20);
    TypeTextCentered("Answer 5 correctly to reach the safe point ($500,000).", 20);
    TypeTextCentered("After that, you can walk away or risk it all for $1,000,000.", 20);
    TypeTextCentered("Before the safe point, you have 3 chances to make mistakes.", 20);
    TypeTextCentered("Good luck, and think carefully!", 20);
    TypeTextCentered("Press any key to begin...", 20);

    system("pause >nul");
}

bool AskReplay()
{
    system("cls");

    int choice;
    bool valid = false;

    do
    {
        cout << "\n\n";
        cout << setw(60) << "Do you want to play again?\n";
        cout << setw(60) << "1) Yes\n";
        cout << setw(60) << "2) No\n\n";

        cout << setw(60) << "Your choice (1/2): ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << setw(60) << "Invalid input. Please enter a number (1 or 2).\n\n";
        }
        else if (choice == 1 || choice == 2)
        {
            valid = true;
        }
        else
        {
            cout << setw(60) << "Invalid input. Please enter 1 or 2 only.\n\n";
        }

    } while (!valid);

    return (choice == 1);
}

void PrintCentered(const string& text)
{
    int spaces = (CONSOLE_WIDTH - text.length()) / 2;
    if (spaces < 0) spaces = 0;
    cout << string(spaces, ' ') << text << endl;
}

void EraseTextCentered(const string& text, int delayMs = 20)
{
    for (int i = text.length(); i >= 0; --i)
    {
        system("cls");
        string sub = text.substr(0, i);
        int spaces = (CONSOLE_WIDTH - sub.length()) / 2;
        if (spaces < 0) spaces = 0;
        cout << string(spaces, ' ') << sub << endl;
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }
}

int main()
{
    ShowWelcomeScreen();

    do
    {
        StartGame();
    } while (AskReplay());

    ShowFarewellScreen();

    return 0;
}
