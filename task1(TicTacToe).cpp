#include <iostream>
#include <limits>

using namespace std;

class TicTacToe {
private:
  int board[3][3]; // 3x3 board for Tic-Tac-Toe game
  int currentPlayer; // 0 for player X, 1 for player O
  //bool gameWon; // Flag to indicate if the game is won
  //bool gameDraw; // Flag to indicate if the game is a draw

public:
  bool gameWon; // Flag to indicate if the game is won
  bool gameDraw; // Flag to indicate if the game is a draw
  // Constructor to initialize the board
  TicTacToe() {
    currentPlayer = 0; // Player X starts the game
    gameWon = false;
    gameDraw = false;
    // Initialize the board with all zeros
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        board[i][j] = 0;
      }
    }
  }

  // Function to make a move
  void makeMove(int row, int col) {
    // Check if the move is valid
    if (validMove(row, col)) {
      // Update the board with the current player's symbol
      //board[row][col] = currentPlayer;
      board[row][col] = currentPlayer == 0 ? 2 : 1;
      // Switch to the other player
      currentPlayer = (currentPlayer + 1) % 2;
      // Check if the game is won or draw
      gameWon = checkWin();
      gameDraw = checkDraw();
      printBoard();
    } else {
      cout << "Invalid move. Please enter a valid location." << endl;
    }
  }

  // Function to check if a move is valid
  bool validMove(int row, int col) {
    // Check if the move is within the bounds of the board
    if (row >= 0 && row <= 2 && col >= 0 && col <= 2) {
      // Check if the cell is empty
      if (board[row][col] == 0) {
        return true;
      } else {
        cout << "Location (" << row << ", " << col << ") is already occupied." << endl;
      }
    } else {
      cout << "Invalid location. Please enter a valid location." << endl;
    }
    return false;
  }

  // Function to check if the game is won
  bool checkWin() {
    // Check rows
    for (int i = 0; i < 3; i++) {
      if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0) {
        return true;
      }
    }
    // Check columns
    for (int j = 0; j < 3; j++) {
      if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != 0) {
        return true;
      }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0)) {
      return true;
    }
    return false;
  }

  // Function to check if the game is a draw
  bool checkDraw() {
    // Check if all cells are occupied
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[i][j] == 0) {
          return false;
        }
      }
    }
    return true;
  }

  // Function to print the board
  void printBoard() {
    cout << "  0  1  2" << endl;
    for (int i = 0; i < 3; i++) {
      cout << i << " ";
      for (int j = 0; j < 3; j++) {
        if (board[i][j] == 0) {
          cout << "  ";
        } else if (board[i][j] == 1 ) {
          cout << " X ";
        } else {
          cout << " o ";
        }
      }
      cout << endl;
    }
    if (currentPlayer == 0) {
      cout << "Player X enter move: ";
    } else {
      cout << "Player O enter move: ";
    }
  }

  // Function to get the game status
  void gameStatus() {
    if (gameWon) {
      if (currentPlayer == 0) {
        cout << "Player O wins!" << endl;
      } else {
        cout << "Player X wins!" << endl;
      }
    } else if (gameDraw) {
      cout << "The game is a draw!" << endl;
    }
  }
};

int main() {
  // Create an instance of TicTacToe game
  TicTacToe game;
  // Print the initial board
  game.printBoard();

  // Game loop
  while (!game.gameWon && !game.gameDraw) {
    int row, col;
    cout << "Enter row and column (separated by space): ";
    cin >> row >> col;
    // Validate the input
    while (cin.fail() || row < 0 || row > 2 || col < 0 || col > 2) {
      cout << "Invalid input. Please enter valid row and column." << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Enter row and column (separated by space): ";
      cin >> row >> col;
    }
    // Make a move
    game.makeMove(row, col);
    // Check if the game is won or draw
    game.gameStatus();
  }

  return 0;
}
