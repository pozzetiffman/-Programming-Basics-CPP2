#include <iostream>
#include <string>    
using namespace std;

// Определение перечисления для месяцев года
enum MonthOfYear {
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
    December
};

int main(int argc, const char * argv[]) {
    int input{};  // Переменная для хранения ввода пользователя

    while (true) {  // Бесконечный цикл для повторного ввода
        cout << "Enter month number (1-12) or 0 to exit: "; // Просим пользователя ввести номер месяца
        cin >> input;  // Читаем введенное значение
        
        if (input == 0) {  // Проверяем, если пользователь ввел 0
            cout << "Goodbye\n";  // Выводим прощальное сообщение
            return 0;  // Завершаем программу
        }
        
        if (input < 1 || input > 12) {  // Проверяем, если введенное число не в диапазоне от 1 до 12
            cout << "Wrong number! Please enter a number between 1 and 12.\n";  // Сообщаем о некорректном вводе
            continue;  // Переходим к следующей итерации цикла
        }
       
        // Преобразование введенного числа в соответствующее значение перечисления MonthOfYear
        MonthOfYear month = static_cast<MonthOfYear>(input);
        
        // Используем оператор switch для вывода названия месяца в зависимости от значения перечисления
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
