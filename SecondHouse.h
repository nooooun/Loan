#ifndef LOAN2_SECONDHOUSE_H
#define LOAN2_SECONDHOUSE_H

#endif //LOAN2_SECONDHOUSE_H

#include "House.h"

template<typename T>
class House2 : public House1<T>{
protected:
    int quantity2;
    //T square2;
    T zn;
public:
    House2() : House1<T>(" ", 0, 0, 0), quantity2(0), zn(0){}
    House2(string name, int quantity, int q2, T price, T square, T z) : House1<T>(name, quantity, price, square), quantity2(q2), zn(z){}
    void print(){
        cout << "Name: " << this->name << "\nQuantity: " << this->quantity1 + quantity2 << "\nPrice: " << this->price << "\nSquare: " << this->square1 << "\nZn: " << zn << "\n\n";
    }
    T PricePerMeter(){
        return this->price * (1 - zn) / this->square1;
    }
    static void insert(list<House1<T>*>&list, string filename){
        ifstream fin(filename);
        string tempN;
        int tempQ1;
        int tempQ2;
        T tempP;
        T tempS1;
        T tempZ;
        if(!fin.is_open()){
            cerr << "Unable to open file" << endl;
            return;
        }
        while(fin >> tempN >> tempQ1 >> tempQ2 >> tempP >> tempS1 >> tempZ){
            House2<T>* temp = new House2<T>(tempN, tempQ1, tempQ2, tempP, tempS1, tempZ);
            list.push_back(dynamic_cast<House1<T>*>(temp));
        }
        fin.close();
    }
    bool operator > (const House1<T>& other) const{
        return this->square1 > other->square1;
    }
    bool operator < (const House1<T>& other) const{
        return this->square1 < other->square1;
    }
    T getSquare() const{
        return this->square1;
    }
    string getName() const{
        return this->name;
    }
};