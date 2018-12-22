#include "pch.h"
#include "eglwindow.h"
#include "egl/egl.h"
#include "gles3/gl32.h"



EGLWindow::EGLWindow()
{
}


EGLWindow::~EGLWindow()
{
}

bool EGLWindow::create(const std::wstring name, size_t width, size_t height)
{
   m_window = std::make_shared<Window>();
   m_window->create(name, width, height);

   EGLDisplay eglDisplay;
   EGLContext eglContext;
   EGLConfig eglConfig;

   eglDisplay = eglGetDisplay((HDC)m_window->native_display());
   if (eglDisplay == EGL_NO_DISPLAY)
   {
      // error
   }

   GLint eglMinor, eglMajor;
   if (!eglInitialize(eglDisplay, &eglMajor, &eglMinor))
   {
      // error
   }

   static int configList[] = {
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT,
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_ALPHA_SIZE, 8,
        EGL_NONE
   };

   EGLint numConfig;

   if (!eglGetConfigs(eglDisplay, NULL, 0, &numConfig))
   {
      // error
   }

   if (!eglChooseConfig(eglDisplay, configList, &eglConfig, 1, &numConfig))
   {
      // error
   }

   if (numConfig != 1)
   {
      // error
   }

   if (!eglBindAPI(EGL_OPENGL_ES_API))
   {
      // error
   }

   EGLint contextAtrrList[] = {
        EGL_CONTEXT_CLIENT_VERSION, 2,
        EGL_NONE
   };

   eglContext = eglCreateContext(eglDisplay, eglConfig, EGL_NO_CONTEXT, contextAtrrList);
   if (eglContext == EGL_NO_CONTEXT)
   {
      // error
   }

   EGLSurface eglSurface = eglCreateWindowSurface(eglDisplay, eglConfig, (HWND)m_window->native_window(), NULL);
   if (eglSurface == EGL_NO_SURFACE)
   {
      // error
   }

   if (!eglMakeCurrent(eglDisplay, eglSurface, eglSurface, eglContext))
   {
      // error
   }

   return true;
}

bool EGLWindow::poll()
{
   return m_window->poll();
}
