# Cohen-Sutherland

Implementation of the Cohen-Sutherland algorithm to cut randomly drawn lines against a window that is going to be draw within the drawing area. In reality, with **Open GL** an automatic clipping is already made on the world window defined in the **gluOrtho2D** instruction. For that reason, and since we want to program a manual clipping, the world window is configured to the custom dimensions of the window's window that acts as a view port, using: **gluOrtho2D (0.0, TAM_VENTANA_X, 0.0, TAM_VENTANA_Y);**

The prototype of the function is:
```
bool Cohen_Suth(float &x0,float &y0,float &x1,float &y1);
```

Where **x0**, **y0**, **x1**, **y1** are the ends of the segment to be trimmed and, at the same time, they will contain the trimmed ends when exiting the algorithm. The output of the algorithm should be the following: 
- If it returns true, then the segment of vertices **(x0, y0) (x1, y1)** is accepted and has to be drawn.
- If it returns false, then the segment does not have to be drawn.

The way the program works is simple: Initially, the cropping rectangle will appear painted in red, which is centered around the center of the window, which is where the drawing starts. With each press of the **r** key, a random white line will be painted both inside and outside the clipping window, and also intersecting with it, and when the **d** key is pressed, it begins to change the sections of the trimmed segment to another color depending if it is inside or outside the window.

## Result: 

![fefwe](https://user-images.githubusercontent.com/96742277/148696703-1157f5fd-18a4-4d1d-88b3-01d93cdf6cbb.JPG)
