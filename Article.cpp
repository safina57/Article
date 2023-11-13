//
// Created by msi on 13/11/2023.
//

#include "Article.h"

#include <utility>

using namespace std;
Article::Article() {
    this->nbReference=0;
    this->price=0;
    this->quantity=0;
    this->name="";
}
Article::Article(int nbReference, std::string name, float price, int quantity) {
    this->nbReference=nbReference;
    this->price=price;
    this->quantity=quantity;
    this->name=std::move(name);
}
int Article::getNbReference() const {
    return nbReference;
}
string Article::getName() {
    return name;
}
float Article::getPrice() const {
    return price;
}
int Article::getQuantity() const {
    return quantity;
}
void Article::setName() {
    cout<<"name:";
    fflush(stdin);
    getline(cin, this->name);
}
void Article::setQuantity() {
    cout<<"Quantity:";
    cin>> this->quantity;
}
void Article::setNbReference() {
    cout<<"Reference:";
    cin>> this->nbReference;
}
void Article::setPrice() {
    cout<<"Price:";
    cin>>this->price;
}
string Article::toString() const {
    return ("NbReference:"+ to_string((this->nbReference)) +" Name:"+ this->name+" Price:"+ to_string((this->price))+" Quantity:"+ to_string((this->quantity)));
}

