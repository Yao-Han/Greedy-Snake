
#include <iostream>   
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h> //�̭��tgotoxy()����COORD��HANDLE�������O��.. 
                     //�Ĥ@���N���b�o@o@


#define clrscr() { system("cls"); } 

void DoUp();
void DoDown();
void DoLeft();           
void DoRight();   
void food(int * , int *);
void gotoxy(int , int );

int z=350,flag2=0,flag3=0,flag4=0,score=0;    //z�N��delay_time(z=>��ı���I)
int sx[20]={0};        
int sy[20]={0};             //sx,sy���O�x�s�D���骺��m�y�СG����0����Y�A����1��ܲĤ@�`����A����2��ܲĤG�`����...      
int j=0;                 //sx,sy������
int last=0;              //�̫�@��(�]�O�̷s)���@��node
int lx[20]={0},ly[20]={0},l=0,k=0;           //�bfood�禡 �x�s�۳Q�D�Y����������m,l,k��ܨ���
int fx,fy;              //�ΦbDoDirect�禡: fr=sr[last] 
using namespace std;

class snake{                   //class���ŧi�򥻤W�N�ܹ������ܼƤF

public:
	int rx;            //rx,ry�N��random sx[j],sy[j] �A�N�O������
	int ry;
                
};




int main()
{   
	snake S;  //class

	int i,up=1,left=1,down=20,right=35;
    
	char Inputkey = ' ' ;  // ��l��
    char BeDirect = ' ' ; 
	char trash = ' ' ; //�]"�丹"�O���r���A�ݥ���@�Ӷi�h(int��ܬO-32)�A�ĤG�Ӧr���Ѥj�g�r���զ��A
	int flag=0;     //���i�H��int sx[j]=sy[j]=0;�ӫŧi
    char Up='H',Down='P',Left='K',Right='M';
    
    srand( time(NULL) );
    


	//while(1){               test1  
	//   Sleep(1000);          test1     
    gotoxy(left,up);
    cout<<"Play the snack game\n";
    gotoxy(left,up+=1);                     //up+=1�o���g
     cout<<"Score:"<<score<<endl<<"Delay_time:"<<z; 
    gotoxy(left=9,up=4); //�e�W��                       
    printf("+-------------------------+");             
    gotoxy(left,down); //�e�U��
    printf("+-------------------------+");
    for(i=up+1;i<down;i++)//�e����
    {
        gotoxy(left,i);
        printf("|");
    }
    for(i=up+1;i<down;i++) //�e�k��
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
   trash=getch();              ���ե�
   cout<<kbhit();*/
	do{   
   S.rx=(rand()%25)+10;
   S.ry=(rand()%15)+5;
    gotoxy(S.rx,S.ry);
	cout<<"*";
	}while( sx[j]==S.rx && sy[j]==S.ry ); 

		while(1){  // �}�l�C��
		BeDirect=Inputkey;
		
		/*if(kbhit()==1) 
		   trash = getch();    // �קﱼ���e���A���I���ƾǪ����h�k
		*/

		while(kbhit()==1)
		{  	Inputkey = getch();
		    
		}
	/*	else
		{Inputkey=BeDirect;		 
		} */  

		if( ((Inputkey == Up) && (BeDirect != Down)) || ((BeDirect == Up) && (Inputkey == Down)) ){   // �B�z�ϥΪ̫��U Up ���ƥ�

			while( kbhit()==0 )	 // kbhit() = 0��ܨϥΪ̨S�����U������
			{	DoUp();
		        food(&S.rx , &S.ry);
			        if(flag2==1) //�� ���쨭��     //�C������
						break;
			}
					Inputkey=Up;
				
        }
        else if(((Inputkey==Down) && (BeDirect != Up)) || ((BeDirect == Down ) && (Inputkey == Up)) ){ // �B�z�ϥΪ̫��U Down ���ƥ�
		     while( kbhit()==0 )
			 {	 DoDown();
			     food(&S.rx , &S.ry);
			     if(flag2==1) //�� ���쨭��     //�C������
                 break;
			 }
				 Inputkey=Down;
        }
		else if(((Inputkey==Right) && (BeDirect != Left)) || ((BeDirect == Right) && (Inputkey == Left)) ){ // �B�z�ϥΪ̫��U Right ���ƥ�
			while( kbhit()==0 )
			{	 DoRight();
			     food(&S.rx , &S.ry);
                 if(flag2==1) //�� ���쨭��     //�C������
                 break;
			}
				 Inputkey=Right;
        }
        else if(((Inputkey==Left) && (BeDirect != Right)) || ((BeDirect == Left ) && (Inputkey == Right)) ){ // �B�z�ϥΪ̫��U Left ���ƥ�
			while( kbhit()==0 )
			{	 DoLeft(); 
			     food(&S.rx , &S.ry);
			     if(flag2==1) //�� ���쨭��     //�C������
                 break;
			}
				 Inputkey=Left;
        }
		else if(Inputkey == 27){ // �B�z�ϥΪ̫��U ���} ���ƥ�A���@�w�n�αj��B��lint
            gotoxy(left+3,down+3);    //***gotoxy�O�@�ӭn�D���ܼƿ�J���禡�A�ҥH���i�H�����N�Ʀr�i�h��		
				break;}
        
	//	else Inputkey=BeDirect;
        if(flag2==1){
		  gotoxy(left+=3,down+=3);      //	  gotoxy(left+3,down+3); �]�i�H����@@ ���O��J�ܼƪ��Pı�I�I����ӵo�{�A�o�ˤ���A�ϥβĤG���A�|�S�ġI�I
		   break; 
		}
		
	

		
			}
    return 0; 
  
}
void DoUp()
{   
  
	int v,w=1,t=0; 
  
	gotoxy( sx[last] , sy[last] );
    if(	sx[last] == lx[k] && sy[last] == ly[k] )   //flag4==0��̫ܳ�@�`�S�Y�쭹��
	{  
		k++;
	cout<<"#";
	last++;	
    }else
	cout<<" ";

    fx=sx[last];
	fy=sy[last];
    	
	for(v=last;v>=1;v--){    //�N�D�������骺�e�@��node��m����(�]�t�Y)�s����@��node��m
       sx[v]=sx[v-1];
	   sy[v]=sy[v-1];
}
	
	gotoxy(sx[0],--(sy[0]));
	
	for(;w<=last;w++)
	{	if( sx[w]==sx[0] && sy[w]==sy[0] )
             t=1;                                //w==0��ܨS�I�쨭��
	}
	

	if( (10<=sx[0] && sx[0]<=34 && 5<=sy[0] && sy[0]<=19) && t==0 )
	{ cout<<"#";	  
	  Sleep( z );
	}
	else{
        gotoxy(fx,fy);      //�o�a��O�I��������A�٭n�A�[�I�쨭�骺�A�i��n�A��@��I�I
		cout<<"#";
		flag2=1;
	}	
	
    
}
void DoDown()
{   
  
	int v,w=1,t=0; 
  
	gotoxy( sx[last] , sy[last] );
    if(	sx[last] == lx[k] && sy[last] == ly[k] )   //flag4==0��̫ܳ�@�`�S�Y�쭹��
	{  
		k++;
	cout<<"#";
	last++;	
    }else
	cout<<" ";

    fx=sx[last];
	fy=sy[last];
    	
	for(v=last;v>=1;v--){    //�N�D�������骺�e�@��node��m����(�]�t�Y)�s����@��node��m
       sx[v]=sx[v-1];
	   sy[v]=sy[v-1];
}
	
	gotoxy(sx[0],++(sy[0]));
	
	for(;w<=last;w++)
	{	if( sx[w]==sx[0] && sy[w]==sy[0] )
             t=1;                                //w==0��ܨS�I�쨭��
	}
	

	if( (10<=sx[0] && sx[0]<=34 && 5<=sy[0] && sy[0]<=19) && t==0 )
	{ cout<<"#";	  
	  Sleep( z );
	}
	else{
        gotoxy(fx,fy);      //�o�a��O�I��������A�٭n�A�[�I�쨭�骺�A�i��n�A��@��I�I
		cout<<"#";
		flag2=1;
	}	
	
    	
}
void DoLeft()
{   
  
	int v,w=1,t=0; 
  
	gotoxy( sx[last] , sy[last] );
    if(	sx[last] == lx[k] && sy[last] == ly[k] )   //flag4==0��̫ܳ�@�`�S�Y�쭹��
	{  
		k++;
	cout<<"#";
	last++;	
    }else
	cout<<" ";

    fx=sx[last];
	fy=sy[last];
    	
	for(v=last;v>=1;v--){    //�N�D�������骺�e�@��node��m����(�]�t�Y)�s����@��node��m
       sx[v]=sx[v-1];
	   sy[v]=sy[v-1];
}
	
	gotoxy(--(sx[0]),sy[0]);
	
	for(;w<=last;w++)
	{	if( sx[w]==sx[0] && sy[w]==sy[0] )
             t=1;                                //w==0��ܨS�I�쨭��
	}
	

	if( (10<=sx[0] && sx[0]<=34 && 5<=sy[0] && sy[0]<=19) && t==0 )
	{ cout<<"#";	  
	  Sleep( z );
	}
	else{
        gotoxy(fx,fy);      //�o�a��O�I��������A�٭n�A�[�I�쨭�骺�A�i��n�A��@��I�I
		cout<<"#";
		flag2=1;
	}	
	
    
}
void DoRight()
{   
	int v,w=1,t=0; 
  
	gotoxy( sx[last] , sy[last] );
    if(	sx[last] == lx[k] && sy[last] == ly[k] )   //flag4==0��̫ܳ�@�`�S�Y�쭹��
	{  
		k++;
	cout<<"#";
	last++;	
    }else
	cout<<" ";

    fx=sx[last];
	fy=sy[last];
    	
	for(v=last;v>=1;v--){    //�N�D�������骺�e�@��node��m����(�]�t�Y)�s����@��node��m
       sx[v]=sx[v-1];
	   sy[v]=sy[v-1];
}
	
	gotoxy(++(sx[0]),sy[0]);
	
	for(;w<=last;w++)
	{	if( sx[w]==sx[0] && sy[w]==sy[0] )
             t=1;                                //w==0��ܨS�I�쨭��
	}
	

	if( (10<=sx[0] && sx[0]<=34 && 5<=sy[0] && sy[0]<=19) && t==0 )
	{ cout<<"#";	  
	  Sleep( z );
	}
	else{
        gotoxy(fx,fy);      //�o�a��O�I��������A�٭n�A�[�I�쨭�骺�A�i��n�A��@��I�I
		cout<<"#";
		flag2=1;
	}	
	
    
}

void food(int *a, int *b)
{  int m,n,u,test;   
   
	while((sx[0]==*a) && (sy[0]==*b)){
			if((sx[0]==*a && sy[0]==*b) && flag3==0 )
			{    score+=10;  	//	�[��;  ====>�o�a��쥻�O��b�i��|�g�{���X���Y��(�o�N�s�����X@@)    
		         z-=10;
			     gotoxy(m=1,n=2);   //�i�Hlocal function���ŧi���ܼƥhcall�O���禡�A�]�i�H�ι� sx[j]+2 �⥦���ܼơA����54��N�i�H
				 	lx[l]=(*a);
		            ly[l]=(*b);	
					l++;
			 cout<<"Score:"<<score<<endl<<"Delay_time:"<<z;        //�@����s���|�{�{�O�]���e���O������
				 if(score==200){
			     gotoxy(m+3,n+19);
				 cout<<"        You are a superman!!";
				 flag2=1;
				 break;
				 }
			}
	
	    *a=(rand()%25)+10;
        *b=(rand()%15)+5;
	    
        for(u=0;u<=last;u++)                //last�i�঳�I���D�I
		{  if( (sx[u] == *a) && (sy[u] == *b) )
              flag3=1; 			
		}


		if( flag3 ==0 ){              
		gotoxy(*a,*b);            //�禡�A�hcall�禡�A���Ъ��ҫ����ȿ�J�i�h�I
	    cout<<"*";
		break; 
		}
	}

	flag3=0;

  }
	

void gotoxy(int xx, int yy)
{
	static HANDLE hConsole = 0; //��l��
	static int instanceCount = 0;
    COORD coord;
    
    if( instanceCount == 0 )
    {
//���o�ù�������
        hConsole = GetStdHandle( STD_OUTPUT_HANDLE ); 
        instanceCount = 1;
    }
    coord.X = xx - 1;
    coord.Y = yy - 1;
	//�N��в��ܩҫ��w���y�Ц�m
    SetConsoleCursorPosition( hConsole, coord );
}

/* �߱o�G1.debug����O����
         2.�����C���@�˳\�h���Ŵ���
         3.�g���ӷ|���Ӥj�{�������s�h�ߤβӵ��O�o�ܲM���A���|ı�o�ФF�A�R���H�ߡI�I
		 4.�g�{���X���ɭԦ��I���g�@��M�e�e�@�ˡA�n���g�A���n���u�O�Q�A�A�q�g�U���{���X���ݥX�@�Ǭ[�c�A�A�ӭק�B���C
        Q5.�p�G������ܼƷ�@�ǤJ�禡���ѼơA�����|���ͶǭȩI�s�ܡH  ���G�|�w
		 6.�b�g�D�����鳡���ɡA�Ǩ�ϥΨ�ؤ�k�G1. <�e�Ϫk>  �i�H���ۤw��p�������{������y�{��[�M��
		                                         2. <�k�Ǫk>  ���M�ϥΨ�o�ǻ������k�Ǫk�F�I�z�I���ŤS���ɤF�I�I
												             
															  ���Y..

		                                                        �Ĥ@�B�G�]n=0�A�o�즨��

																�ĤG�B�G���]n=k���ߡA�Y���on=k+1�]���ߡA�h�즡���ߡI�I
                     
					
         7.�Q��F�@�ǵ{���X�ӫ��g�ɡA���n��A�Ӥߪ��N�{���X���X�ӡA�C�u�X�Ӭ��A�~�����Q����bug
		 8.�n�Q�Ǧn�g�{���A�Ƿ|���^�֥��]�O�@�����פ��D
		 9.�g�X�}�G�{�����̲פ��D==>��ı�A�������𮧤@�U...
*/