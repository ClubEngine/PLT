#include <iostream>


#include "server.hpp"


using namespace std;






int main(int argc, char ** argv) {

    cout << endl << "PLT Server " << __DATE__ << " at " << __TIME__ << endl;

    Server server;

    server.run();

    return 0;
}

