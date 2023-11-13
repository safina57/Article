//
// Created by msi on 13/11/2023.
//
#include "Stock.h"
#include <fstream>
using namespace std;
Article Stock::find(int reference) {
    if(collection.count(reference)){
        return collection[reference];
    }
    else
        throw 0;
}
void Stock::add(const Article& a) {
    if(!collection.count(a.getNbReference()))
        collection[a.getNbReference()]=a;
    else
        cout<<"This reference already exists"<<endl;
}
void Stock::print(){
    if(!collection.empty()) {
        for (const auto &entry: collection) {
            cout << entry.second.toString() << endl;
        }
    }
    else
        throw 0;
}
void Stock::erase(int reference) {
    if(collection.count(reference)){
        collection.erase(reference);
    }
    else
        throw 0;
}
void Stock::change(int reference) {
    int n;
    if(collection.count(reference)) {
        cout << "1 :change name" << endl << "2 :change price" << endl << "3 :change quantity" << endl;
        cin >> n;
        switch (n) {
            case 1:
                collection[reference].setName();
                break;
            case 2:
                collection[reference].setPrice();
                break;
            case 3:
                collection[reference].setQuantity();
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
    else
        throw 0;
}
Article Stock::find(const string& name) {
    for (const auto& entry : collection){
        if(name==collection[entry.first].getName())
            return entry.second;
    }
    throw 0;
}
vector<Article> Stock::find(float min, float max) {
    vector<Article> temp;
    for (const auto& entry : collection){
        if((min<=collection[entry.first].getPrice())&&(collection[entry.first].getPrice()<=max)){
            temp.push_back(entry.second);
        }
    }
    if(temp.empty())
        throw 0;
    return temp;
}
void Stock::save() {
    ofstream file("C:/Users/msi/Desktop/stock.txt");

    if (file.is_open()) {
        for (const auto& article : collection) {
            file << article.second.toString() << endl;
        }
        file.close();
        cout<<"Success!"<<endl;
    } else {
        std::cout << "Error "<<endl;
    }
}


