/*Write a program that has a class to represent time. The class should 
have constructors to initialize data members hour, minute, and second to 
0 and to initialize them to values passed as arguments. The class should 
have a member function to add time objects and return the result as a time 
object. There should be functions to display time in 12-hour and 24-hour 
format.*/
#include <iostream>
using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    // Default constructor
    Time() {
        hour = 0;
        minute = 0;
        second = 0;
    }

    // Parameterized constructor
    Time(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }

    // Function to add two time objects and return the result
    Time addTime(Time t) {
        Time result;
        result.hour = hour + t.hour;
        result.minute = minute + t.minute;
        result.second = second + t.second;

        // Adjust the time if necessary
        if (result.second >= 60) {
            result.second -= 60;
            result.minute++;
        }
        if (result.minute >= 60) {
            result.minute -= 60;
            result.hour++;
        }
        if (result.hour >= 24) {
            result.hour -= 24;
        }

        return result;
    }

    // Function to display time in 12-hour format
    void display12HourFormat() {
        string period = "AM";
        int displayHour = hour;

        if (displayHour >= 12) {
            period = "PM";
            if (displayHour > 12) {
                displayHour -= 12;
            }
        }

        cout << "Time: " << displayHour << ":" << minute << ":" << second << " " << period << endl;
    }

    // Function to display time in 24-hour format
    void display24HourFormat() {
        cout << "Time: " << hour << ":" << minute << ":" << second << endl;
    }
};

int main() {
    int h, m, s;

    // Get user input for time1
    cout << "Enter time 1(hour minute second): ";
    cin >> h >> m >> s;
    Time time1(h, m, s);

    // Get user input for time2
    cout << "Enter time 2 (hour minute second): ";
    cin >> h >> m >> s;
    Time time2(h, m, s); 

    // Display the initial times
     cout << "Time 1: "<<endl;
    time1.display12HourFormat();
    time1.display24HourFormat();
     cout << "Time 2: "<<endl;
    time2.display12HourFormat();
    time2.display24HourFormat();

    // Add the two time objects
    Time result = time1.addTime(time2);

    // Display the result
    cout << "Result: ";
    result.display12HourFormat();

    return 0;
}