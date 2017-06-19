// This is a .h file for the model: gear12_1

#ifndef gear12_1_H
#define gear12_1_H
#include "model.h"
namespace Models {
	namespace Gear12_1_Internal {
		extern float vertices[];
		extern float normals[];
		extern float vertexNormals[];
		extern float texCoords[];
		//extern float colors[];
		extern unsigned int vertexCount;
	}

	class Gear12_1: public Model {
		public:
			Gear12_1();
			virtual ~Gear12_1();
			virtual void drawSolid();
	};

	extern Gear12_1 gear12_1;
}
#endif
