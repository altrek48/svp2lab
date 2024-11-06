#include <iostream>
#include <string>

class Vehicle
{
protected:
    double m_fuelConsumptionLitresPerKm, m_fuelLevel, m_fuelLevelMax, m_milageKm;
    std::string m_name;
protected:
    Vehicle() : m_fuelConsumptionLitresPerKm(0.0), m_fuelLevel(0.0), m_fuelLevelMax(0.0), m_milageKm(0) {};
public:
    void drive(int);
    void refuel();
    void printStatus();
};
using namespace std;
void Vehicle::drive(const int kilometers)
{
    const double requiredFuelLitres = ((double)kilometers) / 100.0 * m_fuelConsumptionLitresPerKm;
    if (requiredFuelLitres > m_fuelLevel)
    {
        cout << "Error: Not enough fuel to drive " << kilometers << " km" << endl;
        return;
    }
    cout << m_name << ": Drive " << kilometers << " km" << endl;
    m_milageKm += kilometers;
    m_fuelLevel -= requiredFuelLitres;
}
void Vehicle::refuel()
{
    cout << "Refuel " << m_name << endl;
    m_fuelLevel = m_fuelLevelMax;
}

void Vehicle::printStatus()
{
    cout << m_name << " status: Mileage(km)=" << m_milageKm << ", Fuel level(l)=" << m_fuelLevel << endl;
}
class Sedan : public Vehicle
{
public:
    Sedan();
};

Sedan::Sedan()
{
    m_fuelConsumptionLitresPerKm = 7.0;
    m_fuelLevelMax = 50.0;
    m_name = "Sedan";
}
class Suv : public Vehicle
{
public:
    Suv();
};
Suv::Suv()
{
    m_fuelConsumptionLitresPerKm = 11.0;
    m_fuelLevelMax = 80.0;
    m_name = "Suv";
}

class Bus : public Vehicle
{
public:
    Bus();
};

Bus::Bus()
{
    m_fuelConsumptionLitresPerKm = 25.0;
    m_fuelLevelMax = 120.0;
    m_name = "Bus";
}
int main()
{
    Vehicle* vehicles[3] = { new Sedan, new Suv, new Bus };
    for (int i = 0; i < 3; ++i) {
        Vehicle* vehicle = vehicles[i];
        vehicle->refuel();
        vehicle->printStatus();
        vehicle->drive(120);
        vehicle->printStatus();
        vehicle->drive(420);
        vehicle->printStatus();
        vehicle->drive(300);
        vehicle->printStatus();
        vehicle->refuel();
        vehicle->drive(300);
        vehicle->printStatus();
        delete vehicle;
        cout << endl;
    }
    return 0;
}
