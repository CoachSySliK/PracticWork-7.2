#include <iostream>

using namespace std;

int main()
{   
    int water;    
    int milk;
    int americanoCounter = 0;
    int latteCounter = 0;
    bool americanoAvailability;
    bool latteAvailability;
    char order;
    int americano = 300;
    int latte[2] = { 30, 270 };

    do {
        cout << "Укажите количество воды в мл: ";
        cin >> water;
        cout << "Укадите количество молока в мл: ";
        cin >> milk;

        if (water <= 0 || milk < 0) {
            cout << "Должно быть положительное значение!\n";
        }

    } while (water <= 0 || milk < 0); //мне в чате сказали, что goto это плохо
        
    americanoAvailability = (water > americano);
    latteAvailability = (water > latte[0] && milk > latte[1]);

    while ( americanoAvailability || latteAvailability ) {            
        do {
            cout << "Выберите напиток:\n";
            if (americanoAvailability) cout << "\t(A)mericano\n";
            if (latteAvailability) cout << "\t(L)atte\n";
            cin >> order;
            cin.ignore(100, '\n'); //чистка буфера

            if ((order == 65 || order == 97) && americanoAvailability) latteAvailability = false;
            else if ((order == 76 || order == 108) && latteAvailability) americanoAvailability = false;
            else {
                order = 'E';
                cout << "Ваш выбор не корректен! Поробуйте ещё раз.\n";
                cout << "----------------\n";
            }

        } while (order == 69);

        cout << "----Ожидайте----\n";

        if (americanoAvailability) {
            cout << "Ваш напиток готов. Приятного аппетита!\n";
            water -= americano;
            americanoCounter++;
            cout << water << endl;
            cout << "----------------\n";
        }
        else if (latteAvailability) {
            cout << "Ваш напиток готов. Приятного аппетита!\n";
            water -= latte[0];
            milk -= latte[1];
            latteCounter++;
            cout << water << endl;
            cout << milk
                << endl;
            cout << "----------------\n";
        }

        americanoAvailability = (water > americano);
        latteAvailability = (water > latte[0] && milk > latte[1]);

    }
    
    cout << "Автомат не работает!\n";
    cout << "***Отчёт***\n";
    cout << "Ингридентов осталось:\n";
    cout << "\t\tВода:\t" << water << " мл\n";
    cout << "\t\tМолоко:\t" << milk << " мл\n";
    cout << "Кружек американо приготовлено: " << americanoCounter << endl;
    cout << "Кружек латте приготовлено: " << latteCounter << endl;
    cout << "***********\n";
    
    return 0;
}