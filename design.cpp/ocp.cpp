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

class Persistence{
private:
    ShoppingCart* cart;
public:
    virtual void save(ShoppingCart* cart)=0;
};
class SQLPersistence : public Persistence {
public:
    void save(ShoppingCart* cart) override {
                cout << "Saving shopping cart to SQL database..." << endl;
    }
};
class MongoPersistence : public Persistence {
public:
    void save(ShoppingCart* cart) override {
                cout << "Saving shopping cart to Mongo database..." << endl;
    }
};
class FilePersistence : public Persistence {
public:
    void save(ShoppingCart* cart) override {
                cout << "Saving shopping cart to File..." << endl;
    }
};

int main(){
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop", 1500));
    cart->addProduct(new Product("Mouse", 50));
    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();
    Persistence* storeMongo = new MongoPersistence();
    storeMongo->save(cart);
    Persistence* storeSQL= new SQLPersistence();
    storeSQL->save(cart);
    Persistence* storeFile = new FilePersistence();
    storeFile->save(cart);
    
}