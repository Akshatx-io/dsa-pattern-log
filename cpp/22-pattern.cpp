//Important square pattern

#include<bits/stdc++.h>
using namespace std;

void print_square(int n)
{   
    for(int i=0 ; i<2*n-1 ; i++)
    {   
        for( int j=0; j<2*n-1 ; j++)
        {
            int top=i;
            int bottom=(2*n-2)-i;
            int right=(2*n-2)-j;
            int left=j;
            cout<<(n - min(min(left,right), min(top,bottom)))<<" "; //great logic
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