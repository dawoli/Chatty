#include <bits/stdc++.h>

using namespace std;
int v[4][14];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(s.size()==2&&s[1]>='0'&&s[1]<='9'){
            if(s[0]=='D'){
                v[0][s[1]-'0']=1;
            }else if(s[0]=='C'){
                v[1][s[1]-'0']=1;
            }else if(s[0]=='H'){
                v[2][s[1]-'0']=1;
            }else if(s[0]=='S'){
                v[3][s[1]-'0']=1;
            }
        }else if(s[1]=='T'){
            if(s[0]=='D'){
                v[0][10]=1;
            }else if(s[0]=='C'){
                v[1][10]=1;
            }else if(s[0]=='H'){
                v[2][10]=1;
            }else if(s[0]=='S'){
                v[3][10]=1;
            }
        }else if(s[1]=='J'){
            if(s[0]=='D'){
                v[0][11]=1;
            }else if(s[0]=='C'){
                v[1][11]=1;
            }else if(s[0]=='H'){
                v[2][11]=1;
            }else if(s[0]=='S'){
                v[3][11]=1;
            }
        }else if(s[1]=='Q'){
            if(s[0]=='D'){
                v[0][12]=1;
            }else if(s[0]=='C'){
                v[1][12]=1;
            }else if(s[0]=='H'){
                v[2][12]=1;
            }else if(s[0]=='S'){
                v[3][12]=1;
            }
        }else if(s[1]=='K'){
            if(s[0]=='D'){
                v[0][13]=1;
            }else if(s[0]=='C'){
                v[1][13]=1;
            }else if(s[0]=='H'){
                v[2][13]=1;
            }else if(s[0]=='S'){
                v[3][13]=1;
            }
        }
        else if(s[1]=='A'){
            if(s[0]=='D'){
                v[0][1]=1;
            }else if(s[0]=='C'){
                v[1][1]=1;
            }else if(s[0]=='H'){
                v[2][1]=1;
            }else if(s[0]=='S'){
                v[3][1]=1;
            }
        }
    }
    int count=0;
    for(int i=0;i<4;i++){
        for(int j=1;j<14;j++){
           if(v[i][j]==0){
            count++;
           }
        }
    }
    cout<<count;
    return 0;
}
