#include <iostream>
#include <string>
using namespace std;

// base class
class Item_base {
public:
    // 构造函数
    Item_base(const std::string &book = "", double sales_price = 0.0):
        isbn(book), price(sales_price)
    {
        std::cout << "Item_base(const std::string&, double)" << std::endl;
    }
    
    std::string book() const
    {
        return isbn;
    }
    
    // 派生类将重载该函数以应用不同的折扣策略
    virtual double net_price(size_t n) const
    {
        return n * price;
    }
    
    // 3个复制控制成员
    Item_base(const Item_base &ib): isbn(ib.isbn), price(ib.price)
    {
        std::cout << "Item_base(const Item_base&)" << std::endl;
    }
    
    Item_base& operator= (const Item_base& rhs)
    {
        isbn = rhs.isbn;
        price = rhs.price;
        std::cout << "Item_base::operator=()" << std::endl;
        return *this;
    }

    virtual ~Item_base()
    {
        std::cout << "~Item_base()" << std::endl;
    }

private:
    std::string isbn;

protected:
    double price;
};

// derived class
class Bulk_item: public Item_base {
public:
    // 构造函数
    Bulk_item(const std::string &book = "", double sales_price = 0.0,
              size_t qty = 0, double disc_rate = 0.0):
        Item_base(book, sales_price), min_qty(qty), discount(disc_rate)
    {
        std::cout << "Bulk_item(const std::string&, double, size_t, double) " << std::endl;
    }

    double net_price(size_t cnt) const
    {
        if (cnt > min_qty)
            return cnt * price * (1 - discount);
        else
            return cnt * price;
    }

    // 3个复制控制成员
    Bulk_item(const Bulk_item &b) :
        Item_base(b), min_qty(b.min_qty), discount(b.discount)
    {
        std::cout << "Bulk_item(const Bulk_item&)" << std::endl;
    }

    Bulk_item& operator= (const Bulk_item &rhs)
    {
        if (this != &rhs) {
            Item_base::operator=(rhs);
            min_qty = rhs.min_qty;
            discount = rhs.discount;
        }
        std::cout << "Bulk_item& operator=()" << std::endl;
        return *this;
    }

    virtual ~Bulk_item()
    {
        std::cout << "~Bulk_item()" << std::endl;
    }    

private:
    size_t min_qty;
    double discount;
};

void func1(Item_base obj)
{
}

void func2(Item_base& obj)
{
}

Item_base func3()
{
    Item_base obj;
    return obj;
}

int main()
{
    Item_base iobj;
    cout << "******" << endl;
    func1(iobj);
    cout << "******" << endl;
    func2(iobj);
    cout << "******" << endl;
    iobj = func3();
    cout << "******" << endl;
    Item_base *p = new Item_base;
    cout << "******" << endl;
    delete p;
    cout << "******" << endl;
    cout << "\n\n" << endl;

    Bulk_item bobj;
    cout << "******" << endl;
    func1(bobj);
    cout << "******" << endl;
    func2(bobj);
    cout << "******" << endl;
    Bulk_item *q = new Bulk_item;
    cout << "******" << endl;
    delete q;
    cout << "******" << endl;
    cout << "\n\n" << endl;
    
    return 0;
}
