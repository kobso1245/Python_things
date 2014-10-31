#include <GL/glfw.h>

int main()
{
    int     width, height;
    bool    running = true;

    //
    // Инициализация на GLFW
    //
    glfwInit();

    //
    // Инициализация и отваряне на графичен позорец
    //
    if( !glfwOpenWindow( 512, 512, 0, 0, 0, 0, 0, 0, GLFW_WINDOW ) )
    {
        glfwTerminate();
        return 0;
    }

    glfwSetWindowTitle("GLFW Application");

    glfwGetWindowSize( &width, &height );
    height = height > 0 ? height : 1;

    glViewport( 0, 0, width, height );
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );

    //
    // Еднократно установяване на вида на проекция
    //
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 65.0f, (GLfloat)width/(GLfloat)height, 1.0f, 100.0f );

    //
    // Еднократно установяване на гледната точка
    //
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(0.0f, -10.0f, 0.0f,
            0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f );

    //
    // Основен цикъл на анимацията за
    // генериране на кадър по кадър
    //
    while(running)
    {
        //
        // Изчистване на работните буфери
        //
        glClear( GL_COLOR_BUFFER_BIT );

        //
        // Рисуване на един кадър в скрит буфер
        //
        glRotatef(1, 0.25f, 1.0f, 0.75f);
        glBegin( GL_TRIANGLES );
          glColor3f(0.1f, 0.0f, 0.0f );
          glVertex3f(0.0f, 3.0f, -4.0f);
          glColor3f(0.0f, 1.0f, 0.0f );
          glVertex3f(3.0f, -2.0f, -4.0f);
          glColor3f(0.0f, 0.0f, 1.0f );
          glVertex3f(-3.0f, -2.0f, -4.0f);
        glEnd();
        glBegin( GL_TRIANGLES );
          glColor3f(0.0f, 0.1f, 0.0f );
          glVertex3f(0.0f, 3.0f, -3.0f);
          glColor3f(0.0f, 0.0f, 1.0f );
          glVertex3f(3.0f, -2.0f, -2.0f);
          glColor3f(1.0f, 0.0f, 0.0f );
          glVertex3f(-3.0f, -2.0f, 2.0f);
        glEnd();

        //
        // Подмяна на скрития буфер с видимия
        //
        glfwSwapBuffers();

        // exit if ESC was pressed or window was closed
        running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam( GLFW_OPENED);
    }

    //
    // Приключване на работата
    //
    glfwTerminate();

    return 0;
}
