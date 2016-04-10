#include <iostream>
using namespace std;
// 工厂方法
// 定义一个核心抽象类Factory，负责创建对象（纯虚函数）
// 具体的行为由子类FactoryA, FactoryB决定实现哪个类（实际创建工作推迟到子类当中）
// 进一步的抽象化使得：引入新的product时不需要改动其他代码

class Product {
public:
	virtual void show() = 0;
};

class ProductA: public Product {
public:
	void show() { cout << "I'm ProductA" << endl; }
};

class ProductB: public Product {
public:
	void show() { cout << "I'm ProductB" << endl; }
};

class ProductC: public Product {
public:
	void show() { cout << "I'm ProductC" << endl; }
};

class Factory {
public:
	virtual Product* CreateProduct() = 0;
};

class FactoryA: public Factory {
public:
	Product *CreateProduct() {
		return new ProductA();
	}
};

class FactoryB: public Factory {
public:
	Product *CreateProduct() {
		return new ProductB();
	}
};

int main() {
	Factory* factoryA = new FactoryA();
	Product *productObjA = factoryA->CreateProduct();
	productObjA->show();

	Factory* factoryB = new FactoryB();
	Product *productObjB = factoryB->CreateProduct();
	productObjB->show();
	
	if (factoryA != NULL) {
		delete factoryA;
		factoryA = NULL;
	}

	if (productObjA != NULL) {
		delete productObjA;
		productObjA = NULL;
	}
	
	if (factoryB != NULL) {
		delete factoryB;
		factoryB = NULL;
	}

	if (productObjB != NULL) {
		delete productObjB;
		productObjB = NULL;
	}

	return 0;
}
