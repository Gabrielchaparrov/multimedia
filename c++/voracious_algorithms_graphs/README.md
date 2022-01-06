
# Voracious Algorithms with Graphs
Implementation of an intelligent displacement program using the Dijkstra algorithm.

## Task 1: Generate the graph
 Using the class graph implemented in the a previous practice, implementation of the creation of a graph. To do this, the **GenerarGrafoInicial()** function for the **test_algoritmo.cpp** program had to be implemented.

### Result:


## Task 2: Dijkstra implementation
 Implementation of the Dijkstra algorithm, by including a new **getRutaDijkstra()** method in the Graph class. The prototype of the method is: 
 ```
 Grafo getRutaDijkstra (size_t origen); 
```
The method returns a directed graph (subgraph of the original) with all the nodes of the original graph and only the arcs (with the original weight) selected by the Dijkstra algorithm.

### Result:


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
