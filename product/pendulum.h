// This is a .h file for the model: pendulum

#ifndef pendulum_H
#define pendulum_H
#include "model.h"
namespace Models {
	namespace Pendulum_Internal {
		extern float vertices[];
		extern float normals[];
		extern float vertexNormals[];
		extern float texCoords[];
//		extern float colors[];
		extern unsigned int vertexCount;
	}

	class Pendulum: public Model {
		public:
			Pendulum();
			virtual ~Pendulum();
			virtual void drawSolid();
	};

	extern Pendulum pendulum;
}
#endif
