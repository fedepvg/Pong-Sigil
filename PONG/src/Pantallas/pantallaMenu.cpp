#include "pantallaMenu.h"

#include "sl.h"
#include "Juego/juego.h"

namespace Juego {
	namespace Menu {
		using namespace Juego;
		static bool estaInicializado = false;
		static bool desinicializar = false;
		//int musica;
		static int opcionElegida = 0;

		void inicializarMenu() {
			if (!estaInicializado) {
				//musica =  slLoadWAV("res/musica.wav");
			}
			estaInicializado = true;
		}

		void desinicializarMenu() {
			if (desinicializar) {
				//StopMusicStream(musica);
				//UnloadMusicStream(musica);
			}
		}

		void dibujarMenu() {
			double tamanioTitulo = (altoPantalla*anchoPantalla)*0.0190 / 100;
			double tamanioSubtitulos = (altoPantalla*anchoPantalla)*0.0092 / 100;
			double tamanioVersion = (altoPantalla*anchoPantalla)*0.0052 / 100.0;
			char titulo[] = "PONG";
			char subt1[] = "Para empezar, presione Enter";
			char subt2[] = "Para ver los creditos, presione C";
			char subt3[] = "Para salir, presione Q";
			char version[] = "PONG v1.0";
			slSetFont(fuente, 50);
			slSetTextAlign(SL_ALIGN_CENTER);
			slSetForeColor(1.0, 1.0, 1.0, 1.0);
			slText(anchoPantalla/2,altoPantalla/2,titulo);
			slSetFont(fuente, 25);
			slText(anchoPantalla / 2, altoPantalla * 30 / 100,subt1);
			slText(anchoPantalla / 2, altoPantalla * 20 / 100,subt2);
			slText(anchoPantalla / 2, altoPantalla * 10 / 100,subt3);
			slSetTextAlign(SL_ALIGN_RIGHT);
			slText(anchoPantalla,0,version);

			/*DrawText(titulo,(GetScreenWidth() -MeasureText(titulo,tamanioTitulo))/2, (GetScreenHeight() -tamanioTitulo) / 2, tamanioTitulo, DARKGRAY);
			DrawText(subt1, 0+tamanioSubtitulos, GetScreenHeight() -tamanioSubtitulos*3, tamanioSubtitulos, DARKGRAY);
			DrawText(subt2, 0 + tamanioSubtitulos, GetScreenHeight() - tamanioSubtitulos*2, tamanioSubtitulos, DARKGRAY);
			DrawText(subt3, 0+tamanioSubtitulos, GetScreenHeight() -tamanioSubtitulos, tamanioSubtitulos, DARKGRAY);
			DrawText(version, GetScreenWidth() - MeasureText(version, tamanioVersion), 0 + tamanioVersion, (int)tamanioVersion, DARKGRAY);*/
		}
		
		void actualizarMenu() {
			if (!desinicializar) {
				//slSoundLoop(musica);
				//PlayMusicStream(musica);
				//UpdateMusicStream(musica);
			}
			
			if (slGetKey(SL_KEY_ENTER) != 0 ||opcionElegida==SL_KEY_ENTER) {
				if (!desinicializar) {
					desinicializar = true;
					opcionElegida = SL_KEY_ENTER;
				}
				else {
					estado = partida;
					estaInicializado = false;
					desinicializar = false;
					opcionElegida = 0;
				}
			}
			if (slGetKey(81) != 0 || slGetKey(113) != 0 || opcionElegida == 81|| opcionElegida == 113) {
				if (!desinicializar) {
					desinicializar = true;
					opcionElegida = 81;
				}
				else {
					enJuego = false;
					estaInicializado = false;
					desinicializar = false;
					opcionElegida = 0;
				}
			}
			if (slGetKey(67) != 0 || slGetKey(99) != 0 ||opcionElegida== 67|| opcionElegida == 99) {
				if (!desinicializar) {
					desinicializar = true;
					opcionElegida = 99;
				}
				else {
					estado = creditos;
					estaInicializado = false;
					desinicializar = false;
					opcionElegida = 0;
				}
			}
		}
	}
}
