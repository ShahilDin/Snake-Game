#include<iostream>
#include <conio.h>
#include  <windows.h> // used for the sleep function
using namespace std;

const int width =22; // the grid is 20 x 20
const int height=22;

enum edirection{STOP=0,LEFT,RIGHT,UP,DOWN};
//enum is just a way to give name to certain values
edirection dir;

int x,y,fx,fy,score,ntail; // fx and fy is the fruit the snake eats
bool gameover;


int tailx[100],taily[100]; // my tail array
 
 //SETUP FUNCTION
void setup(){
	
	//Setting up the start Values
	gameover=false;
	dir=STOP;
	
	x=width/2;
	y=height/2;
	
	fx=rand()%width; //generating random fruit placement 
	fy=rand()%height;
	score=0;
	
	
}
//This functions draw the grid and updates the snake tail
void draw(){
	
	system("cls");// this clears the console window
	for(int i= 0; i < width+2;i++)
		std::cout<< "#";
		cout<< endl; // Top ROW 
	
	
	for (int i=0; i< height;i++)
	{
		
		for(int k = 0; k < width; k++)
		{
			if(k==0){
				std::cout<< "#";
			}
			if(i==y && k==x){
				
				std::cout<< "O";
			}else if(i==fy && k== fx){ 
				
				std::cout<<"K";  // Places the food on grid
			}else
			{
				bool p =false;
				for(int a = 0; a < ntail; a++)
				{
					
					if (tailx[a]== k && taily[a]==i)
					{
						std::cout << "o"; // Displays the tail to be added on  
						p=true;
					}
				}
				if(!p){
						
						std::cout<< " " ;
					}
			}
			if (k == width - 1){
				
				std::cout<<"#";
			}
		}
		cout<<endl;
	}
		for(int i= 0; i < width+2;i++)
		std::cout<< "#";	 // Bottom ROW
		cout<< endl;
	     
		 std::cout<< "Score = "<< score ; 
}




/* KEY_UP 72
KEY_DOWN 80
KEY_LEFT 75
 KEY_RIGHT 77
*/
// This function takes care of the input 
void input(){
	
	if(_kbhit()){
		
		switch(_getch())
		{
			
			case 75: 
				dir = LEFT;
				break;
				
			case 77:
				dir= RIGHT;
				break;
				
			case 72:
				dir=UP;
				break;
				
			case 80:
				dir=DOWN;
				break;
			
			case 'x':
				gameover=true;
				break;
			
			
		}
	}
	
	
}
//This function takes care of the logic for the movement, generates random food placement 
void logic(){
	
	int prevx=tailx[0];
	int prevy=taily[0];
	int prev2x,prev2y;
	
	tailx[0]=x;
	taily[0]=y;
	//Remembers the pervious values of tail
	for(int i=1; i< ntail; i++){
		
		prev2x=tailx[i];
		prev2y=taily[i];
		
		tailx[i]=prevx;
		taily[i]=prevy;
		
		prevx=prev2x;
		prevy=prev2y;
		
	}
	switch(dir)
	{
		
		case LEFT:
			x--;
		
			break;
			
		case RIGHT:
			x++;
			break;
			
		case UP:
			y--;
			break;
			
		case DOWN:
			y++;
			break;
			
		default:
			break; 
	}	
	
	if(x>=width)
	{
		x=0;
	}else if(x <0)
	{
		x = width -1;
	}
	if(y >=height)
	{
		y=0; 
	}else if(y < 0)
	{
		y = height -1;
	}
	
	for(int i=0; i <ntail;i++){
		
			if(tailx[i] ==x && taily[i]==y)
			{
				gameover=true;
			}
	}
	if(x==fx && y== fy){
		
		
	    score +=10;
		fx=rand()%width; //generating random food placement 
	    fy=rand()%height;
		ntail++;
	}
}


int main(){
	
	setup();
	
	while(!gameover){
		
		draw();
		input();
		logic();
		Sleep(5);
		
		
	}
	
}