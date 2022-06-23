#include <string>
#include <bitset>
#include <cialloo/base64.hpp>

namespace {
const char* base64_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
}  // static content

namespace cialloo {
namespace base64 {

std::string encode(std::string char_array)
{
    //=========== count

    uint16_t lack_byte = 0;
    size_t string_size = char_array.size();
    if((string_size % 3) != 0)
        lack_byte = 3 - (string_size % 3);
    char_array.append(lack_byte, '\0');
    string_size = char_array.size();

    //========== encode

    std::string output;
    
    for(int i = 0; i < string_size; i+=3)
    {
        uint32_t temp = static_cast<uint32_t>(char_array[i] << 16 | char_array[i + 1] << 8 | char_array[i + 2]);

        for(int i = 3; i >= 0; i--)
            output.append(1, base64_table[((temp >> (i * 6)) & static_cast<uint32_t>(0b111111))]);
    }

    return output;
}


} // namespace base64
} // namespace cialloo