#ifndef QUERY_H
#define QUERY_H
#include "TextQuery.h"
#include <string>
#include <set>
#include <iostream>
#include <fstream>
using namespace std;

// 用作具体查询类型的基类的抽象类
class Query_base {
    friend class Query;
protected:
    typedef TextQuery::line_no line_no;
    virtual ~Query_base() {}
private:
    // 返回与该查询匹配的行的行号集合
    virtual set<line_no> eval(const TextQuery&) const = 0;
    // 打印查询
    virtual ostream& display(ostream& = cout) const = 0;
};

// 管理Query_base继承层次的句柄类
class Query {
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&); 
    friend Query operator&(const Query&, const Query&); 
public:
    Query(const string&);   // 声明，建立新的WordQuery对象，在定义WordQuery类后才能实现
    // 3个复制控制成员
    Query(const Query &c): q(c.q), use(c.use) { ++*use; }
    Query& operator= (const Query &);
    ~Query() { decr_use(); }
    // 接口函数
    set<TextQuery::line_no> eval(const TextQuery &t) const { return q->eval(t); }
    ostream& display(ostream &os) const { return q->display(os); }
private:
    Query(Query_base *query): q(query), use(new size_t(1)) { }
    Query_base *q;
    size_t *use;
    void decr_use ()
    {
        if (--*use == 0) {
            delete q;
            delete use;
        }
    }
};

inline Query& Query::operator=(const Query &rhs)
{
    ++*rhs.use;
    decr_use();
    q = rhs.q;
    use = rhs.use;
    return *this;
}

inline ostream& operator<<(ostream &os, const Query &q)
{
    return q.display(os);
}

class WordQuery: public Query_base {
    friend class Query;     // 允许Query访问WordQuery的构造函数
    WordQuery(const string &s): query_word(s) { }
    set<line_no> eval(const TextQuery &t) const { return t.run_query(query_word); }
    ostream& display(ostream &os) const { return os << query_word; }
    string query_word;
};

// 实现
inline Query::Query(const string &s): q(new WordQuery(s)), use(new size_t(1)) { }

class NotQuery: public Query_base {
    friend Query operator~(const Query &);
    NotQuery(Query q): query(q) { }
    set<line_no> eval(const TextQuery &) const;
    ostream& display(ostream &os) const { return os << "~(" << query << ")"; }
    const Query query;
};

class BinaryQuery: public Query_base {
protected:
    BinaryQuery(Query left, Query right, string op):
        lhs(left), rhs(right), oper(op) { }
    ostream& display(ostream &os) const { return os << "(" << lhs << " " 
                                          << oper << " " << rhs << ")"; }
    const Query lhs, rhs;
    const string oper;
};

class AndQuery: public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
    // 构造函数，创建BinaryQuery基类部分
    AndQuery(Query left, Query right): BinaryQuery(left, right, "&") { }
    std::set<line_no> eval(const TextQuery &) const;
};

class OrQuery: public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    // 构造函数，创建BinaryQuery基类部分
    OrQuery(Query left, Query right): BinaryQuery(left, right, "|") { }
    std::set<line_no> eval(const TextQuery &) const;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
    return new AndQuery(lhs, rhs);
}

inline Query operator|(const Query &lhs, const Query &rhs)
{
    return new OrQuery(lhs, rhs);
}

inline Query operator~(const Query &oper)
{
    return new NotQuery(oper);
}
#endif
