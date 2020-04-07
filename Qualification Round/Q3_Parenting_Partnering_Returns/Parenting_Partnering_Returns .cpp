#include<iostream>
using namespace std;
int main()
{
    int t,n, temp;
    cin>>t;
    for(int p=1;p<=t;p++)
    {
        cin>>n;
        int start[n], end[n], answer[n], index[n];
        int cstart=-100, cend=-100, jstart=-100, jend=-100, imp=0;
        for(int i=0;i<n;i++)
        {
            cin>>start[i];
            cin>>end[i];
            index[i]=i;
        }
        // cout<<endl;
        // for(int i=0;i<n;i++)
        // {
        //         cout<<start[i]<<" "<<end[i]<<endl;
        // }
        
        for(int y=0;y<n;y++)
        {
            answer[y]=0;
        }
        
        
        for(int i=0;i<n-1;i++)
        {
            temp=0;
            for(int j=0;j<n-i-1;j++)
            {
                if (start[j] > start[j+1]) 
                {
                  temp=end[j];
                  end[j]=end[j+1];
                  end[j+1]=temp;
                  temp=start[j];
                  start[j]=start[j+1];
                  start[j+1]=temp;
                  temp=index[j];
                  index[j]=index[j+1];
                  index[j+1]=temp;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                cstart = start[0];
                cend = end[0];
                answer[i] = -20;
            }
            
            else if(cend<=start[i])
            {
                cstart = start[i];
                cend = end[i];
                answer[i] = -20;
            }
            
            else if(jend<=start[i])
            {
                jstart = start[i];
                jend = end[i];
                answer[i] = -10;
            }
            
            else
            {
                imp = 1;
            }
        }
        
        
        for(int i=0;i<n-1;i++)
        {
            temp=0;
            for(int j=0;j<n-i-1;j++)
            {
                if (index[j] > index[j+1]) 
                {
                  temp=end[j];
                  end[j]=end[j+1];
                  end[j+1]=temp;
                  temp=start[j];
                  start[j]=start[j+1];
                  start[j+1]=temp;
                  temp=index[j];
                  index[j]=index[j+1];
                  index[j+1]=temp;
                  temp = answer[j];
                  answer[j] = answer[j+1];
                  answer[j+1] = temp;
                }
            }
        }
        
        
        cout<<"Case #"<<p<<": ";
        
        
        if(imp==0)
        {
            for(int i=0;i<n;i++)
            {
                if(answer[i]== (-10))
                {
                    cout<<"J";
                }
                else if(answer[i]== (-20))
                {
                    cout<<"C";
                }
            }
            cout<<endl;
        }
        else if (imp == 1)
        {
            cout<<"IMPOSSIBLE"<<endl;
        }
        
        
    }
    return 0;
}