#ifndef LOAN2_HOUSE_H
#define LOAN2_HOUSE_H

#endif

#include <list>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <set>

using namespace std;

template<typename T>
class House1{
protected:
    string name;
    int quantity1;
    T price;
    T square1;
public:
    House1(string n, int q1, T p, T s1) : name(n), quantity1(q1), price(p), square1(s1){}
    virtual void print(){
        cout << "Name: " << name << "\nQuantity: " << quantity1 << "\nPrice: " << price << "\nSquare: " << square1 << "\n\n";
    }
    friend ostream& operator << (ostream& OS, House1<T>& h){
        h.print();
        return OS;
    }
    virtual T PricePerMeter(){
        return price/square1;
    }
    virtual T getSquare() const{
        return square1;
    }
    bool operator > (const House1<T>& other) const{
        return square1 > other->square1;
    }
    bool operator < (const House1<T>& other) const{
        return square1 < other->square1;
    }
    static void insert(list<House1<T>*>&list, string filename){
        ifstream fin(filename);
        string tempN;
        int tempQ;
        T tempP;
        T tempS;
        if(!fin.is_open()){
            cerr << "Unable to open file" << endl;
            return;
        }
        while(fin >> tempN >> tempQ >> tempP >> tempS){
            House1<T>* temp = new House1<T>(tempN, tempQ, tempP, tempS);
            list.push_back(dynamic_cast<House1<T>*>(temp));
        }
        fin.close();
    }
    virtual string getName() const{
        return name;
    }
};