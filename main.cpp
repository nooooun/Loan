#include "SecondHouse.h"

int main() {
    list<House1<double>*>list1;
    House1<double>::insert(list1, "1floor.txt");
    House2<double>::insert(list1, "2floor.txt");
    for(auto a : list1){
        cout << *a;
    }
    auto maxEl = *max_element(list1.begin(), list1.end(), [](const House1<double>*a, const House1<double>*b) { return a->getSquare() < b->getSquare(); });
    list1.sort([](const House1<double>* a, House1<double>*b) { return a->getSquare() < b->getSquare(); });
    cout << "Max: " << *maxEl << endl;
    cout << "Sorted:" << endl;
    for(auto a : list1){
        cout << *a;
    }
    list1.sort([](const House1<double>*a, const House1<double>*b) {return a->getName() > b->getName();});
    auto last = unique(list1.begin(), list1.end(), [](const House1<double>*a, const House1<double>*b) {return a->getName() == b->getName();});
    list1.erase(last, list1.end());
    cout << "With unique name: " << endl;
    for(auto a : list1){
        cout << *a;
    }
    return 0;
}
