#include "pantallaGameOver.h"

#include "sl.h"
#include "Juego/juego.h"
#include "pantallaJuego.h"

namespace Juego {
	namespace GameOver {
		using namespace Juego;

		void dibujarGO() {
			double tamanioTitulo = (altoPantalla*anchoPantalla)*0.009 / 100;
			double tamanioSub = (altoPantalla*anchoPantalla)*0.0048 / 100;

			char subt1[] = "Para volver al menu, presione M";
			char subt2[] = "Para volver a jugar, presione Enter";

			slSetFont(fuente, tamanioTitulo);
			slSetTextAlign(SL_ALIGN_CENTER);
			slSetForeColor(1.0, 1.0, 1.0, 1.0);
			if (PantallaJuego::jugGanador == 1) {
				slText(anchoPantalla / 2, altoPantalla / 2, "GANADOR: JUGADOR 1");
			}else {
				slText(anchoPantalla / 2, altoPantalla / 2, "GANADOR: JUGADOR 2");
			}
			slSetFontSize(tamanioSub);
			slText(anchoPantalla / 2, altoPantalla * 30 / 100, subt1);
			slText(anchoPantalla / 2, altoPantalla * 20 / 100, subt2);
			/*DrawText(FormatText("GANADOR: JUGADOR %i",PantallaJuego::jugGanador), (GetScreenWidth() -MeasureText(ganador,tamanioTitulo))/2, (GetScreenHeight() -tamanioTitulo) / 2, tamanioTitulo, DARKGRAY);
			DrawText(subt1, GetScreenWidth() /9, (GetScreenHeight() /3)*2, tamanioSub, DARKGRAY);
			DrawText(subt2, GetScreenWidth() /9, (GetScreenHeight() / 12)*10 , tamanioSub, DARKGRAY);*/
		}
		
		void actualizarGO() {	
			if (slGetKey(77) != 0 || slGetKey(109) != 0) {
				estado = menu;
			}
			if (slGetKey(SL_KEY_ENTER) != 0) {
				estado = partida;
			}
		}
	}
}