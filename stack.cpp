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
#define  maxi 1000

class Stack{
    int top;
    public: 
        int a[maxi];
        Stack(){
            top = -1;
        }
        bool push(int x){
            if(top>=(maxi-1)){
                cout << "stack overflow" << endl;
                return false;
            }
            else{
                top++;
                a[top]= x;
                // cout << "pushed onto the stack"<< endl;
                return true;
            }
        }
        int pop(){
            if(top<0){
                cout<< "stack underflow" << endl;
            }
            else{
                int x = a[top];
                top--;
                return x;
            }
        }
        int peek(){
            if(top<0){
                cout << "stack is empty" << endl;
                return 0;
            }
            else{
                int x = a[top];
                return x;
            }
        }
        bool isempty(){
            return (top<0);
        }
};


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Stack s;
    s.push(30);
    s.push(10);
    s.push(20);
    cout << s.peek();
}
