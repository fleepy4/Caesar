#pragma once

#include <string>

namespace encryption {

	std::string caesar_encryption(std::string target_text, uint8_t step);
}