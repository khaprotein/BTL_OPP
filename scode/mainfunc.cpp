#include"mainfunc.h"
//
using namespace std;
//
data du_lieu;// du lieu lay tu cau truc data
// khung long khi nhay
string khung_long[9]=  
{
"         мллллллм",
"         ллмллллл",
"         ллллпппп",
"л       мллллппп ",
"ллм  мллллллммм ",
"пллллллллллл  п",
"  плллллллп м  ",
"лпппп   ппппп",
};
////
string dino_die="        ллXллллл";
//
string space   = "                 ";
////
DINO::DINO(){
	
	this->xdino= 15;
	this->ydino= 17;
	this->h= 8;
	this->check_die= false;
}
////
DINO::~DINO(){	
}
////
void DINO::drawdino_up_down(int x,int y){ 
	for(int i=0;i<8;i++){
		GOTOXY(x,y+i);
		cout<<khung_long[i]<<endl;
   }
}
////
void DINO::draw(){
	
	static int foot=0;// 
	
	Color(7);
    GOTOXY(xdino,ydino);  cout<<"         мллллллм";
    GOTOXY(xdino,ydino+1);cout<<"         ллмллллл";
    GOTOXY(xdino,ydino+2);cout<<"         лллллппп";
    GOTOXY(xdino,ydino+3);cout<<"л       мллллппп ";
    GOTOXY(xdino,ydino+4);cout<<"ллм  мллллллммм  ";
    GOTOXY(xdino,ydino+5);cout<<"пллллллллллл  п ";
    GOTOXY(xdino,ydino+6);cout<<"  плллллллп     ";
    GOTOXY(xdino,ydino+7);
    
    if (foot < 2) {
     		cout<<"   пллп  ппп    ";
            GOTOXY(xdino+5,ydino+8);
            cout<<"лм";
            foot++;
       }
       
    else if (foot >= 2) {
	    	cout<<"    плм пл      ";
            GOTOXY(xdino+9,ydino+8);
            cout<<"лм";
            foot++;
			if(foot==4) foot=0;			
		}
}
// khoi tao dat
Ground::Ground():DINO(){
	this->xdat = 1;
	this->ydat = ydino+h;
}
//
Ground::~Ground(){	
}
//
void Ground::taodat(int i){
	//
	int v= rand()% ( 107- 1+ 1)+ 1;// random cac vi tri de in mat dat 
	
	switch (v){
		case 1: case 2:
			ground[1][i]='.';
			ground[2][i]=' ';
		    break;
		    
		case 4: case 5:
			ground[1][i]='`';
			ground[2][i]=' ';
		    break;
		    
		case 9: case 19: case 27: case 39:
			ground[1][i]=248;
			ground[2][i]=' ';
			break;
			
		case 47: case 57: case 87: case 107:
			ground[1][i]=' ';
			ground[2][i]='.';
		     break;
		     
		default:
			ground[1][i]=' ';
			ground[2][i]=' ';
			break;										
	}
}
////
void Ground::khoitaomatdat(){
	
	for(int i=0;i<sl_ground;i++){
		ground[0][i]='_';// tao vien dat
		taodat(i);
	}
	//mat dinh cac ki tu ket thuc o moi hang
	ground[0][sl_ground]='\0';/*  ki tu ket thuc */
	ground[1][sl_ground]='\0';
	ground[2][sl_ground]='\0';
}
//
void Ground::draw(){
    
	for(int i=0;i<3;i++){
		GOTOXY(xdat,ydat+i);
		cout<<ground[i];
	}
}
//
void Ground::di_chuyen(){
	//doi
    Color(7);	    
	for(int i=0;i<sl_ground-1;i++){
		ground[1][i]=ground[1][i+1];//gan ptu dau bang phan ke tiep
		ground[2][i]=ground[2][i+1];
	}
	taodat(sl_ground-1);
	draw();
}
////khoi tao VC
VC::VC():Ground(){
	
	this->x_VC= 106;
	this->x_Bird= 101;
	this->y_Vc=ydat-5;
	this->y_Bird= ydat-7;
	this->check_dap=0;
}
////
VC::~VC(){
}
//
void VC::xoa(int a[], int &n,int vt){// xoa phan tu
    for(int i = vt ; i < n-1; i++){
        a[i] = a[i+1]; // lay ptu dau gan = ptu ke tiep
    }
    n--;  //giam so luong ptu
}
//
string bird_up[5]={  	
"     м    ",	   
" млл ллм  ",
"пплллллллм..",
"   пппппп ",
"          "
};
//
string bird[5]={
"          ",	
" млл      ",
"пплллллллм..",
"   плллпп ",
"    ллп   "
};
//
void VC::draw_bird(int x){
	   
		if (check_dap<10){
     	    for(int i=0;i<5;i++){
       	  	   GOTOXY(x,y_Bird+i);
       	  	   cout<<bird_up[i];
			 }
			 check_dap++;
        }
       	else if (check_dap >=10) {
       	  for(int i=0;i<5;i++){
       	  	   GOTOXY(x,y_Bird+i);
       	  	   cout<<bird[i];
			 }
			 check_dap++;
			 if(check_dap==15)check_dap=0;
		}
}
//
void VC::clear_bird(int x_b){
	
	for(int i=0;i<5;i++){
		GOTOXY(x_b+13,y_Bird+i);
			cout<<" ";		
	}
}
//
void VC::draw_new_bird(int b[],int &n_b){
    
	int ct;

		if(b[0]==xdat){
		xoa(b,n_b,0);
		for(int i=0;i<13;i++){
			clear_bird(xdat-i);
		}
	  }
	 for(int i=0;i<n_b;i++){
		 	draw_bird(b[i]);
		    clear_bird(b[i]);
			b[i]--;			
	  }
	
	
}
//
string nha[6]={
"   мллм ",
"м  лллл ",
"лл лллл м",
"ллмллллмл",
" плллллп ",
"   лллл "
};
//
void VC::draw_tree(int x){
	
    for(int i = 0; i < 6; i++){
        GOTOXY(x, y_Vc + i);
        cout << nha[i];
    }
}
//
void VC::clear_VC(int x_vc){
	for(int i=0;i<6;i++){
		GOTOXY(x_vc+10,y_Vc+i);//di chuyen den vi tri cuoi cung de xoa du lieu cua vc
			cout<<" ";		
	}
}
//
void VC::draw_new_tree(int toa_nha[],int &n_vc){
	
	if(toa_nha[0]==xdat){
	    xoa(toa_nha,n_vc,0);
	    for(int i=0;i<11;i++){
	    	clear_VC(xdat-i);
		}
	}
	
	for(int i= 0; i< n_vc; i++){

		draw_tree(toa_nha[i]);
		clear_VC(toa_nha[i]);
		toa_nha[i]--;// giam toa do 
		
	}
}
// check die
bool VC::check_cham(int x_vc, int x_b, int x, int y){
	// toa do dino
	int xchan_trai , xchan_phai ;
    int ychan = y + 5 ; 
    
    int x_b_max= x_b + 10;// toa do cuoi cua chim
    int x_vc_max = x_vc + 10; // toa do cuoi cua tree
  
    if(du_lieu.kt_jump==true){// neu khung long dang nhay toa se thay doi
    	xchan_phai=x+9;
    	xchan_trai=x+3;
    }
    else{ 
    	xchan_phai=x+13;
    	xchan_trai=x+1;
	}
	// check tao do cua dino vs tree
	if((xchan_phai >= x_vc && xchan_phai <= x_vc_max) || (xchan_trai >= x_vc && xchan_trai <= x_vc_max)){
        if((ychan >= y_Vc && ychan <= ydat)){
            return true;
        }
    }
    // check toa do dino vs con chim
    else if((xchan_trai >= x_b+1 && xchan_trai <= x_b_max) || (xchan_phai >= x_b+1 && xchan_phai <= x_b_max)){
    	if((ychan >= (y_Bird+1) && ychan <= ydat)){
    		return true;
		}
	}
    return false;
}
//
bool VC::GameOver(int x, int y, int toa_nha[],int bird[], int n_vc){
	
	for(int i=0; i<n_vc; i++){
		if(check_cham(toa_nha[i], bird[i], x, y)){// neu nhu true thi dino die 
			GOTOXY(x+1, y+1);
			cout<< dino_die;
			return true;
		}
	}
	return false;
}
//
void game_over(){
	
		Color(4);
		GOTOXY(55,10);
		cout<<"YOU DIE!";
		GOTOXY(47,11);
		cout<<"an cach de quay lai menu";
		Color(7);
        du_lieu.score=0;
}
//
int Random(int a,int b){//ham tao ra mot gia tri ngau nhien
	return rand()% ( b- a+ 1)+ a;
}
//
void save_score(int score){
	// in score vao file
	ofstream data(linkData, ios::app);
	data << score << endl;
}
//
int high_SCORE(){
	// doc file 
	ifstream data(linkData, ios::binary);
	if (data.fail()) return 1;

	vector <int> score;

	while (!data.eof()){
		// ghi diem vao file
		int tmp;
		data >> tmp;
		score.push_back(tmp);
	}
	//sap xep score theo chieu tang dan
	sort(score.begin(), score.end());
	// cho n = vs so luong ptu trong file
	int n = score.size();
    // tra ve score cuoi trong file 
	return score[n - 1];
}
void in_score(){
	int highscore=high_SCORE();
	if(du_lieu.score>highscore){// so sanh diem
	GOTOXY(100,2);cout<<"HIGH SCORE: "<<du_lieu.score;
	}
	else GOTOXY(100,2);cout<<"HIGH SCORE: "<<highscore;
	
	GOTOXY(100,3);cout<<"SCORE:";
	GOTOXY(106,3);cout<<"0";
	GOTOXY(107,3);cout<<"0";
	GOTOXY(108,3);cout<<"0";
	GOTOXY(109,3);cout<<"0";
}
//
void ghi_score(){
	
	GOTOXY(100,3);cout<<"SCORE:";
	GOTOXY(106,3);cout<<(du_lieu.score%10000)/1000;
	GOTOXY(107,3);cout<<(du_lieu.score%1000)/100;
	GOTOXY(108,3);cout<<(du_lieu.score%100)/10;
	GOTOXY(109,3);cout<<(du_lieu.score%10);
}
//

//
void ingame(){
//	//khaai bao ra mot con dino moi 
    DINO *dino = new DINO();
    dino->draw();
    
//   //khai bao mat dat
    DINO *d = new Ground();
    d->draw();
     
 	Ground *dat=new Ground();
    dat->khoitaomatdat();
    //dat->draw();
    
    //khai vao vat can
	VC *vc=new VC();
    //
    in_score();// draw score
    //lay gia tri toa do
	int x=dino->get_x();
    int y=dino->get_y(); 
    int ch_cao=dino->get_h(); 
    
    int check=0;//0 dung im , 1 nhay, 2 xuong
    
    //bien dem
    int ct1;
    int ct2;
    int DD=0;
    int count1=100, count2=500;// kiem soat toc do in vc
    int dem=0;
    
	int n_vc= 0;
	int n_bird= 0;// n vat can
	
    int t1=100,t2=100;// khoang gia tri de in cay
    
    //  cap phat phat bo nho
    int *tree = new int[n_vc];
    
    int *bird = new int[n_bird];
    
    
	while(true){
		//
		dat->di_chuyen();
	    //co che tinh diem
	    dem++;
	    if(dem>30){
	        du_lieu.score++;
	        ghi_score();
	        dem=0;
	        DD++;
	        // toc do se tang neu 
	        if(DD==15){
	    	        DD=0;   
			    //}
		    }   
	    }
		//
		if(count1==0){
	        tree[n_vc++]=vc->get_xvc();
	        count1= Random(t1,t2);// random [60-100] tri hoan viec tang vc	 
		}
		vc->draw_new_tree(tree,n_vc);
		
		// in con chim
        if(count2==0){
			count2=50; // tri hoan tang sl bird ra man hinh
			bird[n_bird++]=vc->get_xbird();
	        
		}
		vc->draw_new_bird(bird,n_bird);
		vc->draw_new_bird(bird,n_bird);
        //
        if(vc->GameOver(x,y,tree,bird,n_vc)==true){
        	// luu diem ngay khi chet
        	save_score(du_lieu.score);
	        du_lieu.check_die=true;
	    	// am thanh khi chet
	    	PlaySound(TEXT(link_die),NULL,SND_FILENAME);
		}
		//
		if(du_lieu.check_die==true){//  check die = true => chet
			du_lieu.check_die=false;
		    game_over();
			// sau khi chet thi thoat khoi vong lap
			break;
		}
		//
       // dieu khien
         if(kbhit()){
	           char c=getch();  
         if(c==-32){
	        	c=getch();
	        	if(c==72&&check==0){//neu nhu an phim mui ten va dino o mat dat thi cho check =1 
	        	// am thanh khi nha
	        	 check=1;du_lieu.kt_jump=true;
	        	// PlaySound(TEXT(link_jump),NULL,SND_FILENAME);
				}
		    }
	    }
		// kiem tra va ve lai khung long khi nhay
		if(check==1){// khi check la nhay thi in ra dino o trang thai nhay
		
            if(y<8){
		    	if((ct1%2)==0){
				GOTOXY(x,y+ch_cao-1);
			    cout<<space;
			    y--;
			    dino->drawdino_up_down(x,y);
			   }
			   ct1++;
		    }
		    else{
		    	GOTOXY(x,y+ch_cao-1);
			    cout<<space;
			    y--;
			    dino->drawdino_up_down(x,y);
			}	
	    }
		else if(check==2){
		    if(y<8){
		    	if((ct2%2)==0){
				   GOTOXY(x,y);
			       cout<<space;
				   y++;
		           dino->drawdino_up_down(x,y); 
			    }
		     ct2++;
			}
			else{
				GOTOXY(x,y);
			    cout<<space;
				y++;
		        dino->drawdino_up_down(x,y); 
			}
			
	    }
	    if(y== dino->get_y()-12){
	    	check=2;
  	      dino->drawdino_up_down(x,y); 
	    }
		else if(y==dino->get_y()){// khi roi xuong toa do y = ydino ban dau thi in dino o mat dat 
 			dino->draw();
			check=0; 	
			du_lieu.kt_jump=false;
	    }
	    // giam bien kiem soat in cay
	    count1--;
	    count2--;
        Sleep(16);
        
    }
    // xoa bo nho 
	delete dino;
	delete dat;
	delete tree;
	delete bird;
}
