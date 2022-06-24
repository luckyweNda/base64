#ifndef CIALLOO_BASE64_H
#define CIALLOO_BASE64_H

#include <string>
#include <bitset>

namespace cialloo {
namespace base64 {

std::string encode(const std::string value);
std::string decode(const std::string value);

class encoder
{
private:
public:
    encoder(){};
    ~encoder(){};

    std::string encode(const std::string value){return cialloo::base64::encode(value);};
};

class decoder
{
private:
public:
    decoder(){};
    ~decoder(){};

    std::string decode(const std::string value){return cialloo::base64::decode(value);};
};

} // namespace base64
} // namespace cialloo


#endif