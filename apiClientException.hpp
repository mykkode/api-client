//
// Created by mykkode on 19.01.2019.
//

#ifndef TEST_APICLIENTEXCEPTIONS_HPP
#define TEST_APICLIENTEXCEPTIONS_HPP


#include <exception>
#include <string>

class apiClientException {
public:
    apiClientException();
    explicit apiClientException(const int exceptionNumber);

    enum API_CLIENT_EXCEPTIONS {
        API_CLIENT_EXCEPTION_NOT_INITIALIZED,
        API_CLIENT_EXCEPTION_UNKNOWN,
    };

    static void initialize();
    const std::string& what() const;

private:
    int thisException;
    static bool initalized;
    static std::string descriptions[API_CLIENT_EXCEPTION_UNKNOWN + 1];
};


#endif //TEST_APICLIENTEXCEPTIONS_HPP
