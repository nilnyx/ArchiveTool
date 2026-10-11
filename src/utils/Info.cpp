#include "Info.h"

#include <iostream>

#include "Scan.h"

namespace fs = std::filesystem;

FileInfo info(const fs::path& path) {
	if (fs::is_directory(path)) {
		std::cerr << path.string() << " is not a file." << std::endl;
		return{};
	}

	FileInfo result{};

	if (fs::is_regular_file(path)) {
		result.name = path.filename();
		result.path = path;
		result.extension = path.extension().string();
		result.bytes = fs::file_size(path);
	}
	

	return result;
}
