#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout << fixed;cout.precision(10);
#define endl "\n"
#define tc ll T; cin >> T; while(T--)
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define MX 1000001
#define vi vector<int>
#define vs vector<string>
#define pii pair<int, int>

using namespace std;

void LPS(string str, int lps[]){
    int n = (int)str.length();
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while(i < n){
        if(str[i] == str[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len == 0){
                lps[i] = 0;
                i++;
            }
            else{
               len = lps[len-1];
            }
        }
    }

}

void KMP(string txt, string pat){
    int n = txt.length();
    int m = pat.length();
    int lps[m];
    LPS(pat, lps);
    int i = 0, j = 0;

    while(i < n){
        if(pat[j] == txt[i]){
            i++;
            j++;
        }
        if(j == m){
            cout << i - j << " ";
            j = lps[j-1];
        }
        else if(i < n and pat[j] != txt[i]){
            if(j == 0){
                i++;
            }
            else
                j = lps[j-1];
        }
    }

}

int main(){

    string txt, pat;
    cin >> txt >> pat;
    KMP(txt, pat);


}
