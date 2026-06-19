#include<bits/stdc++.h>
using namespace std;
string S;
long long A[1000010];
string Res;
long long Cnt=1;
bool Cmp(int X,int Y){
	return X>Y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>S;
	for(int i=0;i<(long long)S.length();i++)
		if(S[i]<='9'&&S[i]>='0'){
			char C;
			C=S[i];
			A[Cnt++]=C-'0';
		}
	sort(A+1,A+Cnt+1,Cmp);
	for(int i=1;i<=Cnt-1;i++){
		Res+=(A[i]+'0');
	}
	cout<<Res;
return 0;
}
