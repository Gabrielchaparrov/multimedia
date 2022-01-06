
# Graph Programming
A weighted undirected graph is one in which all the arcs that connect the nodes go both ways and each arc is assigned a weight. A common way to represent these graphs is by means of an adjacency matrix, that is, a square matrix of **n x n** integers, where each position **(i, j)** of the matrix represents the weight of the arc from node **i** to node **j.**

## Task 1: Printing graphs
Implementation of the print method that prints all the nodes of a graph, indicating for each node the nodes to which it is connected along with their weights. Here, the code creates a graph that corresponds to the one in the figure. Implement the **addArcoNoDirigido()** function that uses the operator **()** implemented in the previous one, so that if an **arc(i, j)** of weight **n** is created, an **arc(j, i)** of weight **n** is also created. Catch the exception if the wrong position is used and prevent the program from stopping.

### Result:

## Task 2: Minimum connection 
Implementation of the function **ConexionMinima(int nodo)** function that returns, for a node of the graph, the arc with the minimum weight with which it is connected to another node.

### Result:

## Task 3: Random generator of undirected graphs 
Implementation the function **GeneraGrafoNoDirigido (int min, int max)** that will be in charge of generating the arcs and weights for a previously initialized graph with a specific dimension. This function should ensure that each node has at least one arc reaching it.

### Result:

foto
