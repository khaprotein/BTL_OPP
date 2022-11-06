#include"game.h"
//////
using namespace std;
//////
void GAME(){
	state Lc;	
    srand(time(NULL));
    //
	int lc1=1, lc2=1;
    string Menu[3]={
		"NEW GAME",
		"HELP",
		"EXIT"
	};
	switch(Lc){
		case MENU:
//			system("cls");
			box();
			menu();
//			//
			while(Lc==MENU){
				char key,c=16;
				if(kbhit()){
				   key=getch();
				   if(key==72){
				       lc1--;
				       if(lc1==0) lc1=3;
			       }
			       else if(key==80){
				       lc1++;
				       if(lc1==4) lc1=1;
			       }
			       Color(7);
			       switch(lc1){
			       	case 1:
			       	     if(lc1!=lc2){
						GOTOXY(50,19);
						cout<<" ";
						GOTOXY(54,19);
						cout<<Menu[1];
						GOTOXY(50,20);
						cout<<" ";
						GOTOXY(54,20);
						cout<<Menu[2];
						Color(3);
						GOTOXY(50,18);
						cout<<c;
						GOTOXY(52,18);
						cout<<Menu[0];
						lc2=1;
					    }
					break;
					case 2:
			       	     if(lc1!=lc2){
						GOTOXY(50,18);
						cout<<" ";
						GOTOXY(52,18);
						cout<<Menu[0];
						GOTOXY(50,20);
						cout<<" ";
						GOTOXY(54,20);
						cout<<Menu[2];
						Color(3);
						GOTOXY(50,19);
						cout<<c;
						GOTOXY(54,19);
						cout<<Menu[1];
						lc2=2;
					    }
					break;
					case 3:
			       	    if(lc1!=lc2){
						GOTOXY(50,18);
						cout<<" ";
						GOTOXY(52,18);
						cout<<Menu[0];
						GOTOXY(50,19);
						cout<<" ";
						GOTOXY(54,19);
						cout<<Menu[1];
						Color(3);
						GOTOXY(50,20);
						cout<<c;
						GOTOXY(54,20);
						cout<<Menu[2];
						lc2=3;
					    }
					break;
				   }
			       if(key==13){
			       	    switch(lc1){
			       		    case 1:
			       		    box();
				            Lc= INGAME;
			                break;
								
					        case 2:
					   	    box();
					   	    Lc=HELP;
					   	    break; 
					   	    
				            case 3:
				        	exit(0);
				        	break;
				       }
				   }
                }
           }
	        break;
//	            
			case INGAME:	
			  box();	
		      ingame();
		      while(Lc==INGAME){
		     	char key;
		        if(kbhit()){
			        key=getch();
			        if(key==32){
				        box();
				        Lc= MENU;
			            break;
		            }
	            }
			}
			break;
//			
			case HELP:
				box();
				while(Lc==HELP){
					Color(7);
					GOTOXY(30,5);
				    cout<<"Ban phai vuot qua chuong ngai vat";
				    GOTOXY(30,6);
			    cout<<"An phim mui ten de nhay qua";
				    GOTOXY(30,7);
				    cout<<"Toc do se tang len khi ban dat duoc 1 luong diem nhat dinh";
				    if(kbhit()){
			        char key=getch();
				        box();
				        Lc= MENU;
			            break;  
	                }
				}
				//
				break;
		}
}
