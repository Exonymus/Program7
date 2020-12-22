//
//  main.cpp
//  Program7.2
//
//  Created by Игорь Аралин on 17.12.20.
//

#include <iostream>

using namespace std;

string reverse_code(string num, bool sign);

int main()
{
    string num;
    cout << "Введите число: ";
    cin >> num;
    bool sign;
    if (num[0] == 0) sign = true; else sign = false;
    num = reverse_code(num,sign);
    cout <<"Полученное число: " << num << endl;
    return 0;
}

string reverse_code(string num, bool sign)
{
    if (sign == false)
        for (int i = 1; i < num.length(); i++)
        if (num[i] == '0') num[i] = '1';   else num[i] = '0';
    return num;
}

