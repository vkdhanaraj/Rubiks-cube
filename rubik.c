#include<stdio.h>
#include<stdlib.h>
//Define colors.
#define KNRM  "\x1B[40;0m"
#define KRED  "\x1B[41;1m"
#define KGRN  "\x1B[42;1m"
#define KYEL  "\x1B[43;1m"
#define KBLU  "\x1B[44;1m"
#define KMAG  "\x1B[45;1m"
#define KCYN  "\x1B[46;1m"
#define KWHT  "\x1B[47;1;30m"

char t1,t2,t3;
int topflag=0,topflag2=0;
char f[3][3]={'o','o','y','o','o','y','o','o','y'},r[3][3]={'g','g','g','g','g','g','g','g','g'},l[3][3]={'b','b','b','b','b','b','b','b','b'},t[3][3]={'y','y','r','y','y','r','y','y','r'},b[3][3]={'w','r','r','w','r','r','w','r','r'},d[3][3]={'o','w','w','o','w','w','o','w','w'};

//Pointer arrays which contain addresses of elements that are needed for corresponding functions.
char *right1[8]={&f[0][0],&r[0][0],&b[0][0],&l[0][0],&f[2][0],&r[2][0],&b[2][0],&l[2][0]};
char *left1[8]={&f[0][0],&l[0][0],&b[0][0],&r[0][0],&f[2][0],&l[2][0],&b[2][0],&r[2][0]};
char *rs[12]={&f[0][2],&t[0][2],&b[2][0],&d[2][0],&f[1][2],&t[1][2],&b[1][0],&d[1][0],&f[2][2],&t[2][2],&b[0][0],&d[0][0]};
char *rsa[12]={&f[0][2],&d[2][0],&b[2][0],&t[0][2],&f[1][2],&d[1][0],&b[1][0],&t[1][2],&f[2][2],&d[0][0],&b[0][0],&t[2][2]};
char *ls[12]={&f[0][0],&d[2][2],&b[2][2],&t[0][0],&f[1][0],&d[1][2],&b[1][2],&t[1][0],&f[2][0],&d[0][2],&b[0][2],&t[2][0]};
char *lsa[12]={&f[0][0],&t[0][0],&b[2][2],&d[2][2],&f[1][0],&t[1][0],&b[1][2],&d[1][2],&f[2][0],&t[2][0],&b[0][2],&d[0][2]};
char *horizon[7]={&f[1][1],&r[1][1],&b[1][1],&l[1][1],&f[1][1],&r[1][1],&b[1][1]};
char *facec[12]={&t[2][0],&r[0][0],&d[2][0],&l[2][2],&t[2][1],&r[1][0],&d[2][1],&l[1][2],&t[2][2],&r[2][0],&d[2][2],&l[0][2]};
char *facea[12]={&t[2][0],&l[2][2],&d[2][0],&r[0][0],&t[2][1],&l[1][2],&d[2][1],&r[1][0],&t[2][2],&l[0][2],&d[2][2],&r[2][0]};
char *backc[12]={&t[0][2],&l[0][0],&d[0][2],&r[2][2],&t[0][1],&l[1][0],&d[0][1],&r[1][2],&t[0][0],&l[2][0],&d[0][0],&r[0][2]};
char *backa[12]={&t[0][2],&r[2][2],&d[0][2],&l[0][0],&t[0][1],&r[1][2],&d[0][1],&l[1][0],&t[0][0],&r[0][2],&d[0][0],&l[2][0]};
char *cube[6]={&f[0][0],&r[0][0],&b[0][0],&l[0][0],&t[0][0],&d[0][0]};


//Display all elements.
void display()
{	int i,k;
	char *m;
	m=*(cube);
	//here, k:number of faces
	for(k=0;k<6;k++)
	{
		m=*(cube+k);
		if(k==0)
			printf("Front:\n");
		else if(k==1)
			printf("Right:\n");
		else if(k==2)
			printf("Back:\n");
		else if(k==3)
			printf("Left:\n");
		else if(k==4)
			printf("Top:\n");
		else if(k==5)
			printf("Down:\n");	
		for(i=0;i<9;i++)
		{	
			if(m[i]=='w')
				printf(KWHT "%c " KNRM,m[i]);
			else if(m[i]=='r')
				printf(KRED "%c " KNRM,m[i]);	
			else if(m[i]=='b')
				printf(KBLU "%c " KNRM,m[i]);	
			else if(m[i]=='g')
				printf(KGRN "%c " KNRM,m[i]);
			else if(m[i]=='y')
				printf(KYEL "%c " KNRM,m[i]);
			else 
				printf(KMAG "%c " KNRM,m[i]);
		if(i%3==2)
			printf("\n");
		}
		printf("\n");
	}
}

//Rotate horizontally towards right(either first or third row)
void right(int row)
{
	int i,j,pos,flag=0;
	char *x,t1,temp1[3],temp2[3];
	if(row==1)
	{	
		pos=0;
		//Rotate top face anticlockwise
		t1=t[0][0];
		t[0][0]=t[0][2];
		t[0][2]=t[2][2];
		t[2][2]=t[2][0];
		t[2][0]=t1;
		t1=t[0][1];
		t[0][1]=t[1][2];
		t[1][2]=t[2][1];
		t[2][1]=t[1][0];
		t[1][0]=t1;	
	}		
	else if(row==3)
	{
		pos=4;
		//Rotate bottom face clockwise
		t1=d[0][0];
		d[0][0]=d[2][0];
		d[2][0]=d[2][2];
		d[2][2]=d[0][2];
		d[0][2]=t1;
		t1=d[0][1];
		d[0][1]=d[1][0];
		d[1][0]=d[2][1];
		d[2][1]=d[1][2];
		d[1][2]=t1;
	}	
	//Shift elements of rows to corresponding positions	
	for(i=pos;i<pos+4;i++)	
	{	
		x=*(right1+i);//right1 array contains addresses of elements on which right(right rotation) operation is to be performed.
		for(j=0;j<3;j++)
		{	
			if(flag==0)
			{	
				temp1[j]=x[j];
				temp2[j]=x[j];
				continue;
			}
			else
			{
				temp1[j]=x[j];
				x[j]=temp2[j];
				temp2[j]=temp1[j];
			}
		}
		flag=1;	
	}	
	x=*(right1+pos);
	for(j=0;j<3;j++)
	{
		x[j]=temp1[j];
	}
}

//Rotate horizontally towards left(either first or third row)
void left(int row)
{
	int i,j,pos,flag=0;
	char *x,temp1[3],temp2[3];
	if(row==1)
	{	
		pos=0;
		//rotate top face clockwise
		t1=t[0][0];
		t[0][0]=t[2][0];
		t[2][0]=t[2][2];
		t[2][2]=t[0][2];
		t[0][2]=t1;
		t1=t[0][1];
		t[0][1]=t[1][0];
		t[1][0]=t[2][1];
		t[2][1]=t[1][2];
		t[1][2]=t1;	
	}		
	else if(row==3)
	{
		pos=4;
		//rotate bottom face anticlockwise
		t1=d[0][0];
		d[0][0]=d[0][2];
		d[0][2]=d[2][2];
		d[2][2]=d[2][0];
		d[2][0]=t1;
		t1=d[0][1];
		d[0][1]=d[1][2];
		d[1][2]=d[2][1];
		d[2][1]=d[1][0];
		d[1][0]=t1;
	}	
	//Shift elements of rows to corresponding positions
	for(i=pos;i<pos+4;i++)	
	{	
		x=*(left1+i);
		for(j=0;j<3;j++)
		{	
			if(flag==0)
			{	
				temp1[j]=x[j];
				temp2[j]=x[j];
				continue;
			}
			else
			{
				temp1[j]=x[j];
				x[j]=temp2[j];
				temp2[j]=temp1[j];
			}
		}
		flag=1;	
	}	
	x=*(left1+pos);
	for(j=0;j<3;j++)
	{
		x[j]=temp1[j];
	}
}


//Rotate right face 
void rside(char ch)
{
	int i,j;
	char temp1,temp2,*x,**y;
	if(ch=='c'||ch=='C')
	{
		y=&(rs[0]);
		//Rotate right face in cloclwise direction
		temp1=r[0][0];
		r[0][0]=r[2][0];
		r[2][0]=r[2][2];
		r[2][2]=r[0][2];
		r[0][2]=temp1;
		temp1=r[0][1];
		r[0][1]=r[1][0];
		r[1][0]=r[2][1];
		r[2][1]=r[1][2];
		r[1][2]=temp1;	
	}
	else
	{
		y=&(rsa[0]);
		//Rotate right face in anti clockwise direction
		temp1=r[0][0];
		r[0][0]=r[0][2];
		r[0][2]=r[2][2];
		r[2][2]=r[2][0];
		r[2][0]=temp1;
		temp1=r[0][1];
		r[0][1]=r[1][2];
		r[1][2]=r[2][1];
		r[2][1]=r[1][0];
		r[1][0]=temp1;	
	}			
	//Shift elements to corresponding positions
	for(j=0;j<9;j=j+4)
	{
		x=*(y+j);
		temp1=x[0];
		temp2=x[0];
		for(i=1;i<4;i++)
		{
			x=*(y+j+i);		
			temp2=x[0];
			x[0]=temp1;
			temp1=temp2;
		}
		x=*(y+j);
		x[0]=temp1;
	}
}

//Rotate left face
void lside(char ch)
{
	int i,j;
	char temp1,temp2,*x,**y;
	if(ch=='c'||ch=='C')
	{
		y=&(ls[0]);
		//Rotate left face in clockwise direction
		temp1=l[0][0];
		l[0][0]=l[2][0];
		l[2][0]=l[2][2];
		l[2][2]=l[0][2];
		l[0][2]=temp1;
		temp1=l[0][1];
		l[0][1]=l[1][0];
		l[1][0]=l[2][1];
		l[2][1]=l[1][2];
		l[1][2]=temp1;
	}
	else
	{
		y=&(lsa[0]);
		//Rotate left face in anti clockwise direction
		temp1=l[0][0];
		l[0][0]=l[0][2];
		l[0][2]=l[2][2];
		l[2][2]=l[2][0];
		l[2][0]=temp1;
		temp1=l[0][1];
		l[0][1]=l[1][2];
		l[1][2]=l[2][1];
		l[2][1]=l[1][0];
		l[1][0]=temp1;		
	}			
	//Shift elements to corresponding positions
	for(j=0;j<9;j=j+4)
	{
		x=*(y+j);
		temp1=x[0];
		temp2=x[0];
		for(i=1;i<4;i++)
		{
			x=*(y+j+i);		
			temp2=x[0];
			x[0]=temp1;
			temp1=temp2;
		}
		x=*(y+j);
		x[0]=temp1;
	}
}
//Rotate front face
void face(char ch)
{
	int i,j;
	char temp1,temp2,*x,**y;
	if(ch=='c'||ch=='C')
	{
		y=&(facec[0]);
		//Shift elements of front face in clockwise direction.
		temp1=f[0][0];
		f[0][0]=f[2][0];
		f[2][0]=f[2][2];
		f[2][2]=f[0][2];
		f[0][2]=temp1;
		temp1=f[0][1];
		f[0][1]=f[1][0];
		f[1][0]=f[2][1];
		f[2][1]=f[1][2];
		f[1][2]=temp1;
	}
	else
	{
		y=&(facea[0]);
		//Shift elements of front face in anti clockwise direction.
		temp1=f[0][0];
		f[0][0]=f[0][2];
		f[0][2]=f[2][2];
		f[2][2]=f[2][0];
		f[2][0]=temp1;
		temp1=f[0][1];
		f[0][1]=f[1][2];
		f[1][2]=f[2][1];
		f[2][1]=f[1][0];
		f[1][0]=temp1;
	}
	//Shift elements to corresponding positions			
	for(j=0;j<9;j=j+4)
	{
		x=*(y+j);
		temp1=x[0];
		temp2=x[0];
		for(i=1;i<4;i++)
		{
			x=*(y+j+i);		
			temp2=x[0];
			x[0]=temp1;
			temp1=temp2;
		}
		x=*(y+j);
		x[0]=temp1;
	}
}

//Rotate back face		
void back(char ch)
{
	int i,j;
	char temp1,temp2,*x,**y;
	if(ch=='c'||ch=='C')
	{
		y=&(backc[0]);
		//Shift elements of front back in clockwise direction.
		temp1=b[0][0];
		b[0][0]=b[2][0];
		b[2][0]=b[2][2];
		b[2][2]=b[0][2];
		b[0][2]=temp1;
		temp1=b[0][1];
		b[0][1]=b[1][0];
		b[1][0]=b[2][1];
		b[2][1]=b[1][2];
		b[1][2]=temp1;
	}
	else
	{
		y=&(backa[0]);
		//Shift elements of back face in anti clockwise direction.
		temp1=b[0][0];
		b[0][0]=b[0][2];
		b[0][2]=b[2][2];
		b[2][2]=b[2][0];
		b[2][0]=temp1;
		temp1=b[0][1];
		b[0][1]=b[1][2];
		b[1][2]=b[2][1];
		b[2][1]=b[1][0];
		b[1][0]=temp1;
	}			
	//Shift elements to corresponding positions
	for(j=0;j<9;j=j+4)
	{
		x=*(y+j);
		temp1=x[0];
		temp2=x[0];
		for(i=1;i<4;i++)
		{
			x=*(y+j+i);		
			temp2=x[0];
			x[0]=temp1;
			temp1=temp2;
		}
		x=*(y+j);
		x[0]=temp1;
	}
}		
//Function to bring all middle white elements to its respective position.(Forms a "Plus" shape in d bottom(white) face.)
void oneplus()
{
	int i,j;
	char color,*x;
	//Check for 'w' in top face.
	if(t[0][1]=='w')
	{
		back('c');
		back('c');
		goto label;
	}
	else if(t[1][0]=='w')
	{
		lside('c');
		lside('c');
		goto label;
	}
	else if(t[2][1]=='w')
	{
		face('c');
		face('c');
		goto label;
	}
	else if(t[1][2]=='w')
	{
		rside('c');
		rside('c');
		goto label;
	}
	
	//Check for 'w' in middle layer.
	if(f[1][0]=='w')
	{
		lside('c');
		goto label;
	}
	else if(f[1][2]=='w')
	{
		rside('a');
		goto label;
	}
	else if(r[1][0]=='w')
	{
		face('c');
		goto label;
	}
	else if(r[1][2]=='w')
	{
		back('a');
		goto label;
	}
	else if(b[1][0]=='w')
	{
		rside('c');
		goto label;
	}
	else if(b[1][2]=='w')
	{
		lside('a');
		goto label;
	}
	else if(l[1][0]=='w')
	{
		back('c');
		goto label;
	}
	else if(l[1][2]=='w')
	{
		face('a');
		goto label;
	}
	
	//Check for 'w' in top layer of vertical faces.
	if(f[0][1]=='w')
	{
		face('c');
		face('c');
	}
	else if(r[0][1]=='w')
	{
		rside('c');
		rside('c');
	}	
	else if(b[0][1]=='w')
	{
		back('c');
		back('c');
	}
	else if(l[0][1]=='w')
	{
		lside('c');
		lside('c');
	}
	//Check for 'w' in bottom layer  of vertical faces.
	if(f[2][1]=='w')
	{
		face('a');
		rside('a');
		face('c');
	}
	else if(r[2][1]=='w')
	{
		rside('a');
		back('a');
		rside('c');
	}
	else if(b[2][1]=='w')
	{
		back('a');
		lside('a');
		back('c');
	}
	else if(l[2][1]=='w')
	{
		lside('a');
		face('a');
		lside('c');
	}
	
	//check for 'w' in middle positions of bottom face and bring it to its respective position.
	label:{
	 if(d[0][1]=='w'&&b[2][1]!=b[1][1])
	{
		color=b[2][1];
		//Bring the element to the top.
		back('c');
		back('c');
		j=2;
		i=2;
		x=*(horizon+i);
		//Find its matching face
		while(x[0]!=color)
		{
			right(1);
			i++;
			if(i==j+4)
				break;
			x=*(horizon+i);
		}
		//Bring it down.
		if(i==j+1)
		{
			lside('c');
			lside('c');
		}
		else if(i==j+2)
		{
			face('c');
			face('c');
		}
		else if(i==j+3)
		{
			rside('c');
			rside('c');
		}
	}
	else if(d[1][0]=='w'&&r[2][1]!=r[1][1])
	{
		color=r[2][1];
		rside('c');
		rside('c');
		j=1;
		i=1;
		x=*(horizon+i);
		while(x[0]!=color)
		{
			right(1);
			i++;
			if(i==j+4)
				break;
			x=*(horizon+i);
		}
		if(i==j+1)
		{
			back('c');
			back('c');
		}
		else if(i==j+2)
		{
			lside('c');
			lside('c');
		}
		else if(i==j+3)
		{
			face('c');
			face('c');
		}
	}
	else if(d[2][1]=='w'&&f[2][1]!=f[1][1])
	{
		color=f[2][1];
		face('c');
		face('c');
		j=0;
		i=0;
		x=*(horizon+i);
		while(x[0]!=color)
		{
			right(1);
			i++;
			if(i==j+4)
				break;
			x=*(horizon+i);
		}
		if(i==j+1)
		{
			rside('c');
			rside('c');
		
		}
		else if(i==j+2)
		{
			back('c');
			back('c');
		}
		else if(i==j+3)
		{
			lside('c');
			lside('c');
		}
	}
	else if(d[1][2]=='w'&&l[2][1]!=l[1][1])
	{
		color=l[2][1];
		lside('c');
		lside('c');
		j=3;
		i=3;
		x=*(horizon+i);
		while(x[0]!=color)
		{
			right(1);
			i++;
			if(i==j+4)
				break;
			x=*(horizon+i);
		}
		if(i==j+1)
		{
			face('c');
			face('c');
		}
		else if(i==j+2)
		{
			rside('c');
			rside('c');
		}
		else if(i==j+3)
		{
			back('c');
			back('c');
		}
	}
	if(d[0][1]!='w'||d[1][0]!='w'||d[2][1]!='w'||d[1][2]!='w')
	{
		oneplus();
	}
	}
}
//Function to bring all corner pieces containing white to the top layer
void bringtotop()
{
	if(d[0][0]=='w'||b[2][0]=='w'||r[2][2]=='w')
	{
		rside('a');
		right(1);
		rside('c');
	}
	if(d[0][2]=='w'||l[2][0]=='w'||b[2][2]=='w')
	{
		back('a');
		right(1);
		back('c'); 
	}
	if(d[2][0]=='w'||r[2][0]=='w'||f[2][2]=='w')
	{
		rside('c');
		right(1);
		rside('a');
	}
	if(d[2][2]=='w'||l[2][2]=='w'||f[2][0]=='w')
	{
		lside('a');
		right(1);
		lside('c');
	}
	if((t[0][0]=='w'||b[0][2]=='w'||l[0][0]=='w')&&(t[0][2]=='w'||b[0][0]=='w'||r[0][2]=='w')&&(t[2][0]=='w'||f[0][0]=='w'||l[0][2]=='w')&&(t[2][2]=='w'||f[0][2]=='w'||r[0][0]=='w'))
		return;
	else
		bringtotop();
	
}
	
//Function to bring all corner white pieces to respective positions in bottom layer.
void bringtobot()
{
	int i;
	for(i=1;i<=4;i++)
	{	
		if((f[0][0]==f[1][1]&&l[0][2]==l[1][1]&&t[2][0]=='w')||(t[2][0]==f[1][1]&&f[0][0]==l[1][1]&&l[0][2]=='w')||(l[0][2]==f[1][1]&&t[2][0]==l[1][1]&&f[0][0]=='w')||(f[0][0]==l[1][1]&&l[0][2]==f[1][1]&&t[2][0]=='w')||(t[2][0]==l[1][1]&&f[0][0]==f[1][1]&&l[0][2]=='w')||(l[0][2]==l[1][1]&&t[2][0]==f[1][1]&&f[0][0]=='w'))
		{
			right(1);
			lside('a');
			left(1);
			lside('c');
			break;
		}
		right(1);
	}
	for(i=1;i<=4;i++)
	{	
		if((f[0][2]==f[1][1]&&r[0][0]==r[1][1]&&t[2][2]=='w')||(r[0][0]==f[1][1]&&t[2][2]==r[1][1]&&f[0][2]=='w')||(t[2][2]==f[1][1]&&f[0][2]==r[1][1]&&r[0][0]=='w')||(f[0][2]==r[1][1]&&r[0][0]==f[1][1]&&t[2][2]=='w')||(r[0][0]==r[1][1]&&t[2][2]==f[1][1]&&f[0][2]=='w')||(t[2][2]==r[1][1]&&f[0][2]==f[1][1]&&r[0][0]=='w'))
		{
			left(1);
			rside('c');
			right(1);
			rside('a');
			break;
		}
		right(1);
	}
	for(i=1;i<=4;i++)
	{
		if((r[0][2]==r[1][1]&&b[0][0]==b[1][1]&&t[0][2]=='w')||(b[0][0]==r[1][1]&&t[0][2]==b[1][1]&&r[0][2]=='w')||(t[0][2]==r[1][1]&&r[0][2]==b[1][1]&&b[0][0]=='w')||(r[0][2]==b[1][1]&&b[0][0]==r[1][1]&&t[0][2]=='w')||(b[0][0]==b[1][1]&&t[0][2]==r[1][1]&&r[0][2]=='w')||(t[0][2]==b[1][1]&&r[0][2]==r[1][1]&&b[0][0]=='w'))
		{
			left(1);
			back('c');
			right(1);
			back('a');
			break;
		}
		right(1);
	}
	for(i=1;i<=4;i++)
	{
		if((b[0][2]==b[1][1]&&l[0][0]==l[1][1]&&t[0][0]=='w')||(l[0][0]==b[1][1]&&t[0][0]==l[1][1]&&b[0][2]=='w')||(t[0][0]==b[1][1]&&b[0][2]==l[1][1]&&l[0][0]=='w')||(b[0][2]==l[1][1]&&l[0][0]==b[1][1]&&t[0][0]=='w')||(l[0][0]==l[1][1]&&t[0][0]==b[1][1]&&b[0][2]=='w')||(t[0][0]==l[1][1]&&b[0][2]==b[1][1]&&l[0][0]=='w'))
		{
 			right(1);
			back('a');
			left(1);
			back('c');
			break;
		}
		right(1);
	}
}

//Rotate the corner pieces of bottom layer in its own position to complete bottom layer.
void complete_bot_layer()
{
	while(d[2][2]!='w')
	{
		lside('a');
		right(1);
		lside('c');
		left(1);
	}
	right(3);
	if(d[2][2]!='w')
		complete_bot_layer();
	else if(d[0][0]=='w'&&d[0][2]=='w'&&d[2][0]=='w'&&d[2][2]=='w')
	{
		while(f[2][1]!=f[1][1])
		{	right(3);}
		return;
	}
	else
	{
		right(3);
		complete_bot_layer();
	}
}	

//Turn the whole cube towards left.
void turnmain()
{	
	int flag=0,i,j;
	char *x,temp1[9],temp2[9];
	for(i=0;i<4;i++)	
	{	
		x=*(left1+i);
		for(j=0;j<9;j++)
		{	
			if(flag==0)
			{	
				temp1[j]=x[j];
				temp2[j]=x[j];
				continue;
			}
			else
			{
				temp1[j]=x[j];
				x[j]=temp2[j];
				temp2[j]=temp1[j];
			}
		}
		flag=1;	
	}	
	x=*(left1);
	for(j=0;j<9;j++)
	{
		x[j]=temp1[j];
	}
	//Shift elements of top face.
	t1=t[0][0];
	t[0][0]=t[2][0];
	t[2][0]=t[2][2];
	t[2][2]=t[0][2];
	t[0][2]=t1;
	t1=t[0][1];
	t[0][1]=t[1][0];
	t[1][0]=t[2][1];
	t[2][1]=t[1][2];
	t[1][2]=t1;		
	//Shift elements of bottom face.
	t1=d[0][0];
	d[0][0]=d[0][2];
	d[0][2]=d[2][2];
	d[2][2]=d[2][0];
	d[2][0]=t1;
	t1=d[0][1];
	d[0][1]=d[1][2];
	d[1][2]=d[2][1];
	d[2][1]=d[1][0];
	d[1][0]=t1;	
}

//Formula to bring pieces in the middle layer to the top layer.
void midtotop(char ch)
{
	if(ch=='l')
	{
		lside('a');
		right(1);
		lside('c');
		left(1);
		face('c');
		left(1);
		face('a');
	}
	else 
	{
		rside('c');
		left(1);
		rside('a');
		right(1);
		face('a');
		right(1);
		face('c');
	}
}
//Formula to bring pieces in top layer to middle layer.
void toptomid(char ch)
{
	if(ch=='r')
	{
		face('c');
		left(1);
		face('c');
		left(1);
		face('c');
		right(1);
		face('a');
		right(1);
		face('a');
	}	
	else
	{
		face('a');
		right(1);
		face('a');
		right(1);
		face('a');
		left(1);
		face('c');
		left(1);
		face('c');
	}
}

//Solve middle layer.
void middle()
{
	int i;
	if(f[1][0]!=f[1][1]&&l[1][2]!=l[1][1]&&f[1][0]!='y'&&l[1][2]!='y')
		midtotop('l');
	else if(f[1][2]!=f[1][1]&&r[1][0]!=r[1][1]&&f[1][2]!='y'&&r[1][0]!='y')
		midtotop('r');
	for(i=0;i<4;i++)
	{	
		if(f[0][1]==f[1][1]&&t[2][1]==r[1][1])
		{
			toptomid('r');
		}
		else if(f[0][1]==f[1][1]&&t[2][1]==l[1][1])
		{
			toptomid('l');
		}
		right(1);
	}
	turnmain();
	if(f[1][1]!=f[1][0]||f[1][1]!=f[1][2]||r[1][1]!=r[1][0]||r[1][1]!=r[1][2]||b[1][1]!=b[1][0]||b[1][1]!=b[1][2]||l[1][1]!=l[1][0]||l[1][1]!=l[1][2])
		middle();
}
//Formula-1 for top face.
void topplusform1()
{
		face('c');
		rside('c');
		left(1);
		rside('a');
		right(1);
		face('a');
}
//Formula-2 for top face.
void topplusform2()
{
	rside('c');
	left(1);
	rside('a');
	left(1);
	rside('c');
	left(1);
	left(1);
	rside('a');
}

//Create plus shape in the top face.
void topplus()
{	while(1)
	{
		if((t[0][1]==t[1][1]&&t[1][0]==t[1][1])||(t[0][1]==t[1][1]&&t[1][2]==t[1][1])||(t[1][2]==t[1][1]&&t[2][1]==t[1][1])||(t[2][1]==t[1][1]&&t[1][0]==t[1][1]))
			break;
		topplusform1();
	}
	while(1)
	{
		right(1);
		if(t[0][1]==t[1][1]&&t[1][0]==t[1][1])
			break;
	}
	topplusform1();	
	if(t[1][0]!=t[1][1]&&t[1][2]!=t[1][1])
		right(1);
	topplusform1();
	topflag=0;	
}

//Match middle edge pieces of top face.
void topplusmatch()
{
	if((b[0][1]==b[1][1]&&r[0][1]==r[1][1])||(r[0][1]==r[1][1]&&l[0][1]==l[1][1]))
		topplusform2();
	if((r[0][1]==r[1][1]&&f[0][1]==f[1][1])||(f[0][1]==f[1][1]&&b[0][1]==b[1][1]))
	{
		turnmain();
		turnmain();
		turnmain();
		topplusform2();
	}
	if((f[0][1]==f[1][1]&&l[0][1]==l[1][1]))
	{
		turnmain();
		turnmain();
		topplusform2();
	}
	if((l[0][1]==l[1][1]&&b[0][1]==b[1][1]))
	{
		turnmain();
		topplusform2();
	}
	right(1);
	if(f[0][1]==f[1][1]&&r[0][1]==r[1][1]&&b[0][1]==b[1][1]&&l[0][1]==l[1][1])
		return;
	else
		topplusmatch();
}

//Formula to bring corner pieces of top face to position.
void topcornerform()
{
	rside('c');
	right(1);
	lside('a');
	left(1);
	rside('a');
	right(1);
	lside('c');
	left(1);
	if(topflag2==1)
	{
		if((f[0][2]==f[1][1]&&r[0][0]==r[1][1]&&t[2][2]=='y')||(r[0][0]==f[1][1]&&t[2][2]==r[1][1]&&f[0][2]=='y')||(t[2][2]==f[1][1]&&f[0][2]==r[1][1]&&r[0][0]=='y')||(f[0][2]==r[1][1]&&r[0][0]==f[1][1]&&t[2][2]=='y')||(r[0][0]==r[1][1]&&t[2][2]==f[1][1]&&f[0][2]=='y')||(t[2][2]==r[1][1]&&f[0][2]==f[1][1]&&r[0][0]=='y'))
		{
			return;
		}
		else
			topcornerform();
		
	}
}

//Bring corner pieces of top face to position.
void topcorner()
{
	if((f[0][0]==f[1][1]&&l[0][2]==l[1][1]&&t[2][0]=='y')||(t[2][0]==f[1][1]&&f[0][0]==l[1][1]&&l[0][2]=='y')||(l[0][2]==f[1][1]&&t[2][0]==l[1][1]&&f[0][0]=='y')||(f[0][0]==l[1][1]&&l[0][2]==f[1][1]&&t[2][0]=='y')||(t[2][0]==l[1][1]&&f[0][0]==f[1][1]&&l[0][2]=='y')||(l[0][2]==l[1][1]&&t[2][0]==f[1][1]&&f[0][0]=='y'))
	{
		topcornerform();
		
		return;
		
	}
	if((f[0][2]==f[1][1]&&r[0][0]==r[1][1]&&t[2][2]=='y')||(r[0][0]==f[1][1]&&t[2][2]==r[1][1]&&f[0][2]=='y')||(t[2][2]==f[1][1]&&f[0][2]==r[1][1]&&r[0][0]=='y')||(f[0][2]==r[1][1]&&r[0][0]==f[1][1]&&t[2][2]=='y')||(r[0][0]==r[1][1]&&t[2][2]==f[1][1]&&f[0][2]=='y')||(t[2][2]==r[1][1]&&f[0][2]==f[1][1]&&r[0][0]=='y'))
	{
		turnmain();
		topflag2=1;
		topcornerform();
		return;
	}
	if((r[0][2]==r[1][1]&&b[0][0]==b[1][1]&&t[0][2]=='y')||(b[0][0]==r[1][1]&&t[0][2]==b[1][1]&&r[0][2]=='y')||(t[0][2]==r[1][1]&&r[0][2]==b[1][1]&&b[0][0]=='y')||(r[0][2]==b[1][1]&&b[0][0]==r[1][1]&&t[0][2]=='y')||(b[0][0]==b[1][1]&&t[0][2]==r[1][1]&&r[0][2]=='y')||(t[0][2]==b[1][1]&&r[0][2]==r[1][1]&&b[0][0]=='y'))
	{
		turnmain();
		turnmain();
		topflag2=1;
		topcornerform();
		return;
	}
	if((b[0][2]==b[1][1]&&l[0][0]==l[1][1]&&t[0][0]=='y')||(l[0][0]==b[1][1]&&t[0][0]==l[1][1]&&b[0][2]=='y')||(t[0][0]==b[1][1]&&b[0][2]==l[1][1]&&l[0][0]=='y')||(b[0][2]==l[1][1]&&l[0][0]==b[1][1]&&t[0][0]=='y')||(l[0][0]==l[1][1]&&t[0][0]==b[1][1]&&b[0][2]=='y')||(t[0][0]==l[1][1]&&b[0][2]==b[1][1]&&l[0][0]=='y'))
	{	turnmain();
		turnmain();
		turnmain();
		topflag2=1;
		topcornerform();
		return;
	}
	topcornerform();
	topcorner();
}

//Rotate corner pieces in top face in its own position to obtain solved cube.
void topfinal()
{
	while(t[2][2]!='y')
	{
		rside('a');
		left(3);
		rside('c');
		right(3);
	}
	if(t[0][0]!='y'||t[0][2]!='y'||t[2][0]!='y')
	{
		left(1);
		topfinal();
	}
	else
	{
		while(f[0][1]!=f[1][1])
			left(1);
		return;
	}
}

void main()
{
	printf("Initial\n");
	display();
	printf("oneplus\n\n");	
	oneplus();
	display();
	bringtotop();
	printf("bringtotop\n\n");
	display();
	bringtobot();
	printf("bringtobottom\n\n");
	display();
	complete_bot_layer();
	printf("cbl\n\n");
	display();
	middle();
	printf("middle\n\n");
	display();
	topplus();
	printf("topplus\n\n");
	display();
	topplusmatch();
	printf("topplusmatch\n\n");
	display();
	topcorner();
	printf("topcorner\n\n");
	display();
	topfinal();
	printf("topfinal\n\n");
	display();
}
