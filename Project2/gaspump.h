#ifndef GASPUMP_H
#define GASPUMP_H

#include <string>
#include <iostream>
using namespace std;

class GasPump {
    private:
        string gasType;
        double pricePerGallon;
        double totalFuel;
        double totalAmt;
    public:
        GasPump(string type, double price);

        string returnType() {
            return gasType;
        }

        double returnPrice() {
            return pricePerGallon;
        }

        double returnTotalFuel() {
            return totalFuel;
        }

        double returnTotalAmt() {
            return totalAmt;
        }

        double dispenseFuel(double amt);
};

#endif