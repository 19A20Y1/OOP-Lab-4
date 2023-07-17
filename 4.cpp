/*Assume that one constructor initializes data member say num_vehicle, 
hour, and rate. There should be a 10% discount if num_vehicle exceeds 
10. Display the total charge. Use two objects and show a bit-by-bit copy 
of one object to another (make your own copy constructor).*/
#include <iostream>

using namespace std;

class ParkingCharge {
private:
  int num_vehicle;
  int hour;
  double rate;

public:
  // Constructor
  ParkingCharge(int num, int h, double r) : num_vehicle(num), hour(h), rate(r) {}

  // Copy constructor
  ParkingCharge(const ParkingCharge& other) {
    num_vehicle = other.num_vehicle;
    hour = other.hour;
    rate = other.rate;
  }

  // Calculate total charge
  double calculateCharge() {
    double totalCharge = hour * rate;
    if (num_vehicle > 10) {
      totalCharge -= totalCharge * 0.1; // Apply 10% discount
    }
    return totalCharge;
  }

  // Display total charge
  void displayTotalCharge() {
    double charge = calculateCharge();
    cout << "Total charge: $" << charge << endl;
  }
};

int main() {
  // Get user input for number of vehicles, hours, and rate
  int numVehicles, hours;
  double rate;
  
  cout << "Enter the number of vehicles: ";
  cin >> numVehicles;
  
  cout << "Enter the number of hours: ";
  cin >> hours;
  
  cout << "Enter the rate per hour: ";
  cin >> rate;

  // Create an object with user input values
  ParkingCharge obj1(numVehicles, hours, rate);

  // Display total charge for obj1
  obj1.displayTotalCharge();

  // Copy obj1 to obj2
  ParkingCharge obj2 = obj1;

  // Display total charge for obj2
  obj2.displayTotalCharge();

  return 0;
}
