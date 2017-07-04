// This is a .h file for the model: cylinder_2

#ifndef cylinder_2_H
#define cylinder_2_H
#include "model.h"
namespace Models {
	namespace Cylinder_2_Internal {
		extern float vertices[];
		extern float normals[];
		extern float vertexNormals[];
		extern float texCoords[];
//		extern float colors[];
		extern unsigned int vertexCount;
	}

	class Cylinder_2: public Model {
		public:
			Cylinder_2();
			virtual ~Cylinder_2();
			virtual void drawSolid();
	};

	extern Cylinder_2 cylinder_2;
}
#endif
