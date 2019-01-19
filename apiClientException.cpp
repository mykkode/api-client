//
// Created by mykkode on 19.01.2019.
//

#include "apiClientException.hpp"

apiClientException::apiClientException() {
    thisException = API_CLIENT_EXCEPTION_UNKNOWN;
}

apiClientException::apiClientException(const int exceptionNumber) {
    if(exceptionNumber > API_CLIENT_EXCEPTION_UNKNOWN || exceptionNumber < 0) {
        thisException = API_CLIENT_EXCEPTION_UNKNOWN;
    }
    else{
        thisException = exceptionNumber;
    }

}

void apiClientException::initialize() {
    if(!initalized){
        apiClientException::descriptions[API_CLIENT_EXCEPTION_NOT_INITIALIZED] = "API_CLIENT_EXCEPTION_NOT_INITIALIZED: Not initialized!";
        apiClientException::descriptions[API_CLIENT_EXCEPTION_UNKNOWN] = "API_CLIENT_EXCEPTION_UNKNOWN: Unknown Exception!";
        initalized = true;
    }
}

const std::string& apiClientException::what() const {
    return descriptions[thisException];
}



