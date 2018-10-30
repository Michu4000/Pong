#include <iostream>
#include <conio.h>
#include <glut.h>
#include <math.h>

#include "Plansza.h"
#include "Pilka.h"
#include "Paletka.h"
#include "Kamera.h"

#define PI 3.141593

Camera camera(-40.0f, 0.0f, 0.0f, -45.0f);
Board board(20.0f, 30.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f);
Ball ball(0.5f, 4.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Racket racket1(1, 7.0f, 0.0f, -14.0f, 0.0f, 0.0f, 1.0f, &board, &ball);
Racket racket2(2, 7.0f, 0.0f, 15.0f, 0.0f, 1.0f, 0.0f, &board, &ball);

//////////////////////////////////////////////////////////////////////////////////////////
// Paint scene's picture from current perspective of observer
void paint()
{
	board.paint();
	ball.paint();
	racket1.paint();
	racket2.paint();
}

void collision()
{
	if( ball.getMoving() )
	{
		if( racket1.isHoldingBall()) //ball hit racket 1
			ball.setAngle(ball.getAngle() + PI - PI * 0.05f * racket1.getPositionX() );

		if (racket2.isHoldingBall()) //ball hit racket 2
			ball.setAngle(ball.getAngle() + PI + PI * 0.05f * racket2.getPositionX() );

		if(ball.getPositionY() + ball.getSize() + 0.99f > board.getHeight() / 2) //ball is flying out (top)
			ball.placeBall(1);

		if(ball.getPositionY() - ball.getSize() - 0.99f < -board.getHeight() / 2) //ball is flying out (bottom)
			ball.placeBall(2);

		if (ball.getPositionX() - ball.getSize() < -board.getWidth() / 2) //ball hit left wall of board
			ball.setAngle(ball.getAngle() + PI/2);

		if (ball.getPositionX() + ball.getSize() > board.getWidth() / 2) //ball hit right wall of board
			ball.setAngle(ball.getAngle() - PI/2);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
// Generate single animation's frame
void showPicture(void)
{
	// Clear frame's buffer and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Duplicate the matrix at the top of the stack
	glPushMatrix();

	// Get observer's position
	// (conversion of scene's coordinate system to observer's coordinate system)
	glTranslatef( 0.0f, 0.0f, camera.getZoom() );
	glRotatef(camera.getX(), 1.0f, 0.0f, 0.0f);
	glRotatef(camera.getY(), 0.0f, 1.0f, 0.0f);
	glRotatef(camera.getZ(), 0.0f, 0.0f, 1.0f);

	// Generate scene's picture in invisible frame's buffer
	paint();

	// Ball movement
	if (ball.getMoving())
	{
		ball.placeBall(	ball.getPositionX() + (ball.getSpeed() / 1000) * sin(ball.getAngle()),
							ball.getPositionY() + (ball.getSpeed() / 1000) * cos(ball.getAngle())	);

		// Collision check
		collision();
	}

	// Remove the matrix at the top of the stack
	// (return to the state before the function was called)
	glPopMatrix();

	// Switch frame buffers
	glutSwapBuffers();
}

//////////////////////////////////////////////////////////////////////////////////////////
// Set parameters of perspective projection and size of viewport
void setViewParams(int width, int height)
{
	// Set parameters of viewport
	glViewport(0, 0, width, height);

	// Enter mode of projction matrix modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, (float)width / (float)height, 1.0, 1000.0);

	// Enter mode of geometric transformations matrix modifying
	glMatrixMode(GL_MODELVIEW);

	// Change matrix a the top of the stack to unit matrix
	glLoadIdentity();
}

//////////////////////////////////////////////////////////////////////////////////////////
// Map special keyboard keys (arrows) to functions
void mapSpecialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		racket1.start();
		break;

	case GLUT_KEY_LEFT:
		racket1.moveLeft();
		break;

	case GLUT_KEY_RIGHT:
		racket1.moveRight();
		break;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
// Map keyboard keys to functions
void mapKeys(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 's':
		racket2.start();
		break;

	case 'a':
		racket2.moveLeft();
		break;

	case 'd':
		racket2.moveRight();
		break;

	case '+':
		camera.zoomPlus();
		break;

	case '-':
		camera.zoomMinus();
		break;

	case '7':
		camera.yMinus();
		break;

	case '9':
		camera.yPlus();
		break;

	case '8':
		camera.xPlus();
		break;

	case '4':
		camera.zPlus();
		break;

	case '6':
		camera.zMinus();
		break;

	case '2':
		camera.xMinus();
		break;
	}

	if (key == 27) //ESC key
		exit(0);
}

//////////////////////////////////////////////////////////////////////////////////////////
// Main application function
int  main(int argc, char **argv)
{
	// Initialize GLUT library
	glutInit(&argc, argv);

	// Set display mode
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// Set position of left-bottom corner of the window
	glutInitWindowPosition(100, 100);

	// Set window size
	glutInitWindowSize(800, 600);

	////MENU
	char select;

menu:
	while (1)
	{
		system("cls");
		std::cout << "Pong v0.1a by Michal K" << std::endl << std::endl;
		std::cout << "[1] Start" << std::endl;
		std::cout << "[2] Options" << std::endl;
		std::cout << "[3] Controls" << std::endl;
		std::cout << "[4] Exit" << std::endl;

		select = _getch();

		switch (select)
		{
		case '1':
			goto start;
			break;
		case '2':
			//options
			while (1)
			{
				system("cls");
				std::cout << "Pong v0.1a by Michal K" << std::endl << std::endl;
				std::cout << "Options" << std::endl;
				std::cout << "[1] Background color: " << board.getBackgroundColor() << std::endl;
				std::cout << "[2] Board color: " << board.getColor() << std::endl;
				std::cout << "[3] Ball color: " << ball.getColor() << std::endl;
				std::cout << "[4] Ball size: " << ball.getSizeName() << std::endl;
				std::cout << "[5] Ball speed: " << ball.getSpeedName() << std::endl;
				std::cout << "[6] Player 1's racket color: " << racket1.getColor() << std::endl;
				std::cout << "[7] Player 1's racket width: " << racket1.getWidth() << std::endl;
				std::cout << "[8] Player 2's racket color: " << racket2.getColor() << std::endl;
				std::cout << "[9] Player 2's racket width: " << racket2.getWidth() << std::endl;
				std::cout << "[0] Back" << std::endl;

				select = _getch();
				switch (select)
				{
				case '1':
					board.nextBackgroundColor();
					break;

				case '2':
					board.nextColor();
					break;

				case '3':
					ball.nextColor();
					break;

				case '4':
					ball.nextSize();
					break;

				case '5':
					ball.nextSpeed();
					break;

				case '6':
					racket1.nextColor();
					break;

				case '7':
					racket1.nextWidth();
					break;

				case '8':
					racket2.nextColor();
					break;

				case '9':
					racket2.nextWidth();
					break;

				case '0':
					goto menu;
					break;
				}
			}
			break;
		case '3':
			//show controls
			system("cls");
			std::cout << "Pong v0.1a by Michal K" << std::endl << std::endl;
			std::cout << "Controls" << std::endl;
			std::cout << "Player 1 - arrows" << std::endl;
			std::cout << "Player 2 - S, A, D" << std::endl;
			std::cout << "Camera - 4, 8, 6, 2, +, -, 7, 9" << std::endl;
			std::cout << "ESC - exit game" << std::endl;
			_getch();
			break;
		case '4':
			return 0;
			break;
		}

		system("cls");
	}

start:

	// Create the window
	glutCreateWindow("Pong");

	// Unlock depth buffer
	glEnable(GL_DEPTH_TEST);

	// Set function performed on depth buffer's data
	glDepthFunc(GL_LEQUAL);

	// Set dept buffer clearing value
	glClearDepth(1000.0);

	// Set frame buffer cleaning color - background color
	glClearColor(board.getBackgroundColorR(), board.getBackgroundColorG(), board.getBackgroundColorB(), 0.0);

	// Register displaying function (callback)
	glutDisplayFunc(showPicture);

	// Register function for changing window size (callback)
	glutReshapeFunc(setViewParams);

	// Register function for idle window
	glutIdleFunc(showPicture);

	// Register function for keyboard service
	glutKeyboardFunc(mapKeys);

	// Register function for keyboard service (special keys)
	glutSpecialFunc(mapSpecialKeys);

	ball.placeBall(1);

	// Main application loop service
	// (callbacks for events and idle state)
	glutMainLoop();

	return 0;
}
