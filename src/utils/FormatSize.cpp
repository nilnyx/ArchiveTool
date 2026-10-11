#include "FormatSize.h"
#include <cmath>
#include <string>
#include <cstdint>

std::pair<float, std::string> formatSize(uintmax_t bytes) {
	const float kb = round(bytes / 10.24f) / 100;
	const float mb = round(kb / 10.24f) / 100;
	const float gb = round(mb / 10.24f) / 100;
	const float tb = round(gb / 10.24f) / 100;

	if (tb >= 1) return { tb, "TB" };
	if (gb >= 1) return { gb, "GB" };
	if (mb >= 1) return { mb, "MB" };
	if (kb >= 1) return { kb, "KB" };
	return { bytes, "B" };
}
