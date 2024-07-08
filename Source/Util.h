#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#ifndef DEBUG_PRINT
  #if JUCE_DEBUG
    #define DEBUG_PRINT(str) Logger::outputDebugString(str)
  #else
    #define DEBUG_PRINT(str)
  #endif
#endif

namespace Util {
  inline int compare(int a, int b) {
    if (a > b) return 1;
    if (a == b) return 0;
    return -1;
  }

  inline String getHomeDirectory() {
  #if JUCE_WINDOWS
      const char* homeDir = std::getenv("USERPROFILE");
  #else
      const char* homeDir = std::getenv("HOME");
  #endif
      return homeDir != nullptr ? String(homeDir) : String();
  }

  inline String expandHomeDirectory(const String& path) {
      if (path.startsWithChar('~')) {
          return getHomeDirectory() + path.substring(1);
      }
      return path;
  }

  inline String convertToRelativeHomePath(const String& path) {
      String homeDir = getHomeDirectory();
      if (path.startsWith(homeDir)) {
          return "~" + path.substring(homeDir.length());
      }
      return path;
  }
}
