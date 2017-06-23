// This is a .h file for the model: gear20_2

#ifndef gear20_2_H
#define gear20_2_H
#include "model.h"
namespace Models {
	namespace Gear20_2_Internal {
		extern float vertices[];
		extern float normals[];
		extern float vertexNormals[];
		extern float texCoords[];
//		extern float colors[];
		extern unsigned int vertexCount;
	}

	class Gear20_2: public Model {
		public:
			Gear20_2();
			virtual ~Gear20_2();
			virtual void drawSolid();
	};

	extern Gear20_2 gear20_2;
}
#endif
