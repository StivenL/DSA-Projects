#ifndef GASPUMP_H
#define GASPUMP_H

#include <string>
#include <iostream>

class GasPump {
    private:
        std::string gasType;
        double pricePerGallon;
        double totalFuel;
        double totalAmt;
    public:
        GasPump(std::string type, double price);

        std::string returnType() {
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