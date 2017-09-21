// This is a .h file for the model: gear64_1

#ifndef gear64_1_H
#define gear64_1_H
#include "model.h"
namespace Models {
	namespace Gear64_1_Internal {
		extern float vertices[];
		extern float normals[];
		extern float vertexNormals[];
		extern float texCoords[];
//		extern float colors[];
		extern unsigned int vertexCount;
	}

	class Gear64_1: public Model {
		public:
			Gear64_1();
			virtual ~Gear64_1();
			virtual void drawSolid();
	};

	extern Gear64_1 gear64_1;
}
#endif
