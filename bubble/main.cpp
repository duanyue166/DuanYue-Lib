#include<graphics.h>
#include<windows.h>
#include<iostream>
#include<ctime>
#include"mylib.hpp"

#define bgc EGERGB(0xda,0xf3,0xef)

int mX=1280,mY=720;
const int bubble_delay=500;

struct Bubble{
	movement item;
};
vector<Bubble> vec;

int main(int argc,char *argv[]){
	if(argc==2 && !strcmp(argv[1],"-f")){
		mX=GetSystemMetrics(SM_CXSCREEN);
		mY=GetSystemMetrics(SM_CYSCREEN);
		setinitmode(1);
	}
	
	initgraph(mX,mY);
	setbkcolor(bgc);
	setrendermode(RENDER_MANUAL); 

	movement bubble;
	MUSIC mc;
	for(int px,py;is_run() && !detect_key(key_esc);){
		
		if(mouse_left_click()){
			printf("%d %d\n",px,py);
			mousepos(&px,&py);
			bubble.obj.load_texture("res\\bubble.png");
			bubble.setpos(px,py);
			bubble.obj.draw(px-50,py-50,0x80);
			mc.OpenFile("res\\bubble_burst.wav");
			mc.Play();
		}
	}

}