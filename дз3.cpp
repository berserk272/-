#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int Zaem(double s, double p, int n) {
    double r = p / 100.0;
    double rn = pow(1 + r, n);
    double m = (s * r * rn) / (12 * (rn - 1));
    return m;
}

double Ssuda(double s, double m, double n) {
    double interestRate = 0.0;
    double eps = 0.01;
    while (true) {
        double mp = Zaem(s, interestRate, n);
        if (abs(mp - m) < eps) {
            break;
        }
        interestRate += 0.01;
    }
    return interestRate;
}
int main(){
    setlocale(LC_ALL, "rus");
    double s, p;
    int n;
    cout << "Задание 1 Заём" << endl;
    cout << "Введите значение для количества рублей (S): ";
    cin >> s;
    cout << "Введите значение для процента (p): ";
    cin >> p;
    cout << "Введите значение для количества лет (n): ";
    cin >> n;
    if (p < 1 || p > 100) {
        cout << "\n" << "Вы ввели некорректное значение для процента!!!";
    }
    else {
        double m1 = Zaem(s, p, n);
        cout << "Месячная выплата составит " << m1 << " рублей" << "\n";
    }

    double s1, m2;
    int n1;
    cout << "\n" << "Задание 2 Ссуда" << endl;
    cout << "Введите значение для количества рублей (S): ";
    cin >> s1;
    cout << "Введите значение для месячной выплаты (m): ";
    cin >> m2;
    cout << "Введите значение для количества лет (n): ";
    cin >> n1;
    double interestrate = Ssuda(s1, m2, n1);
    cout << "Процентная ставка составит: " << interestrate << "%" << "\n";

    return 0;
}