# include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","w",stdout);
    int n;
    cin >> n;
    while(n--){
        int cnt[8]{};
        for(int i = 1;i <= 5;i++){
            for(int j = 0;j < 8;j++){
                string s;
                cin >> s;
                if(s=="math")cnt[i]++;
            }
        }
        int a,b;
        cin >> a >> b;
        long long cntt = 0;
        for(int i = 0,j=b;i < a ;i++,j++,j = (j-1)%7+1){
            cntt+=cnt[j];
        }
        cout << cntt << endl;
    }
    return 0;
}
