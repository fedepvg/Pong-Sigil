#include "pantallaMenu.h"

#include "sl.h"
#include "Juego/juego.h"

namespace Juego {
	namespace Menu {
		using namespace Juego;

		void dibujarMenu() {
			double tamanioTitulo = (altoPantalla*anchoPantalla)*0.0190 / 100;
			double tamanioSubtitulos = (altoPantalla*anchoPantalla)*0.0048 / 100;
			char titulo[] = "PONG";
			char subt1[] = "Para empezar, presione Enter";
			char subt2[] = "Para ver los creditos, presione C";
			char subt3[] = "Para salir, presione Q";
			char version[] = "PONG v1.0";
			slSetFont(fuente, tamanioTitulo);
			slSetTextAlign(SL_ALIGN_CENTER);
			slSetForeColor(1.0, 1.0, 1.0, 1.0);
			slText(anchoPantalla/2,altoPantalla/2,titulo);
			slSetFontSize(tamanioSubtitulos);
			slText(anchoPantalla / 2, altoPantalla * 30 / 100,subt1);
			slText(anchoPantalla / 2, altoPantalla * 20 / 100,subt2);
			slText(anchoPantalla / 2, altoPantalla * 10 / 100,subt3);
			slSetTextAlign(SL_ALIGN_RIGHT);
			slText(anchoPantalla,altoPantalla-tamanioSubtitulos,version);
		}
		
		void actualizarMenu() {
			
			if (slGetKey(SL_KEY_ENTER) != 0) {
					estado = partida;
			}
			if (slGetKey(81) != 0 || slGetKey(113) != 0 ) {
					enJuego = false;
			}
			if (slGetKey(67) != 0 || slGetKey(99) != 0) {
					estado = creditos;
			}
		}
	}
}
