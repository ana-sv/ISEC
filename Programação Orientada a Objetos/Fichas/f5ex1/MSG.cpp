/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MSG.cpp
 * Author: Ana Rita
 * 
 * Created on 2 de dezembro de 2020, 12:12
 */


// int * p = new int; -> aloca 1 inteiro;
// ABC *P = new ABC("ola");
// delete p;  -> liberta 1 inteiro



#include "MSG.h"

#include <cstdlib>
using namespace std;

MSG::MSG(const char *p ) {
    cout << "ola" << p << endl;
}

MSG::MSG(const MSG& orig) {
}

MSG::~MSG() {
    cout << "Adeus!" endl; 
}

