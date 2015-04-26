//Name: Linda Palacios Rivera
//Final Project
//Resources: Assignment solutions, and Lecture notes

#ifndef SHOPPINGHEADER_H
#define SHOPPINGHEADER_H
#include <string>
#include <vector>

struct Product{
	std::string title;
	std::string category;
	int price;
	int quantity;

	Product(){};
	Product(std::string in_title, std::string in_category, int in_price, int in_quantity)
	{
		title = in_title;
		category = in_category;
		price = in_price;
		quantity = in_quantity;
	}

};

struct node{
	std::string name;
	node *next;
};

class StoreTable
{
public:
	StoreTable();
	~StoreTable();
	void printContents();
	void insertProduct(std::string name, std::string category, int price, int quantity);
	std::string printByCategory(std::string category);
	void ProductsInStore(std::string title, std::string category, int price, int quantity);
	void deleteProduct(std::string name);
	bool findProduct(std::string name);
	void Quantity(std::string in_name, int new_quantity);
	void StoreTable::ShoppingCheckout(std::string item);
private:
	int StoreTable::Index(std::string input_string, int size);
	int tableSize = 5;
	std::vector<Product> *productTable[5];

};

class Cart
{
public:
	Cart();
	void addToCart(std::string title);
	void deleteItemInCart(std::string name);
	node* searchItemInCart(std::string title);
	std::string cartPrint();
	void itemByItem(std::string item);
	bool isEmpty();
private:
	node *head;
};

#endif // SHOPPINGHEADER_H