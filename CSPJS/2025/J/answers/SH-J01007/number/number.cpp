#include<bits/stdc++.h>
using namespace std;

int num[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
    string a;
    cin >> a;
    for(char it:a){
        if(it-'0'>=0) num[it-'0']++;
    }
    for(int i=9;i>=0;i--){
        while(num[i]){
            cout << i;
            num[i]--;
        }
    }
}
