#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Структура для хранения изменений баланса
struct balanceChange {
    int amount; // Поле для хранения суммы изменения баланса
};

// Структура для хранения информации о счете
struct Bill {
    string namber;
    string name;
    int balance;
    vector<balanceChange> history; // Вектор для хранения истории изменений баланса
    
    // Метод для ввода информации о счете
    void input() {
        cout << "введите номер счета: ";
        cin >> namber;
        cout << "введите имя владельца: ";
        cin >> name;
        cout << "введите баланс счета: ";
        cin >> balance;
        cout << "\n";
    }

    // Метод для добавления записи в историю изменений баланса
    void addHistori(int change) {
        history.push_back({change}); // Добавление изменения в вектор истории
    }
    
    // Метод для отображения истории изменений баланса
    void displayHistory() {
        if (history.empty()) { // Проверка, если история изменений пуста
            cout << "История изменений пуста.\n";
        } else {
            cout << "История изменений баланса для счета " << namber << ":\n";
            for (const auto& record : history) { // Проход по всем записям истории
                cout << "изменения " << record.amount << "\n"; // Вывод изменений
            }
        }
    }
};

// Функция для отображения всех счетов
void display(vector<Bill>& bills) {
    for (const auto& bill : bills) { // Проход по всем счетам в векторе
        cout << "номер счета: " << bill.namber << "\nимя: " << bill.name << "\nбаланс: " << bill.balance << "\n\n";
    }
}

// Функция для изменения баланса счета
void billChance(vector<Bill>& billsBalance) {
    string accountNumber;
    cout << "введите номер счета: ";
    cin >> accountNumber;
    
    for (auto& bill : billsBalance) { // Проход по всем счетам в векторе
        if (bill.namber == accountNumber) { // Поиск счета по номеру
            int change;
            cout << "ведите сумму изменения баланса (отрицательная для уменьшения): ";
            cin >> change;
            bill.balance += change; // Изменение баланса счета
            bill.addHistori(change); // Добавление изменения в историю
            
            cout << "баланс изменен успешно.\nновый баланс: " <<  bill.balance << "\n\n";
            return; // Выход из функции после успешного изменения
        }
    }
    cout << "счет с номером " << accountNumber << " не найден.\n"; 
}

// Функция для поиска счета по номеру
void searchAccount(vector<Bill>& searchBill) {
    string accountNumber;
    cout << "\nвведите номер счета: ";
    cin >> accountNumber;
    
    bool found = false; // Флаг для отслеживания найденного счета
    
    for (auto& bill : searchBill) { // Проход по всем счетам в векторе
        if (bill.namber == accountNumber) { // Поиск счета по номеру
            cout << "Найденный счет:\n";
            cout << "номер счета: " << bill.namber << "\nимя: " << bill.name << "\nбаланс: " << bill.balance << "\n\n";
            bill.displayHistory(); // Отображение истории изменений баланса
            found = true; // Установка флага в true, если счет найден
        }
    }
    if (!found) { // Если счет не найден
        cout << "счет с номером " << accountNumber << " не найден.\n";
    }
}

int main(int argc, const char * argv[]) {
    vector<Bill> bill; // Вектор для хранения всех счетов
    Bill bills; // Объект для временного хранения данных счета
    
    while (true) { // Бесконечный цикл для работы с меню
        // Вывод меню
        cout << "\nменю:" << "\n1 создать счет" << "\n2 изменить баланс " << "\n3 показать все счета" << "\n4 поиск по счету" << "\n0 выйти \n";
        int num;
        cout << "выберите действие: ";
        cin >> num;
        cin.ignore(); // Игнорирование символа новой строки
        
        switch (num) {
            case 1: {
                bills.input(); // Ввод данных нового счета
                bill.push_back(bills); // Добавление счета в вектор
                cout << "счет успешно создан:\n\n";
                break;
            }
            case 2: {
                billChance(bill); // Изменение баланса счета
                break;
            }
            case 3: {
                cout << "\nвсе созданные счета:\n";
                display(bill); // Отображение всех счетов
                break;
            }
            case 4: {
                searchAccount(bill); // Поиск счета по номеру
                break;
            }
            case 0: {
                return 0; // Выход из программы
                break;
            }
            default:
                break;
        }
    }
    return 0;
}
