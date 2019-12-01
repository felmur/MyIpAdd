/*
 * part of libMyIpAdd
 * (c) 2019 by Felice Murolo, Salerno, Italia
 * All rigths reserved
 * email: linuxboy@giove.tk
 * Released under LGPL LICENSE V 3.0
 * Please, consult LICENSE file for more informations
 *
*/

#ifndef MYIPADD_H
#define MYIPADD_H

#define DEBUG 0

#include "MyIpAdd_global.h"
#include <stdio.h>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sstream>
#include <unistd.h>
#include <list>
#include <iterator>
#include <string>

using namespace std;

class MYIPADD_EXPORT MyIpAdd
{
public:
    MyIpAdd();
    string ip = "";

private:
    string addr = "checkip.dyndns.com";
    struct hostent *host;
    int sk = 0;
    struct sockaddr_in addrin;
    char *buf = nullptr;
};

#endif // MYIPADD_H
