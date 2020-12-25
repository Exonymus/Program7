//
//  main.cpp
//  Program7.4
//
//  Created by Игорь Аралин on 20.12.20.
//

#include <iostream>
#include <math.h>

using namespace std;

string num_plus(string num1, string num2);
string num_minus(string num1, string num2);


int main()
{
    string num1, num2, result;
    char symbol;
    cout << "Введите 1 число: ";
    cin >> num1;
    
    cout << "Введите 2 число: ";
    cin >> num2;
    
    cout << "Введите операцию(+/-): ";
    cin >> symbol;
    
    if (symbol == '+') result = num_plus(num1, num2);
    if (symbol == '-') result = num_minus(num1, num2);
   
    
    cout <<"Полученное число: " << result << endl;
    return 0;
}

string num_plus(string num1, string num2)
{
    string sum;
    long n = 0;
    
    if (num1.length() > num2.length())
        while (num1.length() > num2.length())
            num2 = '0' + num2;
    else if (num1.length() < num2.length())
        while (num2.length() > num1.length())
            num1 = '0' + num1;
   
    n = num1.length() - 1;
    
    int nsum = 0;
    bool check = false;
    for (long i = n; i >= 0; i--)
    {
        if (num1[i] != 'a' && num1[i] != 'b') nsum += (int) num1[i] - 48;
        if (num2[i] != 'a' && num2[i] != 'b') nsum += (int) num2[i] - 48;
        
        if (num1[i] == 'a') nsum += 10;
        if (num2[i] == 'a') nsum += 10;
        
        if (num1[i] == 'b') nsum += 11;
        if (num2[i] == 'b') nsum += 11;
        
        if (nsum == 10) sum = 'a' + sum;
        else if (nsum == 11) sum = 'b' + sum;
        else if (nsum < 10) sum = to_string(nsum) + sum;
        
        if (nsum > 11 && (nsum-12) < 10) {sum = to_string(nsum - 12) + sum; check = true;}
        else if (nsum > 11 && (nsum-12) == 10) {sum = 'a' + sum; check = true;}
        else if (nsum > 11 && (nsum-12) == 11) {sum = 'b' + sum; check = true;}
        
        if ((nsum - 12) < 0) check = false;
        if (check == true) nsum = 1; else nsum = 0;
    }
    if (nsum == 1) sum = '1' + sum;
    return sum;
}

string num_minus(string num1, string num2)
{
    string msum;
    if (num1 == num2) {msum = '0'; return msum;}
    
    long n = 0;
    
    if (num1.length() > num2.length())
        while (num1.length() > num2.length())
            num2 = '0' + num2;
    else if (num1.length() < num2.length())
        while (num2.length() > num1.length())
            num1 = '0' + num1;
   
    n = num1.length() - 1;
    
    int nsum = 0;
    bool check = false;
    for (long i = n; i >= 0; i--)
    {
        if (num1[i] != 'a' && num1[i] != 'b') nsum += (int) num1[i] - 48;
        if (num2[i] != 'a' && num2[i] != 'b') nsum -= (int) num2[i] - 48;
        
        if (num1[i] == 'a') nsum += 10;
        if (num2[i] == 'a') nsum -= 10;
        
        if (num1[i] == 'b') nsum += 11;
        if (num2[i] == 'b') nsum -= 11;

        if (nsum > 0) check = false;
        if (nsum < 0) {nsum += 12; check = true;}
        
        if (nsum == 10) msum = 'a' + msum;
        else if (nsum == 11) msum = 'b' + msum;
        else if (nsum < 10 && nsum >= 0) msum = to_string(nsum) + msum;
        
        
        if (check == true) nsum = -1; else nsum = 0;
    }
    return msum;
}

