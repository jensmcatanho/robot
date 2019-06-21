#ifndef CORE_H
#define CORE_H

#include <memory>

#include "Prerequisites.h"

class Core {
	public:
		Core();

		void Setup() const;

		void Run();

	private:
		std::shared_ptr<Window> m_Window;
};

#endif