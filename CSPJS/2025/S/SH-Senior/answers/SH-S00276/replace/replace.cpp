#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q,f1,l1,f2,l2;
string s1[N],s2[N],question1[N],question2[N];
struct node{
	int first1,last1,first2,last2;
}a[5000006];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i=1;i<=n;i++){
		cin >> s1[i] >> s2[i];
		for (int j=0;j<s1[i].length();j++){
			if (s1[i][j]=='b'){
				a[i].first1=j,a[i].last1=s1[i].length()-j-1;
				break;
			}
		}
		for (int j=0;j<s2[i].length();j++){
			if (s2[i][j]=='b'){
				a[i].first2=j,a[i].last2=s2[i].length()-j-1;
				break;
			}
		}
	}
	for (int i=1;i<=q;i++){
		cin >> question1[i] >> question2[i]; 
	}
	for (int i=1;i<=q;i++){
		if (question1[i].length()!=question2[i].length()){
			cout << 0 << endl;
		}
		else{
			int ans=0;
			for (int j=0;j<question1[i].length();j++){
				if (question1[i][j]=='b'){
					f1=j,l1=question1[i].length()-j-1;
					break;
				}
			}
			for (int j=0;j<question2[i].length();j++){
				if (question2[i][j]=='b'){
					f2=j,l2=question2[i].length()-j-1;
					break;
				}
			}
			for (int j=1;j<=n;j++){
				if (f1>=min(a[j].first1,a[j].first2)&&f2>=min(a[j].first1,a[j].first2)&&l1>=min(a[j].last1,a[j].last2)&&l2>=min(a[j].last1,a[j].last2)&&question1[i].length()>=s1[j].length() && abs(f1-f2)==abs(a[j].first1-a[j].first2)&&abs(l1-l2)==abs(a[j].last1-a[j].last2)){
					ans++;
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
} 
