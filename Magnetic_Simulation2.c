//magnetic simulation

//直線電流でのテスト

/**基本情報**/
/*単位はメートル[m]*/

#include<stdio.h>
#include<math.h>

#define 	dl 	0.01 //微小長さ
#define 	I 	5	 //電流の大きさ

typedef struct MAG_TYPE{
	double x;
	double y;
	double z;
}node_type;

double calc_angle(node_type A,node_type B);

int main(void)
{
	double H,dH,r,angle;//微小磁界・測定点までの長さ・角度
	int i,j,k,l;
	node_type A,B;//磁界の発生源,測定点

	A.x = 0.0;
	A.y = dl;
	A.z = 0.0;

	B.x = 3.0;
	B.y = 3.0;
	B.z = 0.0;

	angle = calc_angle(A,B);
	printf("angle:%lf\n",(angle* 180.0/M_PI));

	r = sqrt( (B.x-A.x)*(B.x-A.x) + (B.y-A.y)*(B.x-A.y) ); //二点間の距離の公式

	dH = (I * dl * sin(angle)) / (4*M_PI*r*r);
	printf("dH = %lf\n",dH);

	return 0;
}

double calc_angle(node_type A,node_type B)
{
	double angle = 0.0;
	double sizeA,sizeB,cache,cosX;

	/*A.x 	-= A.x;
	A.y 	-= A.y;
	A.z 	-= A.z;

	B.x 	-= A.x;
	B.y 	-= A.y;
	B.z 	-= A.z;*/

	sizeA 	 = sqrt( (A.x*A.x + A.y*A.y + A.z*A.z) );
	sizeB 	 = sqrt( (B.x*B.x + B.y*B.y + B.z*B.z) );
	cache	 = A.x*B.x + A.y*B.y + A.z*B.z;
	printf("sizeA:%lf\n",sizeA);
	printf("sizeB:%lf\n",sizeB);
	printf("cache:%lf\n",cache);

	angle	 = cache /(sizeA * sizeB);
	angle 	 = acos(angle);
	//angle 	 = angle * 180.0 / M_PI;
	return angle;
}

