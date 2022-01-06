
# Graph Programming
A weighted undirected graph is one in which all the arcs that connect the nodes go both ways and each arc is assigned a weight. A common way to represent these graphs is by means of an adjacency matrix, that is, a square matrix of **n x n** integers, where each position **(i, j)** of the matrix represents the weight of the arc from node **i** to node **j.**

## Task 1: Printing graphs
Implementation of the print method that prints all the nodes of a graph, indicating for each node the nodes to which it is connected along with their weights. Here, the code creates a graph that corresponds to the one in the figure. Implement the **addArcoNoDirigido()** function that uses the operator **()** implemented in the previous one, so that if an **arc(i, j)** of weight **n** is created, an **arc(j, i)** of weight **n** is also created. Catch the exception if the wrong position is used and prevent the program from stopping.

### Result:
```
* Tarea 1: Definicion e impresion del grafo de ejemplo *

Nodo 0: (0,1):3 (0,2):5 (0,3):2 (0,7):10
Nodo 1: (1,0):3 (1,2):5 (1,3):8 (1,4):8 (1,6):6 (1,7):6
Nodo 2: (2,0):5 (2,1):5 (2,4):1 (2,5):7 (2,6):9
Nodo 3: (3,0):2 (3,1):8 (3,4):12 (3,7):14
Nodo 4: (4,1):8 (4,2):1 (4,3):12 (4,6):15
Nodo 5: (5,2):7 (5,7):9
Nodo 6: (6,1):6 (6,2):9 (6,4):15 (6,7):3
Nodo 7: (7,0):10 (7,1):6 (7,3):14 (7,5):9 (7,6):3
```

## Task 2: Minimum connection 
Implementation of the function **ConexionMinima(int nodo)** function that returns, for a node of the graph, the arc with the minimum weight with which it is connected to another node.

### Result:
```
* Tarea 2: Conexiones minimas del grafo de ejemplo *

Nodo 0 => Nodo 3
Nodo 1 => Nodo 0
Nodo 2 => Nodo 4
Nodo 3 => Nodo 0
Nodo 4 => Nodo 2
Nodo 5 => Nodo 2
Nodo 6 => Nodo 7
Nodo 7 => Nodo 6
```

## Task 3: Random generator of undirected graphs 
Implementation the function **GeneraGrafoNoDirigido (int min, int max)** that will be in charge of generating the arcs and weights for a previously initialized graph with a specific dimension. This function should ensure that each node has at least one arc reaching it.

### Result:
```
* Tarea 3: Grafo aleatorio de tama±o 10 *

Nodo 0: (0,1):37 (0,6):29
Nodo 1: (1,6):69
Nodo 2: (2,2):46 (2,4):5 (2,6):30 (2,8):45 (2,9):41
Nodo 3: (3,2):52 (3,3):41 (3,4):44 (3,5):20 (3,7):85 (3,9):41
Nodo 4: (4,3):81 (4,6):57 (4,8):86 (4,9):3
Nodo 5: (5,4):14
Nodo 6: (6,5):3 (6,6):4 (6,7):70 (6,8):31
Nodo 7: (7,1):61 (7,2):31 (7,3):41 (7,6):6 (7,7):89 (7,8):98
Nodo 8: (8,4):27 (8,7):83
Nodo 9: (9,4):40 (9,7):74 (9,8):81

* Conexiones minimas del grafo aleatorio *

Nodo 0 => Nodo 6
Nodo 1 => Nodo 6
Nodo 2 => Nodo 4
Nodo 3 => Nodo 5
Nodo 4 => Nodo 9
Nodo 5 => Nodo 4
Nodo 6 => Nodo 5
Nodo 7 => Nodo 6
Nodo 8 => Nodo 4
Nodo 9 => Nodo 4
```
