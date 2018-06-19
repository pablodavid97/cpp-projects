#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int MAX_PLAYS = 9;
int MAX_SCORES = 5;

using namespace std;

struct Player {
	int num;
	string name;
	int score;
	bool win;
};


class TicTacToe {

public:

    TicTacToe()
    {
    	scores = 0;
		initializeValues();
		string name = "";
		setPlayer1(name);
		setPlayer2(name);
		readScores();
		displayMenu();
    };

	void initializeValues()
	{
		playNum = 0;
        setWin(false);
		player1.num = 1;
		player1.score = 0;
		player1.win = false;
		player2.num = 2;
		player2.score = 0;
		player2.win = false;

        for(int i=0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
			{
                board[i][j] = 0;
            }
        }
	}

	void addScore(Player &player)
	{
		string line = convertInt(player.score) + "\t\t" + player.name;
		maxScores[scores] = line;
		scores++;
	}

	string convertInt(int number)
	{
	   std::stringstream ss;//create a stringstream
	   ss << number;//add number to the stream
	   return ss.str();//return a string with the contents of the stream
	}

	void setScore(Player player)
	{
		string line1 = convertInt(player.score) + "\t\t" + player.name;
		string line2;
		int score = 0;

		for(int i = 0; i < MAX_SCORES; i++)
		{
			line2 = maxScores[i];
			int score = line2[0];

			if(player.score > 0)
			{
				maxScores[i] = line1;
			}
		}
	}

	void displayMenu()
	{
		char option = 0;

		while(option != 'n')
		{
			for(int i = 0; i < 30; i++)
			{
				cout << "-";
			}
			cout << endl;

			cout << "\tTic Tac Toe" << endl;

			for(int i = 0; i < 30; i++)
			{
				cout << "-";
			}
			cout << endl;

			cout << "a. Ver Lista de Scores." << endl
			<<  "b. Definir el nombre del Jugador1." << endl
			<< "c. Definir el nomber del Jugador2." << endl
			<< "d. Jugar una partida." << endl
			<< "e. Salir." << endl;

			cin >> option;
			string name = "";

			switch(option)
			{
				case ('a'):
					displayScores();
					cout << "\nDesea volver al menu principal (y/n)" << endl;
					cin >> option;

					if(option == 'y')
					{
						initializeValues();
					}
					else
					{
						cout << "Hasta luego" << endl;
					}
					break;
				case ('b'):
					cout << "Ingrese el nombre del Jugador1" << endl;
					cin >> name;
					setPlayer1(name);

					break;

				case ('c'):
					cout << "Ingrese el nombre del Jugador2" << endl;
					cin >> name;
					setPlayer2(name);

					break;
				case ('d'):
					if(player1.name == "" || player2.name == "")
					{
						cout << "Porfavor ingrese los nombres de los jugadores." << endl;
					}
					else
					{
						startGame();
						cout << "\nDesea volver al menu principal (y/n)" << endl;
						cin >> option;

						if(option == 'y')
						{
							initializeValues();
						}
						else
						{
							cout << "Hasta luego" << endl;
						}
					}
					break;
				case ('e'):
					cout << "Hasta luego" << endl;
					option = 'n';
					writeScores();
					break;
				default:
					cerr << "opcion invalida!" << endl;
			};
		}
	}

	void writeScores()
	{
		ofstream myfile;
		myfile.open ("scores.txt");

		for(int i = 0; i < scores; i++)
		{
			myfile << maxScores[i] << endl;
		}

		myfile.close();
	}

    void printBoard()
    {
        for(int i = 0; i <3; i++)
        {
            cout << "\t";

            for(int j = 0; j < 3; j++){

                if(board[i][j] == 1)
                {
                    cout << "| X ";
                }

                else if(board[i][j] == 2)
                {

                    cout << "| O ";
                }

                else
                {
                    cout << "| - ";
                }
            }

            cout << "|" << endl;
        }
    }

	void startGame()
	{
		printBoard();
		while(true)
		{
			playNum++;
			if(playNum % 2 != 0)
			{
				setPlay(player1);
			}
			else
			{
				setPlay(player2);
			}

			if(getWin() == true)
			{
				if(player1.win == true)
				{
					cout << player1.name << " gana!\n" << endl;

					if(scores < MAX_SCORES)
					{
						addScore(player1);
					}
					else
					{
						setScore(player1);
					}
				}
				else
				{
					cout << player2.name << " gana!\n" << endl;

					if(scores < MAX_SCORES)
					{
						addScore(player2);
					}
					else
					{
						setScore(player2);
					}
				}
				break;
			}

			if(playNum == MAX_PLAYS)
			{
				cout << "Nadie gana" << endl;
				break;
			}
		}
	}

	void setPlayer1(string playerName)
	{
		player1.name = playerName;
	}

	Player getPlayer1()
	{
		return player1;
	}

	void setPlayer2(string playerName)
    {
		player2.name = playerName;
	}

	Player getPlayer2()
	{
		return player2;
	}

    void setPlay(Player &player)
    {
        int i, j;

		cout << player.name << " score: " << player.score << endl;
        cout << "Ingrese la posicion (i, j)" << endl;

        cin >> i >> j;

        getPosition(i, j);


        if(board[i][j] == 0){
			player.score = MAX_PLAYS - playNum;

            switch(player.num)
            {
                case 1:

                    board[i][j] = 1;

                    checkWin(player, i, j);

                    break;

                case 2:

                    board[i][j] = 2;

                    checkWin(player, i, j);

                    break;

                default:
                    cerr << "El jugador ingresado es invalido" << endl;
            }

            printBoard();
        }
        else
        {
            cerr << "La posicion ya ha sido ingresada intente de nuevo" << endl;
            setPlay(player);
        }
    }



    void setWin(bool winVal)
    {
        win = winVal;
    }



    bool getWin()
    {
        return win;
    }


    void getPosition(int &i, int &j)
    {

        while(i < 1 || i > 3 || j < 1 || j > 3)
        {

            cerr << "Posicion invalida ingrese los datos de nuevo!" << endl;

            cin >> i >> j;
        }

        i -= 1;

        j -= 1;
    }


    void checkWin(Player &player, int i, int j)
    {
		if(board[0][0] == player.num && board[1][1] == player.num && board[2][2] == player.num)
		{
			player.win = true;
			setWin(true);
		}
		else if(board[0][2] == player.num && board[1][1] == player.num && board[2][0] == player.num)
		{
			player.win = true;
			setWin(true);
		}
		else if(board[0][0] == player.num && board[1][0] == player.num && board[2][0] == player.num)
        {
			player.win = true;
			setWin(true);
        }
		else if(board[0][0] == player.num && board[0][1] == player.num && board[0][2] == player.num)
        {
			player.win = true;
			setWin(true);
	    }
		else if(board[0][1] == player.num && board[1][1] == player.num && board[2][1] == player.num)
        {
			player.win = true;
			setWin(true);
        }
		else if(board[1][0] == player.num && board[1][1] == player.num && board[1][2] == player.num)
        {
			player.win = true;
			setWin(true);
	    }
		else if(board[0][2] == player.num && board[1][2] == player.num && board[2][2] == player.num)
        {
			player.win = true;
			setWin(true);
        }
		else if(board[2][0] == player.num && board[2][1] == player.num && board[2][2] == player.num)
        {
			player.win = true;
			setWin(true);
	    }
    }

    void readScores()
    {
        ifstream myfile ("scores.txt");

	    if (myfile.is_open())
	    {
	        string line;
	        int i = 0;
	        while ( getline(myfile, line) )
	        {
	            maxScores[i] = line;
	            scores++;
	            i++;
	        }
	        myfile.close();
	    }
	    else
	    {
	        cout << "Unable to open file";
	    }
    }

    void displayScores()
    {
    	for(int i = 0; i < 20; i++)
		{
			cout << "-";
		}
		cout << endl;

		cout << "\tScores" << endl;

		for(int i = 0; i < 20; i++)
		{
			cout << "-";
		}
		cout << "\n" << endl;

		cout << "score\t\tJugador" <<endl;

    	for(int i = 0; i < scores; i++)
    	{
    		cout << maxScores[i] << endl;
    	}
    }

private:

    int board[3][3];
	Player player1;
	Player player2;
	int playNum;
	bool win;
	string maxScores[100];
	int scores;
};


int main()
{
    TicTacToe juego;
}


