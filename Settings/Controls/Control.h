#pragma once

#include <Windows.h>
#include <functional>
#include <string>

class Control {
public:
    Control();
    Control(int id, HWND parent);
    ~Control();

    virtual RECT Dimensions();

    virtual void Enable();
    virtual void Disable();
    virtual bool Enabled();
    virtual void Enabled(bool enabled);

    virtual std::wstring Text();
    virtual int TextAsInt();
    virtual bool Text(std::wstring text);
    virtual bool Text(int value);

    void WindowExStyle();
    void WindowExStyle(long exStyle);
    void AddWindowExStyle(long exStyle);
    void RemoveWindowExStyle(long exStyle);

    /// <summary>Handles WM_COMMAND messages.</summary>
    /// <param name="nCode">Control-defined notification code</param>
    virtual DLGPROC Command(unsigned short nCode);

    /// <summary>Handles WM_NOTIFY messages.</summary>
    /// <param name="nHdr">Notification header structure</param>
    virtual DLGPROC Notification(NMHDR *nHdr);

protected:
    int _id;
    HWND _hWnd;
    HWND _parent;

protected:
    static const int MAX_EDITSTR = 4096;
};