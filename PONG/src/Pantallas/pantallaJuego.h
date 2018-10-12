#ifndef PANTALLAJUEGO_H
#define PANTALLAJUEGO_H

namespace Juego {
	namespace PantallaJuego {
		enum fases { inicio, juego, fin };
		extern fases fase;
		extern int jugGanador;
		extern int turno;
		void dibujarJuego();
		void actualizarJuego();
		void inicializarPantJuego();
		void desinicializarPantJuego();
	}
}
#endif