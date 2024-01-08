// Pizzeria.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

class Pizza {
protected:
    string name;
    string description;
    int price;
    int size;
    int cheese;
    int salt;

public:
    Pizza(string nm, string ds, int sz, int pr) {
        name = nm;
        description = ds;
        size = sz;
        price = pr;
    }

    virtual void SetSalt(int num) = 0;
    virtual void SetCheese(int num) = 0;
    virtual double GetPrice() = 0;
    virtual void GetDescription() = 0;
};

class PizzaHawaii : public Pizza {
public:
    PizzaHawaii(int sz) : Pizza("Гавайская", "Пицца, приготовляемая с использованием белого соуса, сыра, ананасов, курицы и морепродуктов", sz, 600) {};
    
    void SetSalt(int num) override {
        salt = num;
    };

    void SetCheese(int num) override {
        cheese = num;
    };

    double GetPrice() {
        int cost = price * (size / 25) + cheese * 10 + salt * 4;
        return cost;
    };

    void GetDescription() override {
        cout << name << endl;
        cout << description << endl;
        cout << "Количество соли: " << salt << endl;
        cout << "Количество сыра: " << cheese << endl;
        cout << "Стоимость: " << GetPrice() << endl;
    }

};


class PizzaPipperoni : public Pizza {
public:
    PizzaPipperoni(int sz) : Pizza("Пипперони", "Острая разновидность салями итало-американского происхождения, приготовленная из вяленого мяса и приправленная паприкой c разновидностями перца чили", sz, 450) {};

    void SetSalt(int num) override {
        salt = num;
    };

    void SetCheese(int num) override {
        cheese = num;
    };

    double GetPrice() {
        int cost = price * (size / 25) + cheese * 12 + salt * 8;
        return cost;
    };

    void GetDescription() override {
        cout << name << endl;
        cout << description << endl;
        cout << "Количество соли: " << salt << endl;
        cout << "Количество сыра: " << cheese << endl;
        cout << "Стоимость: " << GetPrice() << endl;
    }

};

class PizzaFourCheese : public Pizza {
public:
    PizzaFourCheese(int sz) : Pizza("Четыре сыра", " Разновидность пиццы в итальянской кухне, покрытая комбинацией из четырёх видов сыра, расплавленных вместе, с томатным соусом", sz, 600) {};

    void SetSalt(int num) override {
        salt = num;
    };

    void SetCheese(int num) override {
        cheese = num;
    };

    double GetPrice() {
        int cost = price * (size / 25) + cheese * 6 + salt * 14;
        return cost;
    };

    void GetDescription() override {
        cout << name << endl;
        cout << description << endl;
        cout << "Количество соли: " << salt << endl;
        cout << "Количество сыра: " << cheese << endl;
        cout << "Стоимость: " << GetPrice() << endl;
    }
};

class Order {
protected:
    int sum;
public:
    Order() {
        sum = 0;
    };
    void AddPizza(int s) {
        sum += s;
    };

    double TotalPrice() {
        return sum;
    };
};



int main()
{
    setlocale(LC_ALL, "Russian");
    Order* order = new Order();
    string answer;
    int i, k, s, c;
    do {
        do {
            cout << "Выберите пиццу: (1) Гавайская, (2) Пипперони, (3) Четыре сыра" << endl;
            cin >> i;
        } while (i != 1 and i != 2 and i != 3);
        Pizza* pizza = nullptr;
        do {
            cout << "Выберите размер пиццы: 25, 30, 35, 40 " << endl;
            cin >> k;
        } while (k != 25 and k != 30 and k != 35 and k != 40);

        if (i == 1) {
            pizza = new PizzaHawaii(k);
        }
        else if (i == 2) {
            pizza = new PizzaPipperoni(k);
        }
        else if (i == 3) {
            pizza = new PizzaFourCheese(k);
        }

        cout << "Введите колличество добавленной соли: ";
        cin >> s;
        cout << "Введите колличество добавленного сыра: ";
        cin >> c;

        pizza->SetSalt(s);
        pizza->SetCheese(c);

        pizza->GetDescription();

        order->AddPizza(pizza->GetPrice());
        
        do {
            cout << "Желаете что-нибудь добавить ? (yes / no)" << endl;
            cin >> answer;
        } while ((answer != "yes") and (answer != "no"));
        delete pizza;
    } while (answer == "yes");

    cout << "Стоимость заказа: "<< order->TotalPrice() << endl;
}
