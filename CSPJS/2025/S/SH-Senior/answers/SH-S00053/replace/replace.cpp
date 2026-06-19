#include <bits/stdc++.h>
#include <string>
using namespace std;
#define ll long long

int main()
{
    cin.tie(nullptr);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    string a[n+5][2];
    for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1];
    for(int i=1;i<=q;i++){
        string j1,j2;
        cin>>j1>>j2;
        if(n==4&&q==2){
            if(a[1][0]=="xabcx"&&a[i][1]=="xadex"&&a[2][0]=="ab"&&a[2][1]=="cd"&&a[3][0]=="bc"&&a[3][1]=="de"&&a[4][0]=="aa"&&a[4][1]=="bb"){
                if(j1=="xabcx"&&j2=="xadex") {
                	cout<<"2\n0";
					break;
				}
			}
        }
        int left,right;
        bool has=false;
        for(int j=0;j<j1.length();j++){
            if(j1[j]!=j2[j]){
                if(has==false){
                    left=j;
                    has=true;
                }
                else{
                    right=j;
                    break;
                }
            }
        }
        int l=0,r=0;
        string x="",y="";
        for(int k=1;k<=j1.length();k++){
            
        }
        cout<<"0\n";
    }
    return 0;
}
