//Eduardo Avila
//COMSC - 210 - 5293
//Lab 20 - Chair Maker 3000

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;
const int SIZE = 3;

class Chair {
private:
    int legs;
    double *prices;

public:
    //constructors updated
    Chair() {
        prices = new double[SIZE];
        legs = rand() % 2 + 3;

        const int MIN = 10000, MAX = 99999;

        for (int i = 0; i < SIZE; i++)
            prices[i] = (rand() % (MAX-MIN+1) + MIN) / 100.0;
    }

    Chair(int l, double cost[]) {
        prices = new double[SIZE];
        legs = l;

        for (int i = 0; i < SIZE; i++)
            prices[i] = cost[i];
    }

    // setters and getters
    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }

    void setPrices(double p1, double p2, double p3) { 
        prices[0] = p1; prices[1] = p2; prices[2] = p3; 
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl; //error
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    cout << fixed << setprecision(2);

    srand(time(0));

    //creating pointer to first chair object
    Chair *chairPtr = new Chair;

    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();

    //creating dynamic chair object with constructor
    double livingPrices[SIZE] = {525.25, 434.34, 252.52};
    Chair *livingChair = new Chair(3, livingPrices);

    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];

    //loop to display each chair
    for (int i = 0; i < SIZE; i++) {
        collection[i].print();
    }

    //deletion of new stuff
    delete[] collection;
    collection = nullptr;
    for (int i = 0; i < SIZE; i++)
        collection[i].print();
    
    return 0;
}