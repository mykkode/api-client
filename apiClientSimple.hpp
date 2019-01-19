//
// Created by mykkode on 19.01.2019.
//

#ifndef TEST_APICLIENTSIMPLE_HPP
#define TEST_APICLIENTSIMPLE_HPP

#include <curl/curl.h>

class apiClientSimple {
private:
static bool initialized;
public:
    apiClientSimple();
    static void initialize();
    static void deinitialize();
};


#endif //TEST_APICLIENTSIMPLE_HPP
