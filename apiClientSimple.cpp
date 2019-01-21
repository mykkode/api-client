//
// Created by mykkode on 19.01.2019.
//
#include "apiClientSimple.hpp"
#include <sstream>
size_t  apiClientSimple::parseHeaderElement(char *buffer, size_t size, size_t nitems, void *userdata) {
    auto * theResponse = (apiClientResponse *) userdata;
    size_t length;
    length = nitems * size;

    char * target;
    target = (char *)memchr( buffer, ':', nitems);
    if(target != nullptr){
        *target = 0;
        if(target + 2 < buffer + length -1) {
            target += 2;
        }
        theResponse -> headerInsert(buffer, target);
    }
    else {
        target = (char *)memchr( buffer, ' ', nitems);
        if(target != nullptr) {
            int httpCode = (target[1] -'0') * 100 + (target[2] -'0')*10 + (target[3] -'0');
            theResponse -> headerInsert("HTTP", std::to_string(httpCode ) + " ");
        }

    }
    return length;
}
size_t apiClientSimple::writeResponse(char *ptr, size_t size, size_t nmemb, void *userdata) {
    auto * theResponse = (apiClientResponse *) userdata;
    size_t length;
    length = nmemb * size;

    theResponse->appendResponse(ptr, length);

    return length;
}
bool apiClientSimple::initialized = false;

apiClientSimple::apiClientSimple() {
    if(!initialized){
        throw(apiClientException(apiClientException::API_CLIENT_EXCEPTION_NOT_INITIALIZED));
    }
    handler  = curl_easy_init();
    if(handler == nullptr){
        throw(apiClientException(apiClientException::API_CLIENT_EXCEPTION_ERROR_INITIALIZING));
    }
    curl_easy_setopt(handler, CURLOPT_HEADERFUNCTION, apiClientSimple::parseHeaderElement);
    curl_easy_setopt(handler, CURLOPT_WRITEFUNCTION, writeResponse);
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

void apiClientSimple::setUrl(std::string newUrl) {
    url = newUrl;

    std::string::iterator it = url.end() - 1;
    if(*it == '/'){
        url.pop_back();
    }
    curl_easy_setopt(handler, CURLOPT_URL, (url + endpoint) . c_str());
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
    struct curl_slist *headers = nullptr;
    for(int i = 0; i<numberOfHeaders; i++){
        headers = curl_slist_append(headers, (newHeader[i]).c_str());
    }
}

void apiClientSimple::reset() {
    curl_easy_reset(handler);
}

apiClientResponse * apiClientSimple::apiDelete() {
    CURLcode errCode;
    auto theResponse = new apiClientResponse();
    curl_easy_setopt(handler, CURLOPT_HEADERDATA, theResponse);
    curl_easy_setopt(handler, CURLOPT_WRITEDATA, theResponse);
    curl_easy_setopt(handler, CURLOPT_CUSTOMREQUEST, "DELETE");

    errCode = curl_easy_perform(handler);

    if(errCode != CURLE_OK) {
        throw (apiClientException(apiClientException::API_CLIENT_EXCEPTION_WHILE_PERFORMING));
    }
    return theResponse;
}
apiClientResponse * apiClientSimple::apiGet() {
    CURLcode errCode;
    auto theResponse = new apiClientResponse();
    curl_easy_setopt(handler, CURLOPT_HEADERDATA, theResponse);
    curl_easy_setopt(handler, CURLOPT_WRITEDATA, theResponse);
    curl_easy_setopt(handler, CURLOPT_HTTPGET, 1L);

    errCode = curl_easy_perform(handler);

    if(errCode != CURLE_OK) {
        throw (apiClientException(apiClientException::API_CLIENT_EXCEPTION_WHILE_PERFORMING));
    }
    return theResponse;
}
apiClientResponse * apiClientSimple::apiPost(std::string postData) {
    CURLcode errCode;
    auto theResponse = new apiClientResponse();
    curl_easy_setopt(handler, CURLOPT_HEADERDATA, theResponse);
    curl_easy_setopt(handler, CURLOPT_WRITEDATA, theResponse);

    curl_easy_setopt(handler, CURLOPT_POST, 1L);
    curl_easy_setopt(handler, CURLOPT_POSTFIELDS, postData.c_str());

    errCode = curl_easy_perform(handler);

    if(errCode != CURLE_OK) {
        throw (apiClientException(apiClientException::API_CLIENT_EXCEPTION_WHILE_PERFORMING));
    }
    return theResponse;
}
apiClientResponse *  apiClientSimple::apiPut() {

}
apiClientResponse * apiClientSimple::apiPatch(std::string patchData) {
    CURLcode errCode;
    auto theResponse = new apiClientResponse();
    curl_easy_setopt(handler, CURLOPT_HEADERDATA, theResponse);
    curl_easy_setopt(handler, CURLOPT_WRITEDATA, theResponse);

    curl_easy_setopt(handler, CURLOPT_CUSTOMREQUEST, "PATCH");
    curl_easy_setopt(handler, CURLOPT_POSTFIELDS, patchData.c_str());

    errCode = curl_easy_perform(handler);

    if(errCode != CURLE_OK) {
        throw (apiClientException(apiClientException::API_CLIENT_EXCEPTION_WHILE_PERFORMING));
    }
    return theResponse;
}

apiClientSimple::~apiClientSimple() {
    curl_easy_cleanup(handler);
}