
#include <iostream>   
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h> //裡面含gotoxy()中的COORD及HANDLE等的類別等.. 
                     //第一關就難在這@o@


#define clrscr() { system("cls"); } 

void DoUp();
void DoDown();
void DoLeft();           
void DoRight();   
void food(int * , int *);
void gotoxy(int , int );

int z=350,flag2=0,flag3=0,flag4=0,score=0;    //z代表delay_time(z=>睡覺嘛！)
int sx[20]={0};        
int sy[20]={0};             //sx,sy分別儲存蛇身體的位置座標：足標0表示頭，足標1表示第一節身體，足標2表示第二節身體...      
int j=0;                 //sx,sy的足標
int last=0;              //最後一個(也是最新)的一個node
int lx[20]={0},ly[20]={0},l=0,k=0;           //在food函式 儲存著被蛇吃掉食物的位置,l,k表示足標
int fx,fy;              //用在DoDirect函式: fr=sr[last] 
using namespace std;

class snake{                   //class的宣告基本上就很像全域變數了

public:
	int rx;            //rx,ry代表random sx[j],sy[j] ，就是指食物
	int ry;
                
};




int main()
{   
	snake S;  //class

	int i,up=1,left=1,down=20,right=35;
    
	char Inputkey = ' ' ;  // 初始值
    char BeDirect = ' ' ; 
	char trash = ' ' ; //因"鍵號"是雙字元，需先丟一個進去(int顯示是-32)，第二個字元由大寫字母組成，
	int flag=0;     //不可以用int sx[j]=sy[j]=0;來宣告
    char Up='H',Down='P',Left='K',Right='M';
    
    srand( time(NULL) );
    


	//while(1){               test1  
	//   Sleep(1000);          test1     
    gotoxy(left,up);
    cout<<"Play the snack game\n";
    gotoxy(left,up+=1);                     //up+=1這招讚
     cout<<"Score:"<<score<<endl<<"Delay_time:"<<z; 
    gotoxy(left=9,up=4); //畫上面                       
    printf("+-------------------------+");             
    gotoxy(left,down); //畫下面
    printf("+-------------------------+");
    for(i=up+1;i<down;i++)//畫左邊
    {
        gotoxy(left,i);
        printf("|");
    }
    for(i=up+1;i<down;i++) //畫右邊
    {
        gotoxy(right,i);
        printf("|");
	
	}
	
 
	sx[j]=15;
	sy[j]=15;

	if(flag==0){
		gotoxy(sx[j],sy[j]);
		cout<<"#";
		}
        flag=1;


	while(kbhit()==0);       

  /* cout<<(int)kbhit();
   trash=getch();              測試用
   cout<<kbhit();*/
	do{   
   S.rx=(rand()%25)+10;
   S.ry=(rand()%15)+5;
    gotoxy(S.rx,S.ry);
	cout<<"*";
	}while( sx[j]==S.rx && sy[j]==S.ry ); 

		while(1){  // 開始遊戲
		BeDirect=Inputkey;
		
		/*if(kbhit()==1) 
		   trash = getch();    // 修改掉之前的，有點像數學的消去法
		*/

		while(kbhit()==1)
		{  	Inputkey = getch();
		    
		}
	/*	else
		{Inputkey=BeDirect;		 
		} */  

		if( ((Inputkey == Up) && (BeDirect != Down)) || ((BeDirect == Up) && (Inputkey == Down)) ){   // 處理使用者按下 Up 的事件

			while( kbhit()==0 )	 // kbhit() = 0表示使用者沒有按下任何鍵
			{	DoUp();
		        food(&S.rx , &S.ry);
			        if(flag2==1) //或 撞到身體     //遊戲結束
						break;
			}
					Inputkey=Up;
				
        }
        else if(((Inputkey==Down) && (BeDirect != Up)) || ((BeDirect == Down ) && (Inputkey == Up)) ){ // 處理使用者按下 Down 的事件
		     while( kbhit()==0 )
			 {	 DoDown();
			     food(&S.rx , &S.ry);
			     if(flag2==1) //或 撞到身體     //遊戲結束
                 break;
			 }
				 Inputkey=Down;
        }
		else if(((Inputkey==Right) && (BeDirect != Left)) || ((BeDirect == Right) && (Inputkey == Left)) ){ // 處理使用者按下 Right 的事件
			while( kbhit()==0 )
			{	 DoRight();
			     food(&S.rx , &S.ry);
                 if(flag2==1) //或 撞到身體     //遊戲結束
                 break;
			}
				 Inputkey=Right;
        }
        else if(((Inputkey==Left) && (BeDirect != Right)) || ((BeDirect == Left ) && (Inputkey == Right)) ){ // 處理使用者按下 Left 的事件
			while( kbhit()==0 )
			{	 DoLeft(); 
			     food(&S.rx , &S.ry);
			     if(flag2==1) //或 撞到身體     //遊戲結束
                 break;
			}
				 Inputkey=Left;
        }
		else if(Inputkey == 27){ // 處理使用者按下 離開 的事件，不一定要用強制運算子int
            gotoxy(left+3,down+3);    //***gotoxy是一個要求兩變數輸入的函式，所以不可以直接代數字進去喔		
				break;}
        
	//	else Inputkey=BeDirect;
        if(flag2==1){
		  gotoxy(left+=3,down+=3);      //	  gotoxy(left+3,down+3); 也可以降用@@ 不是輸入變數的感覺！！但後來發現，這樣不能再使用第二次，會沒效！！
		   break; 
		}
		
	

		
			}
    return 0; 
  
}
void DoUp()
{   
  
	int v,w=1,t=0; 
  
	gotoxy( sx[last] , sy[last] );
    if(	sx[last] == lx[k] && sy[last] == ly[k] )   //flag4==0表示最後一節沒吃到食物
	{  
		k++;
	cout<<"#";
	last++;	
    }else
	cout<<" ";

    fx=sx[last];
	fy=sy[last];
    	
	for(v=last;v>=1;v--){    //將蛇全部身體的前一個node位置的值(包含頭)存給後一個node位置
       sx[v]=sx[v-1];
	   sy[v]=sy[v-1];
}
	
	gotoxy(sx[0],--(sy[0]));
	
	for(;w<=last;w++)
	{	if( sx[w]==sx[0] && sy[w]==sy[0] )
             t=1;                                //w==0表示沒碰到身體
	}
	

	if( (10<=sx[0] && sx[0]<=34 && 5<=sy[0] && sy[0]<=19) && t==0 )
	{ cout<<"#";	  
	  Sleep( z );
	}
	else{
        gotoxy(fx,fy);      //這地方是碰到牆壁的，還要再加碰到身體的，可能要再改一改！！
		cout<<"#";
		flag2=1;
	}	
	
    
}
void DoDown()
{   
  
	int v,w=1,t=0; 
  
	gotoxy( sx[last] , sy[last] );
    if(	sx[last] == lx[k] && sy[last] == ly[k] )   //flag4==0表示最後一節沒吃到食物
	{  
		k++;
	cout<<"#";
	last++;	
    }else
	cout<<" ";

    fx=sx[last];
	fy=sy[last];
    	
	for(v=last;v>=1;v--){    //將蛇全部身體的前一個node位置的值(包含頭)存給後一個node位置
       sx[v]=sx[v-1];
	   sy[v]=sy[v-1];
}
	
	gotoxy(sx[0],++(sy[0]));
	
	for(;w<=last;w++)
	{	if( sx[w]==sx[0] && sy[w]==sy[0] )
             t=1;                                //w==0表示沒碰到身體
	}
	

	if( (10<=sx[0] && sx[0]<=34 && 5<=sy[0] && sy[0]<=19) && t==0 )
	{ cout<<"#";	  
	  Sleep( z );
	}
	else{
        gotoxy(fx,fy);      //這地方是碰到牆壁的，還要再加碰到身體的，可能要再改一改！！
		cout<<"#";
		flag2=1;
	}	
	
    	
}
void DoLeft()
{   
  
	int v,w=1,t=0; 
  
	gotoxy( sx[last] , sy[last] );
    if(	sx[last] == lx[k] && sy[last] == ly[k] )   //flag4==0表示最後一節沒吃到食物
	{  
		k++;
	cout<<"#";
	last++;	
    }else
	cout<<" ";

    fx=sx[last];
	fy=sy[last];
    	
	for(v=last;v>=1;v--){    //將蛇全部身體的前一個node位置的值(包含頭)存給後一個node位置
       sx[v]=sx[v-1];
	   sy[v]=sy[v-1];
}
	
	gotoxy(--(sx[0]),sy[0]);
	
	for(;w<=last;w++)
	{	if( sx[w]==sx[0] && sy[w]==sy[0] )
             t=1;                                //w==0表示沒碰到身體
	}
	

	if( (10<=sx[0] && sx[0]<=34 && 5<=sy[0] && sy[0]<=19) && t==0 )
	{ cout<<"#";	  
	  Sleep( z );
	}
	else{
        gotoxy(fx,fy);      //這地方是碰到牆壁的，還要再加碰到身體的，可能要再改一改！！
		cout<<"#";
		flag2=1;
	}	
	
    
}
void DoRight()
{   
	int v,w=1,t=0; 
  
	gotoxy( sx[last] , sy[last] );
    if(	sx[last] == lx[k] && sy[last] == ly[k] )   //flag4==0表示最後一節沒吃到食物
	{  
		k++;
	cout<<"#";
	last++;	
    }else
	cout<<" ";

    fx=sx[last];
	fy=sy[last];
    	
	for(v=last;v>=1;v--){    //將蛇全部身體的前一個node位置的值(包含頭)存給後一個node位置
       sx[v]=sx[v-1];
	   sy[v]=sy[v-1];
}
	
	gotoxy(++(sx[0]),sy[0]);
	
	for(;w<=last;w++)
	{	if( sx[w]==sx[0] && sy[w]==sy[0] )
             t=1;                                //w==0表示沒碰到身體
	}
	

	if( (10<=sx[0] && sx[0]<=34 && 5<=sy[0] && sy[0]<=19) && t==0 )
	{ cout<<"#";	  
	  Sleep( z );
	}
	else{
        gotoxy(fx,fy);      //這地方是碰到牆壁的，還要再加碰到身體的，可能要再改一改！！
		cout<<"#";
		flag2=1;
	}	
	
    
}

void food(int *a, int *b)
{  int m,n,u,test;   
   
	while((sx[0]==*a) && (sy[0]==*b)){
			if((sx[0]==*a && sy[0]==*b) && flag3==0 )
			{    score+=10;  	//	加分;  ====>這地方原本是放在可能會寫程式碼裡頭的(這就叫虛擬碼@@)    
		         z-=10;
			     gotoxy(m=1,n=2);   //可以local function內宣告的變數去call別的函式，也可以用像 sx[j]+2 把它當變數，像第54行就可以
				 	lx[l]=(*a);
		            ly[l]=(*b);	
					l++;
			 cout<<"Score:"<<score<<endl<<"Delay_time:"<<z;        //一直更新不會閃爍是因為畫面保持不變
				 if(score==200){
			     gotoxy(m+3,n+19);
				 cout<<"        You are a superman!!";
				 flag2=1;
				 break;
				 }
			}
	
	    *a=(rand()%25)+10;
        *b=(rand()%15)+5;
	    
        for(u=0;u<=last;u++)                //last可能有點問題！
		{  if( (sx[u] == *a) && (sy[u] == *b) )
              flag3=1; 			
		}


		if( flag3 ==0 ){              
		gotoxy(*a,*b);            //函式再去call函式，指標的所指的值輸入進去！
	    cout<<"*";
		break; 
		}
	}

	flag3=0;

  }
	

void gotoxy(int xx, int yy)
{
	static HANDLE hConsole = 0; //初始值
	static int instanceCount = 0;
    COORD coord;
    
    if( instanceCount == 0 )
    {
//取得螢幕的控制
        hConsole = GetStdHandle( STD_OUTPUT_HANDLE ); 
        instanceCount = 1;
    }
    coord.X = xx - 1;
    coord.Y = yy - 1;
	//將游標移至所指定的座標位置
    SetConsoleCursorPosition( hConsole, coord );
}

/* 心得：1.debug的能力提升
         2.像玩遊戲一樣許多等級提升
         3.寫到後來會把整個大程式的來龍去脈及細結記得很清楚，不會覺得煩了，充滿信心！！
		 4.寫程式碼有時候有點像寫作文和畫畫一樣，要先寫，不要光只是想，再從寫下的程式碼中看出一些架構，再來修改、潤飾。
        Q5.如果把全域變數當作傳入函式的參數，那降會產生傳值呼叫嗎？  答：會滴
		 6.在寫蛇的身體部分時，學到使用兩種方法：1. <畫圖法>  可以讓自已對小部分的程式控制流程更加清晰
		                                         2. <歸納法>  竟然使用到這傳說中的歸納法了！哇！等級又提升了！！
												             
															  此即..

		                                                        第一步：設n=0，得到成立

																第二步：假設n=k成立，若推得n=k+1也成立，則原式成立！！
                     
					
         7.想到了一些程式碼該怎麼寫時，不要急，細心的將程式碼打出來，慢工出細活，才遠離討厭的bug
		 8.要想學好寫程式，學會中英快打也是一門必修之道
		 9.寫出漂亮程式的最終之道==>睡覺，讓腦筋休息一下...
*/