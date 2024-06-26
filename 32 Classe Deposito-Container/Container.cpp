#include <iostream>
#include "Container.h"

using namespace std;

/*COSTRUTTORI e DISTRUTTORE*/
Container::Container() {
    code = 0;
    type = "undefined";
    weight = 0;
    category = "undefined";

    Data date;
    stockDate = date;
}
Container::Container(int c, string t, double w, string ctgry, Data date) {
    code = c;
    type = t;
    weight = w;
    category = ctgry;
    stockDate = date;
}
Container::~Container() {

}
/*SET e GET*/
void Container::setCode(int c) {
    code = c;
}
void Container::setType(string t) {
    type = t;
}
void Container::setWeight(double w) {
    weight = w;
}
void Container::setCategory(string ctgry) {
    category = ctgry;
}
void Container::setStockDate(Data date) {
    stockDate = date;
}
void Container::setAll(int c, string t, double w, string ctgry, Data date) {
    code = c;
    type = t;
    weight = w;
    category = ctgry;
    stockDate = date;
}

int Container::getCode() {
    return code;
}
string Container::getType() {
    return type;
}
double Container::getWeight() {
    return weight;
}
string Container::getCategory() {
    return category;
}
Data Container::getStockDate() {
    return stockDate;
}
/*OVERLOADING OUTPUT*/
ostream& operator<<(ostream& out, const Container& d) {
    out << "Code: " << d.code << endl;
    out << "Type: " << d.type << endl;
    out << "Weight: " << d.weight << endl;
    out << "Category: " << d.category << endl;
    out << endl << d.stockDate;
}
/*OVERLOADING INPUT*/
istream& operator>>(istream& in, Container& d) {
    int n;
    cout << "Code: ";
    in >> d.code;

    cout << "Type: ";
    in >> d.type;

    cout << "Weight: ";
    in >> d.weight;

    cout << "Category: ";
    in >> d.category;

    do {
        cout << "Anno: ";
        in >> n;
        d.stockDate.setAnno(n);

        cout << "Mese: ";
        in >> n;
        d.stockDate.setAnno(n);

        cout << "giorno: ";
        in >> n;
        d.stockDate.setAnno(n);
    } while (d.stockDate.validaData() == 1);

    return in;
}