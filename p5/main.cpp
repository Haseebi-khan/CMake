#include <iostream>
#include <adder.h>
#include <GLFW/glfw3.h>


using namespace std;

// chmod +x build.sh configure.ch run.sh

// for Windows
// ------------------
// bash build.sh
// bash configure.ch
// bash run.sh
// ------------------


int main()
{
    cout << "Haseeb Khan."<< endl;    

    GLFWwindow *window;
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }

    window = glfwCreateWindow(mode->width, mode->height, "Gears", monitor, NULL);
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