#include <iostream>
#include <conio.h>
#include <glut.h>
#include <math.h>

#include "Plansza.h"
#include "Pilka.h"
#include "Paletka.h"
#include "Kamera.h"

#define PI 3.141593

Kamera kamera(-40, 0, 0, -45);
Plansza plansza(20, 30, 1, 1, 1, 0, 0, 0);
Pilka pilka(0.5, 4, 1, 0, 0, 0, 0, &plansza);
Paletka paletka1(1, 7, 0, -14, 0, 0, 1, &plansza, &pilka);
Paletka paletka2(2, 7, 0, 15, 0, 1, 0, &plansza, &pilka);

//////////////////////////////////////////////////////////////////////////////////////////
// Funkcja rysujaca obraz sceny widzianej z biezacej pozycji obserwatora
void Rysuj()
{
	plansza.Rysuj();
	pilka.Rysuj();
	paletka1.Rysuj();
	paletka2.Rysuj();
}

void Kolizja()
{
	if( pilka.getWruchu() )
	{
		if( paletka1.PosiadaniePilki())//odbicie od paletki1
			pilka.zmienKat(pilka.getKat() + PI - PI * 0.05 * paletka1.getPolozenie_x() );

		if (paletka2.PosiadaniePilki())//odbicie od paletki2
			pilka.zmienKat(pilka.getKat() + PI + PI * 0.05 * paletka2.getPolozenie_x() );

		if(pilka.getPolozenie_y() + pilka.getRozmiar()+0.99 > plansza.getWysokosc() / 2)//pilka wylatuje do gory
			pilka.ustawPilke(1);

		if(pilka.getPolozenie_y() - pilka.getRozmiar()-0.99 < -plansza.getWysokosc() / 2)//pilka wylatuje do dolu
			pilka.ustawPilke(2);

		if (pilka.getPolozenie_x() - pilka.getRozmiar() < -plansza.getSzerokosc() / 2)//odbicie od lewej sciany
			pilka.zmienKat(pilka.getKat() + PI/2);

		if (pilka.getPolozenie_x() + pilka.getRozmiar() > plansza.getSzerokosc() / 2)//odbicie od prawej sciany
			pilka.zmienKat(pilka.getKat() - PI/2);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
// Funkcja generujaca pojedyncza klatke animacji
void WyswietlObraz(void)
{
	// Wyczyszczenie bufora ramki i bufora glebokosci
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Powielenie macierzy na wierzcholku stosu 
	glPushMatrix();

	// Wyznaczenie polozenia obserwatora (przeksztalcenie uladu wspolrzednych 
	// sceny do ukladu wspolrzednych obserwatora). 
	glTranslatef( 0, 0, kamera.getzoom() );
	glRotatef(kamera.getX(), 1, 0, 0);
	glRotatef(kamera.getY(), 0, 1, 0);
	glRotatef(kamera.getZ(), 0, 0, 1);

	// Generacja obrazu sceny w niewidocznym buforze ramki
	Rysuj();

	//Ruch pilki
	if (pilka.getWruchu())
	{
		pilka.ustawPilke(	pilka.getPolozenie_x() + (pilka.getSzybkosc() / 1000) * sin(pilka.getKat()),
							pilka.getPolozenie_y() + (pilka.getSzybkosc() / 1000) * cos(pilka.getKat())	);

		//Wykrywanie kolizji
		Kolizja();
	}

	// Usuniecie macierzy lezacej na  wierzcholku stosu (powrot do stanu
	// sprzed wywolania funkcji)
	glPopMatrix();

	// Przelaczenie buforow ramki
	glutSwapBuffers();
}

//////////////////////////////////////////////////////////////////////////////////////////
// Funkcja ustawiajaca parametry rzutu perspektywicznego i rozmiary viewportu
void UstawParametryWidoku(int szerokosc, int wysokosc)
{
	// Ustawienie parametrow viewportu
	glViewport(0, 0, szerokosc, wysokosc);

	// Przejscie w tryb modyfikacji macierzy rzutowania
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, (float)szerokosc / (float)wysokosc, 1.0, 1000.0);

	// Przejscie w tryb modyfikacji macierzy przeksztalcen geometrycznych
	glMatrixMode(GL_MODELVIEW);

	// Zmiana macierzy znajdujacej sie na wierzcholku stosu na macierz jednostkowa 
	glLoadIdentity();
}

//////////////////////////////////////////////////////////////////////////////////////////
// Funkcja klawiszy specjalnych
void ObslugaKlawiszySpecjalnych(int klawisz, int x, int y)
{
	switch (klawisz)
	{
	case GLUT_KEY_UP:
		paletka1.Start();
		break;

	case GLUT_KEY_LEFT:
		paletka1.Ruch_L();
		break;

	case GLUT_KEY_RIGHT:
		paletka1.Ruch_P();
		break;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
// Funkcja obslugi klawiatury
void ObslugaKlawiatury(unsigned char klawisz, int x, int y)
{
	switch (klawisz)
	{
	case 's':
		paletka2.Start();
		break;

	case 'a':
		paletka2.Ruch_L();
		break;

	case 'd':
		paletka2.Ruch_P();
		break;

	case '+':
		kamera.zoomplus();
		break;

	case '-':
		kamera.zoomminus();
		break;

	case '7':
		kamera.Yminus();
		break;

	case '9':
		kamera.Yplus();
		break;

	case '8':
		kamera.Xplus();
		break;

	case '4':
		kamera.Zplus();
		break;

	case '6':
		kamera.Zminus();
		break;

	case '2':
		kamera.Xminus();
		break;
	}

	if (klawisz == 27)//esc
		exit(0);
}

//////////////////////////////////////////////////////////////////////////////////////////
// Glowna funkcja programu
int  main(int argc, char **argv)
{
	// Zainicjowanie biblioteki GLUT
	glutInit(&argc, argv);

	// Ustawienie trybu wyswietlania
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// Ustawienie polozenia dolenego lewego rogu okna
	glutInitWindowPosition(100, 100);

	// Ustawienie rozmiarow okna
	glutInitWindowSize(800, 600);


	////MENU
	char wybor;

menu:
	while (1)
	{
		system("cls");
		std::cout << "Pong v0.1a by Michal K" << std::endl << std::endl;
		std::cout << "[1] Start" << std::endl;
		std::cout << "[2] Opcje" << std::endl;
		std::cout << "[3] Sterowanie" << std::endl;
		std::cout << "[4] Wyjscie" << std::endl;

		wybor = _getch();

		switch (wybor)
		{
		case '1':
			goto start;
			break;
		case '2':
			//opcje
			while (1)
			{
				system("cls");
				std::cout << "Pong v0.1a by Michal Krysztofik" << std::endl << std::endl;
				std::cout << "Opcje" << std::endl;
				std::cout << "[1] Kolor tla: " << plansza.getKolorTla() << std::endl;
				std::cout << "[2] Kolor planszy: " << plansza.getKolor() << std::endl;
				std::cout << "[3] Kolor pilki: " << pilka.getKolor() << std::endl;
				std::cout << "[4] Wielkosc pilki: " << pilka.getWielkosc() << std::endl;
				std::cout << "[5] Szybkosc pilki: " << pilka.getPredkosc() << std::endl;
				std::cout << "[6] Kolor paletki gracza 1: " << paletka1.getKolor() << std::endl;
				std::cout << "[7] Szerokosc paletki gracza 1: " << paletka1.getSzerokosc() << std::endl;
				std::cout << "[8] Kolor paletki gracza 2: " << paletka2.getKolor() << std::endl;
				std::cout << "[9] Szerokosc paletki gracza 2: " << paletka2.getSzerokosc() << std::endl;
				std::cout << "[0] Powrot" << std::endl;

				wybor = _getch();
				switch (wybor)
				{
				case '1':
					plansza.nastKolorTla();
					break;

				case '2':
					plansza.nastKolor();
					break;

				case '3':
					pilka.nastKolor();
					break;

				case '4':
					pilka.nastWielkosc();
					break;

				case '5':
					pilka.nastPredkosc();
					break;

				case '6':
					paletka1.nastKolor();
					break;

				case '7':
					paletka1.nastSzerokosc();
					break;

				case '8':
					paletka2.nastKolor();
					break;

				case '9':
					paletka2.nastSzerokosc();
					break;

				case '0':
					goto menu;
					break;
				}
			}
			break;
		case '3':
			//wyswietl sterowanie
			system("cls");
			std::cout << "Pong v0.1a by Michal K" << std::endl << std::endl;
			std::cout << "Sterowanie" << std::endl;
			std::cout << "Gracz 1 - strzalki" << std::endl;
			std::cout << "Gracz 2 - S, A, D" << std::endl;
			std::cout << "Kamera - 4, 8, 6, 2, +, -, 7, 9" << std::endl;
			std::cout << "ESC - wyjscie z gry" << std::endl;
			_getch();
			break;
		case '4':
			return 0;
			break;
		}

		system("cls");
	}

start:

	// Utworzenie okna
	glutCreateWindow("Pong");

	// Odblokowanie bufora glebokosci
	glEnable(GL_DEPTH_TEST);

	// Ustawienie funkcji wykonywanej na danych w buforze glebokosci
	glDepthFunc(GL_LEQUAL);

	// Ustawienie wartosci czyszczacej zawartosc bufora glebokosci
	glClearDepth(1000.0);

	// Ustawienie koloru czyszczenia bufora ramki - kolor tla
	glClearColor(plansza.getKolorTla_R(), plansza.getKolorTla_G(), plansza.getKolorTla_B(), 0.0);

	// Zarejestrowanie funkcji (callback) wyswietlajacej
	glutDisplayFunc(WyswietlObraz);

	// Zarejestrowanie funkcji (callback) wywolywanej za kazdym razem kiedy
	// zmieniane sa rozmiary okna
	glutReshapeFunc(UstawParametryWidoku);

	// Zarejestrowanie funkcji wykonywanej gdy okno nie obsluguje
	// zadnych zadan
	glutIdleFunc(WyswietlObraz);

	// Zarejestrowanie funkcji obslugi klawiatury
	glutKeyboardFunc(ObslugaKlawiatury);

	// Zarejestrowanie funkcji obslugi klawiszy specjalnych
	glutSpecialFunc(ObslugaKlawiszySpecjalnych);

	pilka.ustawPilke(1);

	// Obsluga glownej petli programu (wywolywanie zarejestrowanych callbackow
	// w odpowiedzi na odbierane zdarzenia lub obsluga stanu bezczynnosci)
	glutMainLoop();

	return 0;
}