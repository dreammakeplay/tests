// TestGLES.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <memory>

#include "egl/egl.h"
#include "gles3/gl32.h"

#include "eglwindow.h"


//#pragma comment(lib, "libEGL.dll.lib")
//#pragma comment(lib, "libGLESv2.dll.lib")


int main()
{
   std::shared_ptr<EGLWindow> window = std::make_shared<EGLWindow>();
   window->create(L"gles window", 640, 480);
   
   while (window->poll())
   {

   }

}

