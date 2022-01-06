
# Solar System
The normal situation when we visualize a 3D scene is that it is made up of different objects, each with its own movements. In this case *(although not only in this one)* it is necessary to encapsulate the affine transformations to which each of the objects is subjected, since, otherwise, the transformations of some would act on the others. How to do this? Using the **GL_MODELVIEW** stack and the stack control directives **glPushMatrix()** and **glPopMatrix()**. These instructions apply not only to the **GL_MODELVIEW** stack but also to the rest **(GL_TEXTURES, GL_PROJECTION)**.


Using the instructions **glPushMatrix()** and **glPopMatrix()** together with the affine transformations, the program draws a solar system that represents the sun in the center of the scene and revolves the Earth and Mars with their satellites in circular orbits around it. Note that Earth has one satellite and Mars has two. To do this, it uses compositions of rotations and translations to place each planet in an orbit and then compose these transformations with other translations and rotations to place their moons using **glPushMatrix()** and **glPopMatrix()**. It encapsulates the movement of each "Planet + Satellites" system within **glPushMatrix()** and **glPopMatrix()** instructions to make the movements of these systems independent. I didn't really worry about the radious of the orbits or the scales of the celestial bodies, this project is about composing orbital movements, even if they are not faithful to reality.

## Result:

![ezgif com-gif-maker](https://user-images.githubusercontent.com/96742277/148402971-e6820279-7bd3-490c-8095-8da298fadea0.gif)
