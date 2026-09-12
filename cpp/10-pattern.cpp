//right half kite

#include<bits/stdc++.h>
using namespace std;

void upper_half( int n)
{
    for(int i=0 ; i<n ; i++)
    {
        for( int j=0; j<=i ; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}
void lower_half( int n)
{
    for(int i=0 ; i<n ; i++)
    {
        for( int j=0; j<n-i ; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen( "input.txt", "r", stdin);
        freopen( "output.txt" , "w" , stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //testcases
    int t;
    cin>>t;

    for( int i=0 ; i<t ; i++)
    {
        int n;
        cin>>n;
        upper_half(n);
        lower_half(n-1);
        cout<<endl;
    }
    return 0;
}

// MAKE SURE TO DO THIS WITH STRIVER'S METHOD ALSO