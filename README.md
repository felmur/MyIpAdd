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
Please, see /test directory

# Installation

```
$> cmake .
$> make
$> sudo make install
```

# Uninstallation

Go into compilation directory:

```
$> sudo xargs rm < install_manifest.txt
```

