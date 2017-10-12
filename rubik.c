#include<stdio.h>
#include<stdlib.h>

int i,j,k;
char t1,t2,t3;
char f[3][3]={'o','o','o','o','o','o','o','o','o'},r[3][3]={'g','g','g','g','g','g','g','b','g'},l[3][3]={'b','b','b','b','b','b','b','g','b'},t[3][3]={'y','y','y','y','y','y','y','y','y'},b[3][3]={'r','r','r','r','r','r','r','r','r'},d[3][3]={'w','w','w','w','w','w','w','w','w'};

//char f[3][3]={'a','b','c','d','e','f','g','h','i'},r[3][3]={'q','w','e','r','t','y','u','i','o'},l[3][3]={'a','s','d','f','g','h','j','k','l'},t[3][3]={'z','x','c','v','b','n','m','q','w'},b[3][3]={'r','f','h','r','c','b','n','w','g'},d[3][3]={'q','r','e','w','i','s','j','j','r'};

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
char *backc[12]={&t[0][2],&l[0][0],&d[0][2],&r[2][2],&t[0][1],&l[1][0],&d[0][1],&r[1][2],&t[0][0],&l[2][0],&d[0][2],&r[0][2]};
char *backa[12]={&t[0][2],&r[2][2],&d[0][2],&l[0][0],&t[0][1],&r[1][2],&d[0][1],&l[1][0],&t[0][0],&r[0][2],&d[0][2],&l[2][0]};
char *cube[6]={&f[0][0],&r[0][0],&b[0][0],&l[0][0],&t[0][0],&d[0][0]};

//Display all elements.
void display()
{
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
			printf("%c ",m[i]);
		if(i%3==2)
			printf("\n");
		}
		printf("\n");
	}
}

//Rotate horizontally towards right(either first or third row)
void right(int row)
{
	int pos,flag=0;
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

//Rotate horizontally towards right(either first or third row)
void left(int row)
{
	int pos,flag=0;
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
	char temp1,temp2,*x,**y;
	if(ch=='c'||ch=='C')
	{
		y=&(rs);
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
		y=&(rsa);
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
	char temp1,temp2,*x,**y;
	if(ch=='c'||ch=='C')
	{
		y=&(ls);
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
		y=&(lsa);
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
		y=&(facec);
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
		y=&(facea);
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
	char temp1,temp2,*x,**y;
	if(ch=='c'||ch=='C')
	{
		y=&(backc);
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
		y=&(backa);
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
//Function to bring all middle white elements to its respective position.(Forms a "Plus" shape in d bottom(white) face.
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
	
	//check for 'w' in bottom face and bring it to its respective position.
	label:{
	 if(d[0][1]=='w'&&b[2][1]!=b[1][1])
	{
		color=b[2][1];
		back('c');
		back('c');
		j=2;
		i=2;
		x=*(horizon+i);
		while(x[0]!=color)
		{
			right(1);
			i++;
			if(i==j+4)
				break;
			x=*(horizon+i);
			printf("\n%d\n",i);
			display();
			printf("\n\n");
		}
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
		printf("\n\n");
		display();
		printf("\n\n");
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
		printf("adgadg");
		oneplus();
	}
	}
}

	
void main()
{
	display();
	oneplus();
	printf("\n\n");
	display();
}
