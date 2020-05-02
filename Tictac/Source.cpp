#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <cctype>

using namespace std;
#include "Header.h"



Player::Player(string setname)
{
	name = setname;
}
char Player::shape()
{
	return piece;
}
bool Player::winStat()
{
	return winStatus;
}
void Player::winChange()
{
	winStatus = true;
}
void Player::setShape(char model)
{
	piece = model;
}
void play(int x, char y, char tic[][3], Player& player)
{
	
	switch (y) {
	case 'a':
		tic[x-1][0] = player.shape();
		break;
	case  'A':
		tic[x-1][0] = player.shape();
		break;
	case 'b':
		tic[x-1][1] = player.shape();
		break;
	case  'B':
		tic[x-1][1] = player.shape();
		break;
	case 'c':
		tic[x-1][2] = player.shape();
		break;
	case  'C':
		tic[x-1][2] = player.shape();
		break;
	}
	for (int i = 0; i < 3; i++)
	{
		int count = 0;
		for (int j = 0; j < 3; j++)
		{
			if (tic[i][j] == player.shape())
			{
				count++;
			}
			if (count == 3)
			{
				player.winChange();
				break;
			}
			
		}
	}
	for (int i = 0; i < 3; i++)
	{
		int count = 0;
		for (int j = 0; j < 3; j++)
		{
			if (tic[j][i] == player.shape())
			{
				count++;
			}
			if (count == 3)
			{
				player.winChange();
				break;
			}

		}
	}
	if ((tic[0][0] == player.shape() && tic[1][1] == player.shape() && tic[2][2] == player.shape()) ||
		tic[0][2] == player.shape() && tic[1][1] == player.shape() && tic[2][0] == player.shape()) 
	{
		player.winChange();
	}
}
void display(char arr[][3])
{
	cout << "    1 " << "  2   " << '3' << endl;
	cout << "A| " << arr[0][0] << "  |" << arr[1][0] << "  |" << arr[2][0] << endl;
	cout << "   ---|---|---" << endl;
	cout <<"B| " << arr[0][1] << "  |" << arr[1][1] << "  |" << arr[2][1] << endl;
	cout <<  "   ---|---|---" << endl;
	cout <<"C| " << arr[0][2] << "  |" << arr[1][2] << "  |" << arr[2][2] << endl;
}
int main()
{
	int x;
	char y;
	cout << "Enter player names" << endl;
	string p1;
	string p2;
	cin >> p1 >> p2;
	Player player1(p1);
	Player player2(p2);
	char tic[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tic[i][j] = ' ';
		}
	}
	display(tic);
	cout << p1 << " Choose your Shape Using Any Key" << endl;
	char shape1;
	cin >> shape1;
	player1.setShape(shape1);
	cout << p2 << " Choose your Shape Using Any Key" << endl;
	char shape2;
	cin >> shape2;
	player2.setShape(shape2);
	do
	{
		cout << p1 << " make a move" << endl;

		cin >> y >> x;

		play(x, y, tic, player1);
		display(tic);
		if (player1.winStat()) { 
			cout << player1.name << " Has Won!";
			exit(0);
		}
		cout << p2 << " make a move" << endl;
		cin >> y >> x;
		play(x, y, tic, player2);
		display(tic);
		if (player2.winStat()) { 
			cout << player2.name << " Has Won!";
				exit(0);
		}
		
		

	} while (!player1.winStat() || !player2.winStat());
	
	






	return 0;
}