#include <iostream>
#include <mutex>
using namespace std;

mutex mtx;

class Singleton {
public:
	static Singleton* getInstance() {
		if (m_pInstance == NULL) {	// 判断是否第一次调用
			if (mtx.try_lock()) {			
				if (m_pInstance == NULL) { // double check
					m_pInstance = new Singleton();
				}
				mtx.unlock();
			}
		}
		return m_pInstance;
	}
	static void destroyInstance() {
		if (m_pInstance != NULL) {
			delete m_pInstance;
			m_pInstance = NULL;
		}
	}
private:
	Singleton() { cout << "Singleton()" << endl; }
	static Singleton *m_pInstance;
};

Singleton* Singleton::m_pInstance = NULL;

class Singleton2 {
public:
	static Singleton2* getInstance() {
		return const_cast <Singleton2 *>(m_pInstance);
	}
	static void destroyInstance() {
		if (m_pInstance != NULL) {
			delete m_pInstance;
			m_pInstance = NULL;
		}
	}
private:
	Singleton2() { cout << "Singleton2()" << endl; }
	static const Singleton2 *m_pInstance;
};

const Singleton2* Singleton2::m_pInstance = new Singleton2();

class Singleton3 {
public:
	static Singleton3* getInstance() {
		static Singleton3 instance;	//局部静态变量,不用担心单例的销毁(程序结束时会自动销毁)
		return &instance;
	}
private:
	Singleton3() { cout << "Singleton3()" << endl; }
};

int main() {
	Singleton* p1 = Singleton::getInstance();
	Singleton* p2 = p1->getInstance();
	Singleton &ref = *Singleton::getInstance();
	//p1->destroyInstance();
	//p1 = Singleton::getInstance();

	Singleton2* p3 = Singleton2::getInstance();
	Singleton2* p4 = Singleton2::getInstance();
	
	Singleton3* p5 = Singleton3::getInstance();
	Singleton3* p6 = Singleton3::getInstance();
	return 0;
}
