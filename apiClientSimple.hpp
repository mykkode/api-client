//
// Created by mykkode on 19.01.2019.
//

#ifndef TEST_APICLIENTSIMPLE_HPP
#define TEST_APICLIENTSIMPLE_HPP

#include <curl/curl.h>
#include "vendor/nlohmann/json.hpp"

class apiClientSimple {
private:

CURL * handler;
std::string url;
std::string endpoint;
CURLcode resource;
public:
    static bool initialized;
    apiClientSimple();
    static void initialize();
    static void deinitialize();
    void setUrl(const std::string newUrl);
    void setEndpoint(const std::string newEndpoint);
    void modifyHeader(const std::string newHeader[], int numberOfHeaders);
    void reset();
    void apiGet();
    void apiPost();
    void apiPut();
    void apiPatch();
    void apiDelete();
};


#endif //TEST_APICLIENTSIMPLE_HPP
