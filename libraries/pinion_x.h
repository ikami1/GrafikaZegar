// This is a .h file for the model: pinion_x

#ifndef pinion_x_H
#define pinion_x_H
#include "model.h"
namespace Models {
	namespace Pinion_x_Internal {
		extern float vertices[];
		extern float normals[];
		extern float vertexNormals[];
		extern float texCoords[];
		extern float colors[];
		extern unsigned int vertexCount;
	}

	class Pinion_x: public Model {
		public:
			Pinion_x();
			virtual ~Pinion_x();
			virtual void drawSolid();
	};

	extern Pinion_x pinion_x;
}
#endif
