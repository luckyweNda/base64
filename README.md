# base64
cpp base64 encode and decode library.

## compile in linux:
```
git clone https://github.com/luckyweNda/base64.git
cd base64;
make
```

## usage
```cpp
#include <iostream>
#include <cialloo/base64.hpp>

using namespace std;
using namespace cialloo;

int main()
{
    string a{"abc"};
    string b{"YWJjZGVmZw=="};
    base64::encode(a);
    base64::decode(b);
}
```