#include <ctime>
#include <iostream>
#include <cmath>
using namespace std;
int size=50;
int gap=10;
float borderradius=size/2-1;
float MinorR=borderradius-2;
int converter=0;
double rad=M_PI/180;
int tmpx,tmpy;
int last_second=0;
int secondhandr=MinorR-5,minutehandr=MinorR-10,hourhandr=MinorR-15;
void update_clock(); 
int main(){
   char map[size][size][2];
   cout<<endl<<endl;
   while(1){
	   // timing
	   time_t now = time(0);
	   tm *localT = localtime(&now);
//		cime guide
//	   cout << "Year:" << 1900 + localT->tm_year<<endl;
//	   cout << "Month: "<< 1 + localT->tm_mon<< endl;
//	   cout << "Day: "<< localT->tm_mday << endl;
//	   cout << "Time: "<<localT->tm_hour << ":";
//	   cout << localT->tm_min << ":";
//	   cout << localT->tm_sec << endl;

		if(last_second!=localT->tm_sec){
			
			system("cls"); 
	   last_second=localT->tm_sec;
	   
	   for(int i=0;i<5;i++){
	   	cout<<endl;
	   }
//		cout<<flush;
		   // plotting clock
			
		   for(int x=0; x<size;x++){
		   	for(int y=0; y<size;y++){
		   		map[x][y][0]=' ';
		   		map[x][y][1]=' ';
			   }
		   }
		   //border 
		   for(int deg=0;deg<360;deg++){
		   	tmpx=round(sin(rad*deg)*borderradius)+borderradius;
		   	tmpy=round(cos(rad*deg)*borderradius)+borderradius;
		   	map[tmpx][tmpy][0]='*';
		   	map[tmpx][tmpy][1]=' ';
		   }
		   //minor scale
		   
		   for(int deg=0;deg<360;deg+=6){
		   	tmpx=round(sin(rad*deg)*MinorR)+borderradius;
		   	tmpy=round(cos(rad*deg)*MinorR)+borderradius;
		   	map[tmpx][tmpy][0]='-';
		    map[tmpx][tmpy][1]=' ';
		   }
		   // major scale
		   for(int deg=0;deg<360;deg+=30){
		   	tmpx=round(sin(rad*(deg-60))*MinorR)+borderradius;
		   	tmpy=round(cos(rad*(deg-60))*MinorR)+borderradius;
		//   	cout>> (deg/30+1)/10+'0'>>' '>>(deg/30+1)%10+'0';
		   	map[tmpx][tmpy][0]=(deg/30+1)/10+'0';
		    map[tmpx][tmpy][1]=(deg/30+1)%10+'0';
		   }
		   // second hand
		   for(int l=0;l<secondhandr;l++){
		   	tmpx=round(sin(rad*((localT->tm_sec*6)-90))*l)+borderradius;
		   	tmpy=round(cos(rad*((localT->tm_sec*6)-90))*l)+borderradius;
		   	map[tmpx][tmpy][0]='S';
		    map[tmpx][tmpy][1]=' ';
		   	
		   }
		   // minute hand
		   for(int l=0;l<minutehandr;l++){
		   	tmpx=round(sin(rad*((localT->tm_min*6)-90))*l)+borderradius;
		   	tmpy=round(cos(rad*((localT->tm_min*6)-90))*l)+borderradius;
		   	map[tmpx][tmpy][0]='M';
		    map[tmpx][tmpy][1]=' ';
		   	
		   }
		   // hour hand
		   for(int l=0;l<hourhandr;l++){
		   	// base on minute , hour need to change a bit
		   	// equation
		   	// (localT->tm_hour*30+ 6*round(localT->tm_min/15)-60)
		   	tmpx=round(sin(rad*(localT->tm_hour*30+ 6*round(localT->tm_min/15)-90))*l)+borderradius;
		   	tmpy=round(cos(rad*(localT->tm_hour*30+ 6*round(localT->tm_min/15)-90))*l)+borderradius;
		   	map[tmpx][tmpy][0]='H';
		    map[tmpx][tmpy][1]=' ';
		   	
		   }
		   // printing 
		   for(int x=0; x<size;x++){
		   	for(int y=0; y<size;y++){
		   		cout<<map[x][y][0]<<map[x][y][1];
			   }
			   cout<<endl;
		   }
		}
   }
   return 0;
}
