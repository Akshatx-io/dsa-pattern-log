//star box

#include<bits/stdc++.h>
using namespace std;

void print_stars(int rows, int col)
{
    for( int i=0 ; i < rows ; i++)
    {
        for( int j=0 ; j < col ; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}

int32_t main()
{   

    #ifndef ONLINE_JUDGE
        freopen( "input.txt", "r" , stdin);
        freopen( "output.txt" , "w" , stdout);
    #endif

    int t; //testcases
    cin>>t;
    for(int i=0 ; i<t ; i++)
    {
        int rows, col;
        cin>>rows>>col;
        print_stars(rows, col);
        cout<<endl;
    }
    return 0; 
}