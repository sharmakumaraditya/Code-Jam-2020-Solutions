#include<bits/stdc++.h>
using namespace std;

const int maxn = 50+3;
int ans[maxn][maxn];
int n,k;
namespace Graph{
	void find(int a,int b,bool cho,int stx,int sty){
		if(cho)	ans[stx][sty]=a;
		else ans[stx][sty]=b;
		for(int i=0;i<n;++i)
			if(ans[stx][i]==-1)
				find(a,b,!cho,stx,i);
		for(int i=0;i<n;++i)
			if(ans[i][sty]==-1)
				find(a,b,!cho,i,sty);
	}
};
void ass(int val,int b){
	if(val==0)	val=n;
	for(int i=0;i<n;++i)
		ans[i][(i+b)%n]=val;
}
bool f0(){
	if(k%n!=0)	return false;
	#ifdef xtest
	cerr<<"f(0) HERE!"<<endl;
	#endif // xtest
	for(int i=0;i<n;++i){
		ass((k/n+i)%n,i);
	}
	return true;
}
bool f1(){
	int a,b,c;
	bool flag=false;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j)	continue;
			a=i;
			b=j;
			c=k-(n-2)*i-b;
			if(1<=c&&c<=n&&c!=a&&c!=b){
				flag=true;
				goto ok1;
			}
		}
	}
	ok1:
	if(!flag)	return false;
	#ifdef xtest
	cerr<<"f(1) HERE!"<<" "<<a<<" "<<b<<" "<<c<<endl;
	#endif // xtest
	ass(a,0);
	ass(b,1);
	ass(c,n-1);
	int t=2;
	for(int i=1;i<=n;++i){
		if(i==a||i==b||i==c)	continue;
		ass(i,t++);
	}
	for(int i=0;i<n;++i)
		swap(ans[0][i],ans[1][i]);
	return true;
}
bool f2(){
	int a,b;
	bool flag=false;
	for(int i=1;i<=n;++i){
		a=i;
		b=k-(n-2)*i;
		if(b%2!=0)	continue;
		b/=2;
		if(1<=b&&b<=n&&b!=a){
			flag=true;
			goto ok2;
		}
	}
	ok2:
	if(n<=3||!flag)	return false;
	#ifdef xtest
	cerr<<"f(2) HERE!"<<endl;
	#endif // xtest
    ass(a,0);
    ass(b,1);
    ans[0][0]=b;
    ans[0][1]=a;
    ans[1][0]=a;
    ans[1][1]=b;
    ans[1][2]=-1;
    ans[n-1][0]=-1;
    ans[n-1][2]=b;
    int c=1,d=2;
    while(c==a||c==b)	c++;
    while(d==a||d==b||d==c)d++;
    int t=2;
    for(int i=3;i<=n;++i){
		if(i==a||i==b||i==c||i==d)	continue;
		ass(i,t++);
		if(t==3)	t++;
    }
    for(int i=0;i<n;++i){
		for(int j=0;j<n;++j)
			if(ans[i][j]==-1)
				Graph::find(c,d,true,i,j);
    }
    return true;
}
int main(){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	for(int kase=1;kase<=T;++kase){
        cin>>n>>k;
        for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				ans[i][j]=-1;
        cout<<"Case #"<<kase<<": ";
        if(f0()||f1()||f2()){
			cout<<"POSSIBLE"<<endl;
			for(int i=0;i<n;++i){
				for(int j=0;j<n;++j)
					cout<<ans[i][j]<<" ";
				cout<<endl;
			}
        }else cout<<"IMPOSSIBLE"<<endl;
	}
	return 0;
}