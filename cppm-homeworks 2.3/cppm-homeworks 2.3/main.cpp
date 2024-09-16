#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Структура для хранения информации об адресе
struct Adres {
    string city;
    string street;
    int houseNumber;
    int apartmentNumber;
    int index;
  
    // Метод для ввода данных об адресе
    void input() {
        cout << "введите город: ";
        cin >> city;
        cout << "введите улицу: ";
        cin >> street;
        cout << "введите номер дома: ";
        cin >> houseNumber;
        cout << "введите номер квартиры: ";
        cin >> apartmentNumber;
        cout << "введите индекс: ";
        cin >> index;
    }
    
    // Метод для отображения всех адресов в векторе
    void display(vector<Adres> adres) {
        for (auto& adr : adres) {  // Проход по всем адресам в векторе
            cout << "город " << adr.city
                 << "\nулица " << adr.street
                 << "\nномер дома " <<  adr.houseNumber
                 << "\nномер квартиры " << adr.apartmentNumber
                 << "\nиндекс " <<  adr.index << "\n\n";  // Вывод информации об адресе
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<Adres> addAdres;  // Вектор для хранения всех адресов
    Adres adres;  // Объект для временного хранения данных адреса
    
    while (true) {  // Бесконечный цикл для работы с меню
        // Вывод меню
        cout << "меню: \n0 выход \n1 добавить адрес \n2 показать адреса";
        int menu;  // Переменная для хранения выбора пользователя
        cout << "\nвыберете действие: ";
        cin >> menu;  // Ввод выбора
        cout << "\n";
        
        // Обработка выбора пользователя с помощью оператора switch
        switch (menu) {
            case 0: {  // Выход из программы
                return 0;  // Завершение программы
                break;
            }
            case 1: {  // Добавление нового адреса
                adres.input();  // Ввод данных об адресе
                addAdres.push_back(adres);  // Добавление адреса в вектор
                cout << "адрес успешно добавлен\n\n";
                break;
            }
            case 2: {  // Показ всех адресов
                adres.display(addAdres);  // Вызов метода отображения адресов
                break;
            }
            default:
                break;
        }
    }

    return 0;  
}
