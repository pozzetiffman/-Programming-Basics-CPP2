#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Adres {
    
    string city;
    string street;
    int houseNumber;
    int apartmentNumber;
    int index;
  
    void input (){
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
    
    void display (vector<Adres> adres){
        for (auto& adr : adres ){
            cout << "город " << adr.city << "\nулицa " << adr.street << "\nномер дома " <<  adr.houseNumber<< "\nномер квартиры " << adr.apartmentNumber << "\nиндекс " <<  adr.index << "\n\n";
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<Adres> addAdres;
    Adres adres;
    while (true) {
        cout << "меню: \n0 выход \n1 добавить адрес \n2 показать адреса";
        int menu;
        cout << "\nвыберете действие: ";
        cin >> menu;
        cout << "\n";
        
        switch (menu) {
            case 0:{
                return 0;
                break;
            }
            case 1:{
                adres.input();
                addAdres.push_back(adres);
                cout << "адрес успешно добавлен\n\n";
                break;
            }
            case 2:{
                adres.display(addAdres);
                break;
            }

            default:
                break;
        }
    }

    return 0;
}
