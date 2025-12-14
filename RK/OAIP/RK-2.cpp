#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <memory>
#include <algorithm>
#include <numeric>
#include <sstream>

using namespace std;

class Vehicle {
protected:
    string brand;
    string model;
    int year;
    vector<string> serviceRecords;

public:
    Vehicle(string b, string m, int y) : brand(b), model(m), year(y) {}

    virtual void display() const {
        cout << "Brand: " << brand << ", Model: " << model << ", Year: " << year;
        cout << "\nService records: ";
        for (const auto& record : serviceRecords) {
            cout << record << " | ";
        }
        cout << endl;
    }

    virtual void loadFromString(const string& line) {
        stringstream ss(line);
        getline(ss, brand, ';');
        getline(ss, model, ';');
        string yearStr;
        getline(ss, yearStr, ';');
        year = stoi(yearStr);
        
        string recordsStr;
        getline(ss, recordsStr, ';');
        getline(ss, recordsStr);
        
        stringstream recordsStream(recordsStr);
        string record;
        while (getline(recordsStream, record, '|')) {
            serviceRecords.push_back(record);
        }
    }

    virtual string saveToString() const {
        return brand + ";" + model + ";" + to_string(year);
    }

    string getBrand() const { return brand; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    const vector<string>& getServiceRecords() const { return serviceRecords; }

    void setBrand(const string& b) { brand = b; }
    void setModel(const string& m) { model = m; }
    void setYear(int y) { year = y; }
    void addServiceRecord(const string& record) { serviceRecords.push_back(record); }

    virtual ~Vehicle() = default;
};

class Car : public Vehicle {
private:
    int doors;
    string transmissionType;

public:
    Car(string b, string m, int y, int d, string t) : Vehicle(b, m, y), doors(d), transmissionType(t) {}

    void display() const override {
        cout << "CAR - ";
        Vehicle::display();
        cout << "Doors: " << doors << ", Transmission: " << transmissionType << "\n" << endl;
    }

    void loadFromString(const string& line) override {
        Vehicle::loadFromString(line);
        stringstream ss(line);
        string temp;
        for (int i = 0; i < 4; i++) getline(ss, temp, ';');
        getline(ss, temp, ';');
        
        size_t dashPos = temp.find('-');
        if (dashPos != string::npos) {
            transmissionType = temp.substr(0, dashPos);
            doors = stoi(temp.substr(dashPos + 1));
        }
    }

    string saveToString() const override {
        return "Car;" + Vehicle::saveToString() + ";" + transmissionType + "-" + to_string(doors);
    }

    string getTransmissionType() const { return transmissionType; }
    int getDoors() const { return doors; }
};

class Motorcycle : public Vehicle {
private:
    string type;
    int power;

public:
    Motorcycle(string b, string m, int y, string t, int p) : Vehicle(b, m, y), type(t), power(p) {}

    void display() const override {
        cout << "MOTORCYCLE - ";
        Vehicle::display();
        cout << "Type: " << type << ", Power: " << power << " hp\n" << endl;
    }

    void loadFromString(const string& line) override {
        Vehicle::loadFromString(line);
        stringstream ss(line);
        string temp;
        for (int i = 0; i < 4; i++) getline(ss, temp, ';');
        getline(ss, temp, ';');
        
        size_t dashPos = temp.find('-');
        if (dashPos != string::npos) {
            type = temp.substr(0, dashPos);
            power = stoi(temp.substr(dashPos + 1));
        }
    }

    string saveToString() const override {
        return "Motorcycle;" + Vehicle::saveToString() + ";" + type + "-" + to_string(power);
    }

    int getPower() const { return power; }
    string getType() const { return type; }
};

void loadFromFile(const string& filename, list<unique_ptr<Vehicle>>& vehicles) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string type;
        getline(ss, type, ';');
        
        unique_ptr<Vehicle> vehicle;
        if (type == "Car") {
            vehicle = make_unique<Car>("", "", 0, 0, "");
        } else if (type == "Motorcycle") {
            vehicle = make_unique<Motorcycle>("", "", 0, "", 0);
        } else {
            continue;
        }
        
        vehicle->loadFromString(line);
        vehicles.push_back(move(vehicle));
    }
    file.close();
    cout << "Data loaded successfully!" << endl;
}

void saveToFile(const string& filename, const list<unique_ptr<Vehicle>>& vehicles) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    for (const auto& v : vehicles) {
        string recordsStr;
        const auto& records = v->getServiceRecords();
        for (size_t i = 0; i < records.size(); i++) {
            recordsStr += records[i];
            if (i < records.size() - 1) recordsStr += "|";
        }
        
        file << v->saveToString() << ";" << recordsStr << endl;
    }
    file.close();
    cout << "Data saved successfully!" << endl;
}

void displayMenu() {
    cout << "\n========== MENU ==========" << endl;
    cout << "1. Load data from file" << endl;
    cout << "2. Display all vehicles" << endl;
    cout << "3. Filter by year" << endl;
    cout << "4. Sort by year (ascending)" << endl;
    cout << "5. Count automatic cars" << endl;
    cout << "6. Find most powerful motorcycle" << endl;
    cout << "7. Group by type and save to files" << endl;
    cout << "8. Calculate average year" << endl;
    cout << "9. Search by service record ('engine')" << endl;
    cout << "10. Add new vehicle" << endl;
    cout << "11. Save data to file" << endl;
    cout << "0. Exit" << endl;
    cout << "==========================\n" << endl;
}

int main() {
    list<unique_ptr<Vehicle>> vehicles;
    int choice;
    string filename = "vehicles.txt";

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                loadFromFile(filename, vehicles);
                break;

            case 2:
                cout << "\n--- All Vehicles ---" << endl;
                for (const auto& v : vehicles) {
                    v->display();
                }
                break;

            case 3: {
                int filterYear;
                cout << "Enter year to filter: ";
                cin >> filterYear;
                cout << "\n--- Vehicles from year " << filterYear << " ---" << endl;
                auto it = find_if(vehicles.begin(), vehicles.end(),
                    [filterYear](const unique_ptr<Vehicle>& v) {
                        return v->getYear() == filterYear;
                    });
                while (it != vehicles.end()) {
                    (*it)->display();
                    it = find_if(next(it), vehicles.end(),
                        [filterYear](const unique_ptr<Vehicle>& v) {
                            return v->getYear() == filterYear;
                        });
                }
                break;
            }

            case 4:
                cout << "--- Sorted by year (ascending) ---" << endl;
                vehicles.sort([](const unique_ptr<Vehicle>& a, const unique_ptr<Vehicle>& b) {
                    return a->getYear() < b->getYear();
                });
                for (const auto& v : vehicles) {
                    v->display();
                }
                break;

            case 5: {
                int count = count_if(vehicles.begin(), vehicles.end(),
                    [](const unique_ptr<Vehicle>& v) {
                        auto* car = dynamic_cast<Car*>(v.get());
                        return car && car->getTransmissionType() == "Automatic";
                    });
                cout << "Number of automatic cars: " << count << endl;
                break;
            }

            case 6: {
                auto maxPowerIt = max_element(vehicles.begin(), vehicles.end(),
                    [](const unique_ptr<Vehicle>& a, const unique_ptr<Vehicle>& b) {
                        auto* ma = dynamic_cast<Motorcycle*>(a.get());
                        auto* mb = dynamic_cast<Motorcycle*>(b.get());
                        int powerA = ma ? ma->getPower() : 0;
                        int powerB = mb ? mb->getPower() : 0;
                        return powerA < powerB;
                    });
                
                if (maxPowerIt != vehicles.end()) {
                    auto* m = dynamic_cast<Motorcycle*>((*maxPowerIt).get());
                    if (m) {
                        cout << "Most powerful motorcycle: ";
                        m->display();
                    }
                }
                break;
            }

            case 7: {
                list<unique_ptr<Vehicle>> cars, motorcycles;
                
                for (auto& v : vehicles) {
                    if (dynamic_cast<Car*>(v.get())) {
                        auto* car = dynamic_cast<Car*>(v.get());
                        cars.push_back(make_unique<Car>(*car));
                    } else if (dynamic_cast<Motorcycle*>(v.get())) {
                        auto* mc = dynamic_cast<Motorcycle*>(v.get());
                        motorcycles.push_back(make_unique<Motorcycle>(*mc));
                    }
                }
                
                saveToFile("cars.txt", cars);
                saveToFile("motorcycles.txt", motorcycles);
                break;
            }

            case 8: {
                if (vehicles.empty()) {
                    cout << "No vehicles in list!" << endl;
                    break;
                }
                
                int totalYears = accumulate(vehicles.begin(), vehicles.end(), 0,
                    [](int sum, const unique_ptr<Vehicle>& v) {
                        return sum + v->getYear();
                    });
                
                double average = static_cast<double>(totalYears) / vehicles.size();
                cout << "Average year: " << average << endl;
                break;
            }

            case 9:
                cout << "--- Vehicles with 'engine' in service records ---" << endl;
                for (const auto& v : vehicles) {
                    const auto& records = v->getServiceRecords();
                    bool found = any_of(records.begin(), records.end(),
                        [](const string& record) {
                            return record.find("engine") != string::npos;
                        });
                    
                    if (found) {
                        v->display();
                    }
                }
                break;

            case 10: {
                cout << "Enter vehicle type (1 - Car, 2 - Motorcycle): ";
                int type;
                cin >> type;
                cin.ignore();
                
                string brand, model, param;
                int year, numParam;
                
                cout << "Brand: "; getline(cin, brand);
                cout << "Model: "; getline(cin, model);
                cout << "Year: "; cin >> year;
                cin.ignore();
                
                if (type == 1) {
                    cout << "Transmission type: "; getline(cin, param);
                    cout << "Number of doors: "; cin >> numParam;
                    vehicles.push_back(make_unique<Car>(brand, model, year, numParam, param));
                } else {
                    cout << "Motorcycle type: "; getline(cin, param);
                    cout << "Power (hp): "; cin >> numParam;
                    vehicles.push_back(make_unique<Motorcycle>(brand, model, year, param, numParam));
                }
                cout << "Vehicle added successfully!" << endl;
                break;
            }

            case 11:
                saveToFile(filename, vehicles);
                break;

            case 0:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}