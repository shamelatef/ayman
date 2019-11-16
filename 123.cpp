#include <iostream>
#include <cmath>
using namespace std;
class points{
    public:
        float x,y;
        points(){x=0;
                 y=0;}

        void setpoints(float i,float j){
            x=i;
            y=j;
        } 

        double operator -(points p){
            return sqrt(pow(x-p.x,2)+pow(y-p.y,2));
        }
        ~points(){};
    
};

class lines {
    public :
    double length;
    lines(){length=0;}
    void setlines(points w,points e){
        length=w-e;
    }
    float getlines (){return length;}
    ~lines (){};

};
class rectangle{
    protected: int r1,r2;
    public: 
        rectangle (lines r,lines t){r1=r.getlines();r2=t.getlines();}
       
       virtual float area(){return r1*r2;}
       virtual float circ(){return 2*(r1+r2);}
       ~rectangle(){};
};
class square:public rectangle{
    protected: 
    public: 
        square (lines r): rectangle (r,r){}
        ~square(){};
};

class circle{
    protected: float c1;
    public: 
        circle(lines r){c1=r.getlines();}
       virtual float area(){return 3.14*c1*c1;}
       virtual float circ(){return 2*3.14*c1;}
       ~circle(){};
};
class triangle{

    protected: float t1,t2,t3,t4;
    public: 
        triangle (lines r, lines t,lines q,lines w){t1=r.getlines();t2=t.getlines();t3=q.getlines();t4=w.getlines();}
        
        
       virtual float area(){return 0.5*t1*t4;}
       virtual float circ(){return t1+t2+t3;}
       ~triangle(){};



};
class home :public square, public triangle
{
     private://cout<<"This is your area: "<< 0.5*t1*t4+r1*     
     
             public: home(lines r,lines t,lines q,lines w ):square(r),triangle (r,t,q,w){};

        
             float area(){
                //cout<<"This is your area: "<< 0.5*t1*t4+r1*r2<<endl;
                return square->area()+triangle->area();
             }   
             float circ(){
                 return square->circ()+triangle->circ();
             }
            ~home(){};

}; 
/*class RecCircle: public rectangle, public circle
{

    public: 
        RecCircle(lines r,lines t,lines q): rectangle(r,t), circle(q){};
        void area()
        {
            cout<<"this is your shaded area: "<<r1*r2 - 3.14*c1*c1<<endl;
        }
        void circ()
        {
            cout<< "this is the perimeter: "<<2*(r1+r2)+2*3.14*c1<<endl;
        }
        ~RecCircle(){};

};

class TriCircle:public triangle,public circle
{
    private:
    public:
        TriCircle(lines r,lines t,lines q,lines u,lines p):triangle(r,t,q,u),circle(p){};
        void area(){

            cout<<"This is the shaped area: "<<0.5*t1*t4 - 3.14*c1*c1<<endl;
        }
        void circ(){
            cout<<"this is the perimeter: "<< t1+t2+t3 +2*3.14*c1<<endl;
        }
        ~TriCircle(){};

};

*/

int main(){

    cout <<"choose one of the following shapes to get its circ and area: \n"<<" 1.Circle\n 2.Rectangle\n 3.Square\n 4.Triangle\n 5.Home\n 6.Circle inside a rectangle\n 7.circle inside a triangle\n ";
    int m;
    cin>>m;
    if (m==1){
    points p,p1;
    lines l;
    cout<<"Enter the coordinates of any point on the surface:\n";
    int c1,c2,c4,c3;
    cin>>c1>>c2;
    p.setpoints(c1,c2);
    cout<<"Enter the coordinates of the center point:\n";
    cin>>c3,c4;
    p1.setpoints(c3,c4);
    l.setlines(p,p1);
    circle c(l);
    c.area();
    c.circ();
    }
    
    
    else if (m==2){
    lines l,l1;
    points p,p1,p2;
    int s1,s2,s3,s4,s5,s6;
    cout<<"Enter the coordinates of three points that are in arrange\n";
    cin>>s1>>s2>>s3>>s4;
    p.setpoints(s1,s2);
    p1.setpoints (s3,s4);
    p2.setpoints (s5,s6);
    l.setlines (p,p1);
    l1.setlines (p1,p2);
    rectangle s(l,l1);
    s.area();
    s.circ();
    }



    else if(m==3){
    lines l;
    points p,p1;
    cout<<"Enter the coordinates of two points that are in arrange\n";
    int s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    p.setpoints(s1,s2);
    p1.setpoints (s3,s4);
    l.setlines (p,p1);
    square s(l);
    s.area();
    s.circ();

    }




    else if (m==4)
    {
            lines l,l1,l2,l3;
            points p,p1,p2,p3;
            cout<<"Enter the coordinates of the triangle\n";
            float s1,s2,s3,s4,s5,s6,s7,s8;
            //cin>>s1>>s2>>s3>>s4>>s5>>s6>>s7,s8;
            cout<<"enter the coordinates of your base\n";
            cin>>s1>>s2>>s3>>s4;
            cout<<"enter the coordinates of your head\n";
            cin>>s5>>s6;
            cout<<"enter the extension point of your head to the base\n";
            cin>>s7>>s8;
            p.setpoints(s1,s2);//base
            p1.setpoints(s3,s4);//base
            p2.setpoints(s5,s6);//head
            p3.setpoints(s7,s8);//mid base
            l.setlines(p,p1);//base or side
            l1.setlines(p1,p2);//side
            l2.setlines(p2,p);//side
            l3.setlines(p2,p3);//height
            triangle s(l,l1,l2,l3);
            s.area();
            s.circ();



    }
   
    else if (m==5)
    {
        points p,p1,p2,p3;
        lines l,l1,l2,l3;
        cout<< "Enter the coordinates of the upper side  of the square (which is also considered the base of the triangle)\n";
        float h,h1,h2,h3,h4,h5,h6,h7;
        cin>>h>>h1>>h2>>h3;
        cout <<"enter the coordinates of the head\n";
        cin>>h4>>h5;
        cout<<"enter the coordinates of the extention of the head to the base\n";
        cin>>h6>>h7;
        p.setpoints(h,h1);//base
        p1.setpoints(h2,h3);//base
        p2.setpoints(h4,h5);//head
        p3.setpoints(h6,h7);//mid
        l.setlines(p,p1);
        l1.setlines(p,p2);
        l2.setlines(p1,p2);
        l3.setlines(p2,p3);
        home s(l,l1,l2,l3);

        cout<< s.area();
        //s.circ();
    }
/*
    }
    else if(m==6){
        points p1,p2,p3,p4,p5,p6;
        float s1,s2,s3,s4,s5,s6,s7,s8,s9,s10;
        lines l1,l2,l3;
        cout<<"Enter 3 points of the rectangle that are in arrange: "<<endl;
        cout<<"enter the first point: "<<endl;
        cin>>s1>>s2;
        cout<<"enter the second point\n";
        cin>>s3>>s4;
        cout<<"enter the third point\n";
        cin>>s5>>s6;
        cout<<"enter the center point of the circle:\n";
        cin>>s7>>s8;
        cout<<"enter any point on the circle's surface\n";
        cin>>s9>>s10;
        p1.setpoints(s1,s2);
        p2.setpoints(s3,s4);
        p3.setpoints(s5,s6);
        p4.setpoints(s7,s8);
        p5.setpoints(s9,s10);
        l1.setlines(p1,p2);
        l2.setlines(p2,p3);
        l3.setlines(p4,p5);
        RecCircle s(l1,l2,l3);
        s.area();
        s.circ();
    }
    else if (m==7)
    {
        points p1,p2,p3,p4,p5,p6;
        lines l1,l2,l3,l4,l5;
        cout<<"Enter the points of your triangle that are in arrange\n";
        float s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11,s12;
        cout<<"Enter the first point which is one of the points of your base\n";
        cin>>s1>>s2;
        cout<<"Enter the second point which is one of the points of your base\n";
        cin>>s3>>s4;
        cout<<"Enter the head point\n";
        cin>>s5>>s6;
        cout<<"Enter the mid point of your base\n";
        cin>>s7>>s8;
        cout<<"Enter 2 points of your circle one of them is the center and the other one is on the surface\n";
        cin>>s9>>s10>>s11>>s12;
        p1.setpoints(s1,s2);
        p2.setpoints(s3,s4);
        p3.setpoints(s5,s6);
        p4.setpoints(s7,s8);
        p5.setpoints(s9,s10);
        p6.setpoints(s11,s12);
        l1.setlines(p1,p2);
        l2.setlines(p2,p3);
        l3.setlines(p3,p1);
        l4.setlines(p3,p4);
        l5.setlines(p5,p6);
        TriCircle s(l1,l2,l3,l4,l5);
        s.area();
        s.circ();
    }
    */
   return 0;
    
}