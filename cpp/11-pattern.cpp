//101010... lower triangle

#include<bits/stdc++.h>
using namespace std;

void binary_triangle( int n)
{   
    int start=1;
    for(int i=0 ; i<n ; i++)
    {   
        if(i%2==0) start=1;
        else start=0;

        for( int j=0; j<=i ; j++)
        {   
            cout<<start<<" ";
            start=1-start; //very nice logic
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

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //testcases
    int t;
    cin>>t;

    for( int i=0 ; i<t ; i++)
    {
        int n;
        cin>>n;
        binary_triangle(n);
        cout<<endl;
    }
    return 0;
}