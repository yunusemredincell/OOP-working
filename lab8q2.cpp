#include <iostream>

using namespace std;

class Car
{

protected:
    string brandname;
    int modelYear, price, totalCost;

public:
    Car();
    Car(string brandname, int price, int modelYear);
    Car(const Car &c);
    string getBrandName();
    int getModelYear();
    int getPrice();
    int getCost();
};

Car::Car()
{
}

Car::Car(string brandname, int price, int modelYear)
{
    this->brandname = brandname;
    this->price = price;
    this->modelYear = modelYear;
}

Car::Car(const Car &c)
{
    this->brandname = c.brandname;
    this->modelYear = c.modelYear;
    this->price = c.price;
    this->totalCost = c.totalCost;
}

string Car::getBrandName()
{
    return brandname;
}

int Car::getModelYear()
{
    return modelYear;
}

int Car::getPrice()
{
    return price;
}

int Car::getCost()
{
    return totalCost;
}

class ElectricCar : virtual public Car
{
protected:
    int NumberOfBatteries;
    int electricCost;

public:
    ElectricCar();
    ElectricCar(string brandname, int modelYear, int price, int NumberOfBatteries, int electricCost);
    ElectricCar(const ElectricCar &e);
    void setNumberOfBatteries(int NumberOfBatteries);
    void setElectricCost(int electricCost);
    friend ostream &operator<<(ostream &os, const ElectricCar &obj);
};

ElectricCar::ElectricCar()
{
}

ElectricCar::ElectricCar(string brandname, int modelYear, int price, int NumberOfBatteries, int electricCost)
{
    this->brandname = Car::brandname;
    this->modelYear = Car::modelYear;
    this->price = Car::price;
    this->NumberOfBatteries = NumberOfBatteries;
    this->electricCost = electricCost;
    this->totalCost = this->electricCost;
}

ElectricCar::ElectricCar(const ElectricCar &e)
{
    this->brandname = e.brandname;
    this->modelYear = e.modelYear;
    this->price = e.price;
    this->totalCost = e.totalCost;
    this->electricCost = e.electricCost;
    this->NumberOfBatteries = e.NumberOfBatteries;
}

void ElectricCar::setElectricCost(int ElectricCost)
{
    this->electricCost = ElectricCost;
    this->totalCost = ElectricCost;
}

void ElectricCar::setNumberOfBatteries(int NumberOfBatteries)
{
    this->NumberOfBatteries = NumberOfBatteries;
}

ostream &operator<<(ostream &os, const ElectricCar &obj)
{
    os << obj.brandname << " " << obj.modelYear << " "
       << "Price: " << obj.price << " "
       << "Number Of Batteries: " << obj.NumberOfBatteries << " "
       << "Electric Cost: " << obj.electricCost << " "
       << "Total Cost: " << obj.totalCost << endl;
    return os;
}

class GasolineCar : virtual public Car
{

protected:
    int fuelCost;
    int engineVolume;

public:
    GasolineCar();
    GasolineCar(string brandname, int modelYear, int price, int NumberOfBatteries, int electricCost);
    GasolineCar(const GasolineCar &g);
    void setFuelCost(int fuelCost);
    void setEngineVolume(int engineVolume);
    friend ostream &operator<<(ostream &os, const GasolineCar &obj);
};

GasolineCar::GasolineCar()
{
}

GasolineCar::GasolineCar(string brandname, int modelyear, int price, int fuelCost, int engineVolume)
{
    this->brandname = Car::brandname;
    this->modelYear = Car::modelYear;
    this->price = Car::price;
    this->engineVolume = engineVolume;
    this->fuelCost = fuelCost;
    this->totalCost = this->fuelCost;
}

GasolineCar::GasolineCar(const GasolineCar &g)
{
    this->brandname = g.brandname;
    this->modelYear = g.modelYear;
    this->price = g.price;
    this->totalCost = g.totalCost;
    this->fuelCost = g.fuelCost;
    this->engineVolume = g.engineVolume;
}

void GasolineCar::setFuelCost(int fuelCost)
{
    this->fuelCost = fuelCost;
    this->totalCost = fuelCost;
}

void GasolineCar::setEngineVolume(int engineVolume)
{
    this->engineVolume = engineVolume;
}

ostream &operator<<(ostream &os, const GasolineCar &obj)
{
    os << obj.brandname << " "
       << obj.modelYear << " "
       << "Price: " << obj.price << " "
       << "EngineVolume: " << obj.engineVolume << " "
       << "Fuel Cost: " << obj.fuelCost << " "
       << "Total Cost: "
       << obj.totalCost << endl;
    return os;
}

class HybridCar : public ElectricCar, GasolineCar
{

public:
    HybridCar();
    ElectricCar(const ElectricCar &e);
    friend ostream &operator<<(ostream &os, const HybridCar &obj);
};

HybridCar::HybridCar()
{
    this->fuelCost = 0;
    this->engineVolume = 0;
    this->totalCost = this->electricCost + this->fuelCost;
}

HybridCar::ElectricCar(const ElectricCar &e)
{
    this->brandname = e.brandname;
    this->modelYear = e.modelYear;
    this->price = e.price;
    this->totalCost = e.totalCost;
    this->electricCost = e.electricCost;
    this->NumberOfBatteries = e.NumberOfBatteries;
}

std::ostream &operator<<(ostream &os, const HybridCar &obj)
{
    os << obj.brandname << " "
       << obj.modelyear << " "
       << "Price: " << obj.price << " "
       << "NumberOfBatteries: " << obj.NumberOfBatteries << " "
       << "Electric Cost: " << obj.electricCost << " "
       << "EngineVolume: " << obj.engineVolume << " "
       << "Fuel Cost: " << obj.fuelCost << " "
       << "Total Cost: "
       << obj.totalcost << endl;
    return os;
}

int main()
{
    vector<ElectricCar> vectorE;
    vector<GasolineCar> vectorG;
    vector<HybridCar> vectorH;
    int choice;

    cout << "1 - Electric Car" << endl
         << "2 - Gasoline Car" << endl
         << "3 - Hybrid Car" << endl
         << "4 - Exit" << endl;

    cout << "Enter your choice: ";
    cin >> choice;
    while (choice != 4)
    {
        if (choice == 1)
        {
            string tempname;
            int tempyear, tempprice, tempcost, tempbattery;

            cout << "Enter a brand name: ";
            cin >> tempname;

            cout << "Enter model year: ";
            cin >> tempyear;

            cout << "Enter price of car: ";
            cin >> tempprice;

            cout << "Enter number of batteries: ";
            cin >> tempbattery;

            cout << "Enter electric cost: ";
            cin >> tempcost;

            ElectricCar temp{tempname, tempyear, tempprice, tempbattery, tempcost};
            vectorE.push_back(temp);
        }
        else if (choice == 2)
        {
            string tempname;
            int tempyear, tempprice, tempcost, tempbattery;

            cout << "Enter a brandname: ";
            cin >> tempname;

            cout << "Enter model year: ";
            cin >> tempyear;

            cout << "Enter price of car: ";
            cin >> tempprice;

            cout << "Enter number of batteries: ";
            cin >> tempbattery;

            cout << "Enter electric cost: ";
            cin >> tempcost;

            GasolineCar temp{tempname, tempyear, tempprice, tempbattery, tempcost};
            vectorG.push_back(temp);
        }
        else if (choice == 3)
        {
            string tempname;
            int tempyear, tempprice, tempcost, tempbattery;

            cout << "Enter a brandname: ";
            cin >> tempname;

            cout << "Enter model year: ";
            cin >> tempyear;

            cout << "Enter price of car: ";
            cin >> tempprice;

            cout << "Enter number of batteries: ";
            cin >> tempbattery;

            cout << "Enter electric cost: ";
            cin >> tempcost;
        }
        cout << "1 - Electric Car" << endl
             << "2 - Gasoline Car" << endl
             << "3 - Hybrid Car" << endl
             << "4 - Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
    }

    return 0;
}