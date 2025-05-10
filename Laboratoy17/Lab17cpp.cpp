#include <iostream>
using namespace std;

class Room {
private:
    double area;

public:
    Room(double a = 0) : area(a) {
    }

    void setArea(double a) {
        area = a;
    }

    double getArea() const {
        return area;
    }
};

class OneRoomApartment {
public:
    Room room;
    double kitchenArea;
    int floor;

    OneRoomApartment(double roomArea = 0, double kitchen = 0, int f = 0)
        : room(roomArea), kitchenArea(kitchen), floor(f) {
    }

    void setKitchenArea(double k) {
        kitchenArea = k;
    }

    double getKitchenArea() const {
        return kitchenArea;
    }

    void setFloor(int f) {
        floor = f;
    }

    int getFloor() const {
        return floor;
    }

    Room getRoom() const {
        return room;
    }
};

class CityApartment : public OneRoomApartment {
private:
    string city;

public:
    CityApartment(string c, double roomArea, double kitchen, int f)
        : OneRoomApartment(roomArea, kitchen, f), city(c) {
    }

    ~CityApartment() {
        cout << "Destructing apartment in " << city << endl;
    }

    void printInfo() const {
        cout << "City: " << city << endl;
        cout << "Room area: " << room.getArea() << " m^2" << endl;
        cout << "Kitchen area: " << kitchenArea << " m^2" << endl;
        cout << "Floor: " << floor << endl << endl;
    }
};

int main() {
    CityApartment apt1("Kyiv", 18.5, 7.2, 5);
    CityApartment apt2("Kharkiv", 20.0, 8.0, 3);

    apt1.printInfo();
    apt2.printInfo();
}