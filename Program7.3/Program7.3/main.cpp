//
//  main.cpp
//  Program7.3
//
//  Created by Игорь Аралин on 17.12.20.
//

#include <iostream>

using namespace std;

string binary_code(int num);
string dop_code(string num, bool sign);
string num_sum(string num1, string num2);

int main()
{
    int num;
    string num1, num2, sum;
    
    cout << "Введите 1 число: ";
    cin >> num;
    bool sign;
    if (num > 0) sign = true; else sign = false;
    num1 = binary_code(num);
    num1 = dop_code(num1, sign);

    cout << "Введите 2 число: ";
    cin >> num;
    if (num > 0) sign = true; else sign = false;
    num2 = binary_code(num);
    num2 = dop_code(num2, sign);

    sum = num_sum(num1, num2);
    cout <<"Полученное число: " << sum << endl;
    return 0;
}

string binary_code(int num)
{
    string num2;
    if (num < 0) num = -num;
    while (num)
    {
        if (num % 2 == 0) num2 = '0' + num2; else num2 = '1' + num2;
        num = num / 2;
    }
    for (;num2.length() < 8;)
        num2 = '0' + num2;
    return num2;
}

string dop_code(string num, bool sign)
{
//      Перевод в прямой код
    if (sign == false) num[0] = '1';
        else num[0] = '0';
    
//    Перевод в обратный код
    if (sign == false)
        for (int i = 1; i < num.length(); i++)
        if (num[i] == '0') num[i] = '1';
            else num[i] = '0';
    
//      Перевод в допкод
    bool check = false;
    if (sign == false)
        for (int i = 8; check != true; i--)
        {
            if (num[i] == '0') {num[i] = '1'; check = true;}
                else num[i] = '0';
            if (i == 0) {num = '1' + num; check = true;}
        }
    return num;
}

string num_sum(string num1, string num2)
{
    string sum;
    bool check = false;
    sum = "00000000";
    for (int i = 7; i >= 0; i--)
    {
        if (num1[i] == '1' && num2[i] == '1' && check == true) sum[i] = '1';
        if (num1[i] == '1' && num2[i] == '1' && check == false) {sum[i] = '0'; check = true;}
        
        
        if ((num1[i] == '1' && num2[i] == '0') || (num1[i] == '0' && num2[i] == '1')) sum[i] = '1';
        
        if (num1[i] == '0' && num2[i] == '0' && check == false) sum[i] = '0';
        if (num1[i] == '0' && num2[i] == '0' && check == true) {sum[i] = '1'; check = false;}
        
        if (((num1[i] == '1' && num2[i] == '0') || (num1[i] == '0' && num2[i] == '1')) && check == true) sum[i] = '0';
    }
    
    int ans = 0;
    for (int i = 0; i <= 7; i++)
        ans += ((int) sum[i] - 48) * pow(2,(7-i));
    sum = binary_code(ans);
    return sum;
}
