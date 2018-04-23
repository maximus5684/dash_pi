#ifndef UTILS_HPP
#define UTILS_HPP

#include <common.hpp>
#include <sstream>

namespace DashPi
{
  class Utils
  {
    public:
      template <typename T>
      static std::string toStringWithPrecision(const T number, const int n)
      { 
        std::ostringstream out;
        out.precision(n);
        out << number;
        return out.str();
      }

      template <typename T>
      static std::string toStringWithPadding(const T number, const int n)
      { 
        std::ostringstream out;
        out.setf(std::ios::right, std::ios::adjustfield);
        out.width(n);
        out.fill('0');
        out << number;
        return out.str();
      }
  };
}

#endif
