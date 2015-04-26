//Name: Linda Palacios Rivera
//Final Project
//Resources: Assignment solutions, and Lecture notes

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "ShoppingHeader.h"

using namespace std;


void displayMenu();

int main(int argc, char*argv[])
{

	int input;

	//node* head = NULL;

	// Create a new communication network
	StoreTable store;
	Cart cart;

	store.ProductsInStore("Memory Foam Contour Pillow", "BedandBath", 32, 5);
	store.ProductsInStore("Egyptian Cotton Sheets", "BedandBath", 57, 3);
	store.ProductsInStore("Classic Bath Rug Collection", "BedandBath", 40, 7);
	store.ProductsInStore("Angry Birds Bath Rug", "BedandBath", 20, 5);
	store.ProductsInStore("One-Piece Swimsuit", "Women", 12, 15);
	store.ProductsInStore("All Weather Hooded Coat", "Women", 80, 4);
	store.ProductsInStore("Sleeveless Floral-Print Dress", "Women", 25, 10);
	store.ProductsInStore("Short-Sleeve T-shirt", "Men", 10, 2);
	store.ProductsInStore("Ray-Ban Sunglasses", "Men", 95, 9);
	store.ProductsInStore("Dockers Microfiber Shorts", "Men", 27, 6);
	store.ProductsInStore("MAC lipstick", "Beauty", 16, 1);
	store.ProductsInStore("Skincare Essentials", "Beauty", 88, 3);
	store.ProductsInStore("Turbo Wash", "Beauty", 10, 7);


	// Flag used for exiting menu
	bool quit = false;

	// Used for input 
	string input1;
	string input2;
	string input3;
	string input4;
	string name;
	bool n = false;

	while (quit != true)
	{
		displayMenu();
		cin >> input;

		//clear out cin
		cin.clear();
		cin.ignore(10000, '\n');

		switch (input)
		{
			//Prroducts in stock by catergory plus add item into cart
		case 1:
			cout << endl;
			cout << "Categories: BedandBath, Women, Men, Beauty" << endl;
			cout << "Type category: ";
			getline(cin, input1);
			cout << endl;
			name = store.printByCategory(input1);
			if (store.findProduct(name)){
				cart.addToCart(name);
			}
			cout << endl;
			break;

			// View Cart
		case 2:
			n = cart.isEmpty();
			if (n){
				cout << "cart is empty" << endl;
			}
			else{
				cout << "Items in cart: " << endl;
				name = cart.cartPrint();
				cart.itemByItem(name);
				cout << endl;
				cout << "Would you like to purchase items? (Y/N)" << endl;
				getline(cin, input1);
				if (input1 == "Y" || input1 == "y"){
					store.ShoppingCheckout(name);
					cart.deleteItemInCart(name);
				}
				else{
				}
			}
			cout << endl;
			break;

			// Delete product from cart
		case 3:
			cout << "Enter title:" << endl;
			getline(cin, input1);
			cart.deleteItemInCart(input1);
			cout << endl;
			break;

			// Add inventory
		case 4:
			cout << "Enter title:" << endl;
			getline(cin, input1);
			cout << "Enter category: (BedandBath/Women/Men/Beauty)" << endl;
			getline(cin, input2);
			cout << "Enter price:" << endl;
			getline(cin, input3);
			cout << "Enter quantity:" << endl;
			getline(cin, input4);
			store.insertProduct(input1, input2, stoi(input3), stoi(input4));
			cout << endl;
			break;

			//Delete items in inventory
		case 5:
			cout << "Enter title: " << endl;
			getline(cin, input1);
			store.deleteProduct(input1);
			cout << endl;
			break;

			// Find product in store
		case 6:
			cout << "Enter title:" << endl;
			(cin, input1);
			n = store.findProduct(input1);
			cout << endl;
			break;

			// Print complete inventory in store
		case 7:
			cout << "COMPLETE INVENTORY:" << endl;
			store.printContents();
			cout << endl;
			break;
			// Quit
		case 8:
			cout << "Thank you for choosing us!" << endl;
			quit = true;
			break;

			// invalid input
		default:
			cout << "Invalid Input" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			break;
		}
	}

	return 0;
}

/*displays a menu with options to enqueue and dequeue a message and transmit the entire message and quit*/
void displayMenu(){

	cout << "======Main Menu======" << endl;
	cout << "Customer Options: " << endl;
	cout << "1. Categories/Add to cart" << endl;
	cout << "2. View/Purchase Cart" << endl;
	cout << "3. Delete item from cart" << endl;
	cout << "------------------------------" << endl;
	cout << "Store Options: " << endl;
	cout << "4. Add inventory" << endl;
	cout << "5. Delete Items in inventory" << endl;
	cout << "6. Find item in store" << endl;
	cout << "7. Print complete inventory" << endl;
	cout << "8. Quit" << endl;
	return;
}