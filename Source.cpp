#include <iostream>
#include <math.h>
#include <string>
#include <cstdlib>
using namespace std;
class Point{
	float x,y;
public:
	Point(){x=0;y=0;}
	Point(float xx,float yy){
		x=xx;
		y=yy;
	}
	void setx(float a){x=a;}
	void sety(float a){y=a;}
	float getx(){return x;}
	float gety(){return y;}
	float Distance(Point a,Point b){return sqrt(pow(a.getx()-b.getx(),2)+pow(a.gety()-b.gety(),2));}

};
class Line{
	Point p1,p2;
	float slope;
public:
	void setp1(float x,float y){p1.setx(x);p1.sety(y);}
	void setp2(float x,float y){p2.setx(x);p2.sety(y);}
	Point getp1(){return p1;}
	Point getp2(){return p2;}
	void setslope(){if((p1.getx()-p2.getx())==0&&(p1.gety()-p2.gety())!=0)slope=99999999;
	if((p1.gety()-p2.gety())==0&&(p1.getx()-p2.getx())!=0)slope=0;
	if((p1.gety()-p2.gety())==0&&(p1.getx()-p2.getx())==0)slope=0;
	if((p1.gety()-p2.gety())!=0&&(p1.getx()-p2.getx())!=0)slope=(p1.gety()-p2.gety())/(p1.getx()-p2.getx());}
	float getslope(){return slope;
	}
};
class Polygon{
	Point A[100];
	int npoints,npoints_,no_of_red_points,nlines;
public:
	void setnpoints(int a){npoints=a;}
	int getnpoints(){return npoints;}
	void setnpoints_(int a){npoints_=a;}
	int getnpoints_(){return npoints_;}
	void setnofred(int a){no_of_red_points=a;}
	int getnofred(){return no_of_red_points;}
	void setpoint(int a,Point b){A[a]=b;}
	Point getpoint(int a){return A[a];}
};
//string functions
string reverse(string a)
{string newa="";
for(int k=a.length()-1;k>=0;k--)
newa=newa+a[k];
return newa;
}

int Number_Polygons(string s){
int no_of_p=0;
	int no_of_points_check=0;
	for(int k=0;k<s.length();k++)
	{if(s[k]=='(')no_of_points_check++;}
	if(no_of_points_check==0)return 0;
	else
	{for(int k=0;k<s.length();k++)
	{if(s[k]==';')no_of_p++;}
	no_of_p++;
	return no_of_p;
	}}
int numberPoints(string s)
{
	float result=0;
	for(int k=0;k<s.length();k++)
		{if(s[k]=='(')result++;
	}
	return result;
}
float min(float A[],int s){
		float minimum=A[0];
		for(int k=1;k<s;k++){if(A[k]<minimum)minimum=A[k];
		}
		return minimum;
	}
float max(float A[],int s){
		float maximum=A[0];
		for(int k=1;k<s;k++){if(A[k]>maximum)maximum=A[k];
		}
		return maximum;
	}
int numberRed(float A[],int s1,float B[],int s2)
{
	float result=0,dy1,dx1,dy2,dx2,m1,m2;
	for(int k=0;k<s1;k++)
	{if(A[k]==A[k+1] && B[k]==B[k+1])result++;
	if(A[k]==A[k+1] && B[k]!=B[k+1]){if(A[k+1]==A[k+2] && B[k+1]!=B[k+2])result++;}
	if(B[k]==B[k+1] && A[k]!=A[k+1]){if(B[k+1]==B[k+2] && A[k+1]!=A[k+2])result++;}
	dy1=B[k+1]-B[k];dx1=A[k+1]-A[k];dy2=B[k+2]-B[k+1];dx2=A[k+2]-A[k+1];m1=dy1/dx1;m2=dy2/dx2;
	if(m2==m1)result++;
	}
	return result;
}
	//a function to calculate the slope of a line connecting 2 points
float Slope(Point p1,Point p2)
{
	if((p1.getx()-p2.getx())==0&&(p1.gety()-p2.gety())!=0)return 200;
	if((p1.gety()-p2.gety())==0&&(p1.getx()-p2.getx())!=0)return -0.005;
	if((p1.gety()-p2.gety())!=0&&(p1.getx()-p2.getx())!=0)return (p1.gety()-p2.gety())/(p1.getx()-p2.getx());
}
//a function to calculate the length of a line connecting 2 points
float Distance(Point a,Point b)
{
	return sqrt(pow(a.getx()-b.getx(),2)+pow(a.gety()-b.gety(),2));
}
//a function to calculate the area of a given polygon
float Area(Polygon p){
	float A=0;
	for(int i=0;i<=p.getnpoints()-2;i++)
	{A+=(p.getpoint(i).getx()*p.getpoint(i+1).gety()-p.getpoint(i+1).getx()*p.getpoint(i).gety());}
	A+=(p.getpoint(p.getnpoints()-1).getx()*p.getpoint(0).gety()-p.getpoint(0).getx()*p.getpoint(p.getnpoints()-1).gety());
	A=A*0.5;
	A=abs(A);
	return A;
}
int main(){string p;
getline(cin,p);
//example of input format Polygons=[(1,1),(4,1),(4,5),(1,5);(3,4),(6,4),(6,12),(3,12)]
int length=p.length();
int xindex=0,yindex=0;
float array_of_x[10001];
float array_of_y[10001];
int i,j;int q;
string coo="";
float store;
char co;
//filling x and y coordinates arrays
for(i=0;i<length;i++){
	if(p[i]=='('){coo="";j=1; while(p[i+j] != ','){co=p[i+j]; coo=coo+co;j=j++;}
	store=atof(coo.c_str());
		array_of_x[xindex]=store;xindex++;}
	if(p[i]==')'){coo="";j=1; while(p[i-j] != ','){co=p[i-j]; coo=coo+co;j=j++;}
	coo=reverse(coo);
	store=atof(coo.c_str());
		array_of_y[yindex]=store;yindex++;}
}

float maxX=max(array_of_x,numberPoints(p));
float maxY=max(array_of_y,numberPoints(p));
float minX=min(array_of_x,numberPoints(p));
float minY=min(array_of_y,numberPoints(p));
//creating an array of polygons from the input string
Polygon POL[100];
int k,l,m,n,c=0,a=0,t=0;
float store_,xchecker=0,ychecker=0;
Point poi,pa,pb;
for(k=0;k<Number_Polygons(p);k++){
for(i=a;i<length;i++){
	if(p[i]=='('){coo="";j=1; while(p[i+j] != ','){co=p[i+j]; coo=coo+co;j=j++;}
	store=atof(coo.c_str());xchecker=1;
	}
	if(p[i]==')'){coo="";j=1; while(p[i-j] != ','){co=p[i-j]; coo=coo+co;j=j++;}
	coo=reverse(coo);
	store_=atof(coo.c_str());
		ychecker=1;}
	if(xchecker==1){
	poi.setx(store);xchecker=2;}
	if(ychecker==1){poi.sety(store_);ychecker=2;}
	if(xchecker==2 && ychecker==2){POL[k].setpoint(c,poi);c++;
	xchecker=0;ychecker=0,t++;if(p[i+1]==';' || p[i+1]==']'){POL[k].setnpoints(t);a=i+1;t=0;c=0;break;}}

}
}

//creating another array of polygons but this time without redundant points
Polygon POL_first_step[100];
int ppol_counter=0,ppol_point_counter=0;
    //for filling POL_first_step(easiest case of redundant points)
for(i=0;i<Number_Polygons(p);i++){
	for(j=0;j<POL[i].getnpoints()-1;j++){
		if(POL[i].getpoint(j).getx()==POL[i].getpoint(j+1).getx()&&POL[i].getpoint(j).gety()==POL[i].getpoint(j+1).gety())
		{k=2;c=1;
		while(POL[i].getpoint(j).getx()==POL[i].getpoint(j+k).getx()&&POL[i].getpoint(j).gety()==POL[i].getpoint(j+k).gety())
		{c++;k++;}
		POL_first_step[ppol_counter].setpoint(ppol_point_counter,POL[i].getpoint(j));
		j+=c;
		ppol_point_counter++;
		}
	else {
		POL_first_step[ppol_counter].setpoint(ppol_point_counter,POL[i].getpoint(j));
		ppol_point_counter+=1;
	}
	}
	if(POL[i].getpoint(POL[i].getnpoints()-1).getx()!=POL[i].getpoint(0).getx()&&POL[i].getpoint(POL[i].getnpoints()-1).gety()!=POL[i].getpoint(0).gety()&&POL[i].getpoint(POL[i].getnpoints()-1).getx()!=POL[i].getpoint(POL[i].getnpoints()-2).getx()&&POL[i].getpoint(POL[i].getnpoints()-1).gety()!=POL[i].getpoint(POL[i].getnpoints()-2).gety())
	{POL_first_step[ppol_counter].setpoint(ppol_point_counter,POL[i].getpoint(POL[i].getnpoints()-1));ppol_point_counter++;}
	POL_first_step[ppol_counter].setnpoints(ppol_point_counter);
	//an if condition just to check..
	if(POL_first_step[i].getpoint(POL_first_step[i].getnpoints()-1).getx()==POL_first_step[i].getpoint(0).getx()&&POL_first_step[i].getpoint(POL_first_step[i].getnpoints()-1).gety()==POL_first_step[i].getpoint(0).gety())
	{POL_first_step[ppol_counter].setnpoints(ppol_point_counter-1);}
	ppol_counter++;
	ppol_point_counter=0;
}
//now second step..removing "same slope" points
Polygon POL_second_step[100];
ppol_counter=0;ppol_point_counter=0;
for(i=0;i<Number_Polygons(p);i++){
	for(j=0;j<=POL_first_step[i].getnpoints()-3;j++){
		if(Slope(POL_first_step[i].getpoint(j),POL_first_step[i].getpoint(j+1))==Slope(POL_first_step[i].getpoint(j+1),POL_first_step[i].getpoint(j+2))){
			c=1;m=0;
			while(Slope(POL_first_step[i].getpoint(j+m+1),POL_first_step[i].getpoint(j+m+2))==Slope(POL_first_step[i].getpoint(j+m+2),POL_first_step[i].getpoint(j+m+3))){
				c++;m++;
			}
			POL_second_step[ppol_counter].setpoint(ppol_point_counter,POL_first_step[i].getpoint(j));
		j+=c;
		ppol_point_counter++;

		}
		else {POL_second_step[ppol_counter].setpoint(ppol_point_counter,POL_first_step[i].getpoint(j));
		ppol_point_counter++;}
}
	if(j!=POL_first_step[i].getnpoints())
	{POL_second_step[ppol_counter].setpoint(ppol_point_counter,POL_first_step[i].getpoint(POL_first_step[i].getnpoints()-2));
	ppol_point_counter++;}
	POL_second_step[ppol_counter].setpoint(ppol_point_counter,POL_first_step[i].getpoint(POL_first_step[i].getnpoints()-1));
	POL_second_step[ppol_counter].setnpoints(ppol_point_counter+1);
	


	if(Slope(POL_second_step[i].getpoint(POL_second_step[i].getnpoints()-2),POL_second_step[i].getpoint(POL_second_step[i].getnpoints()-1))==Slope(POL_second_step[i].getpoint(POL_second_step[i].getnpoints()-1),POL_second_step[i].getpoint(0)))
	{POL_second_step[ppol_counter].setnpoints(POL_second_step[i].getnpoints()-1);}




	ppol_counter++;
	ppol_point_counter=0;

}
//Now Final step
Polygon POL_final_step[100];
ppol_counter=0;ppol_point_counter=0;
for(i=0;i<Number_Polygons(p);i++){
	if(Slope(POL_second_step[i].getpoint(POL_second_step[i].getnpoints()-1),POL_second_step[i].getpoint(0))==Slope(POL_second_step[i].getpoint(0),POL_second_step[i].getpoint(1)))
	{k=0;
	for(j=1;j<POL_second_step[i].getnpoints();j++)
	{
		poi.setx(POL_second_step[i].getpoint(j).getx());
		poi.sety(POL_second_step[i].getpoint(j).gety());
		POL_final_step[i].setpoint(k,poi);
		k++;
	}
	POL_final_step[i].setnpoints(POL_second_step[i].getnpoints()-1);
	}

	else{
		for(j=0;j<POL_second_step[i].getnpoints();j++)
	{
		poi.setx(POL_second_step[i].getpoint(j).getx());
		poi.sety(POL_second_step[i].getpoint(j).gety());
		POL_final_step[i].setpoint(j,poi);
	}
		POL_final_step[i].setnpoints(POL_second_step[i].getnpoints());
}

}
//defining some variables that may be useful later
int loop_execution_checker;
string n_input;
float n_input_as_no;
//List_Points_Polygons More/Less/Equal n Variables
int same_point_counter;float Array_of_printedx[100],Array_of_printedy[100];
//List_Rectangles & List_Trapezoid
float s1,s2,s3,s4,d1,d2,d3,d4;
//Inside_Rectangle
string input_string;
float array_of_xrectangle[4],array_of_yrectangle[4];
float maxX_;
float maxY_;
float minX_;
float minY_;
int points_inside_checker=0;
//Inside_Circle
float centrex,centrey,radius;
Point centre;
//Polygons_Area_Range minArea,maxArea
float minArea,maxArea;

int ctr=0;
string op;
getline(cin,op);
while(op!="Quit"){
	//Number_Polygons
	if(op=="Number_Polygons"){
		if(Number_Polygons(p)==0)cout<<"none";
		else cout<<Number_Polygons(p);
	}
	//Total_Number_Points
	if(op=="Total_Number_Points")
	{int no_of_points=0;
	for(i=0;i<length;i++)
	{if(p[i]=='(')no_of_points=no_of_points+1;}
	if(no_of_points==0)cout<<"none";
	else
	cout<<no_of_points;	
	}
		//Minimum_X
	if(op=="Minimum_X"){if(numberPoints(p)==0)cout<<"none";else
	{cout<<minX;}
	}
		//Maximum_X
	if(op=="Maximum_X"){if(numberPoints(p)==0)cout<<"none";else
	{cout<<maxX;}
	}
		//Minimum_Y
	if(op=="Minimum_Y"){if(numberPoints(p)==0)cout<<"none";else
	{cout<<minY;}
	}
		//Maximum_Y
	if(op=="Maximum_Y"){if(numberPoints(p)==0)cout<<"none";else
	{cout<<maxY;}
	}
		//Enclosing_Rectangle
	if(op=="Enclosing_Rectangle"){if(numberPoints(p)==0)cout<<"none";else
	{cout<<"("<<minX<<","<<minY<<"),("<<maxX<<","<<minY<<"),("<<maxX<<","<<maxY<<"),("<<minX<<","<<maxY<<")";}
	}
	//Total_Redundant_Points
	if(op=="Total_Redundant_Points"){l=0;m=0;
		for(i=0;i<Number_Polygons(p);i++){
			l+=POL[i].getnpoints();
		}
		for(i=0;i<Number_Polygons(p);i++){
			m+=POL_final_step[i].getnpoints();
		}

		if(l==m){cout<<"none";}
		else {cout<<l-m;}


	}
	//Level 2
	//Polygon_Points n
	if(op.substr(0,15)=="Polygon_Points "){n_input="";i=15;
	while(1){
		n_input+=op[i];
		i++;
		if(i==op.length()){break;}}
	n_input_as_no=atof(n_input.c_str());
	n=n_input_as_no-1;
	for(i=0;i<POL_second_step[n].getnpoints();i++){
		cout<<"("<<POL_second_step[n].getpoint(i).getx()<<","<<POL_second_step[n].getpoint(i).gety()<<")";
		if(i!=POL_second_step[n].getnpoints()-1)cout<<",";

	}


	}
	//Point_Polygons (2,1)
	if(op.substr(0,15)=="Point_Polygons "){
	string x_input_point="",y_input_point="";i=16;
	while(1){
		x_input_point+=op[i];
		i++;
		if(op[i]==','){i++;break;}}

	while(1){if(op[i]==')')break;
		y_input_point+=op[i];
		i++;
		}
	float x_input_point_as_no=atof(x_input_point.c_str());
	float y_input_point_as_no=atof(y_input_point.c_str());
	float array_of_IDs[100];
	int array_counter=0;
	for(i=0;i<Number_Polygons(p);i++){
		for(j=0;j<POL[i].getnpoints();j++){
			if(POL[i].getpoint(j).getx()==x_input_point_as_no && POL[i].getpoint(j).gety()==y_input_point_as_no)
			{array_of_IDs[array_counter]=i+1;array_counter++;}
		}
	}
	if(array_counter==0)cout<<"none";
	for(k=0;k<array_counter;k++)
		{cout<<array_of_IDs[k];
	if((k+1) != array_counter) cout<<",";}
	}

	
	//List_Polygons_Points More n
if(op.substr(0,26)=="List_Polygons_Points More "){
	n_input="";i=26;loop_execution_checker=0;
	while(1){
		n_input+=op[i];
		i++;
		if(i==op.length()){break;}}
	n_input_as_no=atof(n_input.c_str());
	for(i=0;i<Number_Polygons(p);i++){
		if(n_input_as_no<POL_final_step[i].getnpoints())
		{cout<<i+1;loop_execution_checker++;
		for(j=i+1;j<Number_Polygons(p);j++){if(n_input_as_no<POL_final_step[j].getnpoints()){cout<<",";break;}}

		}
		
	}
	if(loop_execution_checker==0)cout<<"none";
	}    
	//List_Polygons_Points Less n
if(op.substr(0,26)=="List_Polygons_Points Less "){
	n_input="";i=26;loop_execution_checker=0;
	while(1){
		n_input+=op[i];
		i++;
		if(i==op.length()){break;}}
	n_input_as_no=atof(n_input.c_str());
	for(i=0;i<Number_Polygons(p);i++){
		if(n_input_as_no>POL_final_step[i].getnpoints())
		{cout<<i+1;loop_execution_checker++;
		for(j=i+1;j<Number_Polygons(p);j++){if(n_input_as_no>POL_final_step[j].getnpoints()){cout<<",";break;}}

		}
		
	}
	if(loop_execution_checker==0)cout<<"none";
	}         
	//List_Polygons_Points Equal n
	if(op.substr(0,27)=="List_Polygons_Points Equal "){
		n_input="";i=27;loop_execution_checker=0;
	while(1){
		n_input+=op[i];
		i++;
		if(i==op.length()){break;}}
	n_input_as_no=atof(n_input.c_str());
	for(i=0;i<Number_Polygons(p);i++){
		if(n_input_as_no==POL_final_step[i].getnpoints())
		{cout<<i+1;loop_execution_checker++;
		for(j=i+1;j<Number_Polygons(p);j++){if(n_input_as_no==POL_final_step[j].getnpoints()){cout<<",";break;}}

		}
		
	}
	if(loop_execution_checker==0)cout<<"none";
	}         
	//List_Points_Polygons More n
	if(op.substr(0,26)=="List_Points_Polygons More "){
		for(j=0;j<100;j++)
		{
			Array_of_printedx[j]=-133.051;
			Array_of_printedy[j]=-133.054;
		}
	n_input="";i=26;
	same_point_counter=1;c=1;
	while(1){
		n_input+=op[i];
		i++;
		if(i==op.length()){break;}}
	n_input_as_no=atof(n_input.c_str());
	m=0;q=0;
	for(i=0;i<Number_Polygons(p);i++){
		for(j=0;j<POL[i].getnpoints();j++)
		{same_point_counter=1;
			for(n=0;n<100;n++){
						if(POL[i].getpoint(j).getx()==Array_of_printedx[n]&&POL[i].getpoint(j).gety()==Array_of_printedy[n])
						{c=0;break;}}
			if(c==0){c=1;continue;}
			for(k=0;k<Number_Polygons(p);k++){if(k==i)continue;
				for(l=0;l<POL[k].getnpoints();l++){
					
				if(POL[k].getpoint(l).getx()==POL[i].getpoint(j).getx()&&POL[k].getpoint(l).gety()==POL[i].getpoint(j).gety())
				{same_point_counter++;break;}}
			}
			if(same_point_counter>n_input_as_no){Array_of_printedx[q]=POL[i].getpoint(j).getx();
		Array_of_printedy[q]=POL[i].getpoint(j).gety();q++;}
		}
		
		
	}
	if(q==0)cout<<"none";
	else{
	for(n=0;n<q;n++){cout<<"("<<Array_of_printedx[n]<<","<<Array_of_printedy[n]<<")";
	if(n!=q-1)cout<<",";}}
	}

	//List_Points_Polygons Less n
		if(op.substr(0,26)=="List_Points_Polygons Less "){
		for(j=0;j<100;j++)
		{
			Array_of_printedx[j]=-133.051;
			Array_of_printedy[j]=-133.054;
		}
	n_input="";i=26;
	same_point_counter=1;c=1;
	while(1){
		n_input+=op[i];
		i++;
		if(i==op.length()){break;}}
	n_input_as_no=atof(n_input.c_str());
	m=0;q=0;
	for(i=0;i<Number_Polygons(p);i++){
		for(j=0;j<POL[i].getnpoints();j++)
		{same_point_counter=1;
			for(n=0;n<100;n++){
						if(POL[i].getpoint(j).getx()==Array_of_printedx[n]&&POL[i].getpoint(j).gety()==Array_of_printedy[n])
						{c=0;break;}}
			if(c==0){c=1;continue;}
			for(k=0;k<Number_Polygons(p);k++){if(k==i)continue;
				for(l=0;l<POL[k].getnpoints();l++){
					
				if(POL[k].getpoint(l).getx()==POL[i].getpoint(j).getx()&&POL[k].getpoint(l).gety()==POL[i].getpoint(j).gety())
				{same_point_counter++;break;}}
			}
			if(same_point_counter<n_input_as_no){Array_of_printedx[q]=POL[i].getpoint(j).getx();
		Array_of_printedy[q]=POL[i].getpoint(j).gety();q++;}
		}
		
		
	}
	if(q==0)cout<<"none";
	else{
	for(n=0;n<q;n++){cout<<"("<<Array_of_printedx[n]<<","<<Array_of_printedy[n]<<")";
	if(n!=q-1)cout<<",";}}
	}
		//List_Points_Polygons Equal n
		if(op.substr(0,27)=="List_Points_Polygons Equal "){
		for(j=0;j<100;j++)
		{
			Array_of_printedx[j]=-133.051;
			Array_of_printedy[j]=-133.054;
		}
	n_input="";i=27;
	same_point_counter=1;c=1;
	while(1){
		n_input+=op[i];
		i++;
		if(i==op.length()){break;}}
	n_input_as_no=atof(n_input.c_str());
	m=0;q=0;
	for(i=0;i<Number_Polygons(p);i++){
		for(j=0;j<POL[i].getnpoints();j++)
		{same_point_counter=1;
			for(n=0;n<100;n++){
						if(POL[i].getpoint(j).getx()==Array_of_printedx[n]&&POL[i].getpoint(j).gety()==Array_of_printedy[n])
						{c=0;break;}}
			if(c==0){c=1;continue;}
			for(k=0;k<Number_Polygons(p);k++){if(k==i)continue;
				for(l=0;l<POL[k].getnpoints();l++){
					
				if(POL[k].getpoint(l).getx()==POL[i].getpoint(j).getx()&&POL[k].getpoint(l).gety()==POL[i].getpoint(j).gety())
				{same_point_counter++;break;}}
			}
			if(same_point_counter==n_input_as_no){Array_of_printedx[q]=POL[i].getpoint(j).getx();
		Array_of_printedy[q]=POL[i].getpoint(j).gety();q++;}
		}
		
		
	}
	if(q==0)cout<<"none";
	else{
	for(n=0;n<q;n++){cout<<"("<<Array_of_printedx[n]<<","<<Array_of_printedy[n]<<")";
	if(n!=q-1)cout<<",";}}
	}

		//Polygon_Perimeter n
	if(op.substr(0,18)=="Polygon_Perimeter "){
	n_input="";i=18;
	while(1){
		n_input+=op[i];
		i++;
		if(i==op.length()){break;}}
	n_input_as_no=atof(n_input.c_str());
	int POL_ind=n_input_as_no-1;
	float perimeter=0;
	Point pointa,pointb;
	for(i=0;i<POL[POL_ind].getnpoints()-1;i++){
		perimeter+=POL[POL_ind].getpoint(i).Distance(POL[POL_ind].getpoint(i),POL[POL_ind].getpoint(i+1));
	}
	perimeter+=POL[POL_ind].getpoint(POL[POL_ind].getnpoints()-1).Distance(POL[POL_ind].getpoint(POL[POL_ind].getnpoints()-1),POL[POL_ind].getpoint(0));
	cout<<perimeter;
	}
	//List_Triangles
	if(op=="List_Triangles"){
			loop_execution_checker=0;
		for(i=0;i<Number_Polygons(p);i++){
			if(POL_final_step[i].getnpoints()==3){loop_execution_checker++;
				cout<<i+1;
				for(j=i+1;j<Number_Polygons(p);j++){if(POL_final_step[j].getnpoints()==3){cout<<",";break;}}
			}
		}
		if(loop_execution_checker==0)cout<<"none";
	}
	//List_Rectangles
	//note:a square is a special case of a rectangle
	if(op=="List_Rectangles"){
	loop_execution_checker=0;
	for(i=0;i<Number_Polygons(p);i++){
		if(POL_final_step[i].getnpoints()==4){
			s1=Slope(POL_final_step[i].getpoint(0),POL_final_step[i].getpoint(1));
			s2=Slope(POL_final_step[i].getpoint(1),POL_final_step[i].getpoint(2));
			s3=Slope(POL_final_step[i].getpoint(2),POL_final_step[i].getpoint(3));
			s4=Slope(POL_final_step[i].getpoint(3),POL_final_step[i].getpoint(0));
			if(s1*s2==-1&&s2*s3==-1&&s4*s1==-1){cout<<i+1;loop_execution_checker++;
			for(j=i+1;j<Number_Polygons(p);j++){if(POL_final_step[j].getnpoints()==4){
				s1=Slope(POL_final_step[j].getpoint(0),POL_final_step[j].getpoint(1));
				s2=Slope(POL_final_step[j].getpoint(1),POL_final_step[j].getpoint(2));
				s3=Slope(POL_final_step[j].getpoint(2),POL_final_step[j].getpoint(3));
				s4=Slope(POL_final_step[j].getpoint(3),POL_final_step[j].getpoint(0));
			if(s1*s2==-1&&s2*s3==-1&&s4*s1==-1){cout<<",";break;}}}


		}
	}
	}
	if(loop_execution_checker==0)cout<<"none";
	}
	//List_Trapezoid
	if(op=="List_Trapezoid"){
		loop_execution_checker=0;
		for(i=0;i<Number_Polygons(p);i++){
		if(POL_final_step[i].getnpoints()==4){
			s1=Slope(POL_final_step[i].getpoint(0),POL_final_step[i].getpoint(1));
			s2=Slope(POL_final_step[i].getpoint(1),POL_final_step[i].getpoint(2));
			s3=Slope(POL_final_step[i].getpoint(2),POL_final_step[i].getpoint(3));
			s4=Slope(POL_final_step[i].getpoint(3),POL_final_step[i].getpoint(0));
			d1=Distance(POL_final_step[i].getpoint(0),POL_final_step[i].getpoint(1));
			d2=Distance(POL_final_step[i].getpoint(1),POL_final_step[i].getpoint(2));
			d3=Distance(POL_final_step[i].getpoint(2),POL_final_step[i].getpoint(3));
			d4=Distance(POL_final_step[i].getpoint(3),POL_final_step[i].getpoint(0));
			if((s1==s3&&d1!=d3)||(s2==s4&&d2!=d4)){cout<<i+1;loop_execution_checker++;
			for(j=i+1;j<Number_Polygons(p);j++){if(POL_final_step[j].getnpoints()==4){
				s1=Slope(POL_final_step[j].getpoint(0),POL_final_step[j].getpoint(1));
				s2=Slope(POL_final_step[j].getpoint(1),POL_final_step[j].getpoint(2));
				s3=Slope(POL_final_step[j].getpoint(2),POL_final_step[j].getpoint(3));
				s4=Slope(POL_final_step[j].getpoint(3),POL_final_step[j].getpoint(0));
				d1=Distance(POL_final_step[j].getpoint(0),POL_final_step[j].getpoint(1));
				d2=Distance(POL_final_step[j].getpoint(1),POL_final_step[j].getpoint(2));
				d3=Distance(POL_final_step[j].getpoint(2),POL_final_step[j].getpoint(3));
			d4=Distance(POL_final_step[j].getpoint(3),POL_final_step[j].getpoint(0));
			if((s1==s3&&d1!=d3)||(s2==s4&&d2!=d4)){cout<<",";break;}}}


		}
	}
	}
	if(loop_execution_checker==0)cout<<"none";
}



	//Level 3
	//Inside_Rectangle (1,2),(1,5),(6,5),(6,2)
	if(op.substr(0,17)=="Inside_Rectangle "){
	input_string="";
	for(j=17;j<op.length();j++){input_string+=op[j];}
	//cut input_string and store it in 2 arrays
	xindex=0;yindex=0;
	for(i=0;i<input_string.length();i++){
		if(input_string[i]=='('){coo="";j=1; while(input_string[i+j] != ','){co=input_string[i+j]; coo=coo+co;j++;}
	store=atof(coo.c_str());
		array_of_xrectangle[xindex]=store;xindex++;}
		if(input_string[i]==')'){coo="";j=1; while(input_string[i-j] != ','){co=input_string[i-j]; coo=coo+co;j++;}
	coo=reverse(coo);
	store=atof(coo.c_str());
		array_of_yrectangle[yindex]=store;yindex++;}
}
	//getting min and max x/y of the 2 arrays
maxX_=max(array_of_xrectangle,4);
maxY_=max(array_of_yrectangle,4);
minX_=min(array_of_xrectangle,4);
minY_=min(array_of_yrectangle,4);
loop_execution_checker=0;
	for(k=0;k<Number_Polygons(p);k++){points_inside_checker=0;
		for(i=0;i<POL[k].getnpoints();i++){
	if(POL[k].getpoint(i).getx()>=minX_&&POL[k].getpoint(i).gety()>=minY_&&POL[k].getpoint(i).getx()<=maxX_&&POL[k].getpoint(i).gety()<=maxY_)
	{points_inside_checker++;}


	}
		if(points_inside_checker==POL[k].getnpoints()){cout<<k+1;loop_execution_checker++;
		//for the last comma
		    for(l=k+1;l<Number_Polygons(p);l++){points_inside_checker=0;
		for(m=0;m<POL[l].getnpoints();m++){
	if(POL[l].getpoint(m).getx()>=minX_&&POL[l].getpoint(m).gety()>=minY_&&POL[l].getpoint(m).getx()<=maxX_&&POL[l].getpoint(m).gety()<=maxY_)
	{points_inside_checker++;}


	}
		if(points_inside_checker==POL[l].getnpoints()){cout<<",";break;}
		
		}
	}
	
	}
	if(loop_execution_checker==0)cout<<"none";
	}
//Inside_Circle (1,2),5
	if(op.substr(0,14)=="Inside_Circle "){
    input_string="";
	for(j=14;j<op.length();j++){input_string+=op[j];}
	//determining the values of centrex and centrey
	for(i=0;i<input_string.length();i++){
		if(input_string[i]=='('){coo="";j=1; while(input_string[i+j] != ','){co=input_string[i+j]; coo=coo+co;j++;}
	store=atof(coo.c_str());
	centrex=store;}
		if(input_string[i]==')'){coo="";j=1;k=i+2; while(input_string[i-j] != ','){co=input_string[i-j]; coo=coo+co;j++;}
	coo=reverse(coo);
	store=atof(coo.c_str());
	centrey=store;}
}
	centre.setx(centrex);
	centre.sety(centrey);
    //determining the value of radius
	coo="";
	for(l=k;l<input_string.length();l++){coo+=input_string[l];}
	radius=atof(coo.c_str());
	//now performing the operation
	for(k=0;k<Number_Polygons(p);k++){points_inside_checker=0;
		for(i=0;i<POL[k].getnpoints();i++){
			if(Distance(POL[k].getpoint(i),centre)<=radius)
	{points_inside_checker++;}


	}
		if(points_inside_checker==POL[k].getnpoints()){cout<<k+1;loop_execution_checker++;
		//for the last comma
		    for(l=k+1;l<Number_Polygons(p);l++){points_inside_checker=0;
		for(m=0;m<POL[l].getnpoints();m++){
	if(Distance(POL[l].getpoint(m),centre)<=radius)
	{points_inside_checker++;}


	}
		if(points_inside_checker==POL[l].getnpoints()){cout<<",";break;}
		
		}
	}
	
	}
	if(loop_execution_checker==0)cout<<"none";

	}
//Polygon_Area n
	if(op.substr(0,13)=="Polygon_Area "){
	n_input="";i=13;
	while(1){
		n_input+=op[i];
		i++;
		if(i==op.length()){break;}}
	n_input_as_no=atof(n_input.c_str());
	k=n_input_as_no-1;
	cout<<Area(POL[k]);
}
//Polygons_Area_Range minArea,maxArea
	if(op.substr(0,20)=="Polygons_Area_Range "){
     input_string="(";
	for(j=20;j<op.length();j++){input_string+=op[j];}
	input_string+=')';
	for(i=0;i<input_string.length();i++){
		if(input_string[i]=='('){coo="";j=1; while(input_string[i+j] != ','){co=input_string[i+j]; coo=coo+co;j++;}
	store=atof(coo.c_str());
	minArea=store;}
		if(input_string[i]==')'){coo="";j=1;k=i+2; while(input_string[i-j] != ','){co=input_string[i-j]; coo=coo+co;j++;}
	coo=reverse(coo);
	store=atof(coo.c_str());
	maxArea=store;}
}
    //now we have minArea and maxArea as floats..perform the operation
	loop_execution_checker=0;
	for(i=0;i<Number_Polygons(p);i++){
		if(Area(POL[i])>=minArea&&Area(POL[i])<=maxArea){loop_execution_checker++;cout<<i+1;
		//for the last comma
		for(j=i+1;j<Number_Polygons(p);j++){
			if(Area(POL[j])>=minArea&&Area(POL[j])<=maxArea){cout<<",";break;}}
		
		}


	}
	if(loop_execution_checker==0)cout<<"none";
	}

	//last line in while
	cout<<"\n";
		getline(cin,op);
}
	return 0;
}

