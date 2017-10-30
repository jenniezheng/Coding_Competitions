#include <bits/stdc++.h>
using namespace std;

map< pair<int,int>,pair<bool,int> > bestcut;

map< pair<int,int>,int> minsquares;

int limit=61;
//(width,height)=(verticle/horizontal,length)

//(width,height)=(squares)
//bottom left is 0,0

int setup_squares(){
    for(int x=1; x<limit; x++)
        minsquares[make_pair(x,x)]=1;
}



int find_least_squares(int width,int height){
    if(width==height)
        return 1;
    else{
        int mincuts=20000000;
        pair<bool,int> best_cut;
        //vertical cut;
        for (int length=1; length<=width/2; length++){
            int num_cuts=minsquares[make_pair(length,height)]+minsquares[make_pair(width-length,height)];
            if(num_cuts<mincuts){
                mincuts=num_cuts;
                best_cut=make_pair(true,length);
            }
        }
        //horizontal cut
        for (int length=1; length<=height/2; length++){
            int num_cuts=minsquares[make_pair(width,height-length)]+minsquares[make_pair(width,length)];
            if(num_cuts<mincuts){
                mincuts=num_cuts;
                best_cut=make_pair(false,length);
            }
        }
        //can speed up here
        minsquares[make_pair(width,height)]=mincuts;
        bestcut[make_pair(width,height)]=best_cut;
    }
}



void print_least_squares(int width,int height,int offset_x,int offset_y){
     if(width==height)
        printf("%d %d %d\n",offset_x,offset_y,width);
    else{
        pair<bool,int> p=bestcut[make_pair(width,height)];
        bool isVerticle=p.first;
        int length=p.second;
        if(isVerticle){
            print_least_squares(length,height,offset_x,offset_y);
            print_least_squares(width-length,height,offset_x+length,offset_y);
        }

        else{
            print_least_squares(width,height-length,offset_x,offset_y+length);
            print_least_squares(width,length,offset_x,offset_y);
        }

    }
}



int main(){
    // faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("hard.in", "r", stdin);
    //freopen("hard.out", "w", stdout);

    setup_squares();
    for (int width=1; width<limit; width++)
            for (int height=1; height<limit; height++)
                find_least_squares(width,height);



    int num_trials;
    scanf("%d",&num_trials);
    for (int trial=0; trial<num_trials; trial++){
        int width,height;
        scanf("%d %d",&width,&height);
        printf("%d\n",minsquares[make_pair(width,height)]);
        print_least_squares(width,height,0,0);
    }
}