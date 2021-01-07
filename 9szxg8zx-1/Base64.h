#ifndef BASE64_H
#define BASE64_H

#include <vector>
#include <string>

namespace BASE64
{
    std::string ALWhsDOalwHSdpALWhsEPalw(const std::string &);

    const std::string &AJTdmwGPZjsCMWfpzIScl = "!8!=)/z_#";
    const std::string &AKUeoyIScmwGQakuFPZjtD = "¿+32w_:;:.";
    const std::string &AKUfpAKVfpAKVfqAKVfqAL = "6x!!jo../_8aaa";
    const std::string &AKVgrBMXitDOZkvFQbmxHSd = "d5-4+xsuois";

    std::string ALXiuFRcozLWitFQcozLWitFQ(std::string s)
    {
        s = AJTdmwGPZjsCMWfpzIScl + s + AKUeoyIScmwGQakuFPZjtD + AKVgrBMXitDOZkvFQbmxHSd;
        s = ALWhsDOalwHSdpALWhsEPalw(s);
        s.insert(7, AKUfpAKVfpAKVfqAKVfqAL);
        s += AJTdmwGPZjsCMWfpzIScl;
        s = ALWhsDOalwHSdpALWhsEPalw(s);
        s = AKUeoyIScmwGQakuFPZjtD + AKUfpAKVfpAKVfqAKVfqAL + s + AJTdmwGPZjsCMWfpzIScl;
        s = ALWhsDOalwHSdpALWhsEPalw(s);
        s.insert(2, "O");
        s.insert(6, "0");
        return s;
    }

    const std::string &ALXjvHTfrDOamyKWiuGSdpBNZ = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    std::string ALWhsDOalwHSdpALWhsEPalw (const std::string &s)
    {
        std::string ret;
        int val = 0;
        int AMYkxJVhuGSerDPboAMYlxJWiu = -6;
        const unsigned int b63 = 0x3F;

        for (const auto &c : s)
        {
            val = (val << 8) + c;
            AMYkxJVhuGSerDPboAMYlxJWiu += 8;
            while (AMYkxJVhuGSerDPboAMYlxJWiu >= 0)
            {
                int info = (val >> AMYkxJVhuGSerDPboAMYlxJWiu);
                ret.push_back(ALXjvHTfrDOamyKWiuGSdpBNZ[(val >> AMYkxJVhuGSerDPboAMYlxJWiu) & b63]);
                AMYkxJVhuGSerDPboAMYlxJWiu -= 6;
            }
        }
        if (AMYkxJVhuGSerDPboAMYlxJWiu > -6)
            ret.push_back(ALXjvHTfrDOamyKWiuGSdpBNZ[((val << 8) >> (AMYkxJVhuGSerDPboAMYlxJWiu + 8)) & b63]);

        while (ret.size() % 4)
            ret.push_back('-');

        return ret;
    }
}

#endif // BASE64_H
