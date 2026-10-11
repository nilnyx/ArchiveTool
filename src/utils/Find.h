#pragma once

#include <string>

#include "Scan.h"


std::vector<FileInfo> find(std::filesystem::path path, char* target);
