/*
27.	Se llama matriz tridiagonal a aquella que tiene valores distintos de cero 
sólo en la diagonal principal y en las diagonales que están por encima y por debajo 
de ésta. Observe la siguiente figura. Si la matriz es grande, conviene almacenar 
(para ahorrar espacio de memoria) sólo los valores distintos de cero en un arreglo 
unidimensional. Encuentre una fórmula que calcule la posición en la que fueron guardados 
(en un arreglo unidimensio¬nal) los elementos de una matriz tridiagonal.
25	10	0	0
18	41	25	0
0	45	56	31
0	0	22	16

Dato[Ren][Col] =
3(Ren); Ren == Col
3(Ren) + 1; Ren == Col - 1
3(Ren) - 1; Ren == Col + 1
*/