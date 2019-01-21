#include "apiClientSimple.hpp"
#include "apiClientException.hpp"
#include "apiClientResponse.hpp"

#include <iostream>
#include <fstream>

std::ofstream f("poza2.jpg");
int main() {
    apiClientSimple::initialize();

    apiClientSimple * myApi = new apiClientSimple ();
    myApi->setUrl("http://localhost:3000");
    apiClientResponse * respose;
    try{
        myApi->setEndpoint("/photo");
        respose = myApi->apiGet();
        std::string image = respose->getBody();
        f<<image;
        delete respose;

        myApi->setEndpoint("/users");
        respose = myApi->apiPost("user=dolph");
        std::cout<<std::endl;
        std::cout<<respose->getBody();
        delete respose;

        myApi->setEndpoint("/users/1");
        respose = myApi->apiPatch("user=dolphModified");
        std::cout<<std::endl;
        std::cout<<respose->getBody();
        delete respose;
//
        myApi->setEndpoint("/users/1");
        respose = myApi->apiDelete();
        std::cout<<std::endl;
        std::cout<<respose->getBody();
        delete respose;
    }
    catch(apiClientException & e) {
        std::cout <<e.what();
    }
    apiClientSimple::deinitialize();

    delete myApi;
}