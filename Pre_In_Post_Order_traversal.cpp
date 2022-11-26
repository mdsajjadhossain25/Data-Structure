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

void preorder(int node, char T[]){
    if(T[node]==NULL){
        return;
    }
    else{
        cout << T[node] << " ";
        preorder((node*2)+1, T);
        preorder((node*2)+2, T);
    }
}
void inorder(int node, char T[]){
    if(T[node]==NULL){
        return;
    }
    else{
        preorder((node*2)+1, T);
        cout << T[node] << " ";
        preorder((node*2)+2, T);
    }
}
void postorder(int node, char T[]){
    if(T[node]==NULL){
        return;
    }
    else{
        preorder((node*2)+1, T);
        preorder((node*2)+2, T);
        cout << T[node] << " ";
    }
}



int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    char T[128];

    for(int i=0; i<128; i++){
        T[i]=NULL;
    }
    T[0]='A';
    T[1]='B';
    T[2]='C';
    T[3]='D';
    T[5]='E';
    T[6]='F';
    T[7]='G';
    T[8]='H';
    T[18]='I';

    cout << "preorder: ";
    preorder(0, T);
    cout << "inorder: ";
    inorder(0, T);
    cout << "postorder: ";
    postorder(0, T);


}
