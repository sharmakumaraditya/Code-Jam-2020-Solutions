#include<bits/stdc++.h>
using namespace std;

const int maxn = 100+3;
int b[maxn];
int r,c;
int pre,prefix;
int LI;
int B;
int ac,ar;
void re(){
	for(int i=1;i<=pre;++i)
		swap(b[i],b[B+1-i]);
}
void ch(){
	for(int i=1;i<=pre;++i)
		b[i]=1-b[i];
	for(int i=B;i>B-pre;--i)
		b[i]=1-b[i];
}
int ask(int x){
	cout<<x<<endl;
	int ans;
	cin>>ans;
	return ans;
}
int askchange(){
	if(ac==-1){
		for(int i=1;i<=pre;++i){
			if(b[i]==b[B+1-i]){
				ac=i;
				break;
			}
		}
	}
	if(ar==-1){
		for(int i=1;i<=pre;++i){
			if(b[i]!=b[B+1-i]){
				ar=i;
				break;
			}
		}
	}
	if(ac!=-1){
		int d=ask(ac);
		if(b[ac]!=d)
			ch();
	}else ask(1);
	if(ar!=-1){
		int d=ask(ar);
		if(b[ar]!=d)
			re();
	}else ask(1);
	prefix=pre;
	return 2;
}

string ans(){
	string Ans="";
	for(int i=1;i<=B;++i)
		Ans+=('0'+b[i]);
	return Ans;
}
int main(){
	int T;
	cin>>T>>B;
	LI=B/2;
	#ifdef xtest
	freopen("t.err","w",stderr);
	#endif // xtest
	while(T--){
        pre=0;
        prefix=0;
        r=0,c=0;
        ac=ar=-1;
        int tim=1;
        while(tim<=150){
			if(prefix==LI)	break;
			if(tim%10==1)	prefix=0;
			if(prefix!=pre){
				tim+=askchange();
			}else{
				b[pre+1]=ask(pre+1);
				b[B-pre]=ask(B-pre);
				pre++;
				prefix++;
				tim+=2;
			}
        }
        string s;
        cout<<ans()<<endl;
        cin>>s;
        #ifdef xtest
        cerr<<T<<" "<<ans()<<" "<<s<<endl;
        #endif // xtest
        if(s!="Y")	return 0;
	}
	return 0;
}