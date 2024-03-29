#ifndef IDRAWABLE_H
#define IDRAWABLE_H

#include "Prerequisites.h"

class IDrawable {
	public:
		virtual void Init(GLuint) = 0;

		virtual void Draw(glm::mat4) const = 0;
};

#endif