#include "pantallaJuego.h"

#include <cmath>

#include "sl.h"
#include "Juego/juego.h"
#include "Objetos/jugador.h"
#include "Objetos/bola.h"

namespace Juego {
	namespace PantallaJuego {
		using namespace Bola;
		using namespace Jugador;
		using namespace Juego;

		static void chequearColisiones();
		static bool chequearResultado();

		using namespace Juego;
		static bool estaInicializado = false;
		fases fase = inicio;
		int jugGanador = 0;
		int turno = 2;	//indica de quien fue el ultimo golpe golpear la pelota
		const int topeGoles = 7;
		float puntoImpactoY = 0.0f;
		float angMaximoRad = 0.85f;
		/*Sound golpe;
		Sound rebote;
		Sound gol;*/
		static bool desinicializar = false;
		static int opcionElegida = 0;
		
		float calcularAnguloRebote() {
			//			regla de 3----> punto de impacto positivo o negativo * ang max / punto de impacto p/ese angulo
			//					PN------ANG MAX
			//					PI------??
			return (puntoImpactoY - tamanioYJug / 2)*angMaximoRad / (tamanioYJug / 2);
		}

		float calcularReboteX() {
			return cos(calcularAnguloRebote());
		}
		
		float calcularReboteY() {
			return sin(calcularAnguloRebote());
		}

		void chequearColisiones() {
			//bola con jugador
			for (int i = 0; i < cantJug; i++) {
				if (CheckCollisionCircleRec(bola.pos, bola.radio,
					{ jugador[i].pos.x, jugador[i].pos.y, jugador[i].tamanio.x, jugador[i].tamanio.y })) {
					puntoImpactoY = bola.pos.y-jugador[i].pos.y;
					if (turno != i) {	//chequeo que sea el turno para no repetir colision
						if (i == 0) {
							bola.aceleracion.x = calcularReboteX();
						}
						else {
							bola.aceleracion.x = -calcularReboteX();
						}
						bola.aceleracion.y = calcularReboteY();

							bola.velocidad.x += 50.0;
							bola.velocidad.y += 50.0;
							//PlaySound(golpe);
							turno = i;
					}
				}
			}
			//bola con bordes
			if (bola.pos.y + bola.radio >= altoPantalla || bola.pos.y - bola.radio <= 0)
			{
				//PlaySound(rebote);
				bola.aceleracion.y = bola.aceleracion.y * -1;
				if (bola.pos.y + bola.radio >= altoPantalla) {
					bola.pos.y -= bola.radio;
				}
				else {
					bola.pos.y += bola.radio;
				}
			}
			//goles
			if (bola.pos.x + bola.radio >= anchoPantalla)
			{
				//PlaySound(gol);
				fase = inicio;
				turno = 2;
				jugador[0].goles++;
			}
			else {
				if (bola.pos.x - bola.radio <= 0)
				{
					//PlaySound(gol);
					fase = inicio;
					turno = 2;
					jugador[1].goles++;
				}
			}
		}
		
		bool chequearResultado() {
			if (jugador[0].goles >= topeGoles) {
				jugGanador = 1;
				return true;
			}
			else if(jugador[1].goles >= topeGoles) {
				jugGanador = 2;
				return true;
			}else {
				return false;
			}
		}
		
		void dibujarJuego() {
			char instruccJ1[] = "Jugador 1 se mueve con W y S";
			char instruccJ2[] = "Jugador 2 se mueve con las flechas";
			char menu[] = "Pulse M para volver al menu";

			const double tamanioLetras = (altoPantalla*anchoPantalla)*0.0037/100;
			const double tamanioNum = (altoPantalla*anchoPantalla)*0.0092/100;
			/*DrawText(instruccJ1, 0+tamanioLetras, GetScreenHeight() - tamanioLetras*2, tamanioLetras, DARKGRAY);
			DrawText(instruccJ2, 0+tamanioLetras, GetScreenHeight() -tamanioLetras, tamanioLetras, DARKGRAY);
			DrawText(menu, GetScreenWidth() - MeasureText(menu,tamanioLetras), GetScreenHeight() - tamanioLetras, tamanioLetras, DARKGRAY);
			DrawText(FormatText("%i", jugador[0].goles), GetScreenWidth() / 3, 0, tamanioNum, DARKGRAY);
			DrawText(FormatText("%i", jugador[1].goles), (GetScreenWidth() / 3) * 2, 0, tamanioNum, DARKGRAY);*/

			dibujarJug();
			dibujarBola();
		}
		
		void actualizarJuego() {
			moverJug();
			moverBola();
			chequearColisiones();
			if (chequearResultado()) {
				if (!desinicializar) {
					desinicializar = true;
				}
				else {
					fase = fin;
					estado = gameOver;
					estaInicializado = false;
					desinicializar = false;
				}
			}
			if (slGetKey(77) != 0 || slGetKey(109) != 0 ||opcionElegida==77||opcionElegida==109) {
				if (!desinicializar) {
					desinicializar = true;
					opcionElegida = 77;
				}
				else {
					estado = menu;
					estaInicializado = false;
					desinicializar = false;
					opcionElegida = 0;
				}
			}
		}

		void inicializarPantJuego() {
			if (!estaInicializado) {
			/*	golpe = LoadSound("res/golpe.wav");
				rebote = LoadSound("res/rebote.wav");
				gol = LoadSound("res/gol.wav");*/

				inicializarJug();
			}
			estaInicializado = true;
		}

		void desinicializarPantJuego(){
			if (desinicializar) {
				/*UnloadSound(golpe);
				UnloadSound(rebote);
				UnloadSound(gol);*/
			}
		}
	}
}