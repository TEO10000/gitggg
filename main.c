#include <stdio.h>
#include <math.h>

float calcularDistancia(float x1, float y1, float z1, float x2, float y2, float z2);
float calcularPerimetro(float puntos[3][3], float *a, float *b, float *c, float *d, float *e, float *f, float *g);
float calcularArea(float a, float b, float c);

int main()
{
    float puntos[5][3] = {{0, 0, 0}, {3, 0, 0}, {0, 0, 3}, {1, 7, 1}, {1, 0, 1}};
    float a, b, c, d, e, f, g;

    float perimetro = calcularPerimetro(puntos, &a, &b, &c, &d, &e, &f, &g);
    float area = calcularArea(a, b, c);
    float area1 = calcularArea(b, d, e);
    float area2 = calcularArea(a, e, f);
    float area3 = calcularArea(e, f, a);
    float areaSuperficial = area + area1 + area2 + area3;
    float volumen = calcularVolumen(g, area);
    printf("El valor del perimetro es: %0.2f\n", perimetro);
    printf("El valor del area es: %0.2f\n", areaSuperficial);
    printf("El valor del volumen es : %0.2f", volumen );
}

float calcularDistancia(float x1, float y1, float z1, float x2, float y2, float z2)
{

    float dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
    return dist;
}
float calcularPerimetro(float puntos[4][3], float *a, float *b, float *c, float *d, float *e, float *f, float *g)
{
    *a = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *b = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *c = calcularDistancia(puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *d = calcularDistancia(puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *e = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *f = calcularDistancia(puntos[1][0], puntos[1][1], puntos[1][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *g = calcularDistancia(puntos[3][0], puntos[3][1], puntos[3][2], puntos[4][0], puntos[4][1], puntos[4][2]);

    float per = *a + *b + *c + *d + *e + *f;
    return per;
}
float calcularArea(float a, float b, float c)
{
    float s = (a + b + c) / 2;
    float area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}
float calcularVolumen(float g, float area)
{
    float volumen = (g * (area)) / 3;
    return volumen;
}