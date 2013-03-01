// Lab 9: T3.cpp
// Programmer: Jason Hillin
// Editor(s) used: MS Visual C++ 2010 Express
// Compiler(s) used: MS Visual C++ 2010 Express

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <cctype>
#include <cstdlib>
#include <ctime>


//struct definition

//function prototypes
void printGrid(const char[]); //print board
void goX(char[]); //X's turn (human)
void goO1(char[]); //human O's turn
void goO2(char[]); //dumb O's turn
void goO3(char[]); //smart O's turn
char check4Xwinner(char[]); //check if X won
char check4Owinner(char[]); //check if O won
char check4Tie(char[]);//check for tie.

int main ()
{
  cout << "Lab 9: T3.cpp\n";
  cout << "Programmer: Jason Hillin\n\n";

  //X and O array of 9
  char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};//TTT array elements

  //choose your opponent
  cout << "Greetings, Please select from the following:\n"
    << "1 = Human\n2 = Dumb PC\n3 = Smart PC" << endl;
  int answer;
  cin >> answer;
  //scores
  int xwins, owins, tie;

  //get score records
  ifstream fin;
  fin.open("t3.ini");
  if(!fin.good()) 
  {
      xwins=0,owins=0;tie=0;
  }
  else
  {
    fin >> xwins;
    fin.ignore(1000,10);
    fin >> owins;
    fin.ignore(1000,10);
    fin >> tie;
    fin.ignore(1000,10);
  }
  fin.close();
  cout << "Current scores are:\nX Wins: "
    << xwins << "\nO Wins: " << owins
    << "\nTies: " << tie << endl << endl;
  
  while(true)
  {
    while(true)
    {
      //print out board at the start and 
      //show board entries as players make
      //their moves.
      printGrid(board);
      ////////////
      //X's move//
      ////////////
      goX(board);
      printGrid(board);
      //check to see if X won
      char xwinner = check4Xwinner(board);
      if(xwinner!='N') 
      {
        cout << "\nX wins!\n\n\n";
        xwins++;
        break;
      }
      //check for tie
      char ties=check4Tie(board);
      if(ties!='N')
      {
        cout << "\nIts a tie!\n\n" << endl;
        tie++;
        break;
      }
      ////////////
      //O's move//
      ////////////
      if(answer==1) 
      {
        goO1(board); //human
        printGrid(board);   
      }
      srand(time(0)); 
      if(answer==2)
      {
        goO2(board); //dumb pc
        printGrid(board);   
      }
      if(answer==3)
      {
        goO3(board); //smart pc
        printGrid(board);   
      }
      char owinner = check4Owinner(board);
      //check to see if O won
      if(owinner!='N') 
      {
        cout << "\nO wins!\n\n\n";
        owins++;
        break;
      }
    }//while
  
    //record game on t3.ini
    ofstream fout;
    fout.open("t3.ini");
    if(!fout.good()) throw "I/O error";
    fout << xwins << endl;
    fout << owins << endl;
    fout << tie << endl;

    //Prompt to see if another game is needed
    cout << "\nOne more game of Tic Tac Toe?" << endl;
    char gameAgain;
    cin >> gameAgain;
    gameAgain=toupper(gameAgain);
    if(gameAgain!='Y')
    {
    cout << "Updated scores are:\nX Wins: "
      << xwins << "\nO Wins: " << owins
      << "\nTies: " << tie << endl;
      cout << "Goodbye!" << endl;
      break;
    }//if
    else
    {
     for(int i=0;i<9;i++) board[i]=' ';
    }

  }//while
}//main

//functions
//print board out
void printGrid(const char board[])
{
    cout << "###############\n#Current board#\n"
      << "###############\n\n" << endl;
    cout << board[0] << "  | " << board[1] << " | " << board[2] << endl;
    cout << "---+---+---\n";
    cout << board[3] << "  | " << board[4] << " | " << board[5] << endl;
    cout << "---+---+---\n";
    cout << board[6] << "  | " << board[7] << " | " << board[8] << endl << endl;
}
//X's turn (human)
void goX(char board[])
{
  //get player X's grid choice and error check
  while(true)
  {
    cout << "Player X, choose your grid to put X in using "
      << "the corresponding letters in the grid to select:\n";
    cout << " Q" << " | " << 'W' << " | " << 'E' << endl;
    cout << "---+---+---\n";
    cout << " A" << " | " << 'S' << " | " << 'D' << endl;
    cout << "---+---+---\n";
    cout << " Z" << " | " << 'X' << " | " << 'C' << endl;
    cout << "\n\nAnswer: ";
    char answer;
    cin >> answer;
    answer = toupper(answer);  
      if(answer=='Q' && board[0]!='O' && board[0]!='X')
      {
          board[0]='X';
          break;
      }//Q if
      else if(answer=='W' && board[1]!='O' && board[1]!='X')
      {
          board[1]='X';
          break;
      }//W if
     else if(answer=='E' && board[2]!='O' && board[2]!='X')
      {
          board[2]='X';
          break;
      }//E if
      else if(answer=='A' && board[3]!='O' && board[3]!='X')
      {
          board[3]='X';
          break;
      }//A if
      else if(answer=='S' && board[4]!='O' && board[4]!='X')
      {
          board[4]='X';
          break;
      }//S if
      else if(answer=='D' && board[5]!='O' && board[5]!='X')
      {
          board[5]='X';
          break;
      }//D if
      else if(answer=='Z' && board[6]!='O' && board[6]!='X')
      {
          board[6]='X';
          break;
      }//Z if
      else if(answer=='X' && board[7]!='O' && board[7]!='X')
      {
          board[7]='X';
          break;
      }//X if
      else if(answer=='C' && board[8]!='O' && board[8]!='X')
      {
          board[8]='X';
          break;
      }//C if
      else cout << "Wrong Player X, tile is already in use or does not exist."
        << "Please pick again!" << endl;
  }
    
}
//Human O's turn
void goO1(char board[]) 
{
  //get player O's grid choice and error check
  while(true)
  {
    cout << "Player O, choose your grid to put X in using "
      << "the corresponding letters in the grid to select:\n";
    cout << " Q" << " | " << 'W' << " | " << 'E' << endl;
    cout << "---+---+---\n";
    cout << " A" << " | " << 'S' << " | " << 'D' << endl;
    cout << "---+---+---\n";
    cout << " Z" << " | " << 'X' << " | " << 'C' << endl;
    cout << "\n\n Answer: ";
    char answer;
    cin >> answer;
    answer = toupper(answer);  
      if(answer=='Q' && board[0]!='O' && board[0]!='X')
      {
          board[0]='O';
          break;
      }//Q if
      else if(answer=='W' && board[1]!='O' && board[1]!='X')
      {
          board[1]='O';
          break;
      }//W if
     else if(answer=='E' && board[2]!='O' && board[2]!='X')
      {
          board[2]='O';
          break;
      }//E if
      else if(answer=='A' && board[3]!='O' && board[3]!='X')
      {
          board[3]='O';
          break;
      }//A if
      else if(answer=='S' && board[4]!='O' && board[4]!='X')
      {
          board[4]='O';
          break;
      }//S if
      else if(answer=='D' && board[5]!='O' && board[5]!='X')
      {
          board[5]='O';
          break;
      }//D if
      else if(answer=='Z' && board[6]!='O' && board[6]!='X')
      {
          board[6]='O';
          break;
      }//Z if
      else if(answer=='X' && board[7]!='O' && board[7]!='X')
      {
          board[7]='O';
          break;
      }//X if
      else if(answer=='C' && board[8]!='O' && board[8]!='X')
      {
          board[8]='O';
          break;
      }//C if
      else cout << "Wrong Player O, tile is already in use or does not exist."
        << "Please pick again!" << endl;
  }
}

void goO2(char board[]) //dumb O's turn
{
  while(true)
  {
    int choice = rand() % 9; // returns a number between 0 and 8
    if(choice>8) choice=rand()%9;
	  //else if((board[choice]=='X')||(board[choice]=='O')) choice=rand()%9;
	  else if(board[choice]==' ') 
	  {
	  	board[choice]='O';
	  	break;
	  }//else if
  }//while
}//void

void goO3(char board[]) //smart O's turn
{
  while(true)
  {
    //win moves
    //grid 0
    if((board[0]==' ')&&(board[1]=='O')&&(board[2]=='O')) 
    {
      board[0]='O';
      break;
    }
   else  if((board[0]==' ')&&(board[3]=='O')&&(board[6]=='O')) 
    {
      board[0]='O';
      break;
    }
    else if((board[0]==' ')&&(board[4]=='O')&&(board[8]=='O')) 
    {
      board[0]='O';
      break;
    }
    //grid 1
    else if((board[0]=='O')&&(board[1]==' ')&&(board[2]=='O')) 
    {
      board[1]='O';
      break;
    }
    else if((board[7]=='O')&&(board[4]=='O')&&(board[1]==' ')) 
    {
      board[1]='O';
      break;
    }
    //grid 2
    else if((board[0]=='O')&&(board[1]=='O')&&(board[2]==' ')) 
    {
      board[2]='O';
      break;
    }
    else if((board[5]=='O')&&(board[8]=='O')&&(board[2]==' ')) 
    {
      board[2]='O';
      break;
    }
    else if((board[6]=='O')&&(board[4]=='O')&&(board[2]==' ')) 
    {
      board[2]='O';
      break;
    }
    //grid 3
    else if((board[0]=='O')&&(board[6]=='O')&&(board[3]==' ')) 
    {
      board[3]='O';
      break;
    }
    else if((board[4]=='O')&&(board[3]==' ')&&(board[5]==' ')) 
    {
      board[3]='O';
      break;
    }

    //grid 4
    else if((board[0]=='O')&&(board[8]=='O')&&(board[4]==' ')) 
    {
      board[4]='O';
      break;
    }
    else if((board[2]=='O')&&(board[6]=='O')&&(board[4]==' ')) 
    {
      board[4]='O';
      break;
    }
    else if((board[3]=='O')&&(board[5]=='O')&&(board[4]==' ')) 
    {
      board[4]='O';
      break;
    }
    else if((board[1]=='O')&&(board[7]=='O')&&(board[4]==' ')) 
    {
      board[4]='O';
      break;
    }
    //grid 5
    else if((board[2]=='O')&&(board[8]=='O')&&(board[5]==' ')) 
    {
      board[5]='O';
      break;
    }
    else if((board[4]=='O')&&(board[3]=='O')&&(board[5]==' ')) 
    {
      board[5]='O';
      break;
    }
    //grid 6
    else if((board[0]=='O')&&(board[3]=='O')&&(board[6]==' ')) 
    {
      board[6]='O';
      break;
    }
    else if((board[7]=='O')&&(board[8]=='O')&&(board[6]==' ')) 
    {
      board[6]='O';
      break;
    }
    else if((board[2]=='O')&&(board[4]=='O')&&(board[6]==' ')) 
    {
      board[6]='O';
      break;
    }
    //grid 7
    else if((board[1]=='O')&&(board[4]=='O')&&(board[7]==' ')) 
    {
      board[7]='O';
      break;
    }
    else if((board[6]=='O')&&(board[8]=='O')&&(board[7]==' ')) 
    {
      board[7]='O';
      break;
    }
    //grid 8
    else if((board[2]=='O')&&(board[5]=='O')&&(board[8]==' ')) 
    {
      board[8]='O';
      break;
    }
    else if((board[6]=='O')&&(board[7]=='O')&&(board[8]==' ')) 
    {
      board[8]='O';
      break;
    }
    else if((board[0]=='O')&&(board[4]=='O')&&(board[8]==' ')) 
    {
      board[8]='O';
      break;
    }

    //blocking X
    //grid 0
    if((board[0]==' ')&&(board[1]=='X')&&(board[2]=='X')) 
    {
      board[0]='O';
      break;
    }
    else if((board[0]==' ')&&(board[3]=='X')&&(board[6]=='X')) 
    {
      board[0]='O';
      break;
    }
    else if((board[0]==' ')&&(board[4]=='X')&&(board[8]=='X')) 
    {
      board[0]='O';
      break;
    }
    //grid 1
    else if((board[0]=='X')&&(board[1]==' ')&&(board[2]=='X')) 
    {
      board[1]='O';
      break;
    }
    else if((board[7]=='X')&&(board[4]=='X')&&(board[1]==' ')) 
    {
      board[1]='O';
      break;
    }
    //grid 2
    else if((board[0]=='X')&&(board[1]=='X')&&(board[2]==' ')) 
    {
      board[2]='O';
      break;
    }
    else if((board[5]=='X')&&(board[8]=='X')&&(board[2]==' ')) 
    {
      board[2]='O';
      break;
    }
    else if((board[6]=='X')&&(board[4]=='X')&&(board[2]==' ')) 
    {
      board[2]='O';
      break;
    }
    //grid 3
    else if((board[0]=='X')&&(board[6]=='X')&&(board[3]==' ')) 
    {
      board[3]='O';
      break;
    }
    else if((board[4]=='X')&&(board[3]==' ')&&(board[5]=='X')) 
    {
      board[3]='O';
      break;
    }

    //grid 4
    else if((board[0]=='X')&&(board[8]=='X')&&(board[4]==' ')) 
    {
      board[4]='O';
      break;
    }
   else if((board[2]=='X')&&(board[6]=='X')&&(board[4]==' ')) 
    {
      board[4]='O';
      break;
    }
    else if((board[3]=='X')&&(board[5]=='X')&&(board[4]==' ')) 
    {
      board[4]='O';
      break;
    }
    else if((board[1]=='X')&&(board[7]=='X')&&(board[4]==' ')) 
    {
      board[4]='O';
      break;
    }
    //grid 5
    else if((board[2]=='X')&&(board[8]=='X')&&(board[5]==' ')) 
    {
      board[5]='O';
      break;
    }
    else if((board[4]=='X')&&(board[3]=='X')&&(board[5]==' ')) 
    {
      board[5]='O';
      break;
    }
    //grid 6
    else if((board[0]=='X')&&(board[3]=='X')&&(board[6]==' ')) 
    {
      board[6]='O';
      break;
    }
    else if((board[7]=='X')&&(board[8]=='X')&&(board[6]==' ')) 
    {
      board[6]='O';
      break;
    }
    else if((board[2]=='X')&&(board[4]=='X')&&(board[6]==' ')) 
    {
      board[6]='O';
      break;
    }
    //grid 7
    else if((board[1]=='X')&&(board[4]=='X')&&(board[7]==' ')) 
    {
      board[7]='O';
      break;
    }
    else if((board[6]=='X')&&(board[8]=='X')&&(board[7]==' ')) 
    {
      board[7]='O';
      break;
    }
    //grid 8
    else if((board[2]=='X')&&(board[5]=='X')&&(board[8]==' ')) 
    {
      board[8]='O';
      break;
    }
    else if((board[6]=='X')&&(board[7]=='X')&&(board[8]==' ')) 
    {
      board[8]='O';
      break;
    }
    else if((board[0]=='X')&&(board[4]=='X')&&(board[8]==' ')) 
    {
      board[8]='O';
      break;
    }
    else
    {
      int choice = rand() % 9; // returns a number between 0 and 8
      if(choice>8) choice=rand()%9;
	    //else if((board[choice]=='X')||(board[choice]=='O')) choice=rand()%9;
	    else if(board[choice]==' ') 
	    {
		    board[choice]='O';
		    break;
	    }//else if
    }//else
  }//while
}//void

//check if X won
char check4Xwinner(char a[])
{
  if((a[0]=='X')&&(a[1]=='X')&&(a[2]=='X')) return 'Y';
  else if((a[3]=='X')&&(a[4]=='X')&&(a[5]=='X')) return 'Y';
  else if((a[6]=='X')&&(a[7]=='X')&&(a[8]=='X')) return 'Y';
  else if((a[0]=='X')&&(a[3]=='X')&&(a[6]=='X')) return 'Y';
  else if((a[1]=='X')&&(a[4]=='X')&&(a[7]=='X')) return 'Y';
  else if((a[2]=='X')&&(a[5]=='X')&&(a[8]=='X')) return 'Y';
  else if((a[0]=='X')&&(a[4]=='X')&&(a[8]=='X')) return 'Y';
  else if((a[2]=='X')&&(a[4]=='X')&&(a[6]=='X')) return 'Y';
  else return 'N';
}

 //check if O won
char check4Owinner(char a[])
{
  if((a[0]=='O')&&(a[1]=='O')&&(a[2]=='O')) return 'Y';
  else if((a[3]=='O')&&(a[4]=='O')&&(a[5]=='O')) return 'Y';
  else if((a[6]=='O')&&(a[7]=='O')&&(a[8]=='O')) return 'Y';
  else if((a[0]=='O')&&(a[3]=='O')&&(a[6]=='O')) return 'Y';
  else if((a[1]=='O')&&(a[4]=='O')&&(a[7]=='O')) return 'Y';
  else if((a[2]=='O')&&(a[5]=='O')&&(a[8]=='O')) return 'Y';
  else if((a[0]=='O')&&(a[4]=='O')&&(a[8]=='O')) return 'Y';
  else if((a[2]=='O')&&(a[4]=='O')&&(a[6]=='O')) return 'Y';
  else return 'N';
}

//check for tie.
char check4Tie(char a[])
{
  if(a[0]==' ') return 'N';
  else if(a[1]==' ') return 'N';
  else if(a[2]==' ') return 'N';
  else if(a[3]==' ') return 'N';
  else if(a[4]==' ') return 'N';
  else if(a[5]==' ') return 'N';
  else if(a[6]==' ') return 'N';
  else if(a[7]==' ') return 'N';
  else if(a[8]==' ') return 'N';
  else 
    return 'Y';
}