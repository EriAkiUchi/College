#include <stdio.h>
#include <math.h>
//exercício de converter coordenada polar para cartesiana
typedef struct
{
	float raio;
	float angulo;
}polar;

typedef struct
{
	float x;
	float y;
}cartesiano;

void conversor(polar *p, cartesiano *c)
{
	c->x = p->raio * cos(p->angulo);
	c->y = p->raio * sin(p->angulo);
}
int main()
{
	polar coordenada;
	coordenada.raio = 1.0f;
	coordenada.angulo = (180*3.14)/180;
	
	cartesiano coor;
	
	conversor(&coordenada,&coor);
	
	printf("seno:%f cosseno:%f",coor.y,coor.x);
	return 0;	
}
