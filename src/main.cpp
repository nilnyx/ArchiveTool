#include <filesystem>
#include <iostream>

#include "utils/FormatSize.h"
#include "utils/Scan.h"
#include "utils/Find.h"
#include "utils/Info.h"


int main(int args, char* argv[]) {
	if (args < 3) {
		std::cout << "Usage: /.ArchiveTool.exe <command> <flags>";
		return EXIT_FAILURE;
	}

	if (std::string(argv[1]) == "scan") {
		const ScanResult result = scan(argv[2]);

		const auto size = formatSize(result.bytes);

		std::cout << "Files by extensions: " << std::endl;
		for (const auto& extension : result.extensions) {
			std::cout << '"' << extension.first << '"' << " -> " << extension.second << std::endl;
		}

		std::cout << "Regular files: " << result.files.size() << std::endl;
		std::cout << "Size: " << size.first << ' ' << size.second << std::endl;
		return EXIT_SUCCESS;
	}
	if (std::string(argv[1]) == "find") {
		const auto result = find(argv[2], argv[3]);

		for (const auto &file : result) {
			std::wcout << "Found: " << file.path << std::endl;
		}
		std::cout << "\n\nMatches: " << result.size() << std::endl;
	}
	if (std::string(argv[1]) == "info") {
		const auto result = info(argv[2]);

		const auto size = formatSize(result.bytes);

		std::wcout << "File: " << result.name << std::endl;
		std::wcout << "Path: " << result.path << std::endl;
		std::cout << "Extension: " << result.extension << std::endl;
		std::cout << "Size: " << size.first << ' ' << size.second << std::endl;
	}

	return EXIT_SUCCESS;
}
