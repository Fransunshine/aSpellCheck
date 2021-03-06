/*************************************************************************
  > File Name: Class.h
  > Author: 
  > Mail: 
  > Created Time: Mon 03 Aug 2015 08:32:30 AM CST
 ************************************************************************/

#ifndef _CLASS_H
#define _CLASS_H

#include "./seg.h"
#include<vector>

    const char * const JIEBA_DICT_FILE = "./cppjieba/dict/jieba.dict.utf8";
    const char * const HMM_DICT_FILE = "./cppjieba/dict/hmm_model.utf8";
    const char * const USER_DICT_FILE = "./cppjieba/dict/user.dict.utf8";
MixSegment seg(JIEBA_DICT_FILE, HMM_DICT_FILE, USER_DICT_FILE);

class Class
{
public:
    Class()
    {
    }

    std::string wordSplit(std::string& str)
    {
        std::vector<std::string> split_words;
        seg.cut(str, split_words);
        std::string sResult;
        for(auto it: split_words)
        {
            sResult += it;
            sResult += " ";
        }
        return sResult;
    }

    private:
};


#endif


int main()
{
    std::vector<std::string> word;
    std::cout<<"请输入文件名：";
    std::string filename;
    std::cin>>filename;
    Class my;
    std::string res = my.wordSplit(filename);
    std::cout<<"res:"<<res<<std::endl;
    /*
    std::ifstream input("./C15-Energy01.txt");
    if(!input)
    {
        std::cout<<"error: input!"<<std::endl;
    }
    std::string line_content;
    std::string real_content;
    while(getline(input, line_content))
    {
        real_content += line_content;
        real_content += "\n";
    }
    */
    //seg.cut(real_content, word);
}
