#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class TextQuery {
public:
    // 类型别名
    typedef string::size_type str_size;
    typedef vector<string>::size_type line_no;
    // 接口
    // read_file建立给定文件的内部数据结构
    void read_file(ifstream &is)
    {
        store_file(is);
        build_map();
    }
    // run_query查询给定单词，返回该单词所在行的行号
    set<line_no> run_query(const string&) const;
    // text_line返回输入文件中指定行号对应的行
    string text_line(line_no) const;
    line_no size() const;

private:
    // read_file所用的辅助函数
    void store_file(ifstream&); // 存储输入文件
    void build_map();       // 每个单词与一个行号set相关联
    // 保存输入文件
    vector<string> lines_of_text;
    // 单词与“出现该单词的行”的行号set相关联
    map< string, set<line_no> > word_map;
    // 去掉标点，字母变小写
    static string cleanup_str(const string&);
};
#endif
