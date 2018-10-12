#include"jugador.h"

#include "sl.h"

#include "Pantallas/pantallaJuego.h"
#include "Juego\juego.h"

namespace Juego {
	namespace Jugador {
		using namespace Juego;

		Jug jugador[cantJug];
		float tamanioXJug = 0;
			float tamanioYJug = 0;
			float velocidadJug = 0;

		Jug crearJugador(int numJug) {
			if (numJug != 1) {
				jugador[numJug].pos = { 0 + tamanioXJug, ((float)altoPantalla - tamanioYJug) / 2 };
			}
			else {
				jugador[numJug].pos = { (float)anchoPantalla - 2 * tamanioXJug, ((float)altoPantalla - tamanioYJug) / 2 };
			}

			jugador[numJug].tamanio = { tamanioXJug, tamanioYJug };

			jugador[numJug].goles = 0;
			return jugador[numJug];
		}

		void moverJug() {
			if (slGetKey(SL_KEY_UP) != 0) jugador[1].pos.y -= velocidadJug * slGetDeltaTime();
			if ((jugador[1].pos.y) <= 0) jugador[1].pos.y = 0;
			if (slGetKey(SL_KEY_DOWN ) != 0) jugador[1].pos.y += velocidadJug * slGetDeltaTime();
			if ((jugador[1].pos.y + jugador[1].tamanio.y) >= altoPantalla) jugador[1].pos.y = altoPantalla - jugador[1].tamanio.y;

			if (slGetKey(119) != 0|| slGetKey(87) != 0) jugador[0].pos.y -= velocidadJug * slGetDeltaTime();
			if ((jugador[0].pos.y) <= 0) jugador[0].pos.y = 0;
			if (slGetKey(83) != 0 || slGetKey(115) != 0) jugador[0].pos.y += velocidadJug * slGetDeltaTime();
			if ((jugador[0].pos.y + jugador[0].tamanio.y) >= altoPantalla) jugador[0].pos.y = altoPantalla - jugador[0].tamanio.y;
		}

		void dibujarJug() {
			for (int i = 0; i < cantJug; i++) {
				//DrawRectangleV(jugador[i].pos, jugador[i].tamanio, BLACK);
				slSetForeColor(1.0,1.0,1.0,1.0);
				slRectangleFill(jugador[i].pos.x, jugador[i].pos.y, jugador[i].tamanio.x, jugador[i].tamanio.y);
			}
		}

		void inicializarJug() {
			tamanioXJug = (float)(anchoPantalla*2.0 / 100.0);
			tamanioYJug = (float)(altoPantalla*15.0 / 100.0);
			velocidadJug = (float)(altoPantalla * 80.0 / 100.0);
			
			for (int i = 0; i < cantJug; i++) {
				crearJugador(i);
			}
			PantallaJuego::fase = PantallaJuego::inicio;
			jugador[0].goles = 0;
			jugador[1].goles = 0;
		}
	}
}