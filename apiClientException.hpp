//
// Created by mykkode on 19.01.2019.
//

#ifndef TEST_APICLIENTEXCEPTIONS_HPP
#define TEST_APICLIENTEXCEPTIONS_HPP

#include <string>

class apiClientException {
public:
    apiClientException();
    apiClientException(int exceptionNumber);

    enum API_CLIENT_EXCEPTIONS {
        API_CLIENT_EXCEPTION_NOT_INITIALIZED,
        API_CLIENT_EXCEPTION_ERROR_INITIALIZING,
        API_CLIENT_EXCEPTION_WHILE_PERFORMING,
        API_CLIENT_EXCEPTION_UNKNOWN,
    };

    static void initialize();
    const std::string& what() const;

    static bool initalized;
    static std::string descriptions[API_CLIENT_EXCEPTION_UNKNOWN+1];
private:
    int thisException;
};


#endif //TEST_APICLIENTEXCEPTIONS_HPP
