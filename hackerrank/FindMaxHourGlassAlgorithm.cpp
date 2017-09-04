
#include <vector>
#include <iostream>

using namespace std;


int main(){
    vector< vector<int> > arr(6,vector<int>(6));
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }
    int max;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)//one hourglass
            {int glass=0;
             for(int r=0; r<3; r++)
                for(int c=0; c<3; c++)
                    if(r==1&&c!=1) continue;
                    else glass+=arr[i+r][j+c];
            if ((i==0&&j==0) || glass>max)
                max=glass;
            }
    cout<<max;
    return 0;
}