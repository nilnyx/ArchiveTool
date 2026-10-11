#include "Scan.h"

#include <iostream>
#include <unordered_map>

#include "FormatSize.h"


namespace fs = std::filesystem;

void scan(const int& args, const std::filesystem::path &path) {
	if (args < 3) {
		std::cout << "Usage: /.ArchiveTool.exe scan <path>";
		return;
	}

	std::vector<FileInfo> files;
	std::unordered_map<std::string, int> extensions;

	uintmax_t bytes{};

	try {
		for (const auto& entry : fs::recursive_directory_iterator(path)) {
			if (entry.is_regular_file()) {
				const uintmax_t size = entry.file_size();

				bytes += size;

				files.push_back({ entry.path().filename().wstring(), size });

				if (!entry.path().extension().empty())
					extensions[entry.path().extension().string()]++;
			}
		}
		const auto size = formatSize(bytes);

		std::cout << "Regular files: " << files.size() << std::endl;
		std::cout << "Size: " << size.first << ' ' << size.second << std::endl;
		std::cout << "Files by extensions: " << std::endl;

		for (const auto& extension : extensions) {
			std::cout << '"' << extension.first << '"' << " -> " << extension.second << std::endl;
		}
	}
	catch (const fs::filesystem_error& e) {
		std::cerr << "\n" << e.what() << "\n\n";
	}
}
