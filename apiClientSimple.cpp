//
// Created by mykkode on 19.01.2019.
//

#include "apiClientException.hpp"
#include "apiClientSimple.hpp"

#include <iostream>

bool apiClientSimple::initialized = 0;

apiClientSimple::apiClientSimple() {
    if(!initialized){
        throw(apiClientException(apiClientException::API_CLIENT_EXCEPTION_NOT_INITIALIZED));
    }
    handler  = curl_easy_init();
    if(handler == NULL){
        throw(apiClientException(apiClientException::API_CLIENT_EXCEPTION_ERROR_INITIALIZING));
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

void apiClientSimple::setUrl(const std::string newUrl) {
    url = newUrl;

    std::string::iterator it = url.end() - 1;
    if(*it == '/'){
        url.pop_back();
    }
    curl_easy_setopt(handler, CURLOPT_URL, url + endpoint . c_str());
}

void apiClientSimple::setEndpoint(const std::string newEndpoint) {
    endpoint = newEndpoint;

    std::string::iterator it = endpoint.begin();
    if(*it != '/'){
        endpoint.insert(it, '/');
    }
    curl_easy_setopt(handler, CURLOPT_URL, (url + endpoint) . c_str());
}

void apiClientSimple::modifyHeader(const std::string newHeader[], int numberOfHeaders){
    struct curl_slist *headers = NULL;
    for(int i = 0; i<numberOfHeaders; i++){
        headers = curl_slist_append(headers, (newHeader[i]).c_str());
    }
}

void apiClientSimple::reset() {
    curl_easy_reset(handler);
}

void apiClientSimple::apiDelete() {

}
void apiClientSimple::apiGet() {
    resource = curl_easy_perform(handler);
    if(resource != CURLE_OK) {
        throw (apiClientException(apiClientException::API_CLIENT_EXCEPTION_WHILE_PERFORMING));
    }
}
void apiClientSimple::apiPost() {

}
void apiClientSimple::apiPut() {

}
void apiClientSimple::apiPatch() {

}