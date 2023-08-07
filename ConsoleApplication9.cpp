#include <iostream>
using namespace std;

class Airplane {
public:
    virtual void performFlight() const = 0;
};

class PassengerAirplane : public Airplane {
public:
    void performFlight() const override {
        cout << "Passenger airplane is taking off with passengers onboard." << endl;
    }
};

class CargoAirplane : public Airplane {
public:
    void performFlight() const override {
        cout << "Cargo airplane is transporting goods." << endl;
    }
};

class MilitaryAirplane : public Airplane {
public:
    void performFlight() const override {
        cout << "Military airplane is on a tactical mission." << endl;
    }
};

class Airport {
public:
    Airport() : numAirplanes(0) {}

    void addAirplane(Airplane* airplane) {
        if (numAirplanes < MAX_AIRPLANES) {
            airplanes[numAirplanes++] = airplane;
        }
    }

    void operateFlights() const {
        for (int i = 0; i < numAirplanes; ++i) {
            airplanes[i]->performFlight();
        }
    }

private:
    static const int MAX_AIRPLANES = 10;
    Airplane* airplanes[MAX_AIRPLANES];
    int numAirplanes;
};

int main() {
    PassengerAirplane passengerPlane;
    CargoAirplane cargoPlane;
    MilitaryAirplane militaryPlane;

    Airport airport;
    airport.addAirplane(&passengerPlane);
    airport.addAirplane(&cargoPlane);
    airport.addAirplane(&militaryPlane);

    airport.operateFlights();

    return 0;
}
