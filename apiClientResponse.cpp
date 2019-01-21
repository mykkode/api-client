//
// Created by mykkode on 20.01.2019.
//

#include "apiClientResponse.hpp"

void apiClientResponse::headerInsert(const std::string headerName, const std::string headerValue) {
    responseHeaderMap.insert(std::pair <std::string, std::string> (headerName, headerValue));
    responseHeaderMap[headerName].pop_back();
}

void apiClientResponse::debug() {
    std::map<std::string, std::string>::iterator position;
    for(position = responseHeaderMap.begin(); position != responseHeaderMap.end(); position++){
        std::cout<< position->first << "====" <<position->second<<std::endl;
    }
}


void apiClientResponse::appendResponse(char * somethingNew, int size) {
    responseBody.append(somethingNew,size);
}

std::string& apiClientResponse::getBody() {
    return responseBody;
}

