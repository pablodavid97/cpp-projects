#include <iostream>
#include "Discs.h"
using namespace std;

void Discs::getDiscNum()
{
    cout << "Input the number of discs (maximum 100): " << endl;
    cin >> n;

    cin.ignore(); //función para "limpiar" el buffer de ingreso
}

// Funcion que asigna valores especificos a los elementos dentro del vector de la estructura de datos
void Discs::setDisc(Disc d[])
{
    for (j = 0; j < n; j++)
    {
        cout << "Enter disc title: ";
        getline(cin, d[j].title);
        cout << "Enter artist name: ";
        getline(cin, d[j].artist);
        cout << "Enter music genre: ";
        cin.get(d[j].musicGenre, 50);
        cout << "Enter year: ";
        cin >> d[j].year;
        cin.ignore();
        do
        {
            cout << "Enter rating (1 to 10): ";
            cin >> d[j].rating;
            cin.ignore();
        }
        while (d[j].rating < 1 || d[j].rating > 10);
        cout << "Enter ranking: ";
        cin >> d[j].ranking;
        cin.ignore();
        cout << endl;
    }
}

    // Funcion que devuelve el vector de la estructura creada con sus diferentes componentes
Disc Discs::getDisc()
{
    for (j = 0; j < n; j++)
    {
        return d[j];
    }
}

	// Busca un disco por titulo
void Discs::discSearchTitle(Disc d[])
{
    string t;
    cout << "Type the disc title: " << endl;
    getline (cin , t);
    cout << endl;

    cout << "The discs found with your specifications are: " << endl;
    cout << endl;

    for (j = 0; j < n; j++)
    {
        if (t.compare(d[j].title) == 0)
        {
            cout << "Disc Title: " << d[j].title << endl;
            cout << "Artist: " << d[j].artist << endl;
            cout <<"Music Genre: " << d[j].musicGenre << endl;
            cout << "Year: " << d[j].year << endl;
            cout << "Rating: " << d[j].rating << endl;
            cout << "Ranking: " << d[j].ranking << endl;
            cout << "\n" << endl;
        }
        else
        {
            cout << "Disc could not be found!" << endl;
            cout << "\n" << endl;
        }
    }
}

// Busca un disco por nombre del artista o interprete
void Discs::discSearchArtist(Disc d[])
{
    string a;
    cout << "Insert the disc artist name: " << endl;
    getline(cin, a);
    cout << endl;

    cout << "The discs found with your specifications are: " << endl;
    cout << endl;


    for (j = 0; j < n; j++)
    {
        if (a.compare(d[j].artist) == 0)
        {
            cout << "Disc Title: " << d[j].title << endl;
            cout << "Artist: " << d[j].artist << endl;
            cout <<"Music Genre: " << d[j].musicGenre << endl;
            cout << "Year: " << d[j].year << endl;
            cout << "Rating: " << d[j].rating << endl;
            cout << "Ranking: " << d[j].ranking << endl;
            cout << "\n" << endl;
        }
        else
        {
            cout << "Disc could not be found!" << endl;
            cout << "\n" << endl;
        }
    }
}

// Busca un disco por genero musical
void Discs::discSearchMusicGenre(Disc d[])
{
    string m;

    cout << "Insert the disc music genre: " << endl;
    getline(cin, m);
    cout << endl;

    cout << "The discs found with your specifications are: " << endl;
    cout << endl;

    for (j = 0; j < n; j++)
    {
        if (m.compare(d[j].musicGenre) == 0)
        {
            cout << "Disc Title: " << d[j].title << endl;
            cout << "Artist: " << d[j].artist << endl;
            cout <<"Music Genre: " << d[j].musicGenre << endl;
            cout << "Year: " << d[j].year << endl;
            cout << "Rating: " << d[j].rating << endl;
            cout << "Ranking: " << d[j].ranking << endl;
            cout << "\n" << endl;
        }
        else
        {
            cout << "Disc could not be found!" << endl;
            cout << "\n" << endl;
        }
    }
}

// Busca un disco por año
void Discs::discSearchYear(Disc d[])
{
    int y = 0;

    cout << "Insert the disc year: " << endl;
    cin >> y;
    cout << endl;

    cout << "The discs found with your specifications are: " << endl;
    cout << endl;

    for (j = 0; j < n; j++)
    {
        if (y == d[j].year)
        {
            cout << "Disc Title: " << d[j].title << endl;
            cout << "Artist: " << d[j].artist << endl;
            cout <<"Music Genre: " << d[j].musicGenre << endl;
            cout << "Year: " << d[j].year << endl;
            cout << "Rating: " << d[j].rating << endl;
            cout << "Ranking: " << d[j].ranking << endl;
            cout << "\n" << endl;
        }
        else
        {
            cout << "Disc could not be found!" << endl;
            cout << "\n" << endl;
        }
    }
}

// Busca un disco por calificacion o rating
void Discs::discSearchRating(Disc d[])
{
    int r = 0;

    do
    {
        cout << "Insert the disc's rating (1 to 10): " << endl;
        cin >> r;
    }
    while (r < 1 || r > 10);

    cout << endl;
    cout << "The discs found with your specifications are: " << endl;
    cout << endl;

    for (j = 0; j < n; j++)
    {
        if (r == d[j].rating)
        {
            cout << "Disc Title: " << d[j].title << endl;
            cout << "Artist: " << d[j].artist << endl;
            cout <<"Music Genre: " << d[j].musicGenre << endl;
            cout << "Year: " << d[j].year << endl;
            cout << "Rating: " << d[j].rating << endl;
            cout << "Ranking: " << d[j].ranking << endl;
            cout << "\n" << endl;
        }
        else
        {
            cout << "Disc could not be found!" << endl;
            cout << "\n" << endl;
        }
    }
}

// Busca un disco por posicion
void Discs::discSearchRanking(Disc d[])
{
    int rk = 0;

    cout << "Insert the disc's ranking: " << endl;
    cin >> rk;
    cout << endl;

    cout << "The discs with ranking of " << rk << " are: " << endl;
    cout << endl;

    for (j = 0; j < n; j++)
    {
        if (rk == d[j].ranking)
        {
            cout << "Disc Title: " << d[j].title << endl;
            cout << "Artist: " << d[j].artist << endl;
            cout <<"Music Genre: " << d[j].musicGenre << endl;
            cout << "Year: " << d[j].year << endl;
            cout << "Rating: " << d[j].rating << endl;
            cout << "Ranking: " << d[j].ranking << endl;
            cout << "\n" << endl;
        }
        else
        {
            cout << "Disc could not be found!" << endl;
            cout << "\n" << endl;
        }
    }
}

