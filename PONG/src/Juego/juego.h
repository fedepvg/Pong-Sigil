#ifndef JUEGO_H
#define JUEGO_H
namespace Juego {
	enum estados { menu, partida, gameOver, creditos};
	extern estados estado;
	extern int anchoPantalla;
	extern int altoPantalla;
	extern bool enJuego;
	extern int fuente;
	extern int golpe;
	extern int rebote;
	extern int gol;

	void ejecutar();
}
#endif