//
// Created by msi on 13/11/2023.
//

#ifndef TP4_STOCK_H
#define TP4_STOCK_H
#include "Article.h"
#include <unordered_map>
#include <vector>
using namespace std;
class Stock {
private:
    unordered_map<int,Article> collection;
public:
    Article find(int reference);
    void add(const Article& a);
    void print();
    void erase(int reference);
    void change(int reference);
    Article find(const string& name);
    vector<Article> find(float min,float max);
    void save();
};


#endif //TP4_STOCK_H
