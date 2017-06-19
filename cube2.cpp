// This is a .c file for the model: cube2

#include "cube2.h"

namespace Models {
 Cube2 cube2;

	Cube2::Cube2() {
		vertices=Cube2_Internal::vertices;
		normals=Cube2_Internal::normals;
//		vertexNormals=Cube2_Internal::vertexNormals;
		texCoords=Cube2_Internal::texCoords;
//		colors=Cube2_Internal::colors;
		vertexCount=Cube2_Internal::vertexCount;
	}

	Cube2::~Cube2() {
	}

	void Cube2::drawSolid() {
		glEnable(GL_NORMALIZE);

		glEnableClientState(GL_VERTEX_ARRAY);
		//glEnableClientState(GL_COLOR_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glVertexPointer(4,GL_FLOAT,0,vertices);
		//glColorPointer(4,GL_FLOAT,0,colors);
		glNormalPointer(GL_FLOAT,sizeof(float)*4,normals);
		glTexCoordPointer(2,GL_FLOAT,0,texCoords);

		glDrawArrays(GL_TRIANGLES,0,vertexCount);

		glDisableClientState(GL_VERTEX_ARRAY);
		//glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}

	namespace Cube2_Internal {
			unsigned int vertexCount=36;

//			float colors[]={
//			};

			float vertices[]={
			    1, -1, 1, 1, 
			    -1, -1, -1, 1, 
			    1, -1, -1, 1, 
			    -1, 1, -1, 1, 
			    0.999999, 1, 1, 1, 
			    1, 1, -0.999999, 1, 
			    1, 1, -0.999999, 1, 
			    1, -1, 1, 1, 
			    1, -1, -1, 1, 
			    0.999999, 1, 1, 1, 
			    -1, -1, 1, 1, 
			    1, -1, 1, 1, 
			    -1, -1, 1, 1, 
			    -1, 1, -1, 1, 
			    -1, -1, -1, 1, 
			    1, -1, -1, 1, 
			    -1, 1, -1, 1, 
			    1, 1, -0.999999, 1, 
			    1, -1, 1, 1, 
			    -1, -1, 1, 1, 
			    -1, -1, -1, 1, 
			    -1, 1, -1, 1, 
			    -1, 1, 1, 1, 
			    0.999999, 1, 1, 1, 
			    1, 1, -0.999999, 1, 
			    0.999999, 1, 1, 1, 
			    1, -1, 1, 1, 
			    0.999999, 1, 1, 1, 
			    -1, 1, 1, 1, 
			    -1, -1, 1, 1, 
			    -1, -1, 1, 1, 
			    -1, 1, 1, 1, 
			    -1, 1, -1, 1, 
			    1, -1, -1, 1, 
			    -1, -1, -1, 1, 
			    -1, 1, -1, 1, 
			};


			float texCoords[]={
			    1, 0, 
			    0, 1, 
			    0, 0, 
			    1, 0, 
			    0, 1, 
			    0, 0, 
			    1, 0, 
			    0, 1, 
			    0, 0, 
			    1, 0, 
			    0, 1, 
			    0, 0, 
			    0, 0, 
			    1, 1, 
			    0, 1, 
			    1, 0, 
			    0, 1, 
			    0, 0, 
			    1, 0, 
			    1, 1, 
			    0, 1, 
			    1, 0, 
			    1, 1, 
			    0, 1, 
			    1, 0, 
			    1, 1, 
			    0, 1, 
			    1, 0, 
			    1, 1, 
			    0, 1, 
			    0, 0, 
			    1, 0, 
			    1, 1, 
			    1, 0, 
			    1, 1, 
			    0, 1, 
			};


			float normals[]={
			    0, -1, 0, 0, 
			    0, -1, 0, 0, 
			    0, -1, 0, 0, 
			    0, 1, 0, 0, 
			    0, 1, 0, 0, 
			    0, 1, 0, 0, 
			    1, -0, 0, 0, 
			    1, -0, 0, 0, 
			    1, -0, 0, 0, 
			    0, -0, 1, 0, 
			    0, -0, 1, 0, 
			    0, -0, 1, 0, 
			    -1, -0, -0, 0, 
			    -1, -0, -0, 0, 
			    -1, -0, -0, 0, 
			    0, 0, -1, 0, 
			    0, 0, -1, 0, 
			    0, 0, -1, 0, 
			    0, -1, 0, 0, 
			    0, -1, 0, 0, 
			    0, -1, 0, 0, 
			    0, 1, 0, 0, 
			    0, 1, 0, 0, 
			    0, 1, 0, 0, 
			    1, -0, 0, 0, 
			    1, -0, 0, 0, 
			    1, -0, 0, 0, 
			    0, -0, 1, 0, 
			    0, -0, 1, 0, 
			    0, -0, 1, 0, 
			    -1, -0, -0, 0, 
			    -1, -0, -0, 0, 
			    -1, -0, -0, 0, 
			    0, 0, -1, 0, 
			    0, 0, -1, 0, 
			    0, 0, -1, 0, 
			};


  }
}
