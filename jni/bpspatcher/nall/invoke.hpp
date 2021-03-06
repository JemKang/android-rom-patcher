#ifndef NALL_INVOKE_HPP
#define NALL_INVOKE_HPP

//void invoke(const string &name, const string& args...);
//if a program is specified, it is executed with the arguments provided
//if a file is specified, the file is opened using the program associated with said file type
//if a folder is specified, the folder is opened using the associated file explorer
//if a URL is specified, the default web browser is opened and pointed at the URL requested
//path environment variable is always consulted
//execution is asynchronous (non-blocking); use system() for synchronous execution

#include <nall/string.hpp>
#ifdef _WIN32
  #include <nall/windows/utf8.hpp>
#endif

namespace nall {

#ifdef _WIN32

template<typename... Args>
inline void invoke(const string &name, Args&&... args) {
  lstring argl(std::forward<Args>(args)...);
  for(auto &arg : argl) if(arg.position(" ")) arg = {"\"", arg, "\""};
  string arguments = argl.concatenate(" ");
  ShellExecuteW(NULL, NULL, utf16_t(name), utf16_t(arguments), NULL, SW_SHOWNORMAL);
}

#else

template<typename... Args>
inline void invoke(const string &name, Args&&... args) {
  pid_t pid = fork();
  if(pid == 0) {
    const char *argv[1 + sizeof...(args) + 1], **argp = argv;
    lstring argl(std::forward<Args>(args)...);
    *argp++ = (const char*)name;
    for(auto &arg : argl) *argp++ = (const char*)arg;
    *argp++ = nullptr;

    if(execvp(name, (char* const*)argv) < 0) {
      execlp("xdg-open", "xdg-open", (const char*)name, nullptr);
    }
    exit(0);
  }
}

#endif

}

#endif
