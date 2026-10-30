# 🎯 Mastermind — Number Edition

A command-line version of the classic **Mastermind** code-breaking game, implemented in both **Python** and **C**.

Instead of colored pegs, the secret key is a **4-digit number with no repeated digits**. You get **12 guesses** to crack it, with feedback after every attempt.

This project is based on the *Mastermind* problem from **Computer Science with Python – Class XII** (Appendix 3).

---

## 📖 How the Game Works

1. The program first asks for the **4-digit key** that will be guessed. It does not generate a random key, which makes the game easy to test.
2. The player then enters guesses, one at a time.
3. After each valid guess, the program prints feedback with two numbers:
   - **position**: digits that are correct *and* in the right place
   - **exist**: digits that are in the key but in the *wrong* place
4. The game ends when:
   - 🏆 the guess matches the key (winner message and number of guesses taken), or
   - ❌ the 12th guess is wrong (loser message and the key is revealed).
5. A running **history of all guesses** and their feedback is shown each round, so you can see your progress.

### Rules for a valid guess

| Rule | Example of invalid input |
|------|--------------------------|
| Must be exactly 4 characters long | `123`, `12345` |
| Must contain only digits | `1b34` |
| Must have no repeated digits | `1123` |

Invalid input prints an error message and asks again. **It does not count as a guess.**

### Feedback example

Key = `1234`, Guess = `4256`

- `2` is in the key and in the correct position → **position: 1**
- `4` is in the key but in the wrong position → **exist: 1**

Each digit of the guess produces at most one result (exact or misplaced).

---

## 🖥️ Sample Run

```
What is the key : 1234
Guess : 4321
4321 : exist:4, position:0

Guess : 5678
4321 : exist:4, position:0
5678 : exist:0, position:0

Guess : 1243
4321 : exist:4, position:0
5678 : exist:0, position:0
1243 : exist:2, position:2

Guess : 123
****guess must have length of 4, try again

Guess : 1b34
****contains non-numbers, try again

Guess : 1123
****no repeated digits, try again

Guess : 1234
You guessed the key: 1234
It took you 4 guesses
```

---

## 📁 Project Structure

```
Game---Mastermind/
├── mastermind.py    # Python implementation
├── mastermind.c     # C implementation
└── README.md
```

> Update the file names above to match the actual files in the repository.

---

## 🚀 Getting Started

### Clone the repository

```bash
git clone https://github.com/pushpiyush/Game---Mastermind.git
cd Game---Mastermind
```

### Run the Python version

Requires **Python 3.x**.

```bash
python mastermind.py
```

### Run the C version

Requires a C compiler such as **GCC**.

```bash
gcc mastermind.c -o mastermind
./mastermind
```

On Windows (MinGW):

```bash
gcc mastermind.c -o mastermind.exe
mastermind.exe
```

---

## 🧠 Implementation Notes

- **Input validation** checks length, digits-only, and no repeats before a guess is accepted.
- **Feedback logic** compares each guess digit against the key: same position counts as `position`, present elsewhere counts as `exist`.
- **Guess history** is stored and reprinted after every valid guess.
- The same logic is written in two languages, which makes it a handy comparison of how Python and C handle strings, arrays, and input.

---

## 🛠️ Concepts Practiced

- Loops and conditionals
- String / character-array handling
- Input validation
- Lists in Python and arrays in C
- Game-state tracking (guess count, history, win/lose conditions)

---
