#include <bits/stdc++.h>
using namespace std;

class Product{
public:
    string name;
    int price;
    Product(string name, int price){
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart {
    vector<Product*> products;
public:
    void addProduct(Product* p){
        products.push_back(p);
    }
    const vector<Product*>& getProducts(){
        return products;
    }
    int calculateTotal(){
        int total = 0;
        for(auto& p : products){
            total += p->price;
        }
        return total;
    }
};

class ShoppingCartPrinter{
private:
    ShoppingCart* cart;
public:
    ShoppingCartPrinter(ShoppingCart* cart){
        this->cart = cart;
    }
    void printInvoice(){
        cout << "Shopping Cart Invoice:\n";
        for (auto& p : cart->getProducts()) {
            cout << p->name << " - $" << p->price << endl;
        }
        cout << "Total: $" << cart->calculateTotal() << endl;
    }
};

class ShoppingCartStorage{
private:
    ShoppingCart* cart;
public:
    ShoppingCartStorage(ShoppingCart* cart){
        this->cart = cart;
    }
    void saveToDatabase() {
        cout << "Saving shopping cart to database..." << endl;
    }
};

int main(){
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop", 1500));
    cart->addProduct(new Product("Mouse", 50));
    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    ShoppingCartStorage* store = new ShoppingCartStorage(cart);
    printer->printInvoice();
    store->saveToDatabase();
}