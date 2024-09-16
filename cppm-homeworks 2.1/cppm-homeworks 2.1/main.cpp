#include <iostream>
#include <string>
using namespace  std;

enum MonthOfYear{
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December,
    
};

int main(int argc, const char * argv[]) {
    int input{};
    
    while (true) {
        cout << "Enter month number (1-12) or 0 to exit: ";
        cin >> input;
        
        if (input == 0){
            cout << "Goodbye\n";
            return 0;;
        }
        
        if (input < 1 || input > 12 ){
            cout << "Wrong number! Please enter a number between 1 and 12.\n";
            continue;
        }
       
        MonthOfYear month = static_cast<MonthOfYear>(input);
        
        switch (month) {
            case January: {
                cout << "January\n";
                break;
            }
            case February: {
                cout << "February\n";
                break;
            }
            case March: {
                cout << "March\n";
                break;
            }
            case April: {
                cout << "April\n";
                break;
            }
            case May: {
                cout << "May\n";
                break;
            }
            case June: {
                cout << "June\n";
                break;
            }
            case July: {
                cout << "July\n";
                break;
            }
            case August: {
                cout << "August\n";
                break;
            }
            case September: {
                cout << "September\n";
                break;
            }
            case October: {
                cout << "October\n";
                break;
            }
            case November: {
                cout << "November\n";
                break;
            }
            case December: {
                cout << "December\n";
                break;
                }
        }
    }
    return 0;
}
