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
int topflag=0,topflag2=0,j=0;

char f[3][3]={'b','b','b','b','b','b','b','b','b'},r[3][3]={'r','r','r','r','r','r','r','r','r'},l[3][3]={'o','o','o','o','o','o','o','o','o'},t[3][3]={'y','y','y','y','y','y','y','y','y'},b[3][3]={'g','g','g','g','g','g','g','g','g'},d[3][3]={'w','w','w','w','w','w','w','w','w'};

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
//Function to bring all middle elements of bottom layer to its respective position.(Forms a "Plus" shape in d bottom face.)
void oneplus()
{
	int i,j;
	char color,*x;
	//Check for d[1][1] in top face.
	if(t[0][1]==d[1][1])
	{
		back('c');    printf("B ");
		back('c');    printf("B ");
		goto label;
	}
	else if(t[1][0]==d[1][1])
	{
		lside('c');    printf("L ");
		lside('c');    printf("L ");
		goto label;
	}
	else if(t[2][1]==d[1][1])
	{
		face('c');    printf("F ");
		face('c');    printf("F ");
		goto label;
	}
	else if(t[1][2]==d[1][1])
	{
		rside('c');    printf("R ");
		rside('c');    printf("R ");
		goto label;
	}
	
	//Check for d[1][1] in middle layer.
	if(f[1][0]==d[1][1])
	{
		lside('c');	printf("L ");
		goto label;
	}
	else if(f[1][2]==d[1][1])
	{
		rside('a');	printf("R' ");
			goto label;
	}
	else if(r[1][0]==d[1][1])
	{
		face('c');      printf("F ");
		goto label;
	}
	else if(r[1][2]==d[1][1])
	{
		back('a');      printf("B' ");
		goto label;
	}
	else if(b[1][0]==d[1][1])
	{
		rside('c');     printf("R ");
		goto label;
	}
	else if(b[1][2]==d[1][1])
	{
		lside('a');     printf("L' ");
		goto label;
	}
	else if(l[1][0]==d[1][1])
	{
		back('c');     printf("B ");
		goto label;
	}
	else if(l[1][2]==d[1][1])
	{
		face('a');     printf("F' ");
		goto label;
	}
	
	//Check for d[1][1] in top layer of vertical faces.
	if(f[0][1]==d[1][1])
	{
		face('c');    printf("F ");
		face('c');    printf("F ");
	}
	else if(r[0][1]==d[1][1])
	{
		rside('c');    printf("R ");
		rside('c');    printf("R ");
	}	
	else if(b[0][1]==d[1][1])
	{
		back('c');    printf("B ");
		back('c');    printf("B ");
	}
	else if(l[0][1]==d[1][1])
	{
		lside('c');    printf("L ");
		lside('c');    printf("L ");
	}
	//Check for d[1][1] in bottom layer  of vertical faces.
	if(f[2][1]==d[1][1])
	{
		face('a');    printf("F' ");
		rside('a');   printf("R' ");
		face('c');    printf("F ");
	}
	else if(r[2][1]==d[1][1])
	{
		rside('a');    printf("R' ");
		back('a');     printf("B' ");
		rside('c');    printf("R ");
	}
	else if(b[2][1]==d[1][1])
	{
		back('a');    printf("B' ");
		lside('a');   printf("L' ");
		back('c');    printf("B ");
	}
	else if(l[2][1]==d[1][1])
	{
		lside('a');    printf("L' ");
		face('a');     printf("F' ");
		lside('c');    printf("L ");
	}
	
	//check for d[1][1] in middle positions of bottom face and bring it to its respective position.
	label:{
	 if(d[0][1]==d[1][1]&&b[2][1]!=b[1][1])
	{
		color=b[2][1];
		//Bring the element to the top.
		back('c');    printf("B ");
		back('c');    printf("B ");
		j=2;
		i=2;
		x=*(horizon+i);
		//Find its matching face
		while(x[0]!=color)
		{
			right(1);    printf("U' ");
			i++;
			if(i==j+4)
				break;
			x=*(horizon+i);
		}
		//Bring it down.
		if(i==j+1)
		{
			lside('c');    printf("L ");
			lside('c');    printf("L ");
		}
		else if(i==j+2)
		{
			face('c');    printf("F ");
			face('c');    printf("F ");
		}
		else if(i==j+3)
		{
			rside('c');    printf("R ");
			rside('c');    printf("R ");
		}
	}
	else if(d[1][0]==d[1][1]&&r[2][1]!=r[1][1])
	{
		color=r[2][1];
		rside('c');    printf("R ");
		rside('c');    printf("R ");
		j=1;
		i=1;
		x=*(horizon+i);
		while(x[0]!=color)
		{
			right(1);    printf("U' ");
			i++;
			if(i==j+4)
				break;
			x=*(horizon+i);
		}
		if(i==j+1)
		{
			back('c');    printf("B ");
			back('c');    printf("B ");
		}
		else if(i==j+2)
		{
			lside('c');    printf("L ");
			lside('c');    printf("L ");
		}
		else if(i==j+3)
		{
			face('c');    printf("F ");
			face('c');    printf("F ");
		}
	}
	else if(d[2][1]==d[1][1]&&f[2][1]!=f[1][1])
	{
		color=f[2][1];
		face('c');    printf("F ");
		face('c');    printf("F ");
		j=0;
		i=0;
		x=*(horizon+i);
		while(x[0]!=color)
		{
			right(1);    printf("U' ");
			i++;
			if(i==j+4)
				break;
			x=*(horizon+i);
		}
		if(i==j+1)
		{
			rside('c');    printf("R ");
			rside('c');    printf("R ");
		
		}
		else if(i==j+2)
		{
			back('c');    printf("B ");
			back('c');    printf("B ");
		}
		else if(i==j+3)
		{
			lside('c');    printf("L ");
			lside('c');    printf("L ");
		}
	}
	else if(d[1][2]==d[1][1]&&l[2][1]!=l[1][1])
	{
		color=l[2][1];
		lside('c');    printf("L ");
		lside('c');    printf("L ");
		j=3;
		i=3;
		x=*(horizon+i);
		while(x[0]!=color)
		{
			right(1);    printf("U' ");
			i++;
			if(i==j+4)
				break;
			x=*(horizon+i);
		}
		if(i==j+1)
		{
			face('c');    printf("F ");
			face('c');    printf("F ");
		}
		else if(i==j+2)
		{
			rside('c');    printf("R ");
			rside('c');    printf("R ");
		}
		else if(i==j+3)
		{
			back('c');    printf("B ");
			back('c');    printf("B ");
		}
	}
	if(d[0][1]!=d[1][1]||d[1][0]!=d[1][1]||d[2][1]!=d[1][1]||d[1][2]!=d[1][1])
	{
		oneplus();
	}
	}
}
//Function to bring all corner pieces of bottom layer to the top layer
void bringtotop()
{
	if(d[0][0]==d[1][1]||b[2][0]==d[1][1]||r[2][2]==d[1][1])
	{
		while(1)
		{
			if(t[0][2]==d[1][1]||r[0][2]==d[1][1]||b[0][0]==d[1][1])	
				right(1);
			else
				break;
		}
		rside('a');    printf("R' ");
		right(1);      printf("U' ");
		rside('c');    printf("R ");
	}
	if(d[0][2]==d[1][1]||l[2][0]==d[1][1]||b[2][2]==d[1][1])
	{
		while(1)
		{
			if(t[0][0]==d[1][1]||b[0][2]==d[1][1]||l[0][0]==d[1][1])	
				right(1);
			else
				break;
		}
		back('a');    printf("B' ");
		right(1);     printf("U' ");
		back('c');    printf("B "); 
	}
	if(d[2][0]==d[1][1]||r[2][0]==d[1][1]||f[2][2]==d[1][1])
	{
		while(1)
		{
			if(t[2][0]==d[1][1]||l[0][2]==d[1][1]||f[0][0]==d[1][1])	
				right(1);
			else
				break;
		}
		rside('c');    printf("R ");
		right(1);      printf("U' ");
		rside('a');    printf("R' ");
	}
	if(d[2][2]==d[1][1]||l[2][2]==d[1][1]||f[2][0]==d[1][1])
	{	while(1)
		{
			if(t[2][0]==d[1][1]||f[0][0]==d[1][1]||l[0][2]==d[1][1])
				right(1);
			else
				break;
		}
		lside('a');    printf("L' ");
		right(1);      printf("U' ");
		lside('c');    printf("L ");
	}
	if((t[0][0]==d[1][1]||b[0][2]==d[1][1]||l[0][0]==d[1][1])&&(t[0][2]==d[1][1]||b[0][0]==d[1][1]||r[0][2]==d[1][1])&&(t[2][0]==d[1][1]||f[0][0]==d[1][1]||l[0][2]==d[1][1])&&(t[2][2]==d[1][1]||f[0][2]==d[1][1]||r[0][0]==d[1][1]))
		return;
	else
		bringtotop();
	
}
	
//Function to bring all corner pieces of bottom layer to respective positions in bottom layer.
void bringtobot()
{
	int i;
	for(i=1;i<=4;i++)
	{	
		if((f[0][0]==f[1][1]&&l[0][2]==l[1][1]&&t[2][0]==d[1][1])||(t[2][0]==f[1][1]&&f[0][0]==l[1][1]&&l[0][2]==d[1][1])||(l[0][2]==f[1][1]&&t[2][0]==l[1][1]&&f[0][0]==d[1][1])||(f[0][0]==l[1][1]&&l[0][2]==f[1][1]&&t[2][0]==d[1][1])||(t[2][0]==l[1][1]&&f[0][0]==f[1][1]&&l[0][2]==d[1][1])||(l[0][2]==l[1][1]&&t[2][0]==f[1][1]&&f[0][0]==d[1][1]))
		{
			right(1);      printf("U' ");
			lside('a');    printf("L' ");
			left(1);       printf("U ");
			lside('c');    printf("L ");
			break;
		}
		right(1);    printf("U' ");
	}
	for(i=1;i<=4;i++)
	{	
		if((f[0][2]==f[1][1]&&r[0][0]==r[1][1]&&t[2][2]==d[1][1])||(r[0][0]==f[1][1]&&t[2][2]==r[1][1]&&f[0][2]==d[1][1])||(t[2][2]==f[1][1]&&f[0][2]==r[1][1]&&r[0][0]==d[1][1])||(f[0][2]==r[1][1]&&r[0][0]==f[1][1]&&t[2][2]==d[1][1])||(r[0][0]==r[1][1]&&t[2][2]==f[1][1]&&f[0][2]==d[1][1])||(t[2][2]==r[1][1]&&f[0][2]==f[1][1]&&r[0][0]==d[1][1]))
		{
			left(1);       printf("U ");
			rside('c');    printf("R ");
			right(1);      printf("U' ");
			rside('a');    printf("R' ");
			break;
		}
		right(1);    printf("U' ");
	}
	for(i=1;i<=4;i++)
	{
		if((r[0][2]==r[1][1]&&b[0][0]==b[1][1]&&t[0][2]==d[1][1])||(b[0][0]==r[1][1]&&t[0][2]==b[1][1]&&r[0][2]==d[1][1])||(t[0][2]==r[1][1]&&r[0][2]==b[1][1]&&b[0][0]==d[1][1])||(r[0][2]==b[1][1]&&b[0][0]==r[1][1]&&t[0][2]==d[1][1])||(b[0][0]==b[1][1]&&t[0][2]==r[1][1]&&r[0][2]==d[1][1])||(t[0][2]==b[1][1]&&r[0][2]==r[1][1]&&b[0][0]==d[1][1]))
		{
			left(1);      printf("U ");
			back('c');    printf("B ");
			right(1);     printf("U' ");
			back('a');    printf("B' ");
			break;
		}
		right(1);    printf("U' ");
	}
	for(i=1;i<=4;i++)
	{
		if((b[0][2]==b[1][1]&&l[0][0]==l[1][1]&&t[0][0]==d[1][1])||(l[0][0]==b[1][1]&&t[0][0]==l[1][1]&&b[0][2]==d[1][1])||(t[0][0]==b[1][1]&&b[0][2]==l[1][1]&&l[0][0]==d[1][1])||(b[0][2]==l[1][1]&&l[0][0]==b[1][1]&&t[0][0]==d[1][1])||(l[0][0]==l[1][1]&&t[0][0]==b[1][1]&&b[0][2]==d[1][1])||(t[0][0]==l[1][1]&&b[0][2]==b[1][1]&&l[0][0]==d[1][1]))
		{
 			right(1);     printf("U' ");
			back('a');    printf("B' ");
			left(1);      printf("U ");
			back('c');    printf("B ");
			break;
		}
		right(1);    printf("U' ");
	}
}

//Rotate the corner pieces of bottom layer in its own position to complete bottom layer.
void complete_bot_layer()
{
	while(d[2][2]!=d[1][1])
	{
		lside('a');    printf("L' ");
		right(1);      printf("U' ");
		lside('c');    printf("L ");
		left(1);       printf("U ");
	}
	right(3);    printf("D ");
	if(d[2][2]!=d[1][1])
		complete_bot_layer();
	else if(d[0][0]==d[1][1]&&d[0][2]==d[1][1]&&d[2][0]==d[1][1]&&d[2][2]==d[1][1])
	{
		while(f[2][1]!=f[1][1])
		{	right(3);    printf("D ");}
		return;
	}
	else
	{
		right(3);    printf("D ");
		complete_bot_layer();
	}
}	

//Formula to bring pieces in the middle layer to the top layer.
void midtotop(char ch)
{	
	if(ch=='l')
	{	
		printf("\nSteps to bring middle left piece(of front face) to the top layer\n");
		lside('a');    printf("L' ");
		right(1);      printf("U' ");
		lside('c');    printf("L ");
		left(1);       printf("U ");
		face('c');     printf("F ");
		left(1);       printf("U ");
		face('a');     printf("F' ");
	}
	else 
	{	
		printf("\nSteps to bring middle right piece (of front face) to the top layer\n");
		rside('c');    printf("R ");
		left(1);       printf("U ");
		rside('a');    printf("R' ");
		right(1);      printf("U' ");
		face('a');     printf("F' ");
		right(1);      printf("U' ");
		face('c');     printf("F ");
	}
}
//Formula to bring pieces in top layer to middle layer.
void toptomid(char ch)
{
	if(ch=='r')
	{
		printf("\nSteps to bring top middle piece to middle right position(of front face)\n"); 
		face('c');    printf("F ");
		left(1);      printf("U ");
		face('c');    printf("F ");
		left(1);      printf("U ");
		face('c');    printf("F ");
		right(1);     printf("U' ");
		face('a');    printf("F' ");
		right(1);     printf("U' ");
		face('a');    printf("F' ");
	}	
	else
	{
		printf("\nSteps to bring top middle piece to middle left position(of front face)\n"); 
		face('a');    printf("F' ");
		right(1);     printf("U' ");
		face('a');    printf("F' ");
		right(1);     printf("U' ");
		face('a');    printf("F' ");
		left(1);      printf("U ");
		face('c');    printf("F ");
		left(1);      printf("U ");
		face('c');    printf("F ");
	}
}

//Solve middle layer.
void middle()
{
	int i;
	if((f[1][0]!=f[1][1]||l[1][2]!=l[1][1])&&f[1][0]!=t[1][1]&&l[1][2]!=t[1][1])
		midtotop('l');
	else if((f[1][2]!=f[1][1]||r[1][0]!=r[1][1])&&f[1][2]!=t[1][1]&&r[1][0]!=t[1][1])
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
		right(1);    printf("U' ");
	}
	turnmain();    printf("Turn main ");
	if(f[1][1]!=f[1][0]||f[1][1]!=f[1][2]||r[1][1]!=r[1][0]||r[1][1]!=r[1][2]||b[1][1]!=b[1][0]||b[1][1]!=b[1][2]||l[1][1]!=l[1][0]||l[1][1]!=l[1][2])
		middle();
}
//Formula-1 for top face.
void topplusform1()
{
		face('c');     printf("F ");
		rside('c');    printf("R ");
		left(1);       printf("U ");
		rside('a');    printf("R' ");
		right(1);      printf("U' ");
		face('a');     printf("F' ");
}
//Formula-2 for top face.
void topplusform2()
{
	rside('c');    printf("R ");
	left(1);       printf("U ");
	rside('a');    printf("R' ");
	left(1);       printf("U ");
	rside('c');    printf("R ");
	left(1);       printf("U ");
	left(1);       printf("U ");
	rside('a');    printf("R' ");
}

//Create plus shape in the top face.
void topplus()
{
	printf("\nSteps to form a 'L' shape in the top layer\n");
	while(1)
	{
		if((t[0][1]==t[1][1]&&t[1][0]==t[1][1]&&t[1][2]!=t[1][1]&&t[2][1]!=t[1][1])||(t[0][1]==t[1][1]&&t[1][2]==t[1][1]&&t[1][0]!=t[1][1]&&t[2][1]!=t[1][1])||(t[1][2]==t[1][1]&&t[2][1]==t[1][1]&&t[1][0]!=t[1][1]&&t[0][1]!=t[1][1])||(t[2][1]==t[1][1]&&t[1][0]==t[1][1]&&t[1][2]!=t[1][1]&&t[0][1]!=t[1][1]))
			break;
		topplusform1();
	}
	while(1)
	{
		right(1);    printf("U' ");
		if(t[0][1]==t[1][1]&&t[1][0]==t[1][1])
			break;
	}
	display();
	printf("\nSteps to form a horizontal line in top phase\n");
	topplusform1();
	display();	
	if(t[1][0]!=t[1][1]&&t[1][2]!=t[1][1])
		right(1);    printf("U' ");
	printf("\nSteps to form a plus shape in top face\n");
	topplusform1();
	display();
	topflag=0;	
}

//Match middle edge pieces of top face.
void topplusmatch()
{ 
	if((b[0][1]==b[1][1]&&r[0][1]==r[1][1])||(r[0][1]==r[1][1]&&l[0][1]==l[1][1]))
	{	
		topplusform2();
	}
	if((r[0][1]==r[1][1]&&f[0][1]==f[1][1])||(f[0][1]==f[1][1]&&b[0][1]==b[1][1]))
	{
		turnmain();    printf("Turn main ");
		turnmain();    printf("Turn main ");
		turnmain();    printf("Turn main ");
		topplusform2();
	}
	if((f[0][1]==f[1][1]&&l[0][1]==l[1][1]))
	{
		turnmain();    printf("Turn main ");
		turnmain();    printf("Turn main ");
		topplusform2();
	}
	if((l[0][1]==l[1][1]&&b[0][1]==b[1][1]))
	{
		turnmain();    printf("Turn main ");
		topplusform2();
	}
	right(1);    printf("U' ");
	if(f[0][1]==f[1][1]&&r[0][1]==r[1][1]&&b[0][1]==b[1][1]&&l[0][1]==l[1][1])
		return;
	else
		topplusmatch();
}

//Formula to bring corner pieces of top face to position.
void topcornerform()
{
	rside('c');    printf("R ");
	right(1);      printf("U' ");
	lside('a');    printf("L' ");
	left(1);       printf("U ");
	rside('a');    printf("R' ");
	right(1);      printf("U' ");
	lside('c');    printf("L ");
	left(1);       printf("U ");
	if(topflag2==1)
	{
		if((f[0][2]==f[1][1]&&r[0][0]==r[1][1]&&t[2][2]==t[1][1])||(r[0][0]==f[1][1]&&t[2][2]==r[1][1]&&f[0][2]==t[1][1])||(t[2][2]==f[1][1]&&f[0][2]==r[1][1]&&r[0][0]==t[1][1])||(f[0][2]==r[1][1]&&r[0][0]==f[1][1]&&t[2][2]==t[1][1])||(r[0][0]==r[1][1]&&t[2][2]==f[1][1]&&f[0][2]==t[1][1])||(t[2][2]==r[1][1]&&f[0][2]==f[1][1]&&r[0][0]==t[1][1]))
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
	if((f[0][0]==f[1][1]&&l[0][2]==l[1][1]&&t[2][0]==t[1][1])||(t[2][0]==f[1][1]&&f[0][0]==l[1][1]&&l[0][2]==t[1][1])||(l[0][2]==f[1][1]&&t[2][0]==l[1][1]&&f[0][0]==t[1][1])||(f[0][0]==l[1][1]&&l[0][2]==f[1][1]&&t[2][0]==t[1][1])||(t[2][0]==l[1][1]&&f[0][0]==f[1][1]&&l[0][2]==t[1][1])||(l[0][2]==l[1][1]&&t[2][0]==f[1][1]&&f[0][0]==t[1][1]))
	{
		while(1)
		{
			topcornerform();	
			if((f[0][2]==f[1][1]&&r[0][0]==r[1][1]&&t[2][2]==t[1][1])||(r[0][0]==f[1][1]&&t[2][2]==r[1][1]&&f[0][2]==t[1][1])||(t[2][2]==f[1][1]&&f[0][2]==r[1][1]&&r[0][0]==t[1][1])||(f[0][2]==r[1][1]&&r[0][0]==f[1][1]&&t[2][2]==t[1][1])||(r[0][0]==r[1][1]&&t[2][2]==f[1][1]&&f[0][2]==t[1][1])||(t[2][2]==r[1][1]&&f[0][2]==f[1][1]&&r[0][0]==t[1][1]))
				break;
		}
		return;
		
	}
	if((f[0][2]==f[1][1]&&r[0][0]==r[1][1]&&t[2][2]==t[1][1])||(r[0][0]==f[1][1]&&t[2][2]==r[1][1]&&f[0][2]==t[1][1])||(t[2][2]==f[1][1]&&f[0][2]==r[1][1]&&r[0][0]==t[1][1])||(f[0][2]==r[1][1]&&r[0][0]==f[1][1]&&t[2][2]==t[1][1])||(r[0][0]==r[1][1]&&t[2][2]==f[1][1]&&f[0][2]==t[1][1])||(t[2][2]==r[1][1]&&f[0][2]==f[1][1]&&r[0][0]==t[1][1]))
	{
		turnmain();    printf("Turn main ");
		topflag2=1;
		while(1)
		{
			topcornerform();	
			if((f[0][2]==f[1][1]&&r[0][0]==r[1][1]&&t[2][2]==t[1][1])||(r[0][0]==f[1][1]&&t[2][2]==r[1][1]&&f[0][2]==t[1][1])||(t[2][2]==f[1][1]&&f[0][2]==r[1][1]&&r[0][0]==t[1][1])||(f[0][2]==r[1][1]&&r[0][0]==f[1][1]&&t[2][2]==t[1][1])||(r[0][0]==r[1][1]&&t[2][2]==f[1][1]&&f[0][2]==t[1][1])||(t[2][2]==r[1][1]&&f[0][2]==f[1][1]&&r[0][0]==t[1][1]))
				break;
		}
		return;
	}
	if((r[0][2]==r[1][1]&&b[0][0]==b[1][1]&&t[0][2]==t[1][1])||(b[0][0]==r[1][1]&&t[0][2]==b[1][1]&&r[0][2]==t[1][1])||(t[0][2]==r[1][1]&&r[0][2]==b[1][1]&&b[0][0]==t[1][1])||(r[0][2]==b[1][1]&&b[0][0]==r[1][1]&&t[0][2]==t[1][1])||(b[0][0]==b[1][1]&&t[0][2]==r[1][1]&&r[0][2]==t[1][1])||(t[0][2]==b[1][1]&&r[0][2]==r[1][1]&&b[0][0]==t[1][1]))
	{
		turnmain();    printf("Turn main ");
		turnmain();    printf("Turn main ");
		topflag2=1;
		while(1)
		{
			topcornerform();	
			if((f[0][2]==f[1][1]&&r[0][0]==r[1][1]&&t[2][2]==t[1][1])||(r[0][0]==f[1][1]&&t[2][2]==r[1][1]&&f[0][2]==t[1][1])||(t[2][2]==f[1][1]&&f[0][2]==r[1][1]&&r[0][0]==t[1][1])||(f[0][2]==r[1][1]&&r[0][0]==f[1][1]&&t[2][2]==t[1][1])||(r[0][0]==r[1][1]&&t[2][2]==f[1][1]&&f[0][2]==t[1][1])||(t[2][2]==r[1][1]&&f[0][2]==f[1][1]&&r[0][0]==t[1][1]))
				break;
		}
		return;
	}
	if((b[0][2]==b[1][1]&&l[0][0]==l[1][1]&&t[0][0]==t[1][1])||(l[0][0]==b[1][1]&&t[0][0]==l[1][1]&&b[0][2]==t[1][1])||(t[0][0]==b[1][1]&&b[0][2]==l[1][1]&&l[0][0]==t[1][1])||(b[0][2]==l[1][1]&&l[0][0]==b[1][1]&&t[0][0]==t[1][1])||(l[0][0]==l[1][1]&&t[0][0]==b[1][1]&&b[0][2]==t[1][1])||(t[0][0]==l[1][1]&&b[0][2]==b[1][1]&&l[0][0]==t[1][1]))
	{	turnmain();    printf("Turn main ");
		turnmain();    printf("Turn main ");
		turnmain();    printf("Turn main ");
		topflag2=1;
		while(1)
		{
			topcornerform();	
			if((f[0][2]==f[1][1]&&r[0][0]==r[1][1]&&t[2][2]==t[1][1])||(r[0][0]==f[1][1]&&t[2][2]==r[1][1]&&f[0][2]==t[1][1])||(t[2][2]==f[1][1]&&f[0][2]==r[1][1]&&r[0][0]==t[1][1])||(f[0][2]==r[1][1]&&r[0][0]==f[1][1]&&t[2][2]==t[1][1])||(r[0][0]==r[1][1]&&t[2][2]==f[1][1]&&f[0][2]==t[1][1])||(t[2][2]==r[1][1]&&f[0][2]==f[1][1]&&r[0][0]==t[1][1]))
				break;
		}
		return;
	}
	topcornerform();
	topcorner();
}

//Rotate corner pieces in top face in its own position to obtain solved cube.
void topfinal()
{
	while(t[2][2]!=t[1][1])
	{
		rside('a');    printf("R' ");
		left(3);       printf("D' ");
		rside('c');    printf("R ");
		right(3);      printf("D ");
	}
	if(t[0][0]!=t[1][1]||t[0][2]!=t[1][1]||t[2][0]!=t[1][1])
	{
		left(1);    printf("U ");
		topfinal();
	}
	else
	{
		while(f[0][1]!=f[1][1])
		{
			left(1);    printf("U ");
		}
		return;
	}
}

//Function to enter all colors manually
void manual()
{	
	int i,k;
	char *m;
	m=*(cube);
	//here, k:number of faces
	for(k=0;k<6;k++)
	{
		m=*(cube+k);
		if(k==0)
			printf("Enter elements of Front face:\n");
		else if(k==1)
			printf("Enter elements of Right face:\n");
		else if(k==2)
			printf("Enter elements of Back face:\n");
		else if(k==3)
			printf("Enter elements of Left face:\n");
		else if(k==4)
			printf("Enter elements of Top face:\n");
		else if(k==5)
			printf("Enter elements of Bottom face:\n");	
		for(i=0;i<9;i++)
		{	
			EnterChar: scanf("%c",&m[i]);
			if (m[i] == '\n')
				goto EnterChar;
		}
	}
	printf("\n");
	display();
}

//Function to jumble a solved cube in the required way

void Jumble()
{
	int n;
	display();
	while(1)
	{
		printf("Enter option\n");
		printf("1.rotate first row right\n");
		printf("2.rotate third row right\n");
		printf("3.rotate first row left\n");
		printf("4.rotate third row left\n");
		printf("5.rotate right face clockwise\n");
		printf("6.rotate right face antclockwise\n");
		printf("7.rotate left face clockwise\n");
		printf("8.rotate left face antclockwise\n");
		printf("9.rotate front face clockwise\n");
		printf("10.rotate front face antclockwise\n");
		printf("11.rotate back face clockwise\n");
		printf("12.rotate back face antclockwise\n");
		printf("0. Stop\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				right(1);
				display();
				break;
			case 2:
				right(3);
				display();
				break;
			case 3:
				left(1);
				display();
				break;
			case 4:
				left(3);
				display();
				break;
			case 5:
				rside('c');
				display();
				break;
			case 6:	
				rside('a');
				display();
				break;
			case 7:
				lside('c');
				display();
				break;
			case 8:
				lside('a');
				display();
				break;
			case 9:
				face('c');
				display();
				break;
			case 10:
				face('a');
				display();
				break;
			case 11:
				back('c');
				display();
				break;
			case 12:
				back('a');
				display();
				break;
			case 0:
				printf("Initial\n");
				display();
				return;
			default:
				printf("Enter valid option");
				break;
		}
	}
}

//Function to randomly shuffle the cube.
void Random()
{
	int i=0,option;
	time_t t;
	// Declare random number generator 
	srand((unsigned) time(&t));
	//Call predefined moves depending on random integer.
	while(i<12)
	{
		option=rand() % 11;
		switch(option)
		{
			case 0:
				right(1);
				break;
			case 1:
				right(3);
				break;
			case 2:
				left(1);
				break;
			case 3:
				left(3);
				break;
			case 4:
				rside('c');
				break;
			case 5:
				rside('a');
				break;
			case 6:
				lside('c');
				break;
			case 7:
				lside('a');
				break;
			case 8:
				face('c');
				break;
			case 9:
				face('a');
				break;
			case 10:
				back('c');
				break;
			case 11:
				back('a');
				break;
		}
		i++;
	}
	display();
}

//Input function.
void input()
{
	int n;
	again: printf("Enter option\n1.Enter elements manually\n2.Jumble the Cube\n3.Random Cube generator\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			manual();
			break;
		case 2:
			Jumble();
			break;
		case 3:
			Random();
			break;
		default :
			printf("Invalid option\n");
			goto again;
	}
}

void main()
{
	//int choice;
	//newcube:
	//{
		input();
		printf("\nSteps to bring all middle pieces of bottom face to their respective positions in the bottom layer\n");
		oneplus();
		printf("\nAfter forming plus in the bottom layer:\n\n");	
		display();
		printf("\nSteps to bring corner pieces of bottom face to top layer\n");
		bringtotop();
		printf("\nAfter bringing all corner pieces of bottom face to the top layer:\n\n");
		display();
		printf("\nSteps to bring all corner pieces of bottom face to their respective positions in the bottom layer\n");
		bringtobot();
		printf("\nAfter bringing all corner pieces of bottom layer to their respective position:\n\n");
		display();
		printf("\nSteps to rotate corner pieces of bottom face in its own position so as to finish bottom layer\n");	
		complete_bot_layer();
		printf("\nAfter completing bottom layer:\n\n");
		display();
		printf("\nSteps to solve middle layer\n");
		middle();
		printf("\nAfter completing middle layer:\n\n");
		display();
		topplus();
		printf("\nAfter forming plus shape in the top layer\n\n");
		display();
		topplusmatch();
		printf("\nAfter bringing middle pieces of top layer to their respective positions:\n\n");
		display();
		printf("\nSteps to bring corner pieces of top layer to their respective positions:\n");
		topcorner();
		printf("\nAfter bringing corner pieces of top layer to their respective positions:\n\n");
		display();
		printf("Steps to complete the top layer:\n");
		topfinal();
		printf("\nThe solved cube:\n\n");
		display();
	//}
	//printf("Enter 1 to solve another cube and 2 to exit.\n");
	//scanf("%d",&choice);
	//if(choice==1)
	//	goto newcube;
}
