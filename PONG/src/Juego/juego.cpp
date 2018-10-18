#include "juego.h"

#include <iostream>
#include <ctime>

#include "sl.h"
#include "Pantallas/pantallaJuego.h"
#include"Pantallas/pantallaMenu.h"
#include"Pantallas/pantallaGameOver.h"
#include "Pantallas/pantallaCreditos.h"

namespace Juego {

	static void inicializarJuego();
	static void inicializarPantallas();
	static void actualizar();
	static void dibujar();
	static void desinicializarJuego();

	using namespace PantallaJuego;
	estados estado = menu;
	int anchoPantalla = 900;
	int altoPantalla = 600;
	bool enJuego = true;
	int fuente;
	int golpe;
	int rebote;
	int gol;

	void inicializarJuego() {
		srand(time(0));
		slWindow(anchoPantalla, altoPantalla, "PONG",0);
		fuente=slLoadFont("res/fuente.ttf");
		golpe = slLoadWAV("res/golpe.wav");
		rebote = slLoadWAV("res/rebote.wav");
		gol = slLoadWAV("res/gol.wav");
	}

	void inicializarPantallas(){
		switch (estado) {
		case juego:
			inicializarPantJuego();
			break;
		default:break;
		}
	}
	
	void actualizar() {
		switch (estado) {
		case menu:
			Menu::actualizarMenu();
			break;
		case juego:
			actualizarJuego();
			break;
		case gameOver:
			GameOver::actualizarGO();
			break;
		case creditos:
			Creditos::actualizarCreditos();
			break;
		default:break;
		}
	}
	
	void dibujar() {

		switch (estado) {
		case menu:
			Menu::dibujarMenu();
			break;
		case juego:
			dibujarJuego();
			break;
		case gameOver:
			GameOver::dibujarGO();
			break;
		case creditos:
			Creditos::dibujarCreditos();
			break;
		default:break;
		}
		slRender();
	}

	void desinicializarJuego() {
		slClose();
	}

	void ejecutar() {
		
		inicializarJuego();

		while (enJuego && !slShouldClose()){
			inicializarPantallas();
			actualizar();
			dibujar();
		}

		desinicializarJuego();
	}
}