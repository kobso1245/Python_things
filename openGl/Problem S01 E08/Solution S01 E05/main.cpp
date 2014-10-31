
#include <iostream>
#include <GL/glfw.h>

using namespace std;

int main()
{
    int     major, minor, rev;

    glfwInit();
    glfwGetVersion( &major, &minor, &rev );

    cout << "GLFW version: " << major << "." << minor << "." << rev << "\n";

    glfwTerminate();

    return 0;
}
