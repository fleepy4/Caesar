#include <string>
#include <vector>

namespace decryption {
	std::string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ,!.:;%*@ ";

	std::string caesar_decryption(std::string target_text, uint32_t step) {
		if (step > 25) {
			return "ERROR: STEP MUST NOT BE BIGGER THEN 25";
		}
		std::string output = "";
		std::vector<uint32_t> new_positions;
		for (int i = 0; i < target_text.length(); i++) {
			int new_pos = alphabet.find(target_text[i]) - step;
			if (new_pos < 0) {
				new_pos = new_pos + 71;
			}
			new_positions.push_back(new_pos);
		}


		for (int i = 0; i < new_positions.size(); i++) {
			output += alphabet[new_positions[i]];
		}

		return output;
	}
}