

# Voracious Algorithms with Graphs
Implementation of an intelligent displacement program using the Dijkstra algorithm.

## Task 1: Generate the graph
 Using the class graph implemented in the a previous practice, implementation of the creation of a graph. To do this, the **GenerarGrafoInicial()** function for the **test_algoritmo.cpp** program had to be implemented.

### Result:
```
Grafo inicial
-------------------
Nodo 0: (0,1):32 (0,2):43 (0,3):28
Nodo 1: (1,0):32 (1,4):42
Nodo 2: (2,0):43 (2,4):26
Nodo 3: (3,0):28 (3,5):64
Nodo 4: (4,1):42 (4,2):26 (4,5):33 (4,6):71
Nodo 5: (5,3):64 (5,4):33 (5,6):28
Nodo 6: (6,4):71 (6,5):28
```


## Task 2: Dijkstra implementation
 Implementation of the Dijkstra algorithm, by including a new **getRutaDijkstra()** method in the Graph class. The prototype of the method is: 
 ```
 Grafo getRutaDijkstra (size_t origen); 
```
The method returns a directed graph (subgraph of the original) with all the nodes of the original graph and only the arcs (with the original weight) selected by the Dijkstra algorithm.

### Result:
```
Grafo dirigido de Dijkstra desde nodo 0
-------------------
Nodo 0: (0,1):32 (0,2):43 (0,3):28
Nodo 1:
Nodo 2: (2,4):26
Nodo 3: (3,5):64
Nodo 4:
Nodo 5: (5,6):28
Nodo 6:
```

## Task 3: Optimal route
From the results obtained by Dijkstra's algorithm, it is possible to reproduce the route that must be followed to reach (with the lowest possible cost) any node of the graph from the origin node of the route. To do this, it is now implemented the **mostrarRutaDijkstra** function in the **test_grafo.cpp** program. The prototype of the function is: 
````
void mostrarRutaDijkstra (Grafo g, size_t origen, size_t destino); 
````
The arguments of the function indicate: 
- **Grafo g**: Graph obtained by the Dijkstra method 
- **size_t origen**: Node origin of the Dijkstra algorithm, with which the graph g has been obtained. 
- **size_t destino**: destination node of the route for which you want to show the route from the origin. 

The **mostrarRutaDijkstrafunction** displays on the screen the sequence of nodes that make up the path to get from the source node to the destination node using the arcs of the graph g. It also indicates the total weight of the route.

### Result:
```
Mostrar ruta de menor coste desde 0.
Ruta desde 0 hasta 1:
0 ---> 1
Peso total de la ruta = 32
Ruta desde 0 hasta 2:
0 ---> 2
Peso total de la ruta = 43
Ruta desde 0 hasta 3:
0 ---> 3
Peso total de la ruta = 28
Ruta desde 0 hasta 4:
0 ---> 2 ---> 4
Peso total de la ruta = 69
Ruta desde 0 hasta 5:
0 ---> 3 ---> 5
Peso total de la ruta = 92
Ruta desde 0 hasta 6:
0 ---> 3 ---> 5 ---> 6
Peso total de la ruta = 120
```
