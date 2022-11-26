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
    int row1, col1;
    cin >> row1 >> col1;
    int mat1[row1][col1];
    for(int i=0; i<row1; i++){
        for(int j=0; j<col1; j++){
            cin >> mat1[i][j];
        }
    }
    int row2, col2;
    cin >> row2 >> col2;
    int mat2[row2][col2];
    for(int i=0; i<row2; i++){
        for(int j=0; j<col2; j++){
            cin >> mat2[i][j];
        }
    }
    int res[row1][col2];
    int sum =0;
    for(int i=0; i<row1; i++){
        for(int j=0; j<col2; j++){
            for(int k=0; k<col1; k++){
                sum+=mat1[i][k]*mat2[k][j];
            }
            res[i][j]= sum;
            sum =0;
        }
    }
    for(int i=0; i<row1; i++){
        for(int j=0; j<col2; j++){
            cout << res[i][j]<< " ";
        }
        cout << endl;
    }
}
