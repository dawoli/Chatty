#include <bits/stdc++.h>
using namespace std;
int main(){
    char buffer[10000];
    char *endptr;
    gets(buffer); 
    long result=strtol(buffer, &endptr, 8);
    cout<<result;
    return 0;
}
