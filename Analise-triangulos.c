#include <stdio.h> 
#include <math.h> 
 
// Funcao para verificar a desigualdade triangular 
int forma_triangulo(float a, float b, float c) { 
    if (a <= 0 || b <= 0 || c <= 0) { 
        return 0; // Lados devem ser maiores que zero 
    } 
    // Desigualdade triangular estrita (exclui degenerados onde um lado == soma dos outros) 
    if ((a < b + c) && (b < a + c) && (c < a + b)) { 
        return 1; 
    } 
    return 0; 
} 
 
// Funcao para classificar quanto aos lados e angulos 
void classificar_triangulo(float a, float b, float c) { 
    // Classificacao quanto aos lados 
    if (a == b && b == c) { 
        printf("equilatero, "); 
    } else if (a == b || a == c || b == c) { 
        printf("isosceles, "); 
    } else { 
        printf("escaleno, "); 
    } 
 
    // Identificacao do maior lado para teste de Pitagoras 
    float maior = a, cat1 = b, cat2 = c; 
    if (b > maior) { 
        maior = b; 
        cat1 = a; 
        cat2 = c; 
    } 
    if (c > maior) { 
        maior = c; 
        cat1 = a; 
        cat2 = b; 
    } 
 
    // Calculo dos quadrados com tolerancia para ponto flutuante 
    float h2 = maior * maior; 
    float c2 = (cat1 * cat1) + (cat2 * cat2); 
    float diff = h2 - c2; 
 
    if (fabs(diff) < 0.0001f) { 
        printf("retangulo"); 
    } else if (h2 < c2) { 
        printf("acutangulo"); 
    } else { 
        printf("obtusangulo"); 
    } 
} 
 
// Funcao dedicada ao calculo da area pela Formula de Heron 
float area_heron(float a, float b, float c) { 
    float p = (a + b + c) / 2.0f; // Semiperimetro 
    // Garante precedencia correta dos produtos antes da raiz quadrada 
    float termo = p * (p - a) * (p - b) * (p - c); 
    return sqrtf(termo); 
} 
 
int main() { 
    float a, b, c; 
 
    printf("Digite os tres lados do triangulo: \n"); 
    if (scanf("%f %f %f", &a, &b, &c) != 3) { 
        printf("Entrada invalida.\n"); 
        return 0; 
    } 
 
    if (!forma_triangulo(a, b, c)) { 
        printf("Os valores nao formam um triangulo\n"); 
        return 0; 
    } 
 
    classificar_triangulo(a, b, c); 
    float area = area_heron(a, b, c); 
    printf(", area %.2f\n", area); 
 
    return 0; 
} 