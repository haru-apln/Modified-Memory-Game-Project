//Modified Memory Game - Project in CPE103L
//At the start of the game, the player must choose the level of difficulty.
//For Easy mode, the player would have a 2x2 grid board with unlimited attempts. 
//For Medium mode, the player would have a 3x3 grid board with 9 limited attempts.
//For Hard mode, the player would have a 4x4 grid board with 6 limited attempts.
//The goal of the game is to match all the cards before the attempts run out. 

#include <iostream>
using namespace std;

//Class
class MemoryGame
{
  protected:
    //Declare global variables
    int difficulty;
    int column, row, row1Value, column1Value, row2Value, column2Value, matrix[4][4];
    bool matrix2[4][4];
    bool continueGame=true;

  public:
    //Display Cards
    void display1()
    {
	// Grid Setup for Easy Mode
	cout << "    1 2" << endl;
	cout << "  ";

	for (int i = 0; i <= 4; i++) {
	    cout << "-";
	}
	cout << endl;
    for (int row = 0; row < 2; row++) {
	    cout << row + 1 << " | ";

	    for (int column = 0; column < 2; column++) {
		// Print the value or '*' depending on whether the card is exposed.
		if (matrix2[row][column]) {
		    cout << matrix[row][column];
		} else {
		    cout << '*';
		}
		cout << ' ';
	    }
	    cout << endl;
	}
	cout << endl;
    }


    void display2()
    {
	// Grid Setup for Medium Mode
	cout << "    1 2 3" << endl;
	cout << "  ";

	for (int i = 0; i <= 6; i++) {
	    cout << "-";
	}
	cout << endl;
    for (int row = 0; row < 3; row++) {
	    cout << row + 1 << " | ";

	    for (int column = 0; column < 3; column++) {
		// Print the value or '*' depending on whether the card is exposed.
		if (matrix2[row][column]) {
		    cout << matrix[row][column];
		} else {
		    cout << '*';
		}
		cout << ' ';
	    }
	    cout << endl;
	}
	cout << endl;
    }

    void display3()
    {
	// Grid Setup for Hard Mode
	cout << "    1 2 3 4" << endl;
	cout << "  ";

	for (int i = 0; i <= 8; i++) {
	    cout << "-";
	}
	cout << endl;
    for (int row = 0; row < 4; row++) {
	    cout << row + 1 << " | ";

	    for (int column = 0; column < 4; column++) {
		// Print the value or '*' depending on whether the card is exposed.
		if (matrix2[row][column]) {
		    cout << matrix[row][column];
		} else {
		    cout << '*';
		}
		cout << ' ';
	    }
	    cout << endl;
	}
	cout << endl;
    }

    void start()
    {
        //Main Title 
        cout<<"[ Memory Game ] "<<endl<<endl;

        //Difficulty Select
        while (continueGame){
        cout<<"Select your Difficulty:"<<endl<<endl;
        cout<<"Press '1' for Easy Level"<<endl;
        cout<<"Press '2' for Medium Level"<<endl;
        cout<<"Press '3' for Hard Level"<<endl;
        cout<<"Press '4' to exit the Game"<<endl;
        cin>>difficulty;

        //Loop to Open the Game or Exit the Game
        if (difficulty == 1)
        {
            easyMode();
        }
        else if (difficulty == 2)
        {
            mediumMode();
        }
        else if (difficulty == 3)
        {
            hardMode();
        }
        else if (difficulty == 4)
        {
            continueGame=false;
        }
    }
    }

    void easyMode(){
            for (int row=0; row < 2; row++){
                for(int column=0; column <2; column++){
                    matrix[row][column]= rand() % 4 + 1;
                    matrix2[row][column] = false;
                }
                cout<<endl;
            }
            cout<<"Easy Mode"<<endl<<endl;

            //display 2x2 board
            display1();

            //input data
            inputValue();

            //matching cards
            match();
        }

    void mediumMode(){
            for (int row=0; row < 3; row++){
                for(int column=0; column < 3; column++){
                    matrix[row][column]= rand() % 6 + 1;
                    matrix2[row][column] = false;
                }
                cout<<endl;
            }
            cout<<"Medium Mode"<<endl<<endl;

            //display 3x3 board
            display2();

            //input data
            inputValue();

            //matching cards
            match();
        }

    void hardMode(){
            for (int row=0; row < 4; row++){
                for(int column=0; column < 4; column++){
                    matrix[row][column]= rand() % 8 + 1;
                    matrix2[row][column] = false;
                }
                cout<<endl<<endl;
            }
            cout<<"Hard Mode"<<endl;

            //display 4x4 board
            display3();

            //input data
            inputValue();

            //matching cards
            match();
    }
    
    void inputValue(){
        cout<<"Enter row value for the first card: "<<endl;
        cin>>row1Value;
        cout<<"Enter column value of the first card: "<<endl;
        cin>>column1Value;
        cout<<"Enter row value for the second card: "<<endl;
        cin>>row2Value;
        cout<<"Enter column value for the second card: "<<endl;
        cin>>column2Value;

    }

    void match(){

    }
}; 

int main(){
    MemoryGame Game;
    Game.start();
}