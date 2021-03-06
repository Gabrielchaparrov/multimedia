
# LineSketcher

The use of the developed application is described below:

## 1. Initial screen
In the initial screen or configuration screen, the default active colors and the options to edit the characteristics of the lines are presented for their subsequent drawing:

![-2](https://user-images.githubusercontent.com/96742277/148263788-c54c0a1e-a754-41f9-b1bf-3a74458763cd.jpg)


## 2. Help menu
On the screen that is displayed by default when the program is run, there is the option of opening a pop-up window with basic instructions for use. To access them, you must select the "Ayuda" option from the top menu:

![-3](https://user-images.githubusercontent.com/96742277/148263845-d2e2dabd-e535-46d2-92b0-80221e780e96.JPG)

To exit the pop-up window, use the dedicated “Volver” button, located at the bottom of the window.

## 3. Selection of drawing mode
The main purpose of the application is to offer a drawing platform that allows you to choose both the thickness of the drawn lines and their fill color. This color can be a solid color or a two-color gradient. In the initial window, the change between both color modalities, the change of the active colors and the thickness of the lines is allowed:
### 3.1. Change from simple to gradient and vice versa:

![-4](https://user-images.githubusercontent.com/96742277/148263872-f8a3e09a-594a-4b92-bf75-99f374ce9aba.JPG)

To change the drawing mode from simple to gradient, use the "Añadir color secundario" button on the initial screen. When selected, the "Añadir color secundario" button is deactivated, since there can only be two colors in the gradient, and the "Quitar color secundario" button is activated, whose function consists of eliminating the secondary color and restructuring the window to suit it. initial format, in solid color mode. When adding the secondary color, the window is restructured to be able to house the label “Color secundario”, whose function is to show the selected color (White by default), and a new color selection panel: one for the main color and another for the secondary color. This allows you to switch between drawing modes.

### 3.2. Regulation of the thickness of the lines

![-5](https://user-images.githubusercontent.com/96742277/148263884-1492e34a-09cd-405f-b25c-cd3767a47a83.JPG)

It is possible to change the thickness of the lines from the home page using the dedicated slider at the top of the screen. You can also change the thickness from the drawing window.

### 3.3. Colour selection

![-6](https://user-images.githubusercontent.com/96742277/148263918-b386c981-a661-404a-bb8f-8e7cfa1c0473.JPG)

![-7](https://user-images.githubusercontent.com/96742277/148263936-94530226-5f26-4c51-8648-a436390c96f3.JPG)

By selecting one of the colors displayed on screen in the color picker, the label will change to the selected color. In the case that the drawing mode is gradient, there are two color selectors and two labels are also displayed on the screen, each one corresponding to the main or secondary color and, when selecting a color in each one, each label will take its corresponding color. To change the secondary color, you need to select the desired color from the color picker under the secondary color label. Also, if the text is not intelligible over the selected color, the font color will be changed to white.

## 4. Drawing screen

To access the drawing screen, once the desired color or colors and thickness have been chosen, you must select the "Empezar" button at the bottom of the screen, which redirects to the drawing screen. In this new screen, you can perform some of the options that we have already seen: you can change the color or colors using the color selectors on the left side of the screen (If the mode is solid color, only a selection panel will be displayed of colors, if the mode is gradient, two will be displayed, one for each color. Also, if the mode is solid color, only one color appears in the upper bar, if the mode is gradient, the two selected colors will be displayed) and you can change the radius using the slider located at the bottom of the window. However, you cannot change from a color to a gradient or vice versa from here, to do this you have to go back to the initial window.

![-8](https://user-images.githubusercontent.com/96742277/148263950-e068fd2f-2e81-4baa-85b2-9ea8a80478c4.JPG)

Furthermore, in the previous image it can be seen that the color and radio parameters have been transmitted to the drawing window.

To draw lines, you must select the starting point on the drawing area and the end point. Once selected, a line will be drawn connecting the selected points with the desired characteristics.

![-9](https://user-images.githubusercontent.com/96742277/148264196-e4ad54da-e806-488e-b7d5-c82af836ffe8.JPG)

### 4.1. Default values

![-10](https://user-images.githubusercontent.com/96742277/148264058-e326080c-8ff8-4855-8c38-7cb78ee6d03f.JPG)

The default values of the application are: solid color mode, white color and thickness 5. Through the upper menu of the start and drawing window you can select the option "Valores por defecto", which restores these values to its initial state. This would be the only way to change the drawing mode from the drawing screen, since you cannot change from simple color to gradient or vice versa directly, however, using this option you can change from gradient mode to simple, losing all the above configuration.

### 4.2. Erase everything
Another option accessible from the menu is "Borrar todo" which restores the background, eliminates all the drawn lines and restarts the line counter.

![-11](https://user-images.githubusercontent.com/96742277/148264013-f35f17d6-d5ad-4158-a36b-b8e0c1c625c4.JPG)

### 4.3. Save and Load Image
From the initial window and the drawing window, an image can be loaded to set it as a drawing background or save the drawing made. For this, the options "Guardar Imagen" or "Cargar Imagen" are used.

## 5. Authors

In the menu of the initial screen, there is the option "Autores" that shows a pop-up window similar to the help window with my name and the name of my classmate and friend María:

![-12](https://user-images.githubusercontent.com/96742277/148263996-82211a2f-b56c-4b02-8007-8ebf700bea47.JPG)




> The files were originally located in a folder distribution similar to this: "es.uv.eu.LineSketcher"
