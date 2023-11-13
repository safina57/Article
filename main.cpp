#include "Stock.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void Menu() {
    cout << "==== Menu ====\n";
    cout << "1. Rechercher un article par reference.\n";
    cout << "2. Ajouter un article au stock.\n";
    cout << "3. Afficher les articles.\n";
    cout << "4. Supprimer un article par reference.\n";
    cout << "5. Modifier un article par reference.\n";
    cout << "6. Rechercher un article par nom.\n";
    cout << "7. Rechercher un article par intervalle de prix de vente.\n";
    cout << "8. Stocker tous les articles dans un fichier.\n";
    cout << "9. Quitter.\n";
    cout << "==============\n";
}
int main() {
    Stock stockManagement;
    int choice;
    do {
        Menu();
        cout << "Enter Your choice : "<<endl;
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Enter the reference :"<<endl;
                int reference;
                cin>>reference;
                try {
                    Article foundArticle = stockManagement.find(reference);
                    cout << foundArticle.toString() << endl;
                } catch (int n) {
                    std::cout << "Article not found"<<endl;
                }
            }break;
            case 2: {
                Article newAdded;
                newAdded.setNbReference();
                newAdded.setName();
                newAdded.setPrice();
                newAdded.setQuantity();
                stockManagement.add(newAdded);
            }break;
            case 3: {
                try {
                    stockManagement.print();
                } catch(int n){
                    cout<<"Empty Stock"<<endl;
                }
            }break;
            case 4: {
                cout << "Enter the reference :"<<endl;
                int reference;
                cin>>reference;
                try {
                    stockManagement.erase(reference);
                }catch(int n){
                    cout<<"Article not found"<<endl;
                }
            }break;
            case 5: {
                cout << "Enter the reference :"<<endl;
                int reference;
                cin>>reference;
                try{
                    stockManagement.change(reference);
                    Article modifiedArticle=stockManagement.find(reference);
                    cout<<modifiedArticle.toString()<<endl;
                }catch (int n){
                    cout<<"Article not found"<<endl;
                }
            }break;
            case 6: {
                cout << "Enter the name :"<<endl;
                string name;
                fflush(stdin);
                getline(cin, name);
                try {
                    Article foundArticleByName = stockManagement.find(name);
                    cout << foundArticleByName.toString() << endl;
                } catch (int n) {
                    std::cout << "Article not found"<<endl;
                }
            }break;
            case 7: {
                cout<<"Enter your Price range from the min to max:"<<endl;
                float min,max;
                cin>>min>>max;
                try {
                    vector<Article> foundArticlesByPrice = stockManagement.find(min,max);
                    for (const auto &article: foundArticlesByPrice) {
                        cout << article.toString() << endl;
                    }
                } catch (int n) {
                    cout << "No articles found in the specified price range"<<endl;
                }
            }break;
            case 8: {
                stockManagement.save();
            }break;
            case 9: {
                cout<<"Programme is over"<<endl;
            }break;
            default: {
            cout << "Error,retry!" << endl;
        }
        }
    }while(choice!=9);
    return 0;
}
