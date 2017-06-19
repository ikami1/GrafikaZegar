// This is a .h file for the model: cylinder_64_20

#ifndef cylinder_64_20_H
#define cylinder_64_20_H
#include "model.h"
namespace Models {
	namespace Cylinder_64_20_Internal {
		extern float vertices[];
		extern float normals[];
		extern float vertexNormals[];
		extern float texCoords[];
//		extern float colors[];
		extern unsigned int vertexCount;
	}

	class Cylinder_64_20: public Model {
		public:
			Cylinder_64_20();
			virtual ~Cylinder_64_20();
			virtual void drawSolid();
	};

	extern Cylinder_64_20 cylinder_64_20;
}
#endif
