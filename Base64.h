#ifndef BASE64_H
#define BASE64_H

#include <vector>
#include <string>

namespace BASE64
{
    std::string base64_encode(const std::string &);

    const std::string &SALT1 = "!8!=)/z_#";
    const std::string &SALT2 = "¿+32w_:;:.";
    const std::string &SALT3 = "6x!!jo../_8aaa";
    const std::string &SALT4 = "d5-4+xsuois";

    std::string EncryptB64(std::string s)
    {
        s = SALT1 + s + SALT2 + SALT4;
        s = base64_encode(s);
        s.insert(7, SALT3);
        s += SALT1;
        s = base64_encode(s);
        s = SALT2 + SALT3 + s + SALT1;
        s = base64_encode(s);
        s.insert(2, "O");
        s.insert(6, "0");
        return s;
    }

    const std::string &BASE64_CODES = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    std::string base64_encode (const std::string &s)
    {
        std::string ret;
        int val = 0;
        int bits = -6;
        const unsigned int b63 = 0x3F;

        for (const auto &c : s)
        {
            val = (val << 8) + c;
            bits += 8;
            while (bits >= 0)
            {
                int info = (val >> bits);
                ret.push_back(BASE64_CODES[(val >> bits) & b63]);
                bits -= 6;
            }
        }
        if (bits > -6)
            ret.push_back(BASE64_CODES[((val << 8) >> (bits + 8)) & b63]);

        while (ret.size() % 4)
            ret.push_back('-');

        return ret;
    }
}

#endif // BASE64_H
