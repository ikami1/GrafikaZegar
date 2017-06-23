// This is a .h file for the model: cube2

#ifndef cube2_H
#define cube2_H
#include "model.h"
namespace Models {
	namespace Cube2_Internal {
		extern float vertices[];
		extern float normals[];
		extern float vertexNormals[];
		extern float texCoords[];
//		extern float colors[];
		extern unsigned int vertexCount;
	}

	class Cube2: public Model {
		public:
			Cube2();
			virtual ~Cube2();
			virtual void drawSolid();
	};

	extern Cube2 cube2;
}
#endif
