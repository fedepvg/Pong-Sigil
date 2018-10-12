#ifndef BOLA_H
#define BOLA_H

#include "vector2.h"

namespace Juego {
	namespace Bola {
		struct Pelota {
			Vector2 pos;
			Vector2 velocidad;
			int radio = 13;
			Vector2 aceleracion;
		};

		extern Pelota bola;
		Pelota crearBola();
		void moverBola();
		extern void dibujarBola();
	}
}

#endif
