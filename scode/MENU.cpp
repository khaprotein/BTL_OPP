#include"MENU.h"

using namespace std;

char d[3][117];

string bir1[5]={  	
"     м    ",	   
" млл ллм  ",
"пплллллллм....",
"   пппппп ",
"          "
};

string bir2[5]={
"          ",	
" млл      ",
"пплллллллм..",
"   плллпп ",
"    ллп   "
};

string tree1[7]={
"    мллм ",
"м   лллл ",
"ллл лллл м",
" ллмллллмлл",
"  плллллп ",
"   лллл ",
"   лллл "
};

string tree2[6]={
"   мллм ",
"м  лллл ",
"лл лллл м",
"ллмллллмл",
" плллллп ",
"   лллл "
};

void ve_bir1(int x,int y){
	for(int i=0;i<5;i++){
		GOTOXY(x,y+i);
		cout<<bir1[i];
	}
}

void ve_bir2(int x,int y){
	for(int i=0;i<5;i++){
		GOTOXY(x,y+i);
		cout<<bir2[i];
	}
}
void ve_tree1(int x,int y){
	for(int i=0;i<7;i++){
		GOTOXY(x,y+i);
		cout<<tree1[i];
	}
}
void ve_tree2(int x,int y){
	for(int i=0;i<6;i++){
		GOTOXY(x,y+i);
		cout<<tree2[i];
	}
}

void box(){
	Color(8);
	char a=219;
	GOTOXY(0,0);
	for(int i =0;i<119;i++){ 
	    cout<<a; 
	}
	
	for(int j=0;j<28;j++){
		cout<<endl;
		for(int i=0;i<119;i++){
			if(i==0||i==118){
			    cout<<a;
			}
			else{
			    cout<<" ";
			}	
	    }
	}
	cout<<endl;
	for(int i=0;i<119;i++){
	    cout<<a;
	}
}

void dat(int i){
	
	int v=rand()%(18-1+1)+1;
	
	switch (v){
		case 1:
			d[1][i]='.';
			d[2][i]=' ';
		    break;
		case 3:
			d[1][i]='`';
			d[2][i]=' ';
		    break;
		case 4:
			d[1][i]=248;
			d[2][i]=' ';
			break;
		case 7:
			d[1][i]='.';
			d[2][i]='.';
		     break;
		case 8:
			d[1][i]='~';
			d[2][i]='.';
		     break;
		case 20:
			d[1][i]='_';
			d[2][i]='.';
		     break;
		default:
			d[1][i]=' ';
			d[2][i]=' ';
			break;										
	}
}
//
void taomatdat(){
	for(int i=0;i<117;i++){
		d[0][i]='_';
		dat(i);
	}
	//mat dinh cac ki tu ket thuc o moi hang
	d[0][116]='\0';/*  ki tu ket thuc */
	d[1][116]='\0';
	d[2][116]='\0';
}

void vedat(){
	for(int i=0;i<3;i++){
		GOTOXY(1,24+i);
		cout<<d[i];
	}
}
//


void menu(){
	box();
	Color(7);
	taomatdat();
	vedat();
	ve_bir1(15,3);
	ve_bir2(97,3);
	ve_tree1(6,19);
	ve_tree2(105,19);
	
	int x=25,y=11;
	Color(15);
	GOTOXY(x, y);
	cout << "________                           _________                          ";
	Color(10);
	GOTOXY(x, y + 1);
	cout << "___  __ \\ __(_)_______ ______      __  ____/______ ________ ___ _____ ";
	Color(9);
	GOTOXY(x, y + 2);
	cout << "__  / / / _  / __  __ \\_  __ \\     _  / __  _  __ `/__  __ `__ \\_  _ \\";
	Color(7);
	GOTOXY(x, y + 3);
	cout << " / /_/ /  / /   / / / // /_/ /     / /_/ /  / /_/ / _  / / / / //  __/";
	Color(5);
	GOTOXY(x, y + 4);
	cout << "/_____/  /_/   /_/ /_/ \\____/      \\____/   \\__,_/  /_/ /_/ /_/ \\___/ ";
	
    Color(3);
	char c=16;
	GOTOXY(50, y + 7);
	cout<<c;
	GOTOXY(x+27, y + 7);
	cout<<"NEW GAME";
    Color(7);
	GOTOXY(x+29, y + 8);
	cout<<"HELP ";
	GOTOXY(x+29, y + 9);
	cout<<"EXIT ";
	
}



