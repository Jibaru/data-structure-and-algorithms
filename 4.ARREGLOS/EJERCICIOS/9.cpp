/*
9.	Se tienen 2 arreglos paralelos. El primero de ellos almacena las claves de N (1< N<50) 
escuelas, ordenadas ascendentemente. En el segundo se alma¬cena, por escuela, el total de 
alumnos de preprimaria, primaria, secundaria y preparatoria. Observe el siguiente esquema. 
La escuela, cuya clave está en la casilla 0 del primer arreglo, tiene 624 alumnos en preprimaria, 
1600 en primaria, 1260 en secundaria y 893 en preparatoria. Los totales de alumnos, por nivel, 
de la segunda escuela ocuparán las casillas 4, 5, 6 y 7 del segundo arreglo, y así sucesivamente.

Clave escuelas(pos) [{0}, 1, 2, ..., MAX -1]
Total Alumnos (pos) [{0, 1, 2, 3}, ..., MAX*4-1]

Teniendo en cuenta estas especificaciones para guardar los datos, escriba un programa en C++ que:
a)	Genere un reporte que imprima, de cada una de las escuelas, el total de alumnos en cada una 
de las secciones y el total general de la escue¬la. El usuario podrá dar la clave de una escuela 
o pedir un listado de todas las escuelas.
b)	Calcule e imprima el total de alumnos de cualquiera de las 4 secciones, considerando todas 
las escuelas. El usuario indicará la sección elegida.
c)	Calcule e imprima el total de alumnos en cada una de las 4 secciones, considerando todas las 
escuelas. Es decir, el total de alumnos en pre¬primaria, primaria, etcétera, tenga en cuenta las 
N escuelas. ¿Puede reutilizar la solución del inciso b)?
d)	Registre una nueva escuela. Los datos proporcionados por el usuario serán la clave de la escuela 
y el número de alumnos en cada una de las 4 seccio¬nes. Si la escuela no tiene alguna de las secciones 
se ingresará un 0. 
e) Elimine alguna de las escuelas. El dato proporcionado por el usuario será la clave de la escuela.
f) Actualice los totales de alumnos en alguna sección (o en todas). El dato proporcionado por el 
usuario será la clave de la escuela, la clave de la sección (o secciones) y el nuevo número de alumnos.
*/