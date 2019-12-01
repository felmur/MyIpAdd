/*
 * part of libMyIpAdd
 * (c) 2019 by Felice Murolo, Salerno, Italia
 * All rigths reserved
 * email: linuxboy@giove.tk
 * Released under LGPL LICENSE V 3.0
 * Please, consult LICENSE file for more informations
 *
*/

#include "myipadd.h"

template <class Container>
void split(const string& str, Container& cont, char delim = ' ')
{
    stringstream ss(str);
    string token;
    while (getline(ss, token, delim)) {
        cont.push_back(token);
    }
}

MyIpAdd::MyIpAdd()
{

    buf = static_cast<char *>(malloc(1024));

    sk = socket(AF_INET, SOCK_STREAM, 0);
    if (sk==0) {
        if (DEBUG) cout << "Socket error" << endl;
        exit(-1);
    }

    if (DEBUG) cout << "Socket creation OK" << endl;

    host = gethostbyname(addr.c_str());

    if (host == nullptr ) {
        if (DEBUG) cout << "Bad host '" << addr << "'" << endl;
        exit(-3);
    }

    addrin.sin_family = AF_INET;
    addrin.sin_port = htons(80);
    addrin.sin_addr.s_addr = *(reinterpret_cast<unsigned int*>(host->h_addr));

    if (connect(sk, reinterpret_cast<struct sockaddr *>(&addrin), sizeof(addrin))<0){
        if (DEBUG) cout << "Connection Failed" << endl;
        exit(-2);
    }

    if (DEBUG) cout << "Connection OK" << endl;

    string msg = "GET / HTTP/1.1\r\nHost: " + addr + "\r\nConnection: close\r\n\r\n";
    send(sk, msg.c_str(), msg.length(), 0);
    ssize_t ret = 0;
    string html;
    while((ret = read( sk , buf, sizeof(buf)))>0) {
        *(buf+ret) = 0;
        html += buf;
    }
    list<string> cont;
    split(html,cont,'\n');
    size_t r = 0;
    for(auto& line : cont) {
        if (line.length()>20) {
            if ((r = line.find("Current IP Address:"))!=string::npos) {
                string a = line.substr(r+20);
                a = a.substr(0,a.find("<"));
                if (DEBUG) cout << a << endl;
                ip = a;
            }
        }
    }

    close(sk);
}

