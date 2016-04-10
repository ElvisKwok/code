#include <iostream>
using namespace std;
// 简单工厂
// 定义一个类Factory，负责创建对象
// factory根据不同的条件(传入参数)创建不同的product

typedef enum ProductTypeTag {
	TypeA,
	TypeB,
	TypeC
}PRODUCTTYPE;

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
	Product* CreateProduct(PRODUCTTYPE type) {
		switch (type) {
		case TypeA:
			return new ProductA();
		case TypeB:
			return new ProductB();
		case TypeC:
			return new ProductC();
		default:
			return NULL;
		}
	}
};

int main() {
	Factory* ProductFactory = new Factory();
	Product *productObjA = ProductFactory->CreateProduct(TypeA);
	if (productObjA != NULL)
		productObjA->show();

	Product *productObjB = ProductFactory->CreateProduct(TypeB);
	if (productObjB != NULL)
		productObjB->show();

	Product *productObjC = ProductFactory->CreateProduct(TypeC);
	if (productObjC != NULL)
		productObjC->show();
	
	delete ProductFactory;
	ProductFactory = NULL;

	delete productObjA;
	productObjA = NULL;
	delete productObjB;
	productObjB = NULL;
	delete productObjC;
	productObjC = NULL;

	return 0;
}
