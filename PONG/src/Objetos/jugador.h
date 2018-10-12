#ifndef JUGADOR_H
#define JUGADOR_H

#include "vector2.h"

namespace Juego {
	namespace Jugador {
		struct Jug {
			Vector2 pos;
			Vector2 tamanio;
			int goles;
		};

		const int cantJug = 2;
		extern float tamanioXJug;
		extern float tamanioYJug;
		extern Jug jugador[cantJug];
		extern Jug crearJugador(int numJug);
		extern void moverJug();
		extern void dibujarJug();
		extern void inicializarJug();
	}
}

#endif