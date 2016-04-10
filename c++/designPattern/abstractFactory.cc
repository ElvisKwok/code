#include <iostream>
using namespace std;
// 抽象工厂
// 抽象工厂创建的是一系列相关的对象，对象的实现采用工厂方法模式.
// 既延迟了具体子类的实例化，有集中化生产线的管理.
// 工厂方法使用过于产品种类单一的场合，为一类产品提供创建的接口。
// 抽象工厂适用于产品种类多的场合，主要用于创建一组（有多个种类）相关的产品，为它们提供创建的接口

class ProductA {
public:
	virtual void show() = 0;
};

class ProductB {
public:
	virtual void show() = 0;
};

class ProductA1: public ProductA {
public:
	void show() { cout << "I'm ProductA1" << endl; }
};

class ProductA2: public ProductA {
public:
	void show() { cout << "I'm ProductA2" << endl; }
};

class ProductB1: public ProductB {
public:
	void show() { cout << "I'm ProductB1" << endl; }
};

class ProductB2: public ProductB {
public:
	void show() { cout << "I'm ProductB2" << endl; }
};

class Factory {
public:
	virtual ProductA* CreateProductA() = 0;
	virtual ProductB* CreateProductB() = 0;
};

class Factory1: public Factory {
public:
	ProductA *CreateProductA() {
		return new ProductA1();
	}

	ProductB *CreateProductB() {
		return new ProductB1();
	}
};

class Factory2: public Factory {
public:
	ProductA *CreateProductA() {
		return new ProductA2();
	}

	ProductB *CreateProductB() {
		return new ProductB2();
	}
};

int main() {
	Factory* factory1 = new Factory1();
	ProductA *productObjA1 = factory1->CreateProductA();
	ProductB *productObjB1 = factory1->CreateProductB();
	productObjA1->show();
	productObjB1->show();

	Factory* factory2 = new Factory2();
	ProductA *productObjA2 = factory2->CreateProductA();
	ProductB *productObjB2 = factory2->CreateProductB();
	productObjA2->show();
	productObjB2->show();

	if (factory1 != NULL) {
		delete factory1;
		factory1 = NULL;
	}

	if (productObjA1 != NULL) {
		delete productObjA1;
		productObjA1 = NULL;
	}
	
	if (productObjB1 != NULL) {
		delete productObjB1;
		productObjB1 = NULL;
	}

	if (factory2 != NULL) {
		delete factory2;
		factory2 = NULL;
	}

	if (productObjA2 != NULL) {
		delete productObjA2;
		productObjA2 = NULL;
	}
	
	if (productObjB2 != NULL) {
		delete productObjB2;
		productObjB2 = NULL;
	}

	return 0;
}
