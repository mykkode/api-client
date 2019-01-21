//
// Created by mykkode on 19.01.2019.
//

#ifndef TEST_APICLIENTSIMPLE_HPP
#define TEST_APICLIENTSIMPLE_HPP

#include <curl/curl.h>
#include "vendor/nlohmann/json.hpp"
#include "apiClientException.hpp"
#include "apiClientSimple.hpp"
#include "apiClientResponse.hpp"

class apiClientSimple {
private:
CURL * handler;
std::string url;
std::string endpoint;

public:
    static bool initialized;
    apiClientSimple();
    ~apiClientSimple();
    static void initialize();
    static void deinitialize();
    static size_t parseHeaderElement(char *buffer, size_t size, size_t nitems, void *userdata);
    static size_t writeResponse(char *ptr, size_t size, size_t nmemb, void *userdata);
    void setUrl(std::string newUrl);
    void setEndpoint(const std::string newEndpoint);
    void modifyHeader(const std::string newHeader[], int numberOfHeaders);
    void reset();
    apiClientResponse *  apiGet();
    apiClientResponse * apiPost(std::string);
    apiClientResponse *  apiPut();
    apiClientResponse * apiPatch(std::string);
    apiClientResponse * apiDelete();
};


#endif //TEST_APICLIENTSIMPLE_HPP
