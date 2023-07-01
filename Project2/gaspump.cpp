#include "gaspump.h"

// Assigns the given parameters for each GasPump object
GasPump::GasPump(std::string type, double price) {
    gasType = type;
    pricePerGallon = price;
}

// Calculates how many gallons were purchased
double GasPump::dispenseFuel(double amt) {
    double gallons = amt / pricePerGallon;

    totalFuel += gallons;
    totalAmt += amt;

    return gallons;
}