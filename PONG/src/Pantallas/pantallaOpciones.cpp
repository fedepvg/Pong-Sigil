#include "pantallaOpciones.h"

#include"raylib.h"
#include"Juego/juego.h"

namespace Juego {
	namespace Opciones {
		using namespace Juego;

		void dibujarOpciones() {
			char titulo[] = "OPCIONES";
			char seleccion[] = "Seleccione una resolucion con la tecla indicada: ";
			char opc1[] ="1) 1920x1080";
			char opc2[] = "2) 1600x900";
			char opc3[] = "3) 1080x720";
			char opc4[] = "4) 900x600";
			char menu[] = "Pulse M para volver al menu";
			int tamanioTitulo = (altoPantalla*anchoPantalla)*0.011 / 100;
			int tamanioSub = (altoPantalla*anchoPantalla)*0.0055 / 100;

			DrawText(titulo, (anchoPantalla - MeasureText(titulo,tamanioTitulo)) / 2, (altoPantalla - tamanioTitulo) / 3, tamanioTitulo, DARKGRAY);
			DrawText(seleccion, (anchoPantalla - MeasureText(seleccion, tamanioSub)) / 2, (altoPantalla - tamanioSub) / 2, tamanioSub, DARKGRAY);
			DrawText(opc1, anchoPantalla / 4, (altoPantalla / 3) * 2, tamanioSub, DARKGRAY);
			DrawText(opc2, (anchoPantalla / 4)*2, (altoPantalla / 3) * 2, tamanioSub, DARKGRAY);
			DrawText(opc3, anchoPantalla / 4, (altoPantalla / 12) * 10, tamanioSub, DARKGRAY);
			DrawText(opc4, (anchoPantalla / 4)*2, (altoPantalla / 12) * 10, tamanioSub, DARKGRAY);
			DrawText(menu, (anchoPantalla - MeasureText(menu, tamanioSub)) / 2, altoPantalla - tamanioSub, tamanioSub, DARKGRAY);
		}

		void actualizarOpciones() {
			if (IsKeyPressed(KEY_M)) {
				estado = menu;
			}
		}
	}
}
