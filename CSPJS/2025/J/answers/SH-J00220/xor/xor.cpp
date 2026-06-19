#include <bits/stdc++.h>
using namespace std;
long long n,k,a,s[500002];
long long f=1,ans=0;
int main () {
	freopen ( "xor.in" , "r" , stdin );
	freopen ( "xor.out" , "w" , stdout );
	cin >> n >> k;
	for ( int i=1 ; i<=n ; i++ ) {
		cin >> a;
		s[i]=s[i-1]^a;
		if ( a==0 and f==1 ) f=0;
		else if ( a>1 and ( f==0 or f==1 ) ) f=2; 
	}
	if ( f==1 and k==1 ) {
		cout << n;
		return 0;
	}
	else if ( ( f==0 or f==1 ) and k<=1 ) {
		if ( k==1 ) {
			for ( long long i=1 ; i<=n ; i++ ) if ( s[i-1]^s[i]==1 ) ans++;
			cout << ans;
			return 0;
		}
		else {
			for ( long long i=1 ; i<=n ; i++ ) {
				if ( s[i-1]^s[i]==0 ) ans++;
				else if ( i<n and s[i]^s[i+1]==1 ) {
					ans++;
					i++;
				}
			}
			cout << ans;
			return 0;
		}
	}
	long long l=1,r=1,ent=0;
	for ( ; r<=n ; r++ ) {
		for ( l=ent+1 ; l<=r ; l++ ) {
			if ( s[l-1]^s[r]==k ) {
				ans++;
				ent=r;
			}
		}
	}
	cout << ans;
	return 0;
}
