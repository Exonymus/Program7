//
//  main.cpp
//  Program7.4
//
//  Created by Игорь Аралин on 20.12.20.
//

#include <iostream>
#include <math.h>

using namespace std;

int to_ten(string num);
string num_plus(int num1, int num2);
string num_minus(int num1, int num2);

int main()
{
    string num1, num2, result;
    int num_1, num_2;
    char symbol;
    cout << "Введите 1 число: ";
    cin >> num1;
    num_1 = to_ten(num1);
    
    cout << "Введите 2 число: ";
    cin >> num2;
    num_2 = to_ten(num2);
    
    cout << "Введите операцию(+/-): ";
    cin >> symbol;
    
    if (symbol == '+') result = num_plus(num_1, num_2);
    if (symbol == '-') result = num_minus(num_1, num_2);
    
    cout <<"Полученное число: " << result << endl;
    return 0;
}

int to_ten(string num)
{
    int num2 = 0;
    for (int i = 0; i < num.length(); i++)
    {
        if (num[i] != 'a' && num[i] != 'b') num2 += ((int) num[i] - 48) * pow(12,(num.length()-i-1));
        if (num[i] == 'a') num2 += 10 * pow(12,(num.length()-i-1));
        if (num[i] == 'b') num2 += 11 * pow(12,(num.length()-i-1));
    }
    return num2;
}

string num_plus(int num1, int num2)
{
    int num = num1 + num2;
    string sum;
    for (int i = 0; num != 0; i++)
    {
        int k = num % 12;
        if (k < 10) sum += to_string(k);
        else if (k == 10) sum += "a";
        else if (k == 11) sum += "b";
        num = num / 12;
    }
    
    long n = sum.length();
    for (int i = 0; i < n / 2; i++)
        swap(sum[i], sum[n - i - 1]);
    return sum;
}

string num_minus(int num1, int num2)
{
    int num;
    string msum;
    if (num1 == num2) {msum = '0'; return msum;}
    if (num1 > num2) num = num1 - num2;
        else num = num2 - num1;
    
    for (int i = 0; num != 0; i++)
    {
        int k = num % 12;
        if (k < 10) msum += to_string(k);
        else if (k == 10) msum += "a";
        else if (k == 11) msum += "b";
        num = num / 12;
    }
    
    long n = msum.length();
    for (int i = 0; i < n / 2; i++)
        swap(msum[i], msum[n - i - 1]);
    return msum;
}
