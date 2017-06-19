#include <glew/glew.h>
#include <glfw/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "constants.h"
#include "allmodels.h"

using namespace glm;

float speed = 3.14;
float speed_right = 0;
float speed_direction = 0;
// position
glm::vec3 position = glm::vec3(0.0f, 0.0f, -5.0f);
// horizontal angle : toward -Z
float horizontalAngle = -PI;
// vertical angle : 0, look at the horizon
float verticalAngle = 0.0f;
//float speed = 3.0f; // 3 units / second
float mouseSpeed = 0.01f;




//Error processing callback procedure
void error_callback(int error, const char* description) {
	fputs(description, stderr);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		if (key == GLFW_KEY_LEFT) speed_right = -PI;
		if (key == GLFW_KEY_RIGHT) speed_right = PI;
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

//Initialization code procedure
void initOpenGLProgram(GLFWwindow* window) {
	//************Place any code here that needs to be executed once, at the program start************
	glfwSetKeyCallback(window, key_callback); //Register key event processing callback procedure
	glClearColor(1,1,1,1);
}

//Models::Sphere mySphere(2, 36, 36);


//Drawing procedure
void drawScene(GLFWwindow* window, float angle, float distance_cam_z, float distance_cam_y, float deltaTime) {
	//************Place any code here that draws something inside the window******************l
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);

	// Reset mouse position for next frame
	int width, height;
	glfwGetWindowSize(window, &width, &height);
	glfwSetCursorPos(window, width/2, height/2);

	// Compute new orientation
	horizontalAngle += mouseSpeed * deltaTime * float(width/2-xpos);
	verticalAngle += mouseSpeed * deltaTime * float(height/2-ypos);

	glm::vec3 direction( cos(verticalAngle)*sin(horizontalAngle), sin(verticalAngle), cos(verticalAngle)*cos(horizontalAngle) );
	direction *= -1.0f;
	// Right vector
	glm::vec3 right = glm::vec3( sin(horizontalAngle-3.14f/2.0f), 0, cos(horizontalAngle-3.14f/2.0f) );

	// Up vector : perpendicular to both direction and right
	glm::vec3 up = glm::cross(right, direction) * -1.0f;

	position += right * deltaTime * speed_right;
	position += direction * deltaTime * speed_direction;

	glm::mat4 ViewMatrix = glm::lookAt(
		position,           // Camera is here
		position + direction, // and looks here : at the same position, plus "direction"
		up                  // Head is up (set to 0,-1,0 to look upside-down)
	);






	mat4 M = mat4(1.0f);
	/*mat4 V = lookAt(
		vec3(0.0f, distance_cam_y + 0.0f, distance_cam_z + -5.0f),
		vec3(0.0f, distance_cam_y + 0.0f, distance_cam_z + 0.0f),
		vec3(0.0f, distance_cam_y + 1.0f, distance_cam_z + 0.0f));*/
	mat4 V = ViewMatrix;

	mat4 P = perspective(50 * PI / 180, 1.0f, 1.0f, 50.0f);
	M = translate(M, vec3(1.0f, 1.0f, 0.0f));
	M = rotate(M, -90.0f*PI / 180, vec3(1.0f, 0.0f, 0.0f));
	mat4 M1 = M;
	M = rotate(M, angle / 10, vec3(0.0f, 1.0f, 0.0f));
	M = scale(M, vec3(0.05f, 0.05f, 0.05f));
	//M = scale(M, vec3(0.1f, 0.1f, 0.1f));
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(value_ptr(P));
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(value_ptr(V*M));

	glEnable(GL_LIGHTING);			//wlaczenie cieniowania
	glEnable(GL_LIGHT0);			//biale zrodlo swiatla za obserwatorem
	glEnable(GL_DEPTH_TEST);		//wlaczenie z bufora
	glEnable(GL_COLOR_MATERIAL);	//wlaczenie kolorowania wielokatow
	glShadeModel(GL_SMOOTH);		//cieniowanie

	glColor3d(0.3, 0.3, 0.1);
	Models::gearforpinion_x.drawSolid();

	M1 = rotate(M1, 90.0f*PI / 180, vec3(1.0f, 0.0f, 0.0f));
	M1 = translate(M1, vec3(0.0f, -1.0f, -0.45f));
	M1 = rotate(M1, -angle / 5, vec3(0.0f, 1.0f, 0.0f));
	M1 = scale(M1, vec3(0.05f, 0.05f, 0.05f));
	glLoadMatrixf(value_ptr(V*M1));

	glColor3d(0.5, 0.5, 0.5);
	Models::pinion_x.drawSolid();
	//Models::gear16_2.drawSolid();

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
	float distance_cam_y = 0;
	float distance_cam_z = 0;
	float deltaTime = 0;
	glfwSetTime(0);
	//Main application loop
	while (!glfwWindowShouldClose(window)) //As long as the window shouldnt be closed yet...
	{
		angle += speed*glfwGetTime();
		distance_cam_z += speed_direction*glfwGetTime();
		distance_cam_y += speed_right*glfwGetTime();
		glfwSetTime(0);
		drawScene(window, angle, distance_cam_z, distance_cam_y, deltaTime); //Execute drawing procedure
		deltaTime = glfwGetTime();
		glfwPollEvents(); //Process callback procedures corresponding to the events that took place up to now
	}

	glfwDestroyWindow(window); //Delete OpenGL context and the window.
	glfwTerminate(); //Free GLFW resources
	exit(EXIT_SUCCESS);
}