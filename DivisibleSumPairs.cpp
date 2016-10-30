#include <vector>
#include <iostream>


using namespace std;

#include <vector>
#include <iostream>


using namespace std;

int main(){
    int n; //number of ints
    int k; //find pairs divisible by k
    cin >> n >> k;
    vector<int> nums(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> nums[a_i];
    }



    int pairs=0;
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++) 
               if((nums[j]+nums[i])%k==0)   pairs++;
    cout<<pairs;
    return 0;
}
