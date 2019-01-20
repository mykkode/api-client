//
// Created by mykkode on 19.01.2019.
//

#include "apiClientException.hpp"

std::string apiClientException::descriptions[API_CLIENT_EXCEPTION_UNKNOWN+1];
bool apiClientException::initalized = 0;

apiClientException::apiClientException() {
    thisException = API_CLIENT_EXCEPTION_UNKNOWN;
}

apiClientException::apiClientException(int exceptionNumber) {
    if(exceptionNumber > API_CLIENT_EXCEPTION_UNKNOWN || exceptionNumber < 0) {
        thisException = API_CLIENT_EXCEPTION_UNKNOWN;
    }
    else{
        thisException = exceptionNumber;
    }

}

void apiClientException::initialize() {
    if(!initalized){
        descriptions[API_CLIENT_EXCEPTION_NOT_INITIALIZED] = "API_CLIENT_EXCEPTION_NOT_INITIALIZED: Not initialized!";
        descriptions[API_CLIENT_EXCEPTION_UNKNOWN] = "API_CLIENT_EXCEPTION_UNKNOWN: Unknown Exception!";
        descriptions[API_CLIENT_EXCEPTION_ERROR_INITIALIZING] = "API_CLIENT_EXCEPTION_ERROR_INITIALIZING: There was an error while initializing";
        descriptions[API_CLIENT_EXCEPTION_WHILE_PERFORMING] = "API_CLIENT_EXCEPTION_WHILE_PERFORMING: There was an error while executing your request";
        initalized = true;
    }
}

const std::string& apiClientException::what() const {
    return descriptions[thisException];
}



