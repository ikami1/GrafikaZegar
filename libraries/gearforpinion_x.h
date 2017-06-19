// This is a .h file for the model: gearforpinion_x

#ifndef gearforpinion_x_H
#define gearforpinion_x_H
#include "model.h"
namespace Models {
	namespace Gearforpinion_x_Internal {
		extern float vertices[];
		extern float normals[];
		extern float vertexNormals[];
		extern float texCoords[];
		extern float colors[];
		extern unsigned int vertexCount;
	}

	class Gearforpinion_x: public Model {
		public:
			Gearforpinion_x();
			virtual ~Gearforpinion_x();
			virtual void drawSolid();
	};

	extern Gearforpinion_x gearforpinion_x;
}
#endif
