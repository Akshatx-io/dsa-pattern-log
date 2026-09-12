//Hollow square

#include<bits/stdc++.h>
using namespace std;

void print_square(int n)
{   
    for(int i=1 ; i<=n ; i++)
    {   
        for( int j=1; j<=n ; j++)
        {
            if( (i==1) || (i==n) || (j==1) || (j==n) )
            {
                cout<<"*"<<" ";
            }
            else{
                cout<<" "<<" ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen( "input.txt", "r", stdin);
        freopen( "output.txt" , "w" , stdout);
    #endif

    int t;
    cin>>t;

    for( int i=0 ; i<t ; i++)
    {
        int n;
        cin>>n;
        print_square(n);
        cout<<endl;
    }
    return 0;
}