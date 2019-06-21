#include "Core.h"

int main(int argc, char **argv) {
	auto core = std::make_shared<Core>();

	core->Setup();
	core->Run();

	return 0;
}