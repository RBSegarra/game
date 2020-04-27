#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <cctype>

using namespace std;
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
	cout << "Enter player names" << endl;
	string p1;
	string p2;
	cin >> p1 >> p2;
	char tic[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tic[i][j] = ' ';
		}
	}
	display(tic);
	
	






	return 0;
}