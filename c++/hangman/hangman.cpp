///////////////////////////////////////////////
//Authors: María Navarro & Gabriel Chaparro //
//            FINAL PROJECT                 //
//////////////////////////////////////////////
#include<iostream>
#include <cstdlib>
#include <ctime>
#include<string>
#include<fstream>
using namespace std;

//Declaration of vectors and matrix
const int MAX = 30000;
const int maxim = 13;
typedef string Vector[MAX];
typedef char v_word[maxim];
typedef string matrix[7][13];

//Statistics structure
struct format
{
	string word_try;
	int n_games;
	int n_wins;
};

//Functions
void file_words(Vector, int &);
void file_statistics(format &);
void menu(int &);
void option1(format);
void option2(format &, matrix);
void option3(format &, matrix, Vector, int);
void option4(format);
void drawing(matrix);
void hangman(matrix, string, format &);
void show_gallows(matrix);


int main()
{
	Vector words;
	matrix gallows;
	format statistic;
	int option = 0, total_words = 0;
	file_words(words, total_words);
	file_statistics(statistic);
	
	//Options loop
	do
	{
		menu(option);
		
		if(option == 1)
			option1(statistic);
			
		else if(option == 2)
		{
			option2(statistic, gallows);
			statistic.n_games++;
		}
			
		else if(option == 3)
		{
			option3(statistic, gallows, words, total_words);
			statistic.n_games++;
		}
		
		else if(option == 4)
		{
			option4(statistic);
		}
		
	}while(option != 4);
	
	return 0;
}

//Function that reads the file "words.txt" and fills the vector "words" with all the possible words
void file_words(Vector words, int & total_words)
{
	ifstream file_words;
	file_words.open("words.txt");

	if (!file_words) 
		cout << "Error"; 
	else 
	{
		while(!file_words.eof())
		{
			file_words >> words[total_words];
			total_words++; 							//Final number of possible words
		}
	}
	
	file_words.close();
}

//Function that reads the file and inserts the data into the structure
void file_statistics(format & statistic)
{
	ifstream statistics;
	statistics.open("statistics.txt");

	if (!statistics) 
		cout << "Error"; 
	else 
	{
		statistics >> statistic.word_try;
		statistics >> statistic.n_games;
		statistics >> statistic.n_wins;	
	}
	
	statistics.close();
}

//Function that shows the options on the screen and receives the selected one
void menu(int & option)
{
	cout << endl << "SELECT ONE OPTION: " << endl << endl;;
	cout << "1 - Show statistics." << endl;
	cout << "2 - Replay with the last used word." << endl;
	cout << "3 - Play a new game." << endl;
	cout << "4 - Exit." << endl;
	cin >> option;
	cout << endl;
}

//Function that shows the statistics of the previous games on the screen
void option1(format statistic)
{
	cout << "Number of games played: " << statistic.n_games << endl;
	cout << "Number of wins: " << statistic.n_wins << endl;
}

//Function that starts the game with the word from the previous game
void option2(format & statistic, matrix gallows)
{
	string new_word = statistic.word_try;
		
	hangman(gallows, new_word, statistic);	
}

//Function that starts the game with a new word
void option3(format & statistic, matrix gallows, Vector words, int total_words)
{
	int N;
	string new_word;
	
	//Generates a random number
	srand(time(0));
    N = rand() % (total_words);
    
    //Saves a random word from the vector in the variable
    new_word = words[N];
    
    
    hangman(gallows, new_word, statistic);
    
    //Saves the word used in the structure
    statistic.word_try = new_word;
	
}

//Function that writes the data stored in the structure into the file
void option4(format statistic)
{
	ofstream statistics;
	statistics.open("statistics.txt");

	if (!statistics) 
		cout << "Error"; 
	else 
	{
		statistics << statistic.word_try << endl;
		statistics << statistic.n_games << endl;
		statistics << statistic.n_wins << endl;
	}
	
	statistics.close();
}

//Function that draws the initial gallow in a matrix
void drawing(matrix gallows)
{
	for(int j = 0; j < 13; j++)
		gallows[0][j] = "=";
		
		
	for(int i = 1; i < 6; i++)
		{
			gallows[i][0] = "|";
			gallows[i][1] = "|";
		}
		
		
	for(int j = 0; j < 3; j++)
		gallows[6][j] = "=";
		

	
	for(int j = 2; j< 13; j++)
		for(int i = 1; i < 5; i++)
			gallows[i][j] = " ";
		
	
		
	gallows[1][11] = "|";
		
}

//Game function
void hangman(matrix gallows, string new_word, format & statistic)
{
	v_word hidden;
	int length = new_word.length();
	char char_word;
	int right_guess;
	int n_mistakes = 0;
	int total;
	int aux;
	string wrong_inputs = "Wrong inputs -> ";
	
	drawing(gallows);
	
	//Writes in the "hidden" vector the first and last letters of the word to guess and the rest is filled with "_"
	hidden[0] = new_word[0];
	hidden[length - 1] = new_word[length-1];
	
	for(int i = 1; i < length - 1; i++)
		hidden[i] = '_';
		
	//Loop that continues the game as long as the gallows is not completed
	while(gallows[4][12] == " ")
	{
		total = 0;
		right_guess = 0;
		aux = 0;
		
		cout << "Secret word: " << endl << endl;
		
		for(int i = 0; i < length; i++)
			cout << hidden[i] << " ";
		cout << endl << endl;
			
		show_gallows(gallows);
		
		cout << endl << wrong_inputs << endl;
		
		cout << endl <<"Enter a letter: ";
		cin >> char_word;
		
		char_word = tolower(char_word);
	
		//Check that the letter entered has not been previously
		for(int i = 1; i < length - 1; i++)
		{
			if(hidden[i] == char_word)
				aux = 1;
		}
		
		//Check if the entered letter belongs to the word to guess
		for(int i = 1; i < length - 1; i++)
		{
			if(new_word[i] == char_word)
			{
				hidden[i] = char_word;
				right_guess++;
			}
		}
		
		//Check the number of solved cells in the vector
		for(int i = 0; i < length; i++)
		{
			if(hidden[i] != '_')
				total++;	
		}
		
		//Victory message
		if(length == total)
		{
			
			cout << "Secret word: " << endl << endl;
		
		for(int i = 0; i < length; i++)
			cout << hidden[i] << " ";
		cout << endl << endl;
			
		for(int i = 0; i < 7; i++)
		{
			for(int j = 0; j < 13; j++)
				cout << gallows[i][j];
			cout << endl;
		}
			
		cout << "Congratulations! You guessed it!." << endl << endl;	
		statistic.n_wins++;
		return;
		}
		
		//Draws the parts of the hangman when the entered letter is wrong and shows the lost game message when the gallow is complete
		if(right_guess == 0 || aux == 1)
		{
			n_mistakes++;
			wrong_inputs = wrong_inputs + char_word;
			
			
			if(n_mistakes == 1)
				gallows[2][11] = "O";
				
			else if(n_mistakes == 2)
				gallows[3][11] = "|";
				
			else if(n_mistakes == 3)
				gallows[3][10] = "/";
				
			else if(n_mistakes == 4)
				gallows[3][12] = "\\";
				
			else if(n_mistakes == 5)
				gallows[4][10] = "/";
				
			else if(n_mistakes == 6)
			{
				gallows[4][12] = "\\";
				
				cout << "Secret word: " << endl << endl;
		
				for(int i = 0; i < length; i++)
					cout << hidden[i] << " ";
				cout << endl << endl;
			
				cout << ".............................................." << endl;
			
				show_gallows(gallows);
				
				cout << endl << "You lost." << endl << "Better luck next time." << endl;		
				
			}
					
		}
		cout << ".............................................." << endl;
	}	
		
}

//Function that shows the matrix "gallow" on the screen
void show_gallows(matrix gallows)
{
	for(int i = 0; i< 7; i++ )
	{
		for(int j = 0; j < 13; j++)
			cout << gallows[i][j];
		cout << endl;
	}
}
