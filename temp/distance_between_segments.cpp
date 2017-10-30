#include <bits/stdc++.h>
using namespace std;

double distance(double x1, double y1,double x2, double y2){
    return sqrt((x2-x1)*(x2-x1) +(y2-y1)*(y2-y1));
}

bool close_to_zero(double a){
    double eps=.0000000000001;
    return a < eps && a > -eps;
}
bool on_line(double xp, double yp, double a, double b, double c){
    return close_to_zero ((double)a*xp+b*yp+c);
}

bool on_line_segment(double xp, double yp, double x1, double y1, double x2, double y2){
    bool on_line;
    if(xp > x1 && xp > x2  ||
    xp < x1 && xp < x2 ||
    yp > y1 && yp > y2 ||
    yp < y1 && yp < y2)
        on_line=false;
    else if(close_to_zero (xp- x1) && close_to_zero (yp-y1)  ||
    close_to_zero (xp-x2) && close_to_zero (yp-y2))
        on_line=true;
    else{
        double rangex1=xp-x1;
        double rangex2=x2-x1;
        double rangey1=yp-y1;
        double rangey2=y2-y1;
        if(close_to_zero(rangex1))
            on_line=(close_to_zero(rangex2));
        else if(close_to_zero(rangey1))
            on_line=(close_to_zero(rangey2));
        else{
            double res=rangex1/rangex2-rangey1/rangey2;
            on_line= close_to_zero(res);
        }
    }
    return on_line;
}

void intersection(double a,double b, double c, double j, double k, double l,
    double& res_x, double& res_y ){
    res_x = (c*k-b*l) / (b*j-a*k);
    res_y = (a*l-c*j) / (b*j-a*k);
}

double distance_to_line(double xp,double yp,double a,double b,double c){
    double my_distance;
    if(on_line(xp,yp,a,b,c)) my_distance=0;
    else {
        double x,y;
        intersection(a,b,c, -(double)b,a, -((double)xp*-b + yp*a),x,y);
        my_distance=distance(x,y,xp,yp);
    }
    return my_distance;
}

void extend_segment(double x1, double y1, double x2, double y2,
    double& a, double& b, double& c){
    a=-y2+y1;
    b=x2-x1;
    c=-(a*x1+b*y1);
}

double distance_to_line_segment(double xp,double yp,double x1,double y1,double x2,double y2){
     double my_distance;
    if(on_line_segment(xp,yp,x1,y1,x2,y2))
        my_distance=0;
    else{
        double a,b,c;
        //extend the line segment and find intersection point
        extend_segment(x1,y1,x2,y2,a,b,c);
        //printf("%f %f %f\n",a,b,c);

        double potential_intersection_x, potential_intersection_y;
        intersection(a,b,c, -b, a, -((double)xp*-b + yp*a),
            potential_intersection_x,potential_intersection_y);
       //printf("int %f %f\n",potential_intersection_x,potential_intersection_y);
       if(on_line_segment(potential_intersection_x,potential_intersection_y,x1,y1,x2,y2)){
             my_distance=distance(potential_intersection_x, potential_intersection_y,xp,yp);
        }
        else{
            my_distance=min( distance(x1, y1,xp,yp),
                distance(x2, y2,xp,yp) );
        }
    }
    return my_distance;
}

int main(){
    // faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("test.txt", "r", stdin);
    freopen("distance.in", "r", stdin);
    freopen("distance.out", "w", stdout);
    int x1,y1,x2,y2,x3,y3,x4,y4;
    scanf("%d %d %d %d %d %d %d %d",
        &x1,&y1,&x2,&y2,&x3,&y3, &x4,&y4);


    double my_distance=100000000000000;
    {
        double a1,b1,c1;
        extend_segment(x1,y1,x2,y2,a1,b1,c1);
        double a2,b2,c2;
        extend_segment(x3,y3,x4,y4,a2,b2,c2);
        double x,y;
        intersection(a1,b1,c1,a2,b2,c2,x,y);
        if(on_line_segment(x,y,x1,y1,x2,y2) &&
            on_line_segment(x,y,x3,y3,x4,y4))
            my_distance=0;
    }
    my_distance=min(my_distance, distance(x1,y1,x4,y4));
    my_distance=min(my_distance, distance(x1,y1,x3,y3));
    my_distance=min(my_distance, distance(x2,y2,x4,y4));
    my_distance=min(my_distance, distance(x2,y2,x3,y3));
    my_distance=min(my_distance, distance_to_line_segment(x1,y1,x3,y3,x4,y4));
    my_distance=min(my_distance, distance_to_line_segment(x2,y2,x3,y3,x4,y4));
    my_distance=min(my_distance, distance_to_line_segment(x3,y3,x1,y1,x2,y2));
    my_distance=min(my_distance, distance_to_line_segment(x4,y4,x1,y1,x2,y2));
    cout.precision(10);
    cout << fixed << my_distance << endl;

}