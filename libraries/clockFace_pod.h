// This is a .h file for the model: clockFace_pod

#ifndef clockFace_pod_H
#define clockFace_pod_H
#include "model.h"
namespace Models {
	namespace ClockFace_pod_Internal {
		extern float vertices[];
		extern float normals[];
		extern float vertexNormals[];
		extern float texCoords[];
//		extern float colors[];
		extern unsigned int vertexCount;
	}

	class ClockFace_pod: public Model {
		public:
			ClockFace_pod();
			virtual ~ClockFace_pod();
			virtual void drawSolid();
	};

	extern ClockFace_pod clockFace_pod;
}
#endif
