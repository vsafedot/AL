// #include<iostream>
// #include<vector>
// #include<queue>
// #include<algorithm>
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n,a,b;
//         cin>>n>>a>>b;
//         if(abs(a-b)%2 == 0){
//             cout<<"YES"<<endl;
//         }
//         else{
//             cout<<"NO"<<endl;
//         }

//     }
// }


#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include <climits>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            v.push_back(temp);
        }
        vector<int> v1;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            v1.push_back(temp);
        }
        int need = 0;
        int mini = INT_MAX;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(v[i] < v1[i]){
                need += (v1[i] - v[i]);
                cnt++;
            }
            else{
                mini = min(mini, v[i] - v1[i]);
            }
        }
        if(cnt>1){
            cout<<"YES"<<endl;
        }
        else {
            cout << (need <= mini ? "NO" : "YES") << endl;
        }
        
    }
}