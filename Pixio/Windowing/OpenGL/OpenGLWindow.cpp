#include "Pixio/Windowing/OpenGL/OpenGLWindow.h"
#include <cstring>

#include <iostream>
#include <map>
#include <GL/freeglut.h>
using namespace std;

static map<int, OpenGLWindow*> windows;

bool OpenGLWindow::init = false;

void OpenGLWindow::render()
{
    int i = glutGetWindow();
    windows[i]->onRender();
}

void OpenGLWindow::mouseEvent(int button, int state, int x, int y)
{
    int i = glutGetWindow();
    windows[i]->onMouseEvent(button, state, x, y);
}

void OpenGLWindow::keyboardEvent(unsigned char c, int x, int y)
{
    int i = glutGetWindow();
    windows[i]->onKeyboardEvent(c, x, y);
}

void OpenGLWindow::mouseMove(int x, int y)
{
    int i = glutGetWindow();
    windows[i]->onMouseMove(x, y);
}

OpenGLWindow::OpenGLWindow(IApplication& app, const CanvasAttributes& attr) : attr(attr), app(app)
{
    if (!init)
    {
        int argc = 1;
        char* argv = _strdup("Application");
        
        glutInit(&argc, &argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

        init = true;
    }

    glutInitWindowSize(static_cast<int>(attr.size.x), static_cast<int>(attr.size.y));
    glutInitWindowPosition(static_cast<int>(attr.position.x), static_cast<int>(attr.position.y));
    window = glutCreateWindow(attr.name.c_str());
    windows[window] = this; 
    glutMouseFunc(OpenGLWindow::mouseEvent);
    glutKeyboardFunc(OpenGLWindow::keyboardEvent);
    glutDisplayFunc(OpenGLWindow::render);
    glutMotionFunc(OpenGLWindow::mouseMove);
    glutPassiveMotionFunc(OpenGLWindow::mouseMove);
}

OpenGLWindow::~OpenGLWindow()
{
    glutDestroyWindow(window);
}

void OpenGLWindow::startRenderLoop()
{
    app.onInit();
    glutMainLoop();
    app.onDestroy();    
}

unsigned int OpenGLWindow::getWidth() const
{
    return static_cast<unsigned int>(attr.size.x);
}

unsigned int OpenGLWindow::getHeight() const
{
    return static_cast<unsigned int>(attr.size.y);
}

unsigned int OpenGLWindow::getBufferSize() const
{
    return static_cast<unsigned int>(attr.size.x * attr.size.y) * 4;
}

void OpenGLWindow::onRender()
{
    //TODO: calculate delta
    app.onRender(0.016f);
    glutSwapBuffers();
    glutPostRedisplay();
}

void OpenGLWindow::onMouseEvent(int button, int state, int x, int y)
{
    app.onMouseEvent(x, y, button, state, 0);
}

void OpenGLWindow::onKeyboardEvent(unsigned char c, int x, int y)
{
    app.onKeyboardEvent(c, x, y);
}

void OpenGLWindow::onMouseMove(int x, int y)
{
    app.onMouseMove(x, y, 0, 0);
}