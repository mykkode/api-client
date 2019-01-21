//
// Created by mykkode on 20.01.2019.
//

#ifndef TEST_APICLIENTRESPONSE_HPP
#define TEST_APICLIENTRESPONSE_HPP

#include <string>
#include <map>
#include <iostream>

class apiClientResponse {
    std::map <std::string, std::string>responseHeaderMap;
    std::string responseBody;
public:
    std::string& getBody();
    apiClientResponse() = default;
    void headerInsert(std::string, std::string);
    void appendResponse(char *, int size);
    void debug();
};


#endif //TEST_APICLIENTRESPONSE_HPP
