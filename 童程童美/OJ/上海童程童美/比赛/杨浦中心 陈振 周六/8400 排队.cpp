#include<bits/stdc++.h> 
using namespace std;
int a[1005],b[1005];
int main()
{
	int n,m,cnt1=0,cnt2=0;
    cin>>n>>m;//nÄĞÉú mÅ®Éú
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<=m-1;i++){
        if(a[i]>a[i+1])cnt1++;
    }
    for(int i=1;i<=n-1;i++){
        if(b[i]>b[i+1])cnt2++;
    }
    if(cnt1==0&&cnt2==0)cout<<"both";
    if(cnt1==0&&cnt2!=0)cout<<"girls";
    if(cnt1!=0&&cnt2==0)cout<<"boys";
    if(cnt1!=0&&cnt2!=0)cout<<"neither";
	return 0;
}
