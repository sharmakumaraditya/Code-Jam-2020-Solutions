#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,p,i,j;
    
    cin>>t;
    for(p=1;p<=t;p++)
    {
        cin>>n;
        int a[n][n], r=0, c=0;
        int arr[n];
        long long int q=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }
        
        for(i=0,j=0;i<n;i++,j++)
        {
            q=q+a[i][j];
        }
        
        for(i=0;i<n;i++)
        {
            for(int k=0;k<n;k++)
            {
                arr[k] = 0;
            }
            for(j=0;j<n;j++)
            {
                if(arr[a[i][j]-1]==1)
                {
                    r++;
                    break;
                }
                else
                {
                    arr[a[i][j]-1]=1;
                }
            }
        }
        

        for(i=0;i<n;i++)
        {
            for(int k=0;k<n;k++)
            {
                arr[k] = 0;
            }
            for(j=0;j<n;j++)
            {
                if(arr[a[j][i]-1]==1)
                {
                    c++;
                    break;
                }
                else
                {
                    arr[a[j][i]-1]=1;
                }
            }
        }
        
        cout<<"Case #"<<p<<": "<<q<<" "<<r<<" "<<c<<endl;
        
    }
    return 0;
}
        
