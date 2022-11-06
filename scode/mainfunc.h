#include<iostream>
#include<conio.h>
#include"Do hoa.h"
// random
#include <cstdlib>
#include <ctime>
// doc ghi file
#include<fstream>
#include <vector>
#include<algorithm>

//
#pragma comment (lib, "winmm.lib")
#define sl_ground 117
#define linkData "highscore.txt"
#define link_die "dino2.WAV"
#define link_jump "dino1.WAV"

//
class DINO{
	
	protected:// tinh dong goi
		int xdino;
        int ydino;
        int h;
       
        bool check_die;// kiem tra die
    public:
	    DINO();
	    ~DINO();
	    
	    // tinh truu tuong
	    int get_x(){
	    	return xdino;
		}
		int get_y(){
			return ydino;
		}
		int get_h(){
			return h;
		}
		// tinh da hinh
	    virtual void draw();// phuong thuc ao
	    void drawdino_up_down(int x,int y);
//	    
//	    // nap chong toan tu tien to
//	    
//	    DINO operator ++(){
//	    	ydino++;
//	    	return DINO();
//		}
//		// nam chong toan tu hau to
//	    DINO operator --(int){
//	    	DINO a;
//	    	ydino--;
//	    	return a;
//		}
		
};
//
class Ground: public DINO{// tinh ke thua
	protected:
		int xdat;
		int ydat;
		// tao mang 2 chieu de ve mat dat 3 hang va 117 cot
		char ground[3][sl_ground+1];
	public:
	    Ground();
		~Ground();
		
		void draw();// nam chong ham tu 
	    void taodat(int i);
		void khoitaomatdat();
		void di_chuyen();
				
};
//
class VC: public Ground{
	protected:
		int x_VC;
		int x_Bird;
		int y_Vc;
		int y_Bird;
		int check_dap;
		
	public:
	    VC();
		~VC();
		// tinh truu tuong
		int get_xvc(){
			return x_VC;
		}
		int get_xbird(){
			return x_Bird;
		}
		int get_yvc(){
			return y_Vc;
		}
		int get_ybird(){
			return y_Bird;
		}
		
		//xoa phan tu gan cho phan tu cuoi
		void xoa(int a[],int &n, int vt);
		//ve bird
		void draw_bird(int x);
		void clear_bird(int x);
		void draw_new_bird(int vc[],int &n_vc);
		//ve tree
		void draw_tree(int x);
		void clear_VC(int x);
		void draw_new_tree(int toa_nha[],int &n_vc);
				
		bool check_cham(int x_vc,int x_b, int x,int y);
		bool GameOver(int x, int y, int t[], int b[], int n_vc);
		
};
//
typedef struct{
	int score=0;
    int speed=16 ;
    
    int jump=14;// lay ydino - jump = gioi han nhay 
    bool kt_jump= false;// kiem tra nhay
    bool check_die=false;
} data;
//
int Random(int a,int b);
//
int high_SCORE();
void save_score(int score);
void in_score();
void ghi_score();
//
void ingame();

