#pragma once

#include <filesystem>
#include <unordered_map>
#include <string>
#include <vector>

struct FileInfo {
	std::wstring name;
	uintmax_t size;
};

struct ScanResult {
	std::vector<FileInfo> files;
	std::unordered_map<std::string, int> extensions;
	uintmax_t bytes;
};


ScanResult scan(const std::filesystem::path& path);
