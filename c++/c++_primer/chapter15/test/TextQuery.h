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
#include <sstream>
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

string TextQuery::text_line(line_no line) const
{
    if (line < lines_of_text.size())
        return lines_of_text[line];
    //throw out_of_range("line number out of range");
}

void TextQuery::store_file(ifstream &is)
{
    string textline;
    while (getline(is, textline))
        lines_of_text.push_back(textline);
}

void TextQuery::build_map()
{
    for (line_no line_num = 0; line_num < lines_of_text.size(); ++line_num) {
        istringstream line(lines_of_text[line_num]);
        string word;
        while (line >> word)
            word_map[cleanup_str(word)].insert(line_num);
    }
}

set<TextQuery::line_no> TextQuery::run_query(const string &query_word) const
{
    // 使用find函数而不是下标操作，避免在word_map中加入单词
    map< string, set<line_no> >::const_iterator loc = word_map.find(query_word);
    if (loc == word_map.end())
        return set<line_no>();      // 找不到，返回空的set对象
    else
        return loc->second;
}

string TextQuery::cleanup_str(const string &word)
{
    string ret;
    for (string::const_iterator it = word.begin(); it != word.end(); ++it)
        if (!ispunct(*it))
            ret += tolower(*it);
    return ret;
}

vector<string>::size_type TextQuery::size() const
{
    return lines_of_text.size();
}
#endif
