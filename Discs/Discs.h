#include <string>

// Declaración de una estructura para ingresar los datos de una disco
struct Disc
{
    std::string title;
    std::string artist;
    char musicGenre[50];
    int year;
    int rating;
	int ranking;
};

class Discs
{
	public:

    // Funcion que obtiene el numero de discos que desea el usuario
	void getDiscNum();

	// Funcion que asigna valores especificos a los elementos dentro del vector de la estructura de datos
	void setDisc(Disc d[]);

    // Funcion que devuelve el vector de la estructura creada con sus diferentes componentes
	Disc getDisc();

	// Busca un disco por titulo
	void discSearchTitle(Disc d[]);

	// Busca un disco por nombre del artista o interprete
	void discSearchArtist(Disc d[]);

    // Busca un disco por genero musical
	void discSearchMusicGenre(Disc d[]);

	// Busca un disco por año
	void discSearchYear(Disc d[]);

    // Busca un disco por calificacion o rating
	void discSearchRating(Disc d[]);

	// Busca un disco por posicion
	void discSearchRanking(Disc d[]);

	private:
		Disc d[100];
		int n, j;
};
