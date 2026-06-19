#include <bits/stdc++.h>

using namespace std;

int n,k,q,l[100086],s[100086][100086],r[100086],c[100086];

void func(){
    cin>>n>>k>>q;
    for(int i = 0; i<n; i++){
        cin>>l[i];
        for(int j = 0; j<l[i]; j++){
            cin>>s[i][j];
        }
    }
    for(int i = 0; i<q; i++){
        cin>>r[i]>>c[i];
    }

    cout<<1<<endl;
}

bool ddd(lletter,lperson,lr){

}

int main()
{
    freopen("chain.in", "r", stdin)
    freopen("chain.out", "w",stdout);

    int t;
    cin>>t;
    for(int i = 0; i<t; i++){
        func();
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
