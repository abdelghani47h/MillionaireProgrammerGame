# 🎮 Who Wants to Be a Millionaire - Programmer Edition

Welcome to **"Who Wants to Be a Millionaire - Programmer Edition"**, a console-based quiz game built in **C++**.

This game challenges players with **programming questions** and simulates the experience of the popular game show, including **animated text effects**, **progressive prize money**, and a **safe point system**.

---

## 📝 Features

- **10 challenging programming questions** per game session.
- **Safe point system:** reach 5 correct answers to secure earnings.
- **Answer validation:** only valid inputs (A/B/C/D) are accepted.
- **Animated text effects:** questions and answers appear progressively like in movies.
- **Dynamic erase effect:** previous question text erases progressively before showing the next one.
- **Victory and Game Over screens:** clearly show results with animated text.
- **Colored feedback:** correct answers appear in **green**, wrong answers in **red**.
- **Replay option:** play multiple times without restarting the program.

---

## ⚙️ Project Structure

### 1️⃣ Main File

- **main.cpp** – Contains the complete game logic, question handling, and console animations.

### 2️⃣ Structs

- `stQuestion` – stores:
    - Question text
    - Options (A, B, C, D)
    - Correct answer
    - Prize amount

### 3️⃣ Core Functions

### 🎯 Gameplay

- `StartGame()` – main loop of the game:
    - Randomizes questions
    - Displays current earnings
    - Handles correct and wrong answers
    - Checks for safe points and victory
- `AskQuestion(const stQuestion& Q, int QuestionNumber, int TotalEarnings)`
    
    Displays a single question with options and handles user input.
    
- `HandleCorrectAnswer()` / `HandleWrongAnswer()`
    
    Updates score, checks for safe points, and determines continuation or game over.
    

### 🎨 UI & Animation

- `TypeTextCentered(const string& text, int delayMs)`
    
    Prints text **centered in console** with animated typing effect.
    
- `EraseTextCentered(const string& text, int delayMs)`
    
    Erases text progressively from the center, creating a "movie-style" animation.
    
- `PrintCentered(const string& text)`
    
    Prints a single line **centered** in the console.
    

### 💻 Screens

- `ShowWelcomeScreen()` – introduction before starting the game.
- `ShowSafePointScreen()` – asks the player if they want to continue after safe point.
- `ShowVictoryScreen()` – displays winning message and total earnings.
- `ShowGameOverScreen()` – displays losing message with total earnings.
- `ShowFarewellScreen()` – final exit screen.

### 🔄 Replay

- `AskReplay()` – asks the player if they want to play again.

---

## 🛠️ Tools & Libraries

- **Language:** C++ (C++11 and above)
- **Libraries:**
    - `<iostream>` – input/output
    - `<string>` – handling text
    - `<iomanip>` – formatting output
    - `<chrono>` & `<thread>` – delays for animations
    - `<vector>` – storing questions
    - `<algorithm>` – shuffling questions
    - `<random>` – generating random order of questions

---

## 💡 Future Enhancements (Optional)

- Implement **lifelines** like "50-50", "Ask the Audience", or "Skip Question".
- Add **file-based question storage** for easier updates.
- Improve **cross-platform compatibility** for console colors and animations.

---

## 🎨 Notes on Design

- **Centering:** all text is dynamically centered based on `CONSOLE_WIDTH = 100`.
- **Animated typing:** each character is printed with a delay for cinematic effect.
- **Progressive erase:** before displaying a new question, the previous question is erased character by character.
- **Color feedback:** ANSI escape codes are used to display correct answers in green and wrong answers in red.
- **Safe point:** securing earnings after 5 correct answers prevents losing money on mistakes.
- **Prize Table:** progressive prize money increases with each correct answer, adding tension and excitement.
- **Input validation:** ensures only correct options are accepted and prompts user if invalid input is entered.

---

## 📌 How to Play

1. Run the game executable (`main.exe` or your compiled binary).
2. Read the questions carefully and input your answer (A/B/C/D).
3. Reach **5 correct answers** to secure a safe point.
4. Decide if you want to risk it for the million-dollar prize.
5. Win by answering all questions correctly or walk away after the safe point.
6. After finishing, you can choose to play again.

---

## ✅ Conclusion

This project demonstrates **C++ console programming**, **animations**, **user interaction**, and **game logic management** in a structured and interactive way.

