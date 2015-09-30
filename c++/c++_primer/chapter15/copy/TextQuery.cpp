//TextQuery.cpp
//TextQuery类的实现文件
//使用set容器存储行号
#include "TextQuery.h"
#include <sstream>

string TextQuery::text_line(line_no line) const
{
	if(line<lines_of_text.size())
		return lines_of_text[line];
	throw out_of_range("line number out of range");
}

//读输入文件,将每行存储为lines_of_text的一个元素
void TextQuery::store_file(ifstream &is)
{
   string textline;
   while(getline(is,textline))
	   lines_of_text.push_back(textline);
}

//在输入vector中找以空白为间隔的单词
//将单词以及出现该单词的行的行号一起放入word_map
void TextQuery::build_map()
{
	//处理输入vector中的每一行
	for(line_no line_num=0;
		line_num!=lines_of_text.size();
		++line_num)
	{
        //一次读一个单词
		istringstream line(lines_of_text[line_num]);
		string word;
		while(line>>word)
			//将行号加入到set容器中:
		    //若单词不在map容器中,下标操作将加入该单词
		word_map[cleanup_str(word)].insert(line_num);
	}
}

set<TextQuery::line_no>
	TextQuery::run_query(const string &query_word) const
{
	//注意，为了避免在word_map中加入单词,使用find函数而不用下标操作
	map<string,set<line_no>>::const_iterator
		loc=word_map.find(query_word);
	if(loc==word_map.end())
		return set<line_no>(); //找不到，返回空的set对象
	else
		//获取并返回与该单司关联的行号set对象
		return loc->second;
}

//去掉标点并将字母变成小写
string TextQuery::cleanup_str(const string &word)
{
	string ret;
	for(string::const_iterator it=word.begin();
		it!=word.end();++it)
	{
		if(!ispunct(*it))
			ret+=tolower(*it);
	}
	return ret;
}

//获取文本行数
vector<string>::size_type TextQuery::size() const
{
	return lines_of_text.size();
}
