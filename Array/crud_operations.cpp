/*
CURD + random number
C - 1,2,3,4,10,3,4
U - 2,5
R - 
D - 
RN - 
*/

// m[1] = 1
// m[5] = 1
// m[10] = 1
// m[4] = 1
// map<int, int>
// int n = math.rand();
// idx = m.size() % n;


#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int, int> data_map, rand_number;
    int i = 1;
    while(1){
        int op;
        cin>>op;
        if(op == 1){
            //create
            int n;
            cin>>n;
            if(rand_number[n])
            {
                cout<<"number already present"<<endl;
            }
            rand_number[n] = i;
            data_map[i] = n;
            i++;
        }
        else if(op == 2){
            //update
            int n, u;
            cin>>n>>u;
            if(rand_number[n]){
                int pos = rand_number[n];
                rand_number.erase(n);
                rand_number[u] = pos;
                data_map[pos] = n;
            }
            else{
                cout<<"number not present"<<endl;
            }
        }
        else if(op == 3){
        //     //read
            int n;
            cin>>n;
            if(rand_number[n]){
                cout<<"number is present-> "<<n<<endl;
            }
            else{
                cout<<"number is not present-> "<<n<<endl;
            }
        }
        else if(op == 4){
            //D
            int n;
            cin>>n;
            if(rand_number[n]){
                int pos = rand_number[n];
                rand_number.erase(n);
                data_map.erase(pos);
                i--;
            }
            else{
                cout<<"number not present"<<endl;
            }
            
        }
        else if(op == 5){
            //random number
            int n = rand();
            if(data_map.size() == 0){
                cout<<"number not present"<<endl;
            }
            int idx = n % data_map.size();
            cout<<"random number->"<<data_map[idx]<<endl;
            
        }
        else{
            for(auto i = data_map.begin(); i!=data_map.end(); i++){
                cout<<i->second<<" ";
            }
            cout<<"out of ops";
            break;
        }
    }
    return 0;
}