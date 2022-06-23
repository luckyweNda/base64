#ifndef CIALLOO_BASE64_H
#define CIALLOO_BASE64_H

#include <string>
#include <bitset>

namespace cialloo {
namespace base64 {

class encoder
{
private:


public:
    encoder(){};
    ~encoder(){};

    std::string encode(std::string value);
};

class decoder
{

};


std::string encode(std::string value);
std::string decode(std::string value);

} // namespace base64
} // namespace cialloo


#endif