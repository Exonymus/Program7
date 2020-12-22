//
//  main.cpp
//  Program7*
//
//  Created by Игорь Аралин on 22.12.20.
//

#include <iostream>

using namespace std;

void answer(int num, int del);

int main()
{
    int num, del1, del2, del3;
    cout << "Введите делимое: ";
    cin >> num;
    cout << "Введите 3 делителя: ";
    cin >> del1;
    cin >> del2;
    cin >> del3;
    
    cout << "Результат: \n";
    answer(num, del1);
    answer(num, del2);
    answer(num, del3);
    
    return 0;
}

void answer(int num, int del)
{
    int num_ans = num;
    
    do
    {
        for (int i = 0; i < del; i++)
            num = ~- num;
    }
    while (num > 0);
    
    if (num == 0) cout << "Число " << num_ans << " делится на число " << del << " без остатка\n";
    else cout << "Число " << num_ans << " не делится на число " << del << " без остатка\n";

}
