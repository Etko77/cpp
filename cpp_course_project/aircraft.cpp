#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

class AircraftSpecifications {
private:
    string manufacturer;
    string model;
    int seatCapacity;
    double minRunwayLength;
    double fuelConsumptionPerKm;
    double tankCapacity;
    double averageSpeed;

public:
    // DEFAULT CONSTRUCTOR
    AircraftSpecifications() : seatCapacity(0), minRunwayLength(0.0), fuelConsumptionPerKm(0.0), 
                                tankCapacity(0.0), averageSpeed(0.0) {}

    // PARAMETERIZED CONSTRUCTOR
    AircraftSpecifications(const string& manufacturer, const string& model, int seatCapacity,
                           double minRunwayLength, double fuelConsumptionPerKm, double tankCapacity,
                           double averageSpeed)
        : manufacturer(manufacturer), model(model), seatCapacity(seatCapacity),
          minRunwayLength(minRunwayLength), fuelConsumptionPerKm(fuelConsumptionPerKm),
          tankCapacity(tankCapacity), averageSpeed(averageSpeed) {}

    // GETTERS + SETTERS
    const string& getManufacturer() const { return manufacturer; }
    void setManufacturer(const string& manufacturer) { this->manufacturer = manufacturer; }

    const string& getModel() const { return model; }
    void setModel(const string& model) { this->model = model; }

    int getSeatCapacity() const { return seatCapacity; }
    void setSeatCapacity(int seatCapacity) {
        if (seatCapacity > 0) this->seatCapacity = seatCapacity;
    }

    double getMinRunwayLength() const { return minRunwayLength; }
    void setMinRunwayLength(double minRunwayLength) {
        if (minRunwayLength > 0) this->minRunwayLength = minRunwayLength;
    }

    double getFuelConsumptionPerKm() const { return fuelConsumptionPerKm; }
    void setFuelConsumptionPerKm(double fuelConsumptionPerKm) {
        if (fuelConsumptionPerKm > 0) this->fuelConsumptionPerKm = fuelConsumptionPerKm;
    }

    double getTankCapacity() const { return tankCapacity; }
    void setTankCapacity(double tankCapacity) {
        if (tankCapacity > 0) this->tankCapacity = tankCapacity;
    }

    double getAverageSpeed() const { return averageSpeed; }
    void setAverageSpeed(double averageSpeed) {
        if (averageSpeed > 0) this->averageSpeed = averageSpeed;
    }

    // MAX FLIGHT DISTANCE
    double calculateMaxFlightDistance() const {
        return tankCapacity / fuelConsumptionPerKm;
    }
};

class Aircraft {
private:
    string id;
    AircraftSpecifications specifications;
    double crewCost;

public:
    // DEFAULT CONSTRUCTOR
    Aircraft() : crewCost(0.0) {}

    // PARAMETERIZED CONSTRUCTOR
    Aircraft(const string& id, const AircraftSpecifications& specifications, double crewCost)
        : id(id), specifications(specifications), crewCost(crewCost) {}

    // GETTERS + SETTERS
    const string& getId() const { return id; }
    void setId(const string& id) { this->id = id; }

    const AircraftSpecifications& getSpecifications() const { return specifications; }
    void setSpecifications(const AircraftSpecifications& specifications) { this->specifications = specifications; }

    double getCrewCost() const { return crewCost; }
    void setCrewCost(double crewCost) {
        if (crewCost > 0) this->crewCost = crewCost;
    }

    // OVERLOADED OPERATOR FOR PRINTING ( << )
    friend ostream& operator<<(ostream& os, const Aircraft& aircraft) {
        os << "ID: " << aircraft.id << "\n"
           << "Manufacturer: " << aircraft.specifications.getManufacturer() << "\n"
           << "Model: " << aircraft.specifications.getModel() << "\n"
           << "Seats: " << aircraft.specifications.getSeatCapacity() << "\n"
           << "Min Runway Length: " << aircraft.specifications.getMinRunwayLength() << "\n"
           << "Fuel Consumption (per km): " << aircraft.specifications.getFuelConsumptionPerKm() << "\n"
           << "Tank Capacity: " << aircraft.specifications.getTankCapacity() << "\n"
           << "Average Speed: " << aircraft.specifications.getAverageSpeed() << "\n"
           << "Crew Cost: " << aircraft.crewCost << "\n";
        return os;
    }
};

class AirlineManagement {
private:
    vector<Aircraft> aircrafts;

public:
    void addAircraft(const Aircraft& aircraft) {
        aircrafts.push_back(aircraft);
    }

    vector<Aircraft> findAircraftForDestination(double requiredRunwayLength, double distance) {
        vector<Aircraft> suitableAircrafts;
        for (const auto& aircraft : aircrafts) {
            if (aircraft.getSpecifications().getMinRunwayLength() <= requiredRunwayLength && 
                aircraft.getSpecifications().calculateMaxFlightDistance() >= distance) {
                suitableAircrafts.push_back(aircraft);
            }
        }
        return suitableAircrafts;
    }

    void saveToFile(const string& filename) {
        ofstream file(filename);
        for (const auto& aircraft : aircrafts) {
            file << aircraft.getId() << "," << aircraft.getSpecifications().getManufacturer() << ","
                 << aircraft.getSpecifications().getModel() << "," << aircraft.getSpecifications().getSeatCapacity() << ","
                 << aircraft.getSpecifications().getMinRunwayLength() << "," <<
                  aircraft.getSpecifications().getFuelConsumptionPerKm() << ","
                 << aircraft.getSpecifications().getTankCapacity() << "," << aircraft.getSpecifications().getAverageSpeed() << ","
                 << aircraft.getCrewCost() << "\n";
        }
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string id, manufacturer, model;
            int seatCapacity;
            double minRunwayLength, fuelConsumptionPerKm, tankCapacity, averageSpeed, crewCost;

            getline(ss, id, ',');
            getline(ss, manufacturer, ',');
            getline(ss, model, ',');
            ss >> seatCapacity >> minRunwayLength >> fuelConsumptionPerKm >> tankCapacity >> averageSpeed >> crewCost;

            AircraftSpecifications specs(manufacturer, model, seatCapacity, minRunwayLength, 
                                         fuelConsumptionPerKm, tankCapacity, averageSpeed);
            aircrafts.emplace_back(id, specs, crewCost);
        }
    }
};

int main() {
    AirlineManagement management;
    AircraftSpecifications bulgariaAirSpecs("BulgariaAir", "737", 180, 2.5, 0.02, 20000, 900);
    AircraftSpecifications ryanairSpecs("RyanAir", "A320", 150, 2.0, 0.025, 18000, 850);
    
    int airplanes;
    cout << "how many ariplanes do you want to generate?:";
    cin >> airplanes;
    for(int i = 0; i < airplanes;i++){
        string name;
        int aircraftSpecChoice;
        int salary;
        cout <<"Enter the name, bgAir = 1 / ryanair = 2 and salary for the plane: \n";
        cin >> name;
        cin >> aircraftSpecChoice;
        cin >> salary;
        if (aircraftSpecChoice == 1 && salary > 0){
            management.addAircraft(Aircraft(name, bulgariaAirSpecs, salary));
        }else if(aircraftSpecChoice == 2 && salary > 0){
            management.addAircraft(Aircraft(name, ryanairSpecs, salary));
        }else{
            cout << "Invalid data entered\n";
        }

    }
    management.saveToFile("aircrafts.txt");

    cout << "Aircrafts that can fly to a destination with a 2.5 km runway and distance 700 km:\n";
    auto suitable = management.findAircraftForDestination(2.5, 700);
    for (const auto& aircraft : suitable) {
        cout << aircraft << "\n";
    }

    return 0;
}
