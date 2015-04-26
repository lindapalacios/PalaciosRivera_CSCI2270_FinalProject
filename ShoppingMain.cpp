//Name: Linda Palacios Rivera
//Final Project
//Resources: Assignment solutions, and Lecture notes

#include <iostream>
#include "ShoppingHeader.h"
#include <string.h>
#include <vector>

using namespace std;

//Store Inventory using HashTable:

//Constructor
StoreTable::StoreTable(){

	for (int i = 0; i < tableSize; i++){

		productTable[i] = NULL;
	}

}
//_____________________________________________________________________________

//Deconstructor
StoreTable::~StoreTable(){

	for (int i = 0; i < tableSize; i++){

		if (productTable[i] != NULL){
			delete productTable[i];
		}
	}
}
//_____________________________________________________________________________

//Print Complete Inventory in Store
void StoreTable::printContents(){

	bool empty = true;

	for (int i = 0; i < tableSize; i++){

		if (productTable[i] != NULL){

			for (size_t j = 0; j < productTable[i]->size(); j++){

				cout << (*productTable[i])[j].title << ", $" << (*productTable[i])[j].price << ", " << (*productTable[i])[j].quantity << endl;
				empty = false;
			}
		}
	}
	if (empty == true){
		cout << "empty" << endl;
	}
	return;
}
//_____________________________________________________________________________

//Add inventory 
void StoreTable::insertProduct(string in_name, string in_category, int in_price, int in_quantity){

	int index = Index(in_name, tableSize);
	int stock;

	if (productTable[index] == NULL){

		productTable[index] = new vector<Product>;
		productTable[index]->push_back(Product(in_name, in_category, in_price, in_quantity));
	}
	else{

		for (size_t i = 0; i < productTable[index]->size(); i++){

			if ((*productTable[index])[i].title == in_name){

				stock = (*productTable[index])[i].quantity + in_quantity;
				Quantity(in_name, stock);
				cout << "duplicate" << endl;
				return;
			}
		}
		productTable[index]->push_back(Product(in_name, in_category, in_price, in_quantity));
	}

	return;
}
//_____________________________________________________________________________

//Products added to inventory
void StoreTable::ProductsInStore(string title, string category, int price, int quantity){

	insertProduct(title, category, price, quantity);

}
//_____________________________________________________________________________

//Products in inventory print by category and addition to items into cart
string StoreTable::printByCategory(string category){

	Cart c;

	bool empty = true;

	for (int i = 0; i < tableSize; i++)
	{
		if (productTable[i] != NULL)
		{
			for (size_t j = 0; j < productTable[i]->size(); j++)
			{
				if ((*productTable[i])[j].category == category){
					cout << (*productTable[i])[j].title << ", $" << (*productTable[i])[j].price << ", Quantity = " << (*productTable[i])[j].quantity << endl;
					empty = false;
				}
			}
		}
	}
	if (empty == true)
		cout << "empty" << endl;

	cout << endl;

	string option;
	string name;

	cout << "Would you like to add iteam? (Y/N) ";
	cout << endl;
	getline(cin, option);
	cin.clear();

	if (option == "Y" || option == "y"){
		cout << "Type name of product to store in cart: " << endl;
		getline(cin, name);
		return name;
	}
	else if (option == "N" || option == "n"){
		cout << "Thank you for visit" << endl;
		name = "ignore";
		return name;
	}
	else
	{
		cout << "Option not available" << endl;
	}

}
//_____________________________________________________________________________

//Adjusment of Quantity
void StoreTable::Quantity(std::string in_name, int new_quantity){

	int index = Index(in_name, tableSize);
	bool found = false;

	if (productTable[index] != NULL)
	{
		for (size_t i = 0; i < productTable[index]->size(); i++)
		{
			if ((*productTable[index])[i].title == in_name)
			{
				if (new_quantity == 0){
					deleteProduct(in_name);
				}
				else{
					(*productTable[index])[i].quantity = new_quantity;;
					found = true;
				}
				break;
			}
		}
	}
	if (found == false)
	{
		cout << "not found" << endl;
	}
	return;
}
//_____________________________________________________________________________

//Delete Products in store
void StoreTable::deleteProduct(string name)
{
	int index = Index(name, tableSize);
	bool found = false;

	if (productTable[index] != NULL)
	{
		for (size_t i = 0; i < productTable[index]->size(); i++)
		{
			if ((*productTable[index])[i].title == name)
			{
				productTable[index]->erase(productTable[index]->begin() + i);
				found = true;
				break;
			}
		}

		if (productTable[index]->size() == 0)
		{
			delete productTable[index];
			productTable[index] = NULL;
		}
	}
	if (found == false)
	{
		cout << "not found" << endl;
	}
	return;
}
//_____________________________________________________________________________

//Find Products in store
bool StoreTable::findProduct(string name)
{

	int index = Index(name, tableSize);
	bool found = false;

	if (productTable[index] != NULL)
	{
		for (size_t i = 0; i < productTable[index]->size(); i++)
		{
			if ((*productTable[index])[i].title == name)
			{
				cout << "PRODUCT DETAILS: " << endl;
				cout << "Title: " << (*productTable[index])[i].title << ", Category: " << (*productTable[index])[i].category << ", Price: " << (*productTable[index])[i].price << ", Stock: " << (*productTable[index])[i].quantity << endl;
				found = true;
				return found;
				break;
			}
		}
	}
	if (found == false)
	{
		if (name == "ignore"){
			cout << endl;
			return found;
		}
		else{
			cout << "not found" << endl;
			return found;
		}
	}

}
//_____________________________________________________________________________

// Location of item in HashTable (StoreTable)
int StoreTable::Index(string input_string, int size)
{
	int index = 0;
	for (size_t i = 1; i < input_string.length(); i++)
	{
		index = index + input_string[i];
	}
	index = index%size;
	return index;
}
//_____________________________________________________________________________

//Checkout and inventory upgrade
void StoreTable::ShoppingCheckout(std::string item){

	int index = Index(item, tableSize);
	bool found = false;
	int stock = 0;

	if (productTable[index] != NULL)
	{
		for (size_t i = 0; i < productTable[index]->size(); i++)
		{
			if ((*productTable[index])[i].title == item)
			{
				found = true;
				stock = (*productTable[index])[i].quantity - 1;
				Quantity(item, stock);

				//Receipt
				cout << "Thank you for shopping with us!" << endl;
				cout << "Items purchased: " << endl;
				cout << "Product: " << (*productTable[index])[i].title << ", Price: " << (*productTable[index])[i].price << endl;
				break;
			}
		}
	}
	if (found == false)
	{
		cout << "not found" << endl;
	}
}
//_____________________________________________________________________________

//Cart Constructor
Cart::Cart(){

	head = NULL;
}
//_____________________________________________________________________________

//Implemention of adding items to cart
void Cart::addToCart(string title) {


	node* newNode;
	newNode = new node;
	newNode->name = title;
	newNode->next = NULL;

	node* current;
	current = head;
	bool stop = false;

	if (head != NULL) {
		while (!stop){
			if (current->next == NULL) {
				stop = true;
				current->next = newNode;
				current->next->name = newNode->name;
			}
			current = current->next;
		}

	}
	else{
		head = newNode;
	}

	cout << "Item added to cart" << endl;

}
//_____________________________________________________________________________

//Search of item in link list of cart to delete product in cart
node* Cart::searchItemInCart(std::string title){

	if (head == NULL){
		return head;
	}

	node *current;
	current = head;
	node *previous;
	previous = head;

	while (current){
		if (current->name == title){
			return current;
		}
		previous = current;
		current = current->next;
	}
	return current;
}
//_____________________________________________________________________________

//Delete item in cart
void Cart::deleteItemInCart(std::string name){

	node *pointer;
	pointer = searchItemInCart(name);

	if (pointer == NULL){
		cout << name << " not in cart" << endl;
	}
	if (pointer == head){
		head = pointer->next;
		return;
	}

	node *current = head;
	node *previous = head;

	while (current) {
		if (current == pointer) {
			previous->next = current->next;
			return;
		}
		previous = current;
		current = current->next;
	}

}
//_____________________________________________________________________________

//Print cart
string Cart::cartPrint(){

	node* list = head;

	while (list) {
		return list->name;
		list = list->next;
	}

	delete list;

}
//_____________________________________________________________________________

void Cart::itemByItem(std::string item){

	cout << item << endl;
}
//_____________________________________________________________________________

//Checks if cart is empty
bool Cart::isEmpty(){

	node* link = head;
	bool empty = false;

	if (link == NULL){
		empty = true;
		return empty;
	}
	else{
		return empty;
	}
}


