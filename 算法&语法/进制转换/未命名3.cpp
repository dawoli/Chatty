#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    string hex;
    int decimal = 0, i = 0;

    cout << "请输入一个16进制数：";
    cin >> hex;

    while(hex[i] != '\0') {
        int digit;
        if(hex[i] >= '0' && hex[i] <= '9') {
            digit = hex[i] - '0';
        } else if(hex[i] >= 'a' && hex[i] <= 'f') {
            digit = hex[i] - 'a' + 10;
        } else if(hex[i] >= 'A' && hex[i] <= 'F') {
            digit = hex[i] - 'A' + 10;
        }
        decimal += digit * pow(16, i);
        i++;
    }

    cout << "十进制数为：" << decimal << endl;

    return 0;
}
