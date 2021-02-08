#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <random>
#include "time.h"
#include <string>
#include "windows.h"

std::string ObfuscateCode(std::string, std::vector<std::string> &, std::vector<std::string> &,const int);
int GenerateNumber(int seed= 2);
const std::string GenerateWord();
std::string getfile(std::ifstream &);
void find_and_replace(std::string &, const std::string &, const std::string &);
void display(std::vector<std::string> &);

const std::string &DIGITS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int main()
{
    std::vector<std::string> files = {"Base64.h", "Helper.h", "IO.h", "KeyConstants.h", "KeyHook.h", "SendMail.h", "Timer.h", "main.cpp"};
    std::vector<std::string> files_out = {"ObsBase64.h", "ObsHelper.h", "ObsIO.h", "ObsKeyConstants.h", "ObsKeyHook.h", "ObsSendMail.h", "ObsTimer.h", "ObsMain.cpp"};
    std::vector<std::string> words =
    {"SALT1", "SALT2", "SALT3", "SALT4",
    "base64_encode", "EncryptB64", "BASE64_CODES", "bits",
    "GetTimeString", "GetDateTimeString", "WriteAppLog",
    "ToString", "GetOurPath", "append_separator", "appdata_dir", "MkOneDr",
    "MKDir", "WriteLog", "KeyPair", "VKName", "TimerSendMail", "last_file",
    "keylog", "MailTimer", "eHook", "kbs", "InstallHook"};

    std::vector<std::string> after_words = {};
    const int nWords = words.size();
    for(int i = 0; i < nWords; i++)
    {
        std::string after_word = GenerateWord();
        after_words.push_back(after_word);
        Sleep(1000);
    }
    display(after_words);

    for(int i = 0; i < files.size(); i++)
    {
        std::ifstream filein(files[i]);
        std::ofstream fileout(files_out[i]);
        std::string contents = getfile(filein);
        std::string out_content = ObfuscateCode(contents, words, after_words, nWords);
        fileout << out_content;
        filein.close();
        fileout.close();
    }

    //std::ifstream filein("Base64.h");
    //std::ofstream fileout("new_file.h");

    return 0;
}

std::string ObfuscateCode(std::string file_content, std::vector<std::string> &words, std::vector<std::string> &after_words,const int nWords)
{
    int nFiles = 2;
    //std::ofstream fileout("table.txt");
    std::cout<<std::endl;

    for(int i = 0; i < nWords; i++)
    {
        std::cout << words[i] <<" = "<< after_words[i]<<std::endl;
        find_and_replace(file_content, words[i], after_words[i] );
    }
    //fileout << table_content;
    //fileout.close();
    return file_content;
}

const std::string GenerateWord()
{
    int counter = GenerateNumber() + 2;
    std::string ret = "";
    for (int i = 0; i < counter; i++)
    {
        ret.insert(i, DIGITS.substr(GenerateNumber(i), (GenerateNumber(i) - (GenerateNumber(i) - 1))));
    }
    return ret;
}

int GenerateNumber(int seed)
{
    std::default_random_engine generator(time(0) * 450 * (seed * 2));
    std::uniform_int_distribution<int> distribution(0, 51);

    int number = distribution(generator);

    return number;
}

void find_and_replace(std::string &file_contents, const std::string &word, const std::string &word_after)
{
  // This searches the file for the first occurence of the morn string.
    auto pos = file_contents.find(word);
    while (pos != std::string::npos)
    {
        file_contents.replace(pos, word.length(), word_after);
        // Continue searching from here.
        pos = file_contents.find(word, pos);
    }

}

std::string getfile(std::ifstream& is) {
    std::string contents;
    // Here is one way to read the whole file
    for (char ch; is.get(ch); contents.push_back(ch))
    {
        std::cout<<ch;
    }
    return contents;
}

void display(std::vector<std::string> &v)
{
    for(int i; i<v.size(); i++)
    {
        std::cout << v[i] << "\n";
    }
    std::cout << "\n" << std::endl;
}
