//#include<cstdio>
#include<sstream>
#include<iostream>

using namespace std;
struct coord3d{
	float x,y,z;
	coord3d(float x_, float y_, float z_)
	{
		x=x_;
		y=y_;
		z=z_;
	}
	coord3d()
	{
		x=0;
		y=0;
		z=0;
	}
};

coord3d vertice, normal;
int facenum,face[4];

void getFace(int (&f)[4], string s)
{
	int a,b,c,d;
	int n;
	sscanf(s.c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&n,&b,&n,&c,&n,&d,&n);
	facenum=n;
	face[0]=a;
	face[1]=b;
	face[2]=c;
	face[3]=d;
}


coord3d getVertex(string s)
{
	stringstream saved;
	saved<<s;
	char c;
	float x,y,z;
	saved>>c>>x>>y>>z;
	coord3d tmp=coord3d(x,y,z);
	return tmp;	
}

coord3d getNormal(string s)
{
	stringstream saved;
	saved<<s;
	string c;
	float x,y,z;
	saved>>c>>x>>y>>z;
	coord3d tmp=coord3d(x,y,z);
	return tmp;	
}



int main()
{
	
	vertice=getVertex("v 1.000000 -1.000000 -1.000000");
	normal=getNormal("vn 0.0000 0.0000 -1.0000");
	getFace(face,"f 1//3 5//3 6//3 2//3");
	return 0;
}
