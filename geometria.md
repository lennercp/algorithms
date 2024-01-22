# Equação geral da reta
ax + bx + c = 0

*a* = Y1 - Y2
*b* = X2 - X1
*c* = (X1 * Y2) - (Y1 * X2)

### normalizar
multiplicar os 3 coeficientes por -1 quando, a < 0 ou quando a ==0 e b <0
```cpp
if(a < 0 || (a == 0 && b < 0)){
    a = -a;
    b = -b;
    c = -c;
}
```

## Coeficientes A e B formam o vetor normal a reta
Os coeficientes A e B formam o vetor normal a reta, e para rotacionar funciona assim: 
vetor = (x,y), vetor_rotaciona_esquerda = (-y,x), vetor_rotaciona_direita = (y,-x), vetor_rotaciona_180 = (-x,-y)

- oie
- 