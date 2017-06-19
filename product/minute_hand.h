// This is a .h file for the model: minute_hand

#ifndef minute_hand_H
#define minute_hand_H
#include "model.h"
namespace Models {
	namespace Minute_hand_Internal {
		extern float vertices[];
		extern float normals[];
		extern float vertexNormals[];
		extern float texCoords[];
//		extern float colors[];
		extern unsigned int vertexCount;
	}

	class Minute_hand: public Model {
		public:
			Minute_hand();
			virtual ~Minute_hand();
			virtual void drawSolid();
	};

	extern Minute_hand minute_hand;
}
#endif
