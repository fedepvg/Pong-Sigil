#include "bola.h"

#include <cmath>
#include <iostream>
#include <ctime>

#include "sl.h"
#include"Pantallas/pantallaJuego.h"
#include"Juego\juego.h"

namespace Juego {
	namespace Bola {
		using namespace PantallaJuego;
		using namespace Juego;
		Pelota bola;
		Pelota crearBola() {
			bola.pos = { (float)anchoPantalla / 2, (float)altoPantalla/ 2 };
			bola.radio = altoPantalla * 2 / 100;
			bola.velocidad = { (float)(anchoPantalla*50.0 / 100.0),(float)(altoPantalla*50.0 / 100.0) };
			bola.aceleracion = { 0.0,0.0 };
			return bola;
		}

		void moverBola() {
			if (fase == inicio) {
				fase = juego;
				crearBola();
				int angMaximoInicial = 80;
				float anguloInicial = (rand() % (angMaximoInicial * 2)) - angMaximoInicial;
				int multiplicador = 1;
				do {
					multiplicador = rand()%3-1;
					anguloInicial *= 3.14 / 180;
					bola.aceleracion.x = multiplicador * cos(anguloInicial);
				} while (multiplicador == 0);

				bola.aceleracion.y = sin(anguloInicial);
			}
			if (fase == juego) {
				bola.pos.x += (bola.velocidad.x*bola.aceleracion.x)*slGetDeltaTime();
				bola.pos.y += (bola.velocidad.y*bola.aceleracion.y)*slGetDeltaTime();
			}
		}

		void dibujarBola() {
			slSetForeColor(1.0, 0.0, 0.0, 1.0);
			slCircleFill(bola.pos.x, bola.pos.y, bola.radio, 100);
		}
	}
}