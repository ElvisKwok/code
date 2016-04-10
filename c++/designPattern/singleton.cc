#include <iostream>
#include <mutex>
using namespace std;

class Lock {
public:
private:
};
	
mutex mtx;

class Singleton {
public:
	static Singleton* getInstance() {
		if (m_pInstance == NULL) {	// 判断是否第一次调用
			//Lock lock(cs);	// 用lock实现线程安全
			if (mtx.try_lock()) {
				if (m_pInstance == NULL) { // double check
					m_pInstance = new Singleton();
				}
				mtx.unlock();
			}
		}
		return m_pInstance;
	}
private:
	Singleton() { cout << "Singleton()" << endl; }
	static Singleton *m_pInstance;
	class Garbo { // private嵌套类
	public:
		~Garbo() {
			if (Singleton::m_pInstance) {
				cout << "delete m_pInstance now" << endl;
				delete Singleton::m_pInstance;
				Singleton::m_pInstance = NULL;
			}
		}
	};
	static Garbo garbo;	//定义一个static成员变量，程序结束时，系统会自动调用它的析构函数，从而单例对象得到释放
};

Singleton* Singleton::m_pInstance = NULL;

int main() {
	Singleton* p1 = Singleton::getInstance();
	Singleton* p2 = p1->getInstance();
	Singleton &ref = *Singleton::getInstance();
	
	
	return 0;
}
