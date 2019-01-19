//
// Created by mykkode on 19.01.2019.
//

#include "apiClientSimple.hpp"
#include "apiClientException.hpp"

apiClientSimple::apiClientSimple() {
    if(!initialized){
        throw(apiClientException(apiClientException::API_CLIENT_EXCEPTION_NOT_INITIALIZED));
    }
}
void apiClientSimple::initialize() {
    apiClientException::initialize();
    if(!initialized){
        curl_global_init(CURL_GLOBAL_ALL);
        initialized = true;
    }
}
void apiClientSimple::deinitialize() {
    initialized = false;
    curl_global_cleanup();
}