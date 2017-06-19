// This is a .h file for the model: cylinder_45_12

#ifndef cylinder_45_12_H
#define cylinder_45_12_H
#include "model.h"
namespace Models {
	namespace Cylinder_45_12_Internal {
		extern float vertices[];
		extern float normals[];
		extern float vertexNormals[];
		extern float texCoords[];
//		extern float colors[];
		extern unsigned int vertexCount;
	}

	class Cylinder_45_12: public Model {
		public:
			Cylinder_45_12();
			virtual ~Cylinder_45_12();
			virtual void drawSolid();
	};

	extern Cylinder_45_12 cylinder_45_12;
}
#endif
