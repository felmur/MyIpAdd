# MyIpAdd
Pure c++ library which determines our public ip address - no external dependencies

# Usage

```
#include <iostream>
#include <myipadd.h>
using namespace std;
int main()
{
    MyIpAdd * m = new MyIpAdd();
    cout << "My public ip address is: '" << m->ip << "'" << endl;
    return 0;
}
```
see /test directory

