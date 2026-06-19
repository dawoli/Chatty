#include <iostream>

int main() {
    int rows;
    std::cout << "请输入要打印的行数：";
    std::cin >> rows;
    
    int triangle[rows][rows];
    
    for (int i = 0; i < rows; i++) {
        triangle[i][0] = 1;
        triangle[i][i] = 1;
        
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }
    
    std::cout << "杨辉三角形：" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << triangle[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}

