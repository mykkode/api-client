#include "apiClientSimple.hpp"
#include "apiClientException.hpp"

#include <iostream>

int main() {
    apiClientSimple::initialize();

    apiClientSimple * myApi = new apiClientSimple ();
    myApi->setUrl("https://5bca34d3-506c-45c5-8c6e-23ae85009a7d.mock.pstmn.io");
    myApi->setEndpoint("/home");
    try{
        myApi->apiGet();
    }
    catch(apiClientException & e) {
        std::cout <<e.what();
    }
    apiClientSimple::deinitialize();
}