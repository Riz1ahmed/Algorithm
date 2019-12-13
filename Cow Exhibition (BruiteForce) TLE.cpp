/********************
Riz1 Ahmed, CSE, LU.
Code Start Time: 2019-11-24-01.38
********************/
#include<bits/stdc++.h>
#define ll long long int
const ll M=1e9+7;
using namespace std;
int s[200],f[200],dp[2][200],n,ans;
void Max(int p,int ts,int tf){
	if (p>n){
		if (ts>-1 && tf>-1)
			ans=max(ans,ts+tf);
		return;
	}
	Max(p+1,ts,tf);
	Max(p+1,ts+s[p],tf+f[p]);
	return;
}
int main(){
	memset(dp,-1,sizeof dp);
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		scanf("%d %d",s+i,f+i);
	ans=-1e9, Max(1,0,0);
	printf("%d\n",ans);
	return 0;
}
