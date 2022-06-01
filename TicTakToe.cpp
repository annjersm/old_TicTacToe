#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <string.h>
#include <cctype>

std::string gameVersion = " Game Version [ 2.0 ]\n";
std::string responce=" ";
std::string playerInput;
int inputL01, inputL02, inputL03, inputL04, inputL05, inputL06, inputL07, inputL08, inputL09;

bool gameBoard;
int PlayerX=0, PlayerO=0, Tie=0;
std::string player="x", startPlayer="x";
std::string empty="            ";

std::string x1=" ", x2=" ", x3=" ", x4=" ", x5=" ", x6=" ", x7=" ", x8=" ", x9=" ";
std::string Lx1_1 = empty, Lx1_2 = empty, Lx1_3 = "     1      ", Lx1_4 = empty, Lx1_5 = empty;
std::string Lx2_1 = empty, Lx2_2 = empty, Lx2_3 = "     2      ", Lx2_4 = empty, Lx2_5 = empty;
std::string Lx3_1 = empty, Lx3_2 = empty, Lx3_3 = "     3      ", Lx3_4 = empty, Lx3_5 = empty;
std::string Lx4_1 = empty, Lx4_2 = empty, Lx4_3 = "     4      ", Lx4_4 = empty, Lx4_5 = empty;
std::string Lx5_1 = empty, Lx5_2 = empty, Lx5_3 = "     5      ", Lx5_4 = empty, Lx5_5 = empty;
std::string Lx6_1 = empty, Lx6_2 = empty, Lx6_3 = "     6      ", Lx6_4 = empty, Lx6_5 = empty;
std::string Lx7_1 = empty, Lx7_2 = empty, Lx7_3 = "     7      ", Lx7_4 = empty, Lx7_5 = empty;
std::string Lx8_1 = empty, Lx8_2 = empty, Lx8_3 = "     8      ", Lx8_4 = empty, Lx8_5 = empty;
std::string Lx9_1 = empty, Lx9_2 = empty, Lx9_3 = "     9      ", Lx9_4 = empty, Lx9_5 = empty;

std::string lLx1 = " \\#\\    /#/ ", lLo1 = "   /####\\   ";
std::string lLx2 = "  \\#\\  /#/  ", lLo2 = " /#/    \\#\\ ";
std::string lLx3 = "   >####<   ",   lLo3 = " #<      ># ";
std::string lLx4 = "  /#/  \\#\\  ", lLo4 = " \\#\\    /#/ ";
std::string lLx5 = " /#/    \\#\\ ", lLo5 = "   \\####/   ";

void playerScore()
{
    std::cout << gameVersion;
    std::cout << "____________________________________________\n";
    std::cout << " Player x: " << PlayerX << "  |  " << "Player o: " << PlayerO << "  |  " << "Tie: " << Tie << std::endl << std::endl;
    std::cout << " Player " << player << std::endl;
}

void clear() {system("clear");}
void Message() {std::cout << responce << std::endl;}

void resetBoard()
{
    x1=" ", x2=" ", x3=" ", x4=" ", x5=" ", x6=" ", x7=" ", x8=" ", x9=" ";
    Lx1_1 = empty, Lx1_2 = empty, Lx1_3 = "     1      ", Lx1_4 = empty, Lx1_5 = empty;
    Lx2_1 = empty, Lx2_2 = empty, Lx2_3 = "     2      ", Lx2_4 = empty, Lx2_5 = empty;
    Lx3_1 = empty, Lx3_2 = empty, Lx3_3 = "     3      ", Lx3_4 = empty, Lx3_5 = empty;
    Lx4_1 = empty, Lx4_2 = empty, Lx4_3 = "     4      ", Lx4_4 = empty, Lx4_5 = empty;
    Lx5_1 = empty, Lx5_2 = empty, Lx5_3 = "     5      ", Lx5_4 = empty, Lx5_5 = empty;
    Lx6_1 = empty, Lx6_2 = empty, Lx6_3 = "     6      ", Lx6_4 = empty, Lx6_5 = empty;
    Lx7_1 = empty, Lx7_2 = empty, Lx7_3 = "     7      ", Lx7_4 = empty, Lx7_5 = empty;
    Lx8_1 = empty, Lx8_2 = empty, Lx8_3 = "     8      ", Lx8_4 = empty, Lx8_5 = empty;
    Lx9_1 = empty, Lx9_2 = empty, Lx9_3 = "     9      ", Lx9_4 = empty, Lx9_5 = empty;
    if (startPlayer == "x") {
        startPlayer = "o";
    } else {
        startPlayer = "x";
    }
}

void playerTie()
{
    Tie++;
    resetBoard();
}

void playerVictoryX()
{
    PlayerX++;
    resetBoard();
}

void playerVictoryO()
{
    PlayerO++;
    resetBoard();
}

void gameBoardLarge()
{
    playerScore();
    std::cout << " " << Lx1_1 << "##" << Lx2_1 << "##" << Lx3_1 << std::endl;
    std::cout << " " << Lx1_2 << "##" << Lx2_2 << "##" << Lx3_2 << std::endl;
    std::cout << " " << Lx1_3 << "##" << Lx2_3 << "##" << Lx3_3 << std::endl;
    std::cout << " " << Lx1_4 << "##" << Lx2_4 << "##" << Lx3_4 << std::endl;
    std::cout << " " << Lx1_5 << "##" << Lx2_5 << "##" << Lx3_5 << std::endl;
    std::cout << " ######################################## \n";
    std::cout << " " << Lx4_1 << "##" << Lx5_1 << "##" << Lx6_1 << std::endl;
    std::cout << " " << Lx4_2 << "##" << Lx5_2 << "##" << Lx6_2 << std::endl;
    std::cout << " " << Lx4_3 << "##" << Lx5_3 << "##" << Lx6_3 << std::endl;
    std::cout << " " << Lx4_4 << "##" << Lx5_4 << "##" << Lx6_4 << std::endl;
    std::cout << " " << Lx4_5 << "##" << Lx5_5 << "##" << Lx6_5 << std::endl;
    std::cout << " ######################################## \n";
    std::cout << " " << Lx7_1 << "##" << Lx8_1 << "##" << Lx9_1 << std::endl;
    std::cout << " " << Lx7_2 << "##" << Lx8_2 << "##" << Lx9_2 << std::endl;
    std::cout << " " << Lx7_3 << "##" << Lx8_3 << "##" << Lx9_3 << std::endl;
    std::cout << " " << Lx7_4 << "##" << Lx8_4 << "##" << Lx9_4 << std::endl;
    std::cout << " " << Lx7_5 << "##" << Lx8_5 << "##" << Lx9_5 << std::endl;
    std::cout << std::endl << std::endl;
    /*
     *     /####\   ## \#\    /#/ ##   /####\   
     *   /#/    \#\ ##  \#\  /#/  ## /#/    \#\ 
     *   #<      ># ##   >####<   ## #<      ># 
     *   \#\    /#/ ##  /#/  \#\  ## \#\    /#/ 
     *     \####/   ## /#/    \#\ ##   \####/   
     *  ########################################
     *     /####\   ## \#\    /#/ ## \#\    /#/ 
     *   /#/    \#\ ##  \#\  /#/  ##  \#\  /#/  
     *   #<      ># ##   >####<   ##   >####<   
     *   \#\    /#/ ##  /#/  \#\  ##  /#/  \#\  
     *     \####/   ## /#/    \#\ ## /#/    \#\ 
     *  ########################################
     *   \#\    /#/ ##   /####\   ## \#\    /#/ 
     *    \#\  /#/  ## /#/    \#\ ##  \#\  /#/  
     *     >####<   ## #<      ># ##   >####<   
     *    /#/  \#\  ## \#\    /#/ ##  /#/  \#\  
     *   /#/    \#\ ##   \####/   ## /#/    \#\ 
     */
}

void gameBoardSmal()
{
    playerScore();
    std::cout << " [" << x1 << "][" << x2 << "][" << x3 << "]    Tic" << std::endl;
    std::cout << " [" << x4 << "][" << x5 << "][" << x6 << "]    Tac" << std::endl;
    std::cout << " [" << x7 << "][" << x8 << "][" << x9 << "]    Toe" << std::endl;
    std::cout << std::endl << std::endl;
    if (x1 == " ") {std::cout << "  1";} else {std::cout << "   ";}
    if (x2 == " ") {std::cout << "  2";} else {std::cout << "   ";}
    if (x3 == " ") {std::cout << "  3";} else {std::cout << "   ";}
    std::cout << std::endl;
    if (x4 == " ") {std::cout << "  4";} else {std::cout << "   ";}
    if (x5 == " ") {std::cout << "  5";} else {std::cout << "   ";}
    if (x6 == " ") {std::cout << "  6";} else {std::cout << "   ";}
    std::cout << std::endl;
    if (x7 == " ") {std::cout << "  7";} else {std::cout << "   ";}
    if (x8 == " ") {std::cout << "  8";} else {std::cout << "   ";}
    if (x9 == " ") {std::cout << "  9";} else {std::cout << "   ";}
    std::cout << std::endl << std::endl;
}

void checkGameBoard()
{
    if (player == "o") {
        // Check Horizontal
        if (x1 == "x") {if (x2 == "x") {if (x3 == "x") {/*Victory for x*/ playerVictoryX(); }}}
        if (x4 == "x") {if (x5 == "x") {if (x6 == "x") {/*Victory for x*/ playerVictoryX(); }}}
        if (x7 == "x") {if (x8 == "x") {if (x9 == "x") {/*Victory for x*/ playerVictoryX(); }}}
        // Check Vertical
        if (x1 == "x") {if (x4 == "x") {if (x7 == "x") {/*Victory for x*/ playerVictoryX(); }}}
        if (x2 == "x") {if (x5 == "x") {if (x8 == "x") {/*Victory for x*/ playerVictoryX(); }}}
        if (x3 == "x") {if (x6 == "x") {if (x9 == "x") {/*Victory for x*/ playerVictoryX(); }}}
        // Check Diagonal
        if (x1 == "x") {if (x5 == "x") {if (x9 == "x") {/*Victory for x*/ playerVictoryX(); }}}
        if (x3 == "x") {if (x5 == "x") {if (x7 == "x") {/*Victory for x*/ playerVictoryX(); }}}
    }
    if (player == "x") {
        // Check Horizontal
        if (x1 == "o") {if (x2 == "o") {if (x3 == "o") {/*Victory for o*/ playerVictoryO(); }}}
        if (x4 == "o") {if (x5 == "o") {if (x6 == "o") {/*Victory for o*/ playerVictoryO(); }}}
        if (x7 == "o") {if (x8 == "o") {if (x9 == "o") {/*Victory for o*/ playerVictoryO(); }}}
        // Check Vertical
        if (x1 == "o") {if (x4 == "o") {if (x7 == "o") {/*Victory for o*/ playerVictoryO(); }}}
        if (x2 == "o") {if (x5 == "o") {if (x8 == "o") {/*Victory for o*/ playerVictoryO(); }}}
        if (x3 == "o") {if (x6 == "o") {if (x9 == "o") {/*Victory for o*/ playerVictoryO(); }}}
        // Check Diagonal
        if (x1 == "o") {if (x5 == "o") {if (x9 == "o") {/*Victory for o*/ playerVictoryO(); }}}
        if (x3 == "o") {if (x5 == "o") {if (x7 == "o") {/*Victory for o*/ playerVictoryO(); }}}
    }
    if (x1 != " ") {if (x2 != " ") {if (x3 != " ") {if (x4 != " ") {if (x5 != " ") {if (x6 != " ") {if (x7 != " ") { if (x8 != " ") {if (x9 != " ")
    {
        // It's a tie
        playerTie();
    }}}}}}}}}
}

void changeGameBoardLarge()
{
    // x1
    if (x1 == "x") { Lx1_1 = lLx1, Lx1_2 = lLx2, Lx1_3 = lLx3, Lx1_4 = lLx4, Lx1_5 = lLx5; }
    if (x1 == "o") { Lx1_1 = lLo1, Lx1_2 = lLo2, Lx1_3 = lLo3, Lx1_4 = lLo4, Lx1_5 = lLo5; }
    // x2
    if (x2 == "x") { Lx2_1 = lLx1, Lx2_2 = lLx2, Lx2_3 = lLx3, Lx2_4 = lLx4, Lx2_5 = lLx5; }
    if (x2 == "o") { Lx2_1 = lLo1, Lx2_2 = lLo2, Lx2_3 = lLo3, Lx2_4 = lLo4, Lx2_5 = lLo5; }
    // x3
    if (x3 == "x") { Lx3_1 = lLx1, Lx3_2 = lLx2, Lx3_3 = lLx3, Lx3_4 = lLx4, Lx3_5 = lLx5; }
    if (x3 == "o") { Lx3_1 = lLo1, Lx3_2 = lLo2, Lx3_3 = lLo3, Lx3_4 = lLo4, Lx3_5 = lLo5; }
    // x4
    if (x4 == "x") { Lx4_1 = lLx1, Lx4_2 = lLx2, Lx4_3 = lLx3, Lx4_4 = lLx4, Lx4_5 = lLx5; }
    if (x4 == "o") { Lx4_1 = lLo1, Lx4_2 = lLo2, Lx4_3 = lLo3, Lx4_4 = lLo4, Lx4_5 = lLo5; }
    // x5
    if (x5 == "x") { Lx5_1 = lLx1, Lx5_2 = lLx2, Lx5_3 = lLx3, Lx5_4 = lLx4, Lx5_5 = lLx5; }
    if (x5 == "o") { Lx5_1 = lLo1, Lx5_2 = lLo2, Lx5_3 = lLo3, Lx5_4 = lLo4, Lx5_5 = lLo5; }
    // x6
    if (x6 == "x") { Lx6_1 = lLx1, Lx6_2 = lLx2, Lx6_3 = lLx3, Lx6_4 = lLx4, Lx6_5 = lLx5; }
    if (x6 == "o") { Lx6_1 = lLo1, Lx6_2 = lLo2, Lx6_3 = lLo3, Lx6_4 = lLo4, Lx6_5 = lLo5; }
    // x7
    if (x7 == "x") { Lx7_1 = lLx1, Lx7_2 = lLx2, Lx7_3 = lLx3, Lx7_4 = lLx4, Lx7_5 = lLx5; }
    if (x7 == "o") { Lx7_1 = lLo1, Lx7_2 = lLo2, Lx7_3 = lLo3, Lx7_4 = lLo4, Lx7_5 = lLo5; }
    // x8
    if (x8 == "x") { Lx8_1 = lLx1, Lx8_2 = lLx2, Lx8_3 = lLx3, Lx8_4 = lLx4, Lx8_5 = lLx5; }
    if (x8 == "o") { Lx8_1 = lLo1, Lx8_2 = lLo2, Lx8_3 = lLo3, Lx8_4 = lLo4, Lx8_5 = lLo5; }
    // x9
    if (x9 == "x") { Lx9_1 = lLx1, Lx9_2 = lLx2, Lx9_3 = lLx3, Lx9_4 = lLx4, Lx9_5 = lLx5; }
    if (x9 == "o") { Lx9_1 = lLo1, Lx9_2 = lLo2, Lx9_3 = lLo3, Lx9_4 = lLo4, Lx9_5 = lLo5; }
}

void gameOn()
{
    int game=1;
    while (game == 1)
    {
        changeGameBoardLarge();
        checkGameBoard();
        clear();
        if (gameBoard == false) {
            gameBoardSmal();
        } else {
            gameBoardLarge();
        }
        std::cout << " Player " << player << ": ";
        std::cin >> playerInput;
        if (playerInput == "1") {if (x1 == " ") {x1 = player; if (player == "x") {player = "o";} else {player = "x";}}}
        if (playerInput == "2") {if (x2 == " ") {x2 = player; if (player == "x") {player = "o";} else {player = "x";}}}
        if (playerInput == "3") {if (x3 == " ") {x3 = player; if (player == "x") {player = "o";} else {player = "x";}}}
        if (playerInput == "4") {if (x4 == " ") {x4 = player; if (player == "x") {player = "o";} else {player = "x";}}}
        if (playerInput == "5") {if (x5 == " ") {x5 = player; if (player == "x") {player = "o";} else {player = "x";}}}
        if (playerInput == "6") {if (x6 == " ") {x6 = player; if (player == "x") {player = "o";} else {player = "x";}}}
        if (playerInput == "7") {if (x7 == " ") {x7 = player; if (player == "x") {player = "o";} else {player = "x";}}}
        if (playerInput == "8") {if (x8 == " ") {x8 = player; if (player == "x") {player = "o";} else {player = "x";}}}
        if (playerInput == "9") {if (x9 == " ") {x9 = player; if (player == "x") {player = "o";} else {player = "x";}}}
        if (playerInput == "q") {game--;}
        /** SWITCH /
        switch (playerInput)
        {
        case 1:
            if (x1 == " ") {x1 = player; if (player == "x") {player = "o";} else {player = "x";}}
            break;
        case 2:
            if (x2 == " ") {x2 = player; if (player == "x") {player = "o";} else {player = "x";}}
            break;
        case 3:
            if (x3 == " ") {x3 = player; if (player == "x") {player = "o";} else {player = "x";}}
            break;
        case 4:
            if (x4 == " ") {x4 = player; if (player == "x") {player = "o";} else {player = "x";}}
            break;
        case 5:
            if (x5 == " ") {x5 = player; if (player == "x") {player = "o";} else {player = "x";}}
            break;
        case 6:
            if (x6 == " ") {x6 = player; if (player == "x") {player = "o";} else {player = "x";}}
            break;
        case 7:
            if (x7 == " ") {x7 = player; if (player == "x") {player = "o";} else {player = "x";}}
            break;
        case 8:
            if (x8 == " ") {x8 = player; if (player == "x") {player = "o";} else {player = "x";}}
            break;
        case 9:
            if (x9 == " ") {x9 = player; if (player == "x") {player = "o";} else {player = "x";}}
            break;

        default:
            break;
        } /**/
    }
}

void help()
{
    std::string i = "1";
    while (i == "1")
    {
        clear();
        int flag;
        std::cout << gameVersion;
        printf("\nThe goal of tic-tac-toe is to be the first player to get three in a row on a 3-by-3 grid\n\n");
        printf("In a 3-by-3 grid game, the player who is playing 'X' always goes first. Players alternate \n");
        printf("placing Xs and Os on the board until either player has three in a row, horizontally, \n");
        printf("vertically, or diagonally or until all squares on the grid are filled. If a player is \n");
        printf("able to draw three Xs or three Os in a row, then that player wins. If all squares are \n");
        printf("filled and neither player has made a complete row of Xs or Os, then the game is a draw.\n\n");
        printf("Press 'q' to go back.\n");
        std::cin >> i;
    }
}

void newGame()
{
    resetBoard();
    player="x", startPlayer="x";
    gameOn();
}

void menu()
{
    int menu = 1;
    while (menu == 1)
    {
        clear();
        printf(" | - - Tic Tak Toe - -\n\n");
        printf(" 1 - New Game - Large Map\n");
        printf(" 2 - New Game - Smal Map\n");
        printf(" 3 - Help\n");
        printf("\n q - Quit\n");
        std::string input;
        std::cin >> input;
        if (input == "1") {gameBoard = true; newGame();}
        if (input == "2") {gameBoard = false; newGame();}
        if (input == "3") {help();}
        if (input == "q") {menu--;}
    }
}

int main()
{
    menu();
    return 0;
}