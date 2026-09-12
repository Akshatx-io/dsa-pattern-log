//Symmetric malabar-Gold number logo

#include<bits/stdc++.h>
using namespace std;

//METHOD 1
void print_upper_half(int n)
{   
    for(int i=1 ; i<=n ; i++)
    {   
        for( int j=1; j<=i ; j++)   //for stars
        {   
            cout<<"*"<<" ";
        }

        for( int j=1; j<=2*n-2*i ; j++) // for spaces
        {   
            cout<<" "<<" ";
        }

        for( int j=i ; j>=1 ; j--) // for stars again 
        {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}
void print_lower_half(int n)
{   
    for(int i=1 ; i<=n ; i++)
    {   
        for( int j=1; j<=n-i+1 ; j++)   //for stars
        {   
            cout<<"*"<<" ";
        }

        for( int j=1; j<=2*i ; j++) // for spaces
        {   
            cout<<" "<<" ";
        }

        for( int j=1 ; j<=n-i+1 ; j++) // for stars again
        {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

//METHOD 2
// void print_pattern(int n)
// {   
//     for(int i=0 ; i<2*n-1 ; i++)
//     {
//         if(i <n)
//         {
//             for( int j=0; j<i ; j++)   //for stars
//                 {   
//                 cout<<"*"<<" ";
//                 } 
//             for( int j=0; j<2*n-2*i-2 ; j++) // for spaces
//                 {   
//                 cout<<" "<<" ";
//                 }

//             for( int j=0 ; j<i ; j++) // for stars again 
//                 {
//                 cout<<"*"<<" ";
//                 }
//             cout<<endl;  
//         }

//         else
//         {   
//             int iNis=2; //iNis =initial spaces in the 2nd half of the pattern
//             for( int j=0; j<2*n-i-1 ; j++)   //for stars
//                 {   
//                 cout<<"*"<<" ";
//                 } 
//             for( int j=0; j< iNis ; j++) // for spaces
//                 {   
//                 cout<<" "<<" ";
//                 }

//             for( int j=0 ; j<2*n-i-1 ; j++) // for stars again 
//                 {
//                 cout<<"*"<<" ";
//                 }
//             cout<<endl;
//             iNis+=2; 
//         }
//     }
// }

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
        print_upper_half(n);
        print_lower_half(n-1);
        cout<<endl;
    }
    return 0;
}