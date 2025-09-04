#include <iostream>
#include "p7Config.h"
using namespace std;

#ifdef USE_ADDER 
    #include <adder.h>
#endif



int main(int argc, char *argv[])
{   

    cout << "\n\n"<<argv[0] << " VERSION : " << p7_VERSION_MAJOR << "." << p7_VERSION_MINOR << endl;

    #ifdef USE_ADDER

        cout << "\n\n\n\n"<< haseebMath::add(34,45)<<endl;
        cout << haseebMath::add(23,34);

    #endif
    
    cout << "Adder Library is not used."<<endl;

    return 0;
}