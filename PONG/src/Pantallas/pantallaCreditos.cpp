#include "pantallaCreditos.h"

#include "sl.h"
#include "Juego/juego.h"

namespace Juego {
	namespace Creditos {
		using namespace Juego;

		void dibujarCreditos() {
			double tamanioTitulo = (altoPantalla*anchoPantalla)*0.0190 / 100.0;
			double tamanioSubtitulos = (altoPantalla*anchoPantalla)*0.0048 / 100.0;
			double tamanioVolver = (altoPantalla*anchoPantalla)*0.0027 / 100.0;
			char titulo[] = "Creditos";
			char subt1[] = "Hecho con la libreria Raylib";
			char subt2[] = "Programador: Federico van Gelderen";
			char subt3[] = "Sonidos: BFXR";
			char subt4[] = "Musica: Bosca Ceoil, Music Maker";
			char version[] = "PONG v1.0";
			char volver[] = "Pulse M para volver al menu";

			slSetFont(fuente, tamanioTitulo);
			slSetTextAlign(SL_ALIGN_CENTER);
			slSetForeColor(1.0, 1.0, 1.0, 1.0);
			slText(anchoPantalla / 2, altoPantalla / 2, titulo);
			slSetFontSize(tamanioSubtitulos);
			slText(anchoPantalla / 2, altoPantalla * 40 / 100, subt1);
			slText(anchoPantalla / 2, altoPantalla * 30 / 100, subt2);
			slText(anchoPantalla / 2, altoPantalla * 20 / 100, subt3);
			slText(anchoPantalla / 2, altoPantalla * 10 / 100, subt4);
			slSetTextAlign(SL_ALIGN_RIGHT);
			slText(anchoPantalla, altoPantalla - tamanioSubtitulos, version);
			slSetFontSize(tamanioVolver);
			slText(anchoPantalla, 0, volver);
		}

		void actualizarCreditos() {
			if (slGetKey(77) != 0 || slGetKey(109) != 0) {
				estado = menu;
			}
		}
	}
}