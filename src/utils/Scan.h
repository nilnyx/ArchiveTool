#pragma once
#include <filesystem>

struct FileInfo {
	std::wstring name;
	size_t size;
};


void scan(const int& args, const std::filesystem::path& path);
