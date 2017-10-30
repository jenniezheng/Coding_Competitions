#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<int> wins;
vector<int> c1_scores;
vector<int> c2_scores;
int get_date()
{
    int date, month, year;
    scanf("%d %d %d",&date,&month,&year);
    return year*400+month*31+date;
}

int main(){
    // faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("codecoder.in", "r", stdin);
    freopen("codecoder.out", "w", stdout);

    int num_people;
    scanf("%d",&num_people);
    for (int currentPerson=0; currentPerson<num_people; currentPerson++){
        int c1_score,c2_score;
        scanf("%d %d",&c1_score,&c2_score);
        c1_scores.push_back(c1_score);
        c2_scores.push_back(c2_score);
        wins.push_back(0);
        for (int prePerson=0; prePerson<currentPerson; prePerson++){
            if(c1_scores[currentPerson]>c1_scores[prePerson] ||
                c2_scores[currentPerson]>c2_scores[prePerson] ){
                wins[currentPerson]+=1;
            }
            if(c1_scores[currentPerson]<c1_scores[prePerson] ||
                c2_scores[currentPerson]<c2_scores[prePerson] ){
                wins[prePerson]+=1;
            }
        }

    }

    for (int currentPerson=0; currentPerson<num_people; currentPerson++){
        printf("%d\n",wins[currentPerson]);
    }


}