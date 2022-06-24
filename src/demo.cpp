#include <iostream>
#include <cialloo/base64.hpp>

int main(int argc, char* argv[])
{
    std::string a{"abc"}, b{"abcd"};
    std::string c = cialloo::base64::encode(a), d = cialloo::base64::encode(b);
    std::cout << "\'abc\' after encode: " << c << std::endl
              << "\'abcd\' after encode: " << d << std::endl
              << c << " after decode: " << cialloo::base64::decode(c) << std::endl
              << d << " after decode: " << cialloo::base64::decode(d) << std::endl;

    return 0;
}