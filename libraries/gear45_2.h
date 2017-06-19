// This is a .h file for the model: gear45_2

#ifndef gear45_2_H
#define gear45_2_H
#include "model.h"
namespace Models {
	namespace Gear45_2_Internal {
		extern float vertices[];
		extern float normals[];
		extern float vertexNormals[];
		extern float texCoords[];
		extern float colors[];
		extern unsigned int vertexCount;
	}

	class Gear45_2: public Model {
		public:
			Gear45_2();
			virtual ~Gear45_2();
			virtual void drawSolid();
	};

	extern Gear45_2 gear45_2;
}
#endif
