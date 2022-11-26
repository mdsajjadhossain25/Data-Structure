#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define mp make_pair
#define pb push_back
#define pp pop_back
#define fi first
#define se second
#define as(x) (x).begin(), (x).end()
#define rev(x) (x).rbegin(), (x).rend()

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; 
    cin >> n;
    int arr[n][n];
    memset(arr, 0, sizeof(arr));

    //taking the input of sparse matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cin >> arr[i][j];
        }
    }

    //defining size of 1D array.
    int sz = (n*(n+1))/2;
    int newArray[sz];
    int idx=0;

    //setting the value to 1D Array.
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            newArray[idx] = arr[i][j];
            idx++;
        }
    }

    //getting output as per row and column.
    int searchRow, searchCol;
    cin>> searchRow >> searchCol;
    searchRow--;
    int newIdx = (searchRow*(searchRow+1))/2;
    cout << newArray[newIdx+searchCol-1] << endl;

}
