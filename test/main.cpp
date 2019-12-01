/*
 * part of libMyIpAdd
 * (c) 2019 by Felice Murolo, Salerno, Italia
 * All rigths reserved
 * email: linuxboy@giove.tk
 * Released under LGPL LICENSE V 3.0
 * Please, consult LICENSE file for more informations
 *
*/

#include <iostream>
#include <myipadd.h>

using namespace std;

int main()
{
    MyIpAdd * m = new MyIpAdd();

    cout << "My public ip address is: '" << m->ip << "'" << endl;

    return 0;
}
