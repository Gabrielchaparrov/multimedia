

# Binary Search Tree

The ABB (Árbol de Búsqueda Binaria) class implements a structure to represent a node-based binary search tree with pointers to its children. The objective of the practice is to create an ABB of students in which the key will be a student ID (the "DNI" without the letter) and the value of each node an object of type "Alumno". The following tasks will be carried out a ABB filled with 10 students, all implemented using recursion, except for the main test function.

## Task 1: Inorder printing

Implementation of the Inorder method for the ABB class, which must print all the available information of the students entered in the tree following this criteria: an inorder (infix) traversal first traverses the left subtree until it reaches the leaves, then the root node, and then continues through the right subtree.

### Result:

```
****** TAREA 1 ******

==================================
    DNI: 41H
    Nombre: Jose    Calderon
    Curso: 0    Telefono: 600019169
==================================
  | Nivel 1

==================================
    DNI: 491F
    Nombre: Angel    Contreras
    Curso: 3    Telefono: 600005436
==================================
  | Nivel 4

==================================
    DNI: 4664J
    Nombre: Jorge    Bernal
    Curso: 9    Telefono: 600006868
==================================
  | Nivel 6

==================================
    DNI: 5447Q
    Nombre: Carlos    Alonso
    Curso: 6    Telefono: 600001869
==================================
  | Nivel 5

==================================
    DNI: 5705N
    Nombre: Jorge    Contreras
    Curso: 2    Telefono: 600009961
==================================
  | Nivel 3

==================================
    DNI: 12382B
    Nombre: Carlos    Bernal
    Curso: 5    Telefono: 600019895
==================================
  | Nivel 4

==================================
    DNI: 15724M
    Nombre: Raul    Aranda
    Curso: 1    Telefono: 600024464
==================================
  | Nivel 2

==================================
    DNI: 19912F
    Nombre: Jose    Calderon
    Curso: 7    Telefono: 600009894
==================================
  | Nivel 4

==================================
    DNI: 28703V
    Nombre: Angel    Alonso
    Curso: 8    Telefono: 600017673
==================================
  | Nivel 5

==================================
    DNI: 32391S
    Nombre: Angel    Alonso
    Curso: 4    Telefono: 600000292
==================================
  | Nivel 3
```


## Task 2: ABB Height 
Implementation of a method for the ABB class that obtains the height of the ABB, that is, the level at which its leaves are deepest. Modification of the Inorder method above so that in addition to the student information, it shows the height at which each node is located to verify that the method works properly.

### Result:

```
****** TAREA 2 ******

Altura del arbol = 6
```

## Task 3 & 4: Search by identifier 
Implementation of a search method in the ABB class that, given an identifier as an integer, prints on the screen all the students whose identifier (DNI) is equal to or greater than the one entered. The implemented function is optimized so as not to go through the entire ABB and stop when it is not possible to obtain a higher identifier.
It is  will be tried first with an identifier that returns results, in this case, 5705, and, secondly, with an identifier that does not return any student.

### Result:

```
****** TAREA 3 ******

==================================
    DNI: 15724M
    Nombre: Raul    Aranda
    Curso: 1    Telefono: 600024464
==================================
==================================
    DNI: 5705N
    Nombre: Jorge    Contreras
    Curso: 2    Telefono: 600009961
==================================
==================================
    DNI: 12382B
    Nombre: Carlos    Bernal
    Curso: 5    Telefono: 600019895
==================================
==================================
    DNI: 32391S
    Nombre: Angel    Alonso
    Curso: 4    Telefono: 600000292
==================================
==================================
    DNI: 19912F
    Nombre: Jose    Calderon
    Curso: 7    Telefono: 600009894
==================================
==================================
    DNI: 28703V
    Nombre: Angel    Alonso
    Curso: 8    Telefono: 600017673
==================================


****** TAREA 4 ******

No se muestran resultados
```