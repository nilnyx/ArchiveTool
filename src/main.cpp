#include <filesystem>
#include "utils/Scan.h"


int main(int args, char* argv[]) {
	if (std::string(argv[1]) == "scan") {
		scan(args, argv[2]);
	}

	return EXIT_SUCCESS;
}
