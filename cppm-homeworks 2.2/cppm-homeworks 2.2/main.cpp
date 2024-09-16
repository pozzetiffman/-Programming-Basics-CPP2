#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct balanceChange {
    int amount;
};

struct Bill {
  
    string namber;
    string name;
    int balance;
    vector<balanceChange> history;
    
    void input () {
        cout << "введите номер счета: ";
        cin >> namber;
        cout << "введите имя владельца: ";
        cin >> name;
        cout << "введите баланс счета: ";
        cin >> balance;
        cout << "\n";
    }
    void addHistori (int change){
        history.push_back({change});
    }
    
    void displayHistory (){
        if (history.empty()){
            cout << "История изменений пуста.\n";
        }
        else {
            cout << "История изменений баланса для счета " << namber << ":\n";
            for (const auto& record : history){
                cout << "изменения " << record.amount << "\n";
            }
        }
    }
};

void display (vector<Bill>& bills){
    for (const auto& bill : bills){
        cout << "номер счета: " << bill.namber << "\nимя: " << bill.name << "\nбаланс: " << bill.balance << "\n\n";
        }
    }

void billChance (vector<Bill>& billsBalance){
    string accountNumber;
    cout << "введите номер счета: ";
    cin >> accountNumber;
    
    for (auto& bill : billsBalance){
        if (bill.namber == accountNumber){
            int change;
            cout << "ведите сумму изменения баланса (отрицательная для уменьшения): ";
            cin >> change;
            bill.balance += change;
            bill.addHistori(change);

            cout << "баланс изменен успешно.\nновый баланс: " <<  bill.balance << "\n\n";
           
            return;
        }
    }
    cout << "счет с номером " << accountNumber << " не найден.\n";
}

void searchAccount (vector<Bill>(searchBill)){
    string accountNumber;
    cout << "\nвведите номер счета: ";
    cin >> accountNumber;
    
    bool found = false;
    
    for (auto& bill : searchBill){
        if (bill.namber == accountNumber){
            cout << "Найденный счет:\n";
            cout << "номер счета: " << bill.namber << "\nимя: " << bill.name << "\nбаланс: " << bill.balance << "\n\n";
            bill.displayHistory();
            found = true;
        }
    }
    if (!found){
        cout << "счет с номером " << accountNumber << " не найден.\n";
    }
}

int main(int argc, const char * argv[]) {
    
        vector<Bill> bill;
        Bill bills;
    
    while (true) {
       
        cout << "\nменю:" << "\n1 создать счет" << "\n2 изменить баланс " << "\n3 показать все счета"<< "\n4 поиск по счету" << "\n0 выйти \n";
        int num;
        cout << "выберите действие: ";
        cin >> num;
        cin.ignore();
        
        switch (num) {
            case 1:{
                bills.input();
                bill.push_back(bills);
                cout << "счет успешно создан:\n\n";
                break;
            }
            case 2:{
                billChance(bill);
                
                break;
            }
            case 3:{
                cout << "\nвсе созданные счета:\n";
                display(bill);
                break;
            }
            case 4:{
                searchAccount(bill);
                break;
            }
            case 0:{
                return 0;
                break;
            }
                
            default:
                break;
        }
    }

    return 0;
}
