//main.cpp
//使用TextQuery类,Query类及Query_base类层次
//Query("fiery") & Query("bird") | Query("wind")
#include "Query.h"
#include "TextQuery.h"

string make_plural(size_t a,const string& b,const string& c)
{
	return a>1?b+c:b;
}

ifstream& open_file(ifstream& infile,const string& file)
{
	infile.close();
	infile.clear();
	infile.open(file.c_str());
	return infile;
}

void print_results(const set<TextQuery::line_no>& locs,
				   const TextQuery &file)
{
	typedef set<TextQuery::line_no> line_nums;
	line_nums::size_type size=locs.size();
	//如果找到匹配的结果,则输出匹配的行数
	cout<<"match occurs"
		<<size<<" "
		<<make_plural(size,"time","s")<<endl;

	//输出出现该单词的每一行
	line_nums::const_iterator it=locs.begin();
	for(;it!=locs.end();++it)
	{
		cout<<"\t(line"
			//行号从1开始
			<<(*it)+1<<")"
			<<file.text_line(*it)<<endl;
	}
}

int main(int argc,char **argv)
{
	//找开要在其中进行查询的文本文件
	ifstream infile;
    if(!open_file(infile,"data.txt"))
	{
		cerr<<"No input file!"<<endl;
//		return EXIT_FAILURE;
	}

	TextQuery file;
	file.read_file(infile); //读入文本,建立map容器

	typedef set<TextQuery::line_no> line_nums;

	//构造查询
	Query q=Query("fiery")&Query("bird")|Query("wind");                        

	//计算查询，获得匹配行的行号集合
	const line_nums &locs=q.eval(file);

	//输出查询表达式
	cout<<"\nExecuted Query for:"<<q<<endl;

	//输出查询结果
	print_results(locs,file);

//	system("pause");

	return 0;
}
