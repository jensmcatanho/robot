#ifndef CORE_H
#define CORE_H

#include "Prerequisites.h"

class Core {
	public:
		Core();

		GLboolean Setup() const;

		void Run();

	private:
		std::shared_ptr<Window> m_Window;
};

#endif