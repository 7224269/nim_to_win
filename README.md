COEN 243 Project (Nim to Win)

Deadline: December 3, 2023

Type: Group (Not Compulsory)

Weight:7%

Submission: Moodle

//***********************************************************************************

Write the code in C++ to simulate a Nim game. The rules of Nim are as follows:

1- This game includes two players.

2- Each player can pick up from one pile.

3- The player can only take one or two tokens.

4- The winner is the player who makes the last move.

5- Suppose we only have 5 heaps.

8- The game must be recursive, namely, it calls itself each turn.

7- Try to use an array in C++ style (for example to represent the heaps).

//***********************************************************************************

Code conditions:

- The game displays three options:
  
1- Two players (user vs. user)
  
2- Two players (PC vs. user)

3- Exit

- In the next step, the users must enter their names. Thus, the player's turn is displayed during the game run.
  
- At the end of the game, display the winner's name.
  
The first option, user vs. user, allows two people to play the game.

- Prompt the user to enter the total number of tokens.
  
- Distribute tokens to 5 piles randomly so that there is no empty pile at the beginning.
For example, let's say the user enters 15 tokens, the game might display the following:

A: O O

B: O O O O

C: O O O

D: O O O O O

E: O

Note her the pile is represented by a row but you can draw it vertically as you like.

Assume player1 chooses two tokens from the second pile, she/he may enter B2 or B 2 then the game shows

A: O O

B: O O

C: O O O

D: O O O O O

E: O

The second option, PC vs. user, option allows the user to play against your algorithm.

- Instead of using only 5 heaps, prompt the user to enter the number of heaps (or columns).

- Distribute tokens to all piles based on the binary number weight. For example, the first pile has 1 token, 20,
the second pile has 2 tokens, 21, the third token has 4 tokens, 22, and so on.

- Develop an algorithm enabling your game to play and win against any user.
  
//*************************************************************************************************

Note:

- This game (project is a team of 2 students).
  
- To create this game you are allowed to use materials and concepts covered during COEN 243 lectures.
It is not allowed to use something that we didn't cover during our study otherwise, 20% of your grade will be deducted.

- The main objective of this game is to apply the knowledge gained from the course lectures.
  
//************************************************************************************************

Evaluation process:

- First, two students, namely from two teams, must test their games.
  
- Each student examines his or her colleague's game based on the form that is available on Moodle.
  
- Submit the form with your project on Moodle.
  
- We will hold a tournament to determine the winners of this league. Recall, this Nim is to win :)

© Dr. Fadi Alzhouri 2023. All rights reserved.
