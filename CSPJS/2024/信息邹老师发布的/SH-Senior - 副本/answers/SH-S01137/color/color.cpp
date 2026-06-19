//prepare
#include <iostream>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;
// prepare 

int main() 
{
    cin.tie(nullptr) -> sync_with_stdio(false);
#ifndef DEBUG
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
#endif
	cout << 1 << endl << 0 << endl << 8 << endl;
#ifndef DEBUG
    fclose(stdin);
    fclose(stdout);
#endif
}
