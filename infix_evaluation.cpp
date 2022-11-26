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

int b_exponential(int a, int b){
    int res = 1;
    while(b>0){
        if(b&1){
            res*=a;
            a*=a;
            b>>1;
        }
    }
    return res;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    map<string, int> pow;
    pow["+"] = 2;
    pow["-"] = 2;
    pow["/"] = 3;
    pow["*"] = 3;
    pow["^"] = 4;
    
    string s;
    cin >> s;

    stack<string> st;
    vector<string> v;//to store all the value individually.
    vector<string> postfix;// to store postfix value.

    string ok = "";


//storing the expression in a string vector;
    for(int i=0; i<s.size(); i++){
        char sym = s[i];
        string temp="";
        temp+=sym;
        if(sym=='+' || sym=='-' || sym=='/' || sym=='*' || sym=='*' ||sym=='(' || sym==')'){
            if(ok!=""){
                v.pb(ok);
            }
            v.pb(temp);
            ok="";
        }
        else{
            ok+=s[i];
        }
    }
    if(ok.size()>0){
        v.pb(ok);
    }


//infix to postfix
    for(int i=0; i<v.size(); i++){
        string scaned = v[i];
        if(scaned=="("){
            st.push(scaned);
        }
        else if(scaned==")"){
            while(!st.empty() && st.top()!="(" ){
                string tmp = st.top();
                postfix.pb(tmp);
                st.pop();
            }
            st.pop();
        }
        else if(scaned=="+"|| scaned=="-"||scaned=="*"||scaned=="/"||scaned=="^"){
            if(!st.empty() && pow[st.top()]>=pow[scaned]){
                string x = st.top();
                postfix.pb(x);
                st.pop();
            }
            st.push(scaned);
        }
        else{
            postfix.pb(scaned);
        }
    }
    while(!st.empty()){
        postfix.pb(st.top());
        st.pop();
    }
//showing output of postfix
    cout << "postfix: ";
    for(auto it: postfix){
         cout << it << " ";
    }
    cout << endl;

    //postfix evaluation
    double ans; 
    stack<double> final;
    for(int i=0; i<postfix.size(); i++){
        string symb = postfix[i];
        if(symb=="+"||symb=="-"|| symb =="*" || symb=="/" || symb == "^"){
            double second = final.top();
            final.pop();
            double first = final.top();
            final.pop();
            if(symb=="+"){
                ans = first + second;
            }
            if(symb=="-"){
                ans = first - second;
            }
            if(symb=="*"){
                ans = first * second;
            }
            if(symb=="/"){
                ans = first / second;
            }
            if(symb=="^"){
                ans = b_exponential(first, second);
            }
            final.push(ans);
        }
        else{
            double ok = stod(symb);
            final.push(ok);
        }
    }
    cout << "ans: " << ans;    

}
