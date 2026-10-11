#include <filesystem>
#include <iostream>

#include "utils/FormatSize.h"
#include "utils/Scan.h"


int main(int args, char* argv[]) {
	if (args < 3) {
		std::cout << "Usage: /.ArchiveTool.exe <command> <flags>";
		return EXIT_FAILURE;
	}

	if (std::string(argv[1]) == "scan") {
		ScanResult result = scan(argv[2]);

		const auto size = formatSize(result.bytes);

		std::cout << "Files by extensions: " << std::endl;
		for (const auto& extension : result.extensions) {
			std::cout << '"' << extension.first << '"' << " -> " << extension.second << std::endl;
		}

		std::cout << "Regular files: " << result.files.size() << std::endl;
		std::cout << "Size: " << size.first << ' ' << size.second << std::endl;
	}

	return EXIT_SUCCESS;
}
