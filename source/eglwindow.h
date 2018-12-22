#pragma once

#include <string>
#include <memory>

#include "window.h"

class EGLWindow
{
public:
   EGLWindow();
   ~EGLWindow();

   bool create(const std::wstring name, size_t width, size_t height);
   bool poll();

private:
   std::shared_ptr<Window> m_window;
};

