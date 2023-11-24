// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};
class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

private:
    void OnHello(wxCommandEvent &event);
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
    wxDECLARE_EVENT_TABLE();
};
enum
{
    ID_Hello = 1
};
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_Hello, MyFrame::OnHello)
        EVT_MENU(wxID_EXIT, MyFrame::OnExit)
            EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
                wxEND_EVENT_TABLE()
                    wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame("Hello World", wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);
    return true;
}
MyFrame::MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");
}
void MyFrame::OnExit(wxCommandEvent &event)
{
    Close(true);
}
void MyFrame::OnAbout(wxCommandEvent &event)
{
    wxMessageBox("This is a wxWidgets' Hello world sample",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}
void MyFrame::OnHello(wxCommandEvent &event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

/*
Microsoft Windows [Version 10.0.22621.2715]
(c) Microsoft Corporation. All rights reserved.

E:\test widget>git clone https://github.com/lszl84/wx_cmake_template.git
Cloning into 'wx_cmake_template'...
remote: Enumerating objects: 133, done.
remote: Counting objects: 100% (54/54), done.
remote: Compressing objects: 100% (21/21), done.
Receiving objects:  68% (91/133)
Receiving objects: 100% (133/133), 32.23 KiB | 970.00 KiB/s, done.
Resolving deltas: 100% (58/58), done.

E:\test widget>cd wx_cmake_template

E:\test widget\wx_cmake_template>cmake -S . -B build
-- Building for: Visual Studio 17 2022
-- Selecting Windows SDK version 10.0.19041.0 to target Windows 10.0.22621.
-- The CXX compiler identification is MSVC 19.33.31630.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.33.31629/bin/Hostx64/x64/cl.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Preinstalled wxWidgets not found.
-- Will download and install wxWidgets in E:/test widget/wx_cmake_template/build/stage
-- Configuring done (10.6s)
-- Generating done (0.1s)
-- Build files have been written to: E:/test widget/wx_cmake_template/build

E:\test widget\wx_cmake_template>cmake --build build
MSBuild version 17.3.1+2badb37d1 for .NET Framework
  1>Checking Build System
  Creating directories for 'wxWidgets_external'
  Building Custom Rule E:/test widget/wx_cmake_template/thirdparty/wxwidgets/CMakeLists.txt
  Performing download step (git clone) for 'wxWidgets_external'
  Cloning into 'wxWidgets_external'...
  HEAD is now at 6cdaedd42b Fill in the binaries SHA-1 checksums
  Submodule '3rdparty/catch' (https://github.com/wxWidgets/Catch.git) registered for path '3rdparty/catch'
  Submodule 'src/expat' (https://github.com/wxWidgets/libexpat.git) registered for path 'src/expat'
  Submodule 'src/jpeg' (https://github.com/wxWidgets/libjpeg-turbo.git) registered for path 'src/jpeg'
  Submodule 'src/png' (https://github.com/wxWidgets/libpng.git) registered for path 'src/png'
  Submodule 'src/tiff' (https://github.com/wxWidgets/libtiff.git) registered for path 'src/tiff'
  Submodule 'src/zlib' (https://github.com/wxWidgets/zlib.git) registered for path 'src/zlib'
  Cloning into 'E:/test widget/wx_cmake_template/build/subprojects/Source/wxWidgets_external/3rdparty/catch'...
  Cloning into 'E:/test widget/wx_cmake_template/build/subprojects/Source/wxWidgets_external/src/expat'...
  Cloning into 'E:/test widget/wx_cmake_template/build/subprojects/Source/wxWidgets_external/src/jpeg'...
  Cloning into 'E:/test widget/wx_cmake_template/build/subprojects/Source/wxWidgets_external/src/png'...
  Cloning into 'E:/test widget/wx_cmake_template/build/subprojects/Source/wxWidgets_external/src/tiff'...
  Cloning into 'E:/test widget/wx_cmake_template/build/subprojects/Source/wxWidgets_external/src/zlib'...
  Submodule path '3rdparty/catch': checked out 'ee4acb6ae6e32a02bc012d197aa82b1ca7a493ab'
  Submodule path 'src/expat': checked out '7532d85708929ebdb148308ca998268d3aaf3527'
  Submodule path 'src/jpeg': checked out '852493611506076fd9ad931d35bf1c3cc5b5a9c3'
  Submodule path 'src/png': checked out '3ffeff7877598d3236cc09a6d3f478073eb33f35'
  Submodule path 'src/tiff': checked out '9f657ff8a7411c95ffe83ec39e3e881c3fec6bb0'
  Submodule path 'src/zlib': checked out '5888671274cde770edbe683b435f052de2b03681'
  No update step for 'wxWidgets_external'
  No patch step for 'wxWidgets_external'
  Performing configure step for 'wxWidgets_external'
  -- wxWidgets_external configure command succeeded.  See also E:/test widget/wx_cmake_template/build/subprojects/Stamp/wxWidge      
  ts_external/wxWidgets_external-configure-*.log
  Performing build step for 'wxWidgets_external'
  -- wxWidgets_external build command succeeded.  See also E:/test widget/wx_cmake_template/build/subprojects/Stamp/wxWidgets_e
  xternal/wxWidgets_external-build-*.log
  Performing install step for 'wxWidgets_external'
  -- wxWidgets_external install command succeeded.  See also E:/test widget/wx_cmake_template/build/subprojects/Stamp/wxWidgets
  _external/wxWidgets_external-install-*.log
  Completed 'wxWidgets_external'
  Creating directories for 'wx_cmake_template_core'
  Building Custom Rule E:/test widget/wx_cmake_template/CMakeLists.txt
  No download step for 'wx_cmake_template_core'
  No update step for 'wx_cmake_template_core'
  No patch step for 'wx_cmake_template_core'
  Performing configure step for 'wx_cmake_template_core'
  loading initial cache file E:/test widget/wx_cmake_template/build/subprojects/tmp/wx_cmake_template_core/wx_cmake_template_co
  re-cache-Debug.cmake
  -- Selecting Windows SDK version 10.0.19041.0 to target Windows 10.0.22621.
  -- The CXX compiler identification is MSVC 19.33.31630.0
  -- Detecting CXX compiler ABI info
  -- Detecting CXX compiler ABI info - done
  -- Check for working CXX compiler: C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.33.31629/bin/Host
  x64/x64/cl.exe - skipped
  -- Detecting CXX compile features
  -- Detecting CXX compile features - done
  -- Found wxWidgets: E:/test widget/wx_cmake_template/build/stage/lib/vc_x64_lib/wxmsw31ud_core.lib;E:/test widget/wx_cmake_te
  mplate/build/stage/lib/vc_x64_lib/wxbase31ud.lib;E:/test widget/wx_cmake_template/build/stage/lib/vc_x64_lib/wxpngd.lib;E:/te      
  st widget/wx_cmake_template/build/stage/lib/vc_x64_lib/wxtiffd.lib;E:/test widget/wx_cmake_template/build/stage/lib/vc_x64_li      
  b/wxjpegd.lib;E:/test widget/wx_cmake_template/build/stage/lib/vc_x64_lib/wxzlibd.lib;E:/test widget/wx_cmake_template/build/      
  stage/lib/vc_x64_lib/wxregexud.lib;E:/test widget/wx_cmake_template/build/stage/lib/vc_x64_lib/wxexpatd.lib;winmm;comctl32;uu      
  id;oleacc;uxtheme;rpcrt4;shlwapi;version;wsock32 (found version "3.1.4") found components: core base png tiff jpeg zlib regex      
   expat
  -- Configuring done (10.6s)
  -- Generating done (0.1s)
CUSTOMBUILD : CMake warning :  [E:\test widget\wx_cmake_template\build\wx_cmake_template_core.vcxproj]
    Manually-specified variables were not used by the project:

      CMAKE_BUILD_TYPE


  -- Build files have been written to: E:/test widget/wx_cmake_template/build/subprojects/Build/wx_cmake_template_core
  Performing build step for 'wx_cmake_template_core'
  MSBuild version 17.3.1+2badb37d1 for .NET Framework
    1>Checking Build System
    Building Custom Rule E:/test widget/wx_cmake_template/src/CMakeLists.txt
    main.cpp
    main.vcxproj -> E:\test widget\wx_cmake_template\build\subprojects\Build\wx_cmake_template_core\Debug\main.exe
    Building Custom Rule E:/test widget/wx_cmake_template/src/CMakeLists.txt
  No install step for 'wx_cmake_template_core'
  Completed 'wx_cmake_template_core'
  Building Custom Rule E:/test widget/wx_cmake_template/CMakeLists.txt

E:\test widget\wx_cmake_template>
*/