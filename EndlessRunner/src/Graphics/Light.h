#ifndef FHL_LIGHT_H
#define FHL_LIGHT_H

#include <glm/glm.hpp>

#include "Color.h"

namespace fhl
{

	 struct Light
	 {
		  enum Type
		  {
				Directional = 0,
				Point,
				Spot
		  };

		  Light();

		  Vec3f position, direction;
		  Color color;
		  float linear, quadratic;
		  float cutOffAngle;
		  float illuminance;
		  Type type;
	 };

} // ns

#endif // FHL_LIGHT_H
