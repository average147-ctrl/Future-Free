#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    string ownerName;
    double balance;

public:
    // Конструктор
    BankAccount(string num, string name, double initialBalance = 0.0) 
        : accountNumber(num), ownerName(name), balance(initialBalance) {}

    // Метод пополнения счета
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Пополнение на " << amount << " выполнено.\n";
        } else {
            cout << "Сумма пополнения должна быть положительной!\n";
        }
    }

    // Метод снятия средств
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Снятие " << amount << " выполнено.\n";
        } else if (amount > balance) {
            cout << "Недостаточно средств на счете!\n";
        } else {
            cout << "Сумма снятия должна быть положительной!\n";
        }
    }

    // Метод получения баланса
    double getBalance() const {
        return balance;
    }

    // Метод вывода информации о счете
    void display() const {
        cout << fixed << setprecision(2);
        cout << "Счет: " << accountNumber 
             << " | Владелец: " << ownerName 
             << " | Баланс: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    // Конструктор
    SavingsAccount(string num, string name, double initialBalance = 0.0, double rate = 0.05)
        : BankAccount(num, name, initialBalance), interestRate(rate) {}

    // Метод начисления процентов
    void addInterest() {
        double interest = balance * interestRate;
        balance += interest;
        cout << "Начислены проценты: " << interest 
             << " (ставка " << (interestRate * 100) << "%)\n";
    }

    // Переопределение метода вывода
    void display() const {
        BankAccount::display();
        cout << "Процентная ставка: " << (interestRate * 100) << "%\n";
    }

    // Геттер для ставки
    double getInterestRate() const {
        return interestRate;
    }
};

int main() {
    cout << "=== Моделирование работы банка ===\n\n";

    // Создание обычного счета
    BankAccount checking("12345-678", "Иван Петров", 1000.0);
    cout << "Обычный счет:\n";
    checking.display();

    // Операции с обычным счетом
    checking.deposit(500.0);
    checking.withdraw(200.0);
    checking.display();
    cout << "\n";

    // Создание сберегательного счета
    SavingsAccount savings("98765-432", "Мария Сидорова", 2000.0, 0.06);
    cout << "Сберегательный счет:\n";
    savings.display();

    // Операции со сберегательным счетом
    savings.deposit(1000.0);
    savings.withdraw(500.0);
    savings.addInterest();
    savings.display();

    // Попытка снять больше, чем есть на счете
    cout << "\nПопытка снять больше доступной суммы:\n";
    savings.withdraw(5000.0);

    cout << "\nИтоговое состояние счетов:\n";
    checking.display();
    savings.display();

    return 0;
}
