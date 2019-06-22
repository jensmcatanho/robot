#include "Core.h"

int main(int argc, char **argv) {
	auto core = std::make_shared<Core>();

	if (!core->Setup()) {
		std::cout << "Error: Failed to setup rendering." << std::endl;
		return EXIT_FAILURE;
	}

	core->Run();

	return EXIT_SUCCESS;
}