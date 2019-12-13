#include <cstdio>
#include <cstring>
#define S 100000
#define ll long long
ll pos[S+5][2], pw[S+5], M=1e9+7, ans;
void hishab(){//2nd idx0=Same, idx1=Defrent.
	pos[0][0]=pos[0][1]=1;
	pos[1][0]=2, pos[1][1]=1;
	pw[0]=1ll, pw[1]=2ll;
	for (int i=2; i<S; i++){
		pw[i]=(pw[i-1]*2ll)%M;
		pos[i][0]=(2ll*pos[i-1][1])%M;
		pos[i][1]=(pos[i-1][0]+pos[i-1][1])%M;
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	hishab();
	int t,cs=1;
	char s[S+5],c;
	scanf("%d",&t);
	while (t--){
		scanf("%s",s);
		int l=strlen(s),i,f=0;
		ans=1, c='-';
		for (i=0; i<l; i++){
			if (s[i]=='W') f++;
			else{
				if (c=='-')	ans=pw[f];
		else if (c==s[i]) ans=(ans*pos[f][0])%M;
				else			ans=(ans*pos[f][1])%M;
				c=s[i], f=0;
			}
		} if (f) {
			if (c=='-') ans=(3ll*pw[f-1])%M;
			else ans=(ans*pw[f])%M;
		}
		printf("Case %d: %lld\n",cs++,ans);
	} return 0; 
}
