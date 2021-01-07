#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const std::string &SALT1 = "!8!=)/z_#";
const std::string &SALT2 = "¿+32w_:;:.";
const std::string &SALT3 = "6x!!jo../_8aaa";
const std::string &SALT4 = "d5-4+xsuois";
const std::string &BASE64_CODES = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

std::string EncryptB64(std::string);
std::string DecryptB64 (std::string);
std::string base64_decode(const std::string &);
std::string base64_encode(const std::string &);

int main(int argc, char *argv[])
{

    if(argc < 3)
    {
        return std::cout << "Program needs 3 arguments, input, output & mode!" << std::endl, 2;
    }

    std::string in (argv[1]), out (argv[2]);
    std::string mode (argv[3]);
    std::ifstream fi (in);
    if (!fi)
    {
        return std::cout << "Cannot read input file '" << in << "'" << std::endl, 3;
    }

    std::string data;
    fi >> data;
    if (!fi)
    {
        return std::cout << "Input file '" << in << "' corrupted!" << std::endl, 4;
    }

    if(mode == "enc")
    {
        data = EncryptB64(data);

    }
    else if(mode == "dec")
    {
        data = DecryptB64(data);
    }
    else
    {
        return std::cout << "Invalid mode selected. enc = encrypt || dec = decrypt" << std::endl, 6;
    }

    std::ofstream fo (out);
    if (!fo)
    {
        return std::cout << "Cannot write output file '" << out << "'" << std::endl, 5;
    }

    fo << data;
    std::cout << "Decoding was successfull!" << std::endl;
    return 0;
}

std::string DecryptB64 (std::string s)
{
    s = s.erase (6, 1);
    s = s.erase (2, 1);
    s = base64_decode (s);
    s = s.substr (SALT2.length() + SALT3.length());
    s = s.substr (0, s.length() - SALT1.length());
    s = base64_decode (s);
    s = s.substr (0, s.length() - SALT1.length());
    s = s.erase (7, SALT3.length());
    s = base64_decode (s);
    s = s.substr (SALT1.length());
    s = s.substr (0, s.length() - SALT2.length() - SALT4.length());
    return s;
}

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

std::string base64_decode(const std::string &s)
{
    std::string ret;
    std::vector<int> vec(256, -1);
    for (int i = 0; i < 64; i++)
        vec [BASE64_CODES[i]] = i;
    int val = 0, bits = -8;
    for (const auto &c : s)
        {
            if (vec[c] == -1) break;
            val = (val << 6) + vec[c];
            bits += 6;
            if (bits >= 0)
                {

                    ret.push_back(char((val >> bits) & 0xFF));
                    bits -= 8;
                }
        }
    return ret;
}

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
            ret.push_back(BASE64_CODES[((val >> bits) & b63)]);
            bits -= 6;
        }
    }
    if (bits > -6)
        ret.push_back(BASE64_CODES[((val << 8) >> (bits + 8)) & b63]);

    while (ret.size() % 4)
        ret.push_back('-');

    return ret;
}

