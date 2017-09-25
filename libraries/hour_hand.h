// This is a .h file for the model: hour_hand

#ifndef hour_hand_H
#define hour_hand_H
#include "model.h"
namespace Models {
	namespace Hour_hand_Internal {
		extern float vertices[];
		extern float normals[];
		extern float vertexNormals[];
		extern float texCoords[];
//		extern float colors[];
		extern unsigned int vertexCount;
	}

	class Hour_hand: public Model {
		public:
			Hour_hand();
			virtual ~Hour_hand();
			virtual void drawSolid();
	};

	extern Hour_hand hour_hand;
}
#endif
