#include <iostream>
#include <adder.h>
#include <GLFW/glfw3.h>
#include <p5Config.h>

using namespace std;

// chmod +x build.sh configure.ch run.sh

// for Windows
// ------------------
// bash build.sh
// bash configure.ch
// bash run.sh
// ------------------


int main(int argc, char* argv[] )
{
    cout << "Haseeb Khan."<< endl;    

    cout << argv[0] << " VERSION " << p5_VERSION_MAJOR << "." << p5_VERSION_MINOR << endl;

    GLFWwindow *window;
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }

    window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );

    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }
    while( !glfwWindowShouldClose(window) )
    {
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}