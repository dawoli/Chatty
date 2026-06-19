#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int nummap[10];
// the key dight exists for value times

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string a; cin >> a;
    for(auto x: a){
        if(x >= '0' and x <= '9'){
            nummap[x - '0']++;
        }
    }

    for(int i = 9; i >= 0; i--){
        for(int j = 1; j <= nummap[i]; j++){
            cout << i;
        }
    }

    cout << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}