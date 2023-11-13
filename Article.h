//
// Created by msi on 13/11/2023.
//

#ifndef TP4_ARTICLE_H
#define TP4_ARTICLE_H
#include <iostream>
#include <string>
using namespace std;
class Article {
private:
    int nbReference;
    string name;
    float price;
    int quantity;
public:
    Article();
    Article(int nbReference,string name,float price,int quantity);
    int getNbReference() const;
    string getName();
    float getPrice() const;
    int getQuantity() const;
    void setNbReference();
    void setName();
    void setPrice();
    void setQuantity();
    string toString() const;
};


#endif //TP4_ARTICLE_H
