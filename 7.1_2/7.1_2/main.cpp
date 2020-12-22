//
//  main.cpp
//  7.1_2
//
//  Created by Игорь Аралин on 17.12.20.
//

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    cout << "Вариант второй:\n";
    char num[80];
    cout << "Введите число: ";
    gets(num);
        
    //    Перевод в десятичную систему
    int num2 = 0;
    long length = 0;
    for (int i = 0; num[i] != '\0'; i++) length++;
    
    for (int i = 0; i < length; i++)
        num2 += ((int) num[i] - 48) * pow(7,(length-i-1));

    //    Перевод в двенадцатиричную систему
    string num3;
    for (int i = 0; num2 != 0; i++)
    {
        int k = num2 % 12;
        if (k < 10) num3 += to_string(k);
        else if (k == 10) num3 += "a";
        else if (k == 11) num3 += "b";
        num2 = num2 / 12;
    }
        
    //    Отразим результат
    length = 0;
    cout <<"Полученное число: ";
    length = num3.length();
    for (int i = 0; i < length / 2; i++)
        swap(num3[i], num3[length - i - 1]);
    
    cout << num3 << endl;
    return 0;
}
