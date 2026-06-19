#include <bits/stdc++.h>
using namespace std;
int ans;
struct stu{
    int a1;
    int a2;
    int a3;
    int mid;
    int now;
    int maxi;
    int mini;
    int t;
};
int p1,p2,p3;
stu s[100010];
int T;
int n;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++){
        p1=0;
        p2=0;
        p3=0;
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            s[i].t=0;
        }
        for(int i=1;i<=n;i++){
            cin>>s[i].a1>>s[i].a2>>s[i].a3;
            s[i].maxi=max(max(s[i].a1,s[i].a2),max(s[i].a2,s[i].a3));
            s[i].mini=min(min(s[i].a1,s[i].a2),min(s[i].a2,s[i].a3));
            if(s[i].maxi==s[i].a1&&s[i].a1!=s[i].a2&&s[i].a1!=s[i].a3){
                p1++;
                s[i].now=1;
            }else if(s[i].maxi==s[i].a2&&s[i].a1!=s[i].a2&&s[i].a2!=s[i].a3){
                p2++;
                s[i].now=2;
            }else if(s[i].maxi==s[i].a3&&s[i].a3!=s[i].a1&&s[i].a2!=s[i].a3){
                p3++;
                s[i].now=3;
            }else if(s[i].a1==s[i].a2&&s[i].a2==s[i].a3){
                if(p1==min(min(p1,p2),min(p2,p3))){
                    p1++;
                    s[i].now=1;
                }else if(p2==min(min(p1,p2),min(p2,p3))){
                    p2++;
                    s[i].now=1;
                }else{
                    p3++;
                    s[i].now=3;
                }
            }else if(s[i].maxi==s[i].a1&&s[i].a1==s[i].a2){
                if(p1<p2){
                    p1++;
                    s[i].now=1;
                }else{
                    p2++;
                    s[i].now=2;
                }
            }else if(s[i].maxi==s[i].a2&&s[i].a2==s[i].a3){
                if(p2>p3){
                    p3++;
                    s[i].now=3;
                }else{
                    p2++;
                    s[i].now=2;
                }
            }else{
                if(p1>p3){
                    p3++;
                    s[i].now=3;
                }else{
                    p1++;
                    s[i].now=1;
                }
            }
            if(s[i].mini<=s[i].a1&&s[i].a1<=s[i].maxi&&s[i].now!=1){
                s[i].mid=s[i].a1;
            }else if(s[i].mini<=s[i].a2&&s[i].a2<=s[i].maxi&&s[i].now!=2){
                s[i].mid=s[i].a2;
            }else{
                s[i].mid=s[i].a3;
            }
        }
        while(p1>n/2||p2>n/2||p3>n/2){
            int mo=0;
            if(p1==max(max(p1,p2),max(p2,p3))){
                mo=1;
                p1--;
            }else if(p2==max(max(p1,p2),max(p2,p3))){
                mo=2;
                p2--;
            }else{
                mo=3;
                p3--;
            }
            int wi=0x3f3f3f3f;
            int mos=0;
            for(int i=1;i<=n;i++){
                if(s[i].now==mo&&s[i].maxi-s[i].mid<wi){
                    if(s[i].t<2){
                        wi=s[i].maxi-s[i].mid;
                        mos=i;
                    }
                }
            }
            if(s[mos].mid==s[mos].a1){
                p1++;
                s[mos].now=1;
            }else if(s[mos].mid==s[mos].a2){
                p2++;
                s[mos].now=2;
            }else{
                p3++;
                s[mos].now=3;
            }
            s[mos].t++;
            s[mos].maxi=s[mos].mid;
            s[mos].mid=s[mos].mini;
        }
        for(int i=1;i<=n;i++){
            if(s[i].now==1){
                ans+=s[i].a1;
            }else if(s[i].now==2){
                ans+=s[i].a2;
            }else{
                ans+=s[i].a3;
            }
        }

        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
