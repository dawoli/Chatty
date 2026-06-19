#include <bits/stdc++.h>

using namespace std;

freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);

int n;
bool poker[52];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        string p;
        cin>>p;
        int x=0;
        char a=p[0];
        char b=p[1];
        if(a=='D'){
            x+=13;
        }
        if(a=='H'){
            x+=26;
        }
        if(a=='S'){
            x+=39;
        }
        int c;
        if(b=='T'){
            c=9;
        }
        else if(b=='J'){
            c=10;
        }
        else if(b=='Q'){
            c=11;
        }
        else if(b=='K'){
            c=12;
        }
        else{
            c=b-'1';
        }
        x+=c;
        poker[x]=true;
    }
    int y=0;
    for(int i=0;i<52;i++){
        if(poker[i]==false){
            y++;
        }
    }
    cout << y << endl;
    return 0;
}
