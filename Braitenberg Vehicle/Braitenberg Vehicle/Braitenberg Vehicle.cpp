#include "stdafx.h"
#include "Point.h"
#include "Matrix.h"
#include "Vehicle.h"
#include "LightSource.h"

using namespace std;

/*--------------------------------------------------------------------------*/
/* DEFINES */
/*--------------------------------------------------------------------------*/

#define ImageW 800
#define ImageH 600




vector<Vehicle> vehicles;
vector<LightSource> light_sources;



void display(void)
{
	// should not be necessary but some GPUs aren't displaying anything until a clear call.
	glClear(GL_COLOR_BUFFER_BIT);


	for (int i = 0; i < vehicles.size(); ++i) {
		Point c = vehicles[i].center;
		int w = vehicles[i].width / 2;
		int h = vehicles[i].height / 2;
		glBegin(GL_QUADS);
		glVertex2f(c.x - w, c.y - h);
		glVertex2f(c.x + w, c.y - h);
		glVertex2f(c.x + w, c.y + h);
		glVertex2f(c.x - w, c.y + h);
		glEnd();
	}



	glFlush();
}

void moveVehicles(int value) {
	for (int i = 0; i < vehicles.size(); ++i) {
//		vehicles[i].center.x += vehicles[i].velocity.x;
//		vehicles[i].center.y += vehicles[i].velocity.y;
	}
	glutTimerFunc(50, moveVehicles, 0);
	glutPostRedisplay();
}

/*--------------------------------------------------------------------------*/
/* LOCAL FUNCTIONS -- GLUT CALLBACK FUNCTIONS */
/*--------------------------------------------------------------------------*/

void mouseClick(int button, int state, int x, int y) {

	
}

void mouseMove(int x, int y) {

}

void keyboard(unsigned char key, int x, int y) {
	//glutTimerFunc(10, moveVehicles, 10);
}





/*--------------------------------------------------------------------------*/
/* LOCAL FUNCTIONS -- OPENGL INITIALIZATION FUNCTIONS */
/*--------------------------------------------------------------------------*/
void init(void)
{
	gluOrtho2D(0, ImageW - 1, ImageH - 1, 0);

	Matrix<int> k(2, 2);

	Vehicle v1(Point(200,200), VEHICLE_K_STRAIGHT);
	//Vehicle v2(10, 10, { 300, 300 }, { 0, 1 }, k);
	//Vehicle v3(10, 10, { 400, 300 }, { 1, 1 }, k);

	vehicles.push_back(v1);


	//glutIdleFunc(moveVehicles);
	glutTimerFunc(50, moveVehicles, 0);

}


/*--------------------------------------------------------------------------*/
/* MAIN FUNCTION */
/*--------------------------------------------------------------------------*/

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(ImageW, ImageH);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Braitenberg Vehicles");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouseClick);
	glutMotionFunc(mouseMove);
	glutKeyboardFunc(keyboard);
	glutMainLoop();


	return 0;
}
