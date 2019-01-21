#include "apiClientSimple.hpp"
#include "apiClientException.hpp"
#include "apiClientResponse.hpp"

#include <iostream>
#include <fstream>

std::ofstream f("iesire.png");
int main() {
    apiClientSimple::initialize();

    apiClientSimple * myApi = new apiClientSimple ();
    myApi->setUrl("http://localhost:3000");
    myApi->setEndpoint("/answer");
    try{
        apiClientResponse * respose = myApi->apiGet();
        respose -> debug();
        std::string image = respose->getBody();
        f<<image;
        delete respose;

        myApi->setEndpoint("/dolphins");
        respose = myApi->apiPost("user=dolph");
        std::cout<<std::endl;
        std::cout<<respose->getBody();
        respose -> debug();
        delete respose;
    }
    catch(apiClientException & e) {
        std::cout <<e.what();
    }
    apiClientSimple::deinitialize();

    delete myApi;
}