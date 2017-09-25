// This is a .h file for the model: clockFace

#ifndef clockFace_H
#define clockFace_H
#include "model.h"
namespace Models {
	namespace ClockFace_Internal {
		extern float vertices[];
		extern float normals[];
		extern float vertexNormals[];
		extern float texCoords[];
//		extern float colors[];
		extern unsigned int vertexCount;
	}

	class ClockFace: public Model {
		public:
			ClockFace();
			virtual ~ClockFace();
			virtual void drawSolid();
	};

	extern ClockFace clockFace;
}
#endif
