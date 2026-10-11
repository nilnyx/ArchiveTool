#pragma once

#include <filesystem>
#include <unordered_map>
#include <string>
#include <vector>

struct FileInfo {
	std::filesystem::path path;
	std::wstring name;
	std::string extension;
	uintmax_t bytes;
};

struct ScanResult {
	std::vector<FileInfo> files;
	std::unordered_map<std::string, int> extensions;
	uintmax_t bytes;
};


ScanResult scan(const std::filesystem::path& path);
