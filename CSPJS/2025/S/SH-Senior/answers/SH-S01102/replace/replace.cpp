#include<bits/stdc++.h>
using namespace std;

string s1[200005],s2[200005];
int fin(string sx,string sy){
    for(int i=0;i<=sx.size()-sy.size();i++){
        bool flag=true;
        for(int j=i;j<i+sy.size();j++){
            if(sx[j]!=sy[j-i]) flag=false;
        }
        if(flag) return i;
    }
    return -1;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
    while(q--){
        string sx,sy;
        int ans=0;
        cin>>sx>>sy;
        for(int i=1;i<=n;i++){
            int m=fin(sx,s1[i]),n=fin(sy,s2[i]);
            if(m==-1 || n==-1) continue;
            int len1=s1[i].size(),len2=s2[i].size();
            string fr1="",la1="",fr2="",la2="";
            for(int i=0;i<m;i++) fr1+=sx[i];
            for(int i=m+len1;i<sx.size();i++) la1+=sx[i];
            for(int i=0;i<n;i++) fr2+=sy[i];
            for(int i=n+len2;i<sy.size();i++) la2+=sy[i];
            if(fr1==fr2 && la1==la2) ans++;
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
