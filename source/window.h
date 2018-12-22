#pragma once

#include <string>
#include <memory>

#include "window_events.h"


class Window
{
public:
    Window();
   ~Window();

   bool create(const std::wstring _name, size_t _width, size_t _height);
   void destroy();

   bool poll();

   // platform access
   void* native_display();
   void* native_window();

   void push_event(const Event& _event);
   void set_mouse_focus(bool _in_window);
   bool get_mouse_focus();

private:
   std::shared_ptr<struct PrivateData> m_data;
};

