#include <string>
#include <bitset>
#include <cialloo/base64.hpp>

namespace {

const std::string base64_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

size_t encode_handler(uint16_t& lack_byte, std::string& char_array)
{
    lack_byte = 0;
    size_t string_size = char_array.size();
    if((string_size % 3) != 0)
        lack_byte = 3 - (string_size % 3);
    char_array.append(lack_byte, '\0');
    return char_array.size();
}

}  // static content

namespace cialloo {
namespace base64 {

std::string encode(const std::string char_array)
{
    uint16_t lack_byte;
    std::string handled_char_array{char_array};
    size_t string_size = encode_handler(lack_byte, handled_char_array);
    std::string output;

    for(int i = 0; i < string_size; i+=3)
    {
        uint32_t temp = static_cast<uint32_t>(handled_char_array[i] << 16 
                                        | handled_char_array[i + 1] << 8 
                                        | handled_char_array[i + 2]);

        for(int j = 3; j >= 0; j--)
            output.append(1, base64_table[((temp >> (j * 6)) & static_cast<uint32_t>(0b111111))]);
    }

    switch (lack_byte)
    {
        case 0:
        {
            break;
        }
        case 1:
        {
            output[output.size() - 1] = '=';
            break;
        }
        case 2:
        {
            output[output.size() - 1] = '=';
            output[output.size() - 2] = '=';
            break;
        }
    }

    return output;
}

std::string decode(const std::string char_array)
{
    uint16_t lack_byte = 0;

    std::string temp_string{char_array};

    if(temp_string.find("==") != std::string::npos)
    {
        lack_byte = 2;
        temp_string[temp_string.size() - 1] = temp_string[temp_string.size() - 2] = 'A';
    }
    else if(temp_string.find('=') != std::string::npos)
    {
        lack_byte = 1;
        temp_string[temp_string.size() - 1] = 'A';
    }

    std::string output;

    for(int i = 0; i < temp_string.size(); i+=4)
    {
        uint32_t temp = static_cast<uint32_t>(base64_table.find(temp_string[i]) << 18 
                                        | base64_table.find(temp_string[i + 1]) << 12 
                                        | base64_table.find(temp_string[i + 2]) << 6 
                                        | base64_table.find(temp_string[i + 3]));

        for(int j = 2; j >= 0; j--)
            output.append(1, static_cast<char>((temp >> (8 * j) & 0b11111111)));
    }

    return output;
}


} // namespace base64
} // namespace cialloo