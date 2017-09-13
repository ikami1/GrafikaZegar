#include <glew/glew.h>
#include <glfw/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "constants.h"
#include "lodepng.h"
#include "allmodels.h"

using namespace glm;

float speed = 3.14;
float speed_right = 0;
float speed_direction = 0;
// position
vec3 position = vec3(0.0f, 0.0f, -5.0f);
// horizontal angle : toward -Z
float horizontalAngle = -PI;
// vertical angle : 0, look at the horizon
float verticalAngle = 0.0f;
//float speed = 3.0f; // 3 units / second
float mouseSpeed = 0.01f;

GLuint tex[10];


//Error processing callback procedure
void error_callback(int error, const char* description) {
	fputs(description, stderr);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		if (key == GLFW_KEY_LEFT) speed_right = PI;
		if (key == GLFW_KEY_RIGHT) speed_right = -PI;
		if (key == GLFW_KEY_UP) speed_direction = PI;
		if (key == GLFW_KEY_DOWN) speed_direction = -PI;
	}

	/*if (action == GLFW_PRESS) {
	if (key == GLFW_KEY_LEFT) position -= right * deltaTime * speed;
	if (key == GLFW_KEY_RIGHT) position += right * deltaTime * speed_right;
	if (key == GLFW_KEY_UP) position += direction * deltaTime * speed_direction;
	if (key == GLFW_KEY_DOWN) position -= direction * deltaTime * speed;
	}*/

	if (action == GLFW_RELEASE) {
		if (key == GLFW_KEY_LEFT) speed_right = 0;
		if (key == GLFW_KEY_RIGHT) speed_right = 0;
		if (key == GLFW_KEY_UP) speed_direction = 0;
		if (key == GLFW_KEY_DOWN) speed_direction = 0;
	}
}


GLuint readTexture(const char* filename) {
	GLuint tex;
	glActiveTexture(GL_TEXTURE0);

	//Wczytanie do pamiêci komputera
	std::vector<unsigned char> image;   //Alokuj wektor do wczytania obrazka
	unsigned width, height;   //Zmienne do których wczytamy wymiary obrazka
							  //Wczytaj obrazek
	unsigned error = lodepng::decode(image, width, height, filename);

	if (error != 0) {
		printf("Error while reading texture %s. Error code: %d. \n", filename, error);
	}

	//Import do pamiêci karty graficznej
	glGenTextures(1, &tex); //Zainicjuj jeden uchwyt
	glBindTexture(GL_TEXTURE_2D, tex); //Uaktywnij uchwyt
									   //Wczytaj obrazek do pamiêci KG skojarzonej z uchwytem
	glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*)image.data());

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //mozna zamienic styl teksturowania
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return tex;
}

//Initialization code procedure
void initOpenGLProgram(GLFWwindow* window) {
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_NORMALIZE);

	//************Place any code here that needs to be executed once, at the program start************
	glfwSetKeyCallback(window, key_callback); //Register key event processing callback procedure
	glEnable(GL_DEPTH_TEST);		//wlaczenie z bufora
	glEnable(GL_LIGHTING);			//wlaczenie cieniowania
	glEnable(GL_LIGHT0);			//biale zrodlo swiatla za obserwatorem
	//glEnable(GL_COLOR_MATERIAL);	//wlaczenie kolorowania wielokatow
	glShadeModel(GL_SMOOTH);		//cieniowanie
	glClearColor(1, 1, 1, 1);

	tex[0] = readTexture("Images/bronze1.png");
	tex[1] = readTexture("Images/dwood1.png");
	tex[2] = readTexture("Images/paper3.png");
	tex[3] = readTexture("Images/steel1.png");
	tex[4] = readTexture("Images/steel2.png");
	//tex[5] = readTexture("Images/steel2_paper3.png");
}

mat4 macierzWidoku(GLFWwindow* window, float deltaTime) {
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);

	// Reset mouse position for next frame
	int width, height;
	glfwGetWindowSize(window, &width, &height);
	glfwSetCursorPos(window, width / 2, height / 2);

	// Compute new orientation
	horizontalAngle += mouseSpeed * deltaTime * float(width / 2 - xpos);
	verticalAngle += mouseSpeed * deltaTime * float(height / 2 - ypos);

	vec3 direction(cos(verticalAngle)*sin(horizontalAngle), sin(verticalAngle), cos(verticalAngle)*cos(horizontalAngle));
	direction *= -1.0f;
	// Right vector
	vec3 right = vec3(sin(horizontalAngle - 3.14f / 2.0f), 0, cos(horizontalAngle - 3.14f / 2.0f));

	// Up vector : perpendicular to both direction and right
	vec3 up = cross(right, direction) * -1.0f;

	position += right * deltaTime * speed_right;
	position += direction * deltaTime * speed_direction;


	return lookAt(
		position,           // Camera is here
		position + direction, // and looks here : at the same position, plus "direction"
		up                  // Head is up (set to 0,-1,0 to look upside-down)
	);
}

mat4 ustawPinion(mat4 Mpinion, float angle) {
	Mpinion = rotate(Mpinion, 90.0f*PI / 180, vec3(1.0f, 0.0f, 0.0f));
	Mpinion = translate(Mpinion, vec3(0.0f, -1.0f, -0.45f));
	Mpinion = rotate(Mpinion, 7.5f*PI / 180, vec3(0.0f, 1.0f, 0.0f));
	Mpinion = rotate(Mpinion, -angle * 2, vec3(0.0f, 1.0f, 0.0f));
	Mpinion = scale(Mpinion, vec3(0.05f, 0.05f, 0.05f));
	return Mpinion;
}


//Drawing procedure
void drawScene(GLFWwindow* window, float angle, float deltaTime) {
	//************Place any code here that draws something inside the window******************l
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	angle /= 3600.0f;		// angle/10 to jeden obrot godzinowej co 10 sekund


	mat4 V = macierzWidoku(window, deltaTime);
	mat4 M = mat4(1.0f);
	vec3 skala = vec3(0.02f, 0.02f, 0.02f);
	mat4 P = perspective(50 * PI / 180, 1.0f, 1.0f, 50.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(value_ptr(P));
	glMatrixMode(GL_MODELVIEW);

	/*mat4 Mgearforpinion = M;
	Mgearforpinion = translate(Mgearforpinion, vec3(1.0f, 1.0f, 0.0f));
	Mgearforpinion = rotate(Mgearforpinion, -90.0f*PI / 180, vec3(1.0f, 0.0f, 0.0f));
	mat4 Mpinion = Mgearforpinion;
	Mgearforpinion = rotate(Mgearforpinion, angle, vec3(0.0f, 1.0f, 0.0f));
	Mgearforpinion = scale(Mgearforpinion, vec3(0.05f, 0.05f, 0.05f));
	Mpinion = ustawPinion(Mpinion, angle);

	glBindTexture(GL_TEXTURE_2D, tex[0]);
	glLoadMatrixf(value_ptr(V*Mgearforpinion));
	Models::gearforpinion_x.drawSolid();
	glLoadMatrixf(value_ptr(V*Mpinion));
	Models::pinion_x.drawSolid();*/

	mat4 Mgear45 = M;
	Mgear45 = translate(Mgear45, vec3(0.0f, 0.0f, 2.0f));
	Mgear45 = rotate(Mgear45, -90.0f*PI / 180, vec3(1.0f, 0.0f, 0.0f));
	mat4 Mgear20 = Mgear45;
	mat4 Mgear12 = Mgear45;
	Mgear45 = rotate(Mgear45, angle, vec3(0.0f, 1.0f, 0.0f));
	Mgear45 = scale(Mgear45, skala);

	glBindTexture(GL_TEXTURE_2D, tex[3]);
	glLoadMatrixf(value_ptr(V*Mgear45));
	Models::gear45_2.drawSolid();
	Models::cylinder_45_12.drawSolid();

	Mgear20 = translate(Mgear20, vec3(1.3f, 0.0f, 0.0f));
	Mgear20 = rotate(Mgear20, -angle*2.25f, vec3(0.0f, 1.0f, 0.0f));		//2.25 bo 45/20
	Mgear20 = scale(Mgear20, skala);
	mat4 Mgear64 = Mgear20;					//gear64 polaczony z cylindrem i gear20
	Mgear64 = translate(Mgear64, vec3(0.0f, 50.0f, 0.0f));

	glLoadMatrixf(value_ptr(V*Mgear20));
	Models::gear20_2.drawSolid();
	Models::cylinder_64_20.drawSolid();		//cylinder polaczony jest z gear20
	glLoadMatrixf(value_ptr(V*Mgear64));
	Models::gear64_1.drawSolid();

	//mat4 Mgear12 = Mgear45;  wczesniej jest to zeby byly w tej samej plaszczyznie juz obliczonej
	Mgear12 = translate(Mgear12, vec3(0.0f, 1.0f, 0.0f));
	mat4 Mclockface = Mgear12;
	Mgear12 = rotate(Mgear12, angle*12.0f, vec3(0.0f, 1.0f, 0.0f));			//12 bo 64*45/(12*20)
	Mgear12 = scale(Mgear12, skala);
	glLoadMatrixf(value_ptr(V*Mgear12));
	Models::gear12_1.drawSolid();

	Mclockface = translate(Mclockface, vec3(0.0f, 0.2f, 0.0f));
	Mclockface = rotate(Mclockface, PI, vec3(0.0f, 1.0f, 0.0f));
	Mclockface = scale(Mclockface, skala * 4.0f);
	mat4 MclockFace_pod = Mclockface;
	mat4 MclockBody = Mclockface;
	MclockBody = translate(MclockBody, vec3(0.0f, -0.1f, 9.0f));
	MclockBody = scale(MclockBody, vec3(1.7f, 1.7f, 1.7f));
	mat4 MhourHand = Mclockface;
	MhourHand = rotate(MhourHand, PI - angle*2.25f, vec3(0.0f, 1.0f, 0.0f));
	mat4 MminuteHand = Mclockface;
	MminuteHand = rotate(MminuteHand, PI - angle*12.0f, vec3(0.0f, 1.0f, 0.0f));

	glBindTexture(GL_TEXTURE_2D, tex[4]);
	glLoadMatrixf(value_ptr(V*Mclockface));
	Models::clockFace.drawSolid();
	glLoadMatrixf(value_ptr(V*MhourHand));
	Models::hour_hand.drawSolid();
	glLoadMatrixf(value_ptr(V*MminuteHand));
	Models::minute_hand.drawSolid();
	glBindTexture(GL_TEXTURE_2D, tex[2]);
	glLoadMatrixf(value_ptr(V*MclockFace_pod));
	Models::clockFace_pod.drawSolid();
	glBindTexture(GL_TEXTURE_2D, tex[1]);
	glLoadMatrixf(value_ptr(V*MclockBody));
	Models::clockBody.drawSolid();

	glfwSwapBuffers(window);

}

int main(int argc, char **argv) {

	GLFWwindow* window; //Pointer to object that represents the application window

	glfwSetErrorCallback(error_callback);//Register error processing callback procedure

	if (!glfwInit()) { //Initialize GLFW library
		fprintf(stderr, "Can't initialize GLFW.\n");
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(700, 700, "OpenGL", NULL, NULL);  //Create a window 500pxx500px titled "OpenGL" and an OpenGL context associated with it.

	if (!window) //If no window is opened then close the program
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window); //Since this moment OpenGL context corresponding to the window is active and all OpenGL calls will refer to this context.
	glfwSwapInterval(1); //During vsync wait for the first refresh

	GLenum err;
	if ((err = glewInit()) != GLEW_OK) { //Initialize GLEW library
		fprintf(stderr, "Can't initialize GLEW: %s\n", glewGetErrorString(err));
		exit(EXIT_FAILURE);
	}

	initOpenGLProgram(window); //Call initialization procedure

	float angle = 50;
	float deltaTime = 0;
	glfwSetTime(0);
	//Main application loop
	while (!glfwWindowShouldClose(window)) //As long as the window shouldnt be closed yet...
	{
		angle += speed*glfwGetTime();
		glfwSetTime(0);
		drawScene(window, angle, deltaTime); //Execute drawing procedure
		deltaTime = glfwGetTime();
		glfwPollEvents(); //Process callback procedures corresponding to the events that took place up to now
	}
	
	glDeleteTextures(10, tex); //Delete textures from memory
	glfwDestroyWindow(window); //Delete OpenGL context and the window.
	glfwTerminate(); //Free GLFW resources
	exit(EXIT_SUCCESS);
}