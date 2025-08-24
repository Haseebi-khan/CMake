#include <iostream>
#include <GLFW/glfw3.h>
#include <OptionalLibConfig.h>
#ifdef USE_ADDER
    #include <adder.h>
#endif

using namespace std;

int main(int argc, char *argv[])
{
    // cout << "Haseeb khan\n";
    #ifdef USE_ADDER
        cout << "Using Adder lib: " << haseebMath::add(23, 44) << endl;
    #else
        cout << "Without using Adder lib, Value: " << (23 + 44) << endl;
    #endif
    cout << argv[0] << " VERSION: " << optionalLib_VERSION_MAJOR << "." << optionalLib_VERSION_MINOR << endl;

    return 0;
}