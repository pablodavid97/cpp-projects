#include <iostream>
#include "Discs.h"
using namespace std;

int main ()
{
	int y = 0;

	char x;

	Discs Mydiscs;

	Disc d[100];

	while (y == 0)
	{
		cout << "Type the following values: \n" << endl
		<< "\ta for disc data input " << endl
		<< "\tb for disc search by title " << endl
		<< "\tc for disc search by artist " << endl
		<< "\td for disc search by music genre " << endl
		<< "\te for disc search by year " << endl
		<< "\tf for disc search by rating " << endl
		<< "\tg for disc search by ranking \n" << endl;

		cout << "Option: ";
		cin >> x;
		cin.ignore();

		cout << "\n" << endl;

		switch (x)
		{
			case 'a':
				Mydiscs.getDiscNum();
				Mydiscs.setDisc(d);
				Mydiscs.getDisc();
				break;

			case 'b':
				Mydiscs.discSearchTitle(d);
				break;

			case 'c':
				Mydiscs.discSearchArtist(d);
				break;

			case 'd':
				Mydiscs.discSearchMusicGenre(d);
				break;

			case 'e':
				Mydiscs.discSearchYear(d);
				break;

			case 'f':
				Mydiscs.discSearchRating(d);
				break;

			case 'g':
				Mydiscs.discSearchRanking(d);
				break;

			default:
				cout << "value of x unknown ";
		}

		cout << "Press 0 if you want to continue." << endl
		<<"Press 1 if you want to exit." << endl;
		cin >> y;
	}

	return 0;
}
