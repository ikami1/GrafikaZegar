// This is a .h file for the model: clockBody

#ifndef clockBody_H
#define clockBody_H
#include "model.h"
namespace Models {
	namespace ClockBody_Internal {
		extern float vertices[];
		extern float normals[];
		extern float vertexNormals[];
		extern float texCoords[];
//		extern float colors[];
		extern unsigned int vertexCount;
	}

	class ClockBody: public Model {
		public:
			ClockBody();
			virtual ~ClockBody();
			virtual void drawSolid();
	};

	extern ClockBody clockBody;
}
#endif
