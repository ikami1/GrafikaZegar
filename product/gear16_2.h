// This is a .h file for the model: gear16_2

#ifndef gear16_2_H
#define gear16_2_H
#include "model.h"
namespace Models {
	namespace Gear16_2_Internal {
		extern float vertices[];
		extern float normals[];
		extern float vertexNormals[];
		extern float texCoords[];
//		extern float colors[];
		extern unsigned int vertexCount;
	}

	class Gear16_2: public Model {
		public:
			Gear16_2();
			virtual ~Gear16_2();
			virtual void drawSolid();
	};

	extern Gear16_2 gear16_2;
}
#endif
