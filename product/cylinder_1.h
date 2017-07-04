// This is a .h file for the model: cylinder_1

#ifndef cylinder_1_H
#define cylinder_1_H
#include "model.h"
namespace Models {
	namespace Cylinder_1_Internal {
		extern float vertices[];
		extern float normals[];
		extern float vertexNormals[];
		extern float texCoords[];
//		extern float colors[];
		extern unsigned int vertexCount;
	}

	class Cylinder_1: public Model {
		public:
			Cylinder_1();
			virtual ~Cylinder_1();
			virtual void drawSolid();
	};

	extern Cylinder_1 cylinder_1;
}
#endif
