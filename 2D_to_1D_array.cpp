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
    int row, col;
    cin >> row >> col;
    int arr[row][col];

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> arr[i][j];
        }
    }

    //implementing 1d array.
    int arr1[row*col];
    int idx = 0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            arr1[idx]=arr[i][j];
            idx++;
        }
    }

    cout <<"Enter the index of row you want to see: ";
    int searchInd;
    cin >> searchInd;
    idx = (searchInd-1)*col;

    int cnt=0;
    while(cnt<col){
        cout << arr1[idx] << " ";
        idx++;
        cnt++;
    }
    cout << endl;

}
