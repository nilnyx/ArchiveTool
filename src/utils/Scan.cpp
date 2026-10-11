#include "Scan.h"

#include <iostream>
#include <unordered_map>


namespace fs = std::filesystem;

ScanResult scan(const std::filesystem::path &path) {
	ScanResult result{};
	try {
		for (const auto& entry : fs::recursive_directory_iterator(path)) {
			if (entry.is_regular_file()) {
				const uintmax_t size = entry.file_size();

				result.bytes += size;

				result.files.push_back({ entry.path().filename().wstring(), size });

				if (!entry.path().extension().empty())
					result.extensions[entry.path().extension().string()]++;
			}
		}
		return result;
	} catch (const fs::filesystem_error& e) {
		std::cerr << "\n" << e.what() << "\n\n";
		return result;
	}
}
