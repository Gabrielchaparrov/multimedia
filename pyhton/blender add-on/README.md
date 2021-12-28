# Blender Add-on

This file collects the results of three different projects dedicated to object animation in Blender. Once the projects were combined, the necessary changes were made to be able to use the content as an installable Add-on, without having to touch any code.

## Project 1: Procedural control of movement in Blender using keyframes
The first project's main objective is to generate a piece of code that allows a group of objects to move around the scene following irregular paths. The performance of the result meets the following requirements:

- The path is not defined by the code, but by the user.
- The user can choose the type of interpolation.
- A random oscillation can be added to the movement.

Using this code, the user can choose between three different types of interpolation: **Linear interpolation**, **Hermite polynomial interpolation** or **Catmull-Rom interpolation**. In addition, the user also has the option to add a random oscillation to the movement of the object and can define the amplitude of the oscillation.


## Project 2: Speed control along a curve
The objective of this project is to get an object to travel a path at a controlled speed. To do this, the shape of the path is first determined using the interpolation system that has already been developed, and then the path is traversed at a constant speed. Furthermore, the speed of the object can also be controlled by adding the desired speed values as a custom property.

To do this, different re-parameterizations are made within the code to be able to adapt the speed of the object to the wishes of the user.



## Project 3: Object orientation in the scene
The objective of project 3 is to modify the developed complement so that it is possible to control the orientation of the objects during the movement in the trajectory. In this project, tools are developed to control the spatial orientation of objects. Quaternions are introduced, which are an alternative to rotation matrices widely used in graphics and video games. The option to make an object look towards a predefined direction, or towards the direction in which it is moving, is added to this system.
