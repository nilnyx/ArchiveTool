#include <filesystem>
#include <string>
#include <iostream>

#include "Find.h"


namespace fs = std::filesystem;

std::vector<FileInfo> find(fs::path path, char* target) {
	std::vector<FileInfo> result{};
	try {
		for (const auto &entry : fs::recursive_directory_iterator(path)) {
			if (!entry.is_regular_file()) continue;
			if (entry.path().filename() == target) {
				fs::path entryPath = entry.path();
				result.push_back({
					       entryPath,
					    entryPath.filename().wstring(),
					entryPath.extension().string(),
					entry.file_size()
				});
			}
		}
	}
	catch (const fs::filesystem_error& e) {
		std::cerr << "\n" << e.what() << "\n\n";
		return result;
	}
	return result;
}