#include <iostream>
#include <cmath>

using namespace std;

int main() {

    setlocale(LC_ALL, "");

    int Num; // Размер массива
    bool isEqual;
    double Prob = 0, Chance = 0;
    
    
    cout << "События равновероятные? 0 - нет, 1 - да. ";
    cin >> isEqual;

    cout << "Введите количество событий: ";
    cin >> Num; // Получение от пользователя размера массива количества событий
    
    if (isEqual == 1) {
        cout << "Количество информации " << Num << " равновероятностных событий: " << log2(Num) << endl; //Вычисление количества информации равновероятных событий
    }
    else {
        cout << "Неравные." << endl;
        double* MasN = new double[Num]; // Выделение памяти для массива
        while (Prob != 1) {
            for (int i = 0; i < Num; i++) { // Заполнение массива
                cout << "Ввероятность " << i + 1 << " события равна: ";
                cin >> MasN[i];
                Prob = Prob + MasN[i];
            }
            for (int i = 0; i < Num; i++) { //Вывод введенных значений
                cout << "Значение " << i + 1 << " элемента равно " << MasN[i] << endl;
            }
           for (int i = 0; i < Num; i++) { // Проверка массива на "правильные" вероятности
                Chance = MasN[i];
                if ((Chance <= 0) || (Chance >= 1)) {
                    Prob = 0;
                    break;
                }
            }
            Prob = round(Prob * 100) / 100; // Проверка что сумма вероятностей равна единице
            if (Prob != 1) {
                cout << Prob << endl << round(Prob * 100) / 100 << endl;
                cout << "Неправильно введены вероятности. Введите снова." << endl;
            }
        }
        Prob = 0;
        cout << "Cработало" << endl;
        for (int i = 0; i < Num; i++) { //Вычисление количества информации неравновероятных событий 
            Prob = Prob + MasN[i]*log2(MasN[i]);
        }
        cout << "Количество информации " << Num << " неравновероятностных событий: " << -Prob << endl;
        delete[] MasN; // очистка памяти массива
    }
    return 0;
}
