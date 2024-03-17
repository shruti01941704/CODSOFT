#include <iostream>
#include <vector>


void displayBoard(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


bool checkForWin(const std::vector<std::vector<char>>& board, char player) {
    
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}


bool checkForDraw(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; 
            }
        }
    }
    return true; 
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';

    do {
        
        displayBoard(board);

        
        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            std::cout << "Invalid move. Try again." << std::endl;
            continue;
        }

       
        board[row][col] = currentPlayer;

        
        if (checkForWin(board, currentPlayer)) {
            displayBoard(board);
            std::cout << "Player " << currentPlayer << " wins!" << std::endl;
            break;
        }

       
        if (checkForDraw(board)) {
            displayBoard(board);
            std::cout << "The game is a draw!" << std::endl;
            break;
        }

        
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

    } while (true);


    char playAgain;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        main(); 
    }

    return 0;
}
