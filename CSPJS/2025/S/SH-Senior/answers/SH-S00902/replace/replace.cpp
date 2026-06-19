#include <bits/stdc++.h>
using namespace std;
int n;
int q;
struct group{
    string rep1;
    string rep2;
};
group av[202020];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>av[i].rep1>>av[i].rep2;
    }
    for(int i=1;i<=q;i++){
        int ans=0;
        string st;
        string re;
        cin>>st>>re;
        for(int j=1;j<=n;j++){
            for(int k=0;k+av[j].rep1.length()<=st.length();k++){
                string aft;
                bool flag=1;
                for(int l=0;l<av[j].rep1.length();l++){
                    if(av[j].rep1[l]!=st[k+l]){
                        flag=0;
                    }
                }
                if(flag==1){
                    for(int l=0;l<st.length();l++){
                        if(l<k||l>k+av[j].rep1.length()-1){
                            aft=aft+st[l];
                        }else{
                            aft=aft+av[j].rep2[l-k];
                        }
                    }
                }
                if(aft==re){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
