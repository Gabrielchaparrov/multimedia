
# Accelerometer
The objective of this project is to create a game or application that uses some element of the mobile device in which it is used for its operation.
This project consists of a game that uses the accelerometer sensor and the light sensor of the device it is running on.
The goal is to steer a vehicle by tilting the positive to get it to avoid oncoming traffic. The values ​​obtained from the light sensor are used to determine if the vehicles in the game should have their lights on or off, being, therefore, a graphic detail.
The game ends when the player's vehicle collides with another vehicle, subsequently obtaining game statistics and the option to replay.
In order to create a game like this in processing, it is necessary to use libraries that allow the information created by the different sensors of the device to be collected. In this case, the Ketai library has been used, which offers predefined functions that allow creating different events when changes are detected in a sensor and transferring the value of the sensors to the code itself.

## Implementation

The onAccelerometerEvent () function is used to use the accelerometer information. In this event, the previous value of x is saved in one variable and the current value in another. Subsequently, the difference between the two is calculated and, if the value of the difference is greater than a threshold, in this case 0.05, a variable is activated that signals that there have been changes in the inclination of the device. This variable is used when calculating the position of the player's vehicle: if there have been changes, the value of the target position of the vehicle is changed, if not, no.
It is important to note that the value that changes is that of the target position and not the position of the vehicle, since a smoothing function has been implemented to prevent the player's car from being in the position entered by the accelerometer sensor instantly, since that would decrease the level of difficulty and would not be necessary to plan each movement, since having a smoothing function, the vehicle takes a certain time to move from one position to another with a more realistic movement.
On the other hand, the values ​​collected by the light sensor are treated in the onLightEvent () function. Inside this event if you compare the current lighting level with a certain threshold, in this case 1250, and, if the value is lower, a Boolean variable that determines if the lighting is very dark is set to true, if not, the value of the Boolean variable is false.

This Boolean variable is used later in the drawing functions of both the user's car and the enemy cars. If the variable that determines that the light level is too low is true, in addition to drawing the sprite of each car, the image of two light bulbs placed at the front of each vehicle is also drawn.

The project consists of 5 different files:
- **Proyectofinal.pde**, in this file all variables are initialized and sensor events are created. It could be considered as the main file that unites the rest of the files.
- **Coche.pde**, where the movement and drawing rules are set for the player's vehicle.
- **Enemigo.pde**, where the movement and drawing rules for enemy vehicles are set.
- **Trafico.pde**, in charge of managing all enemy vehicles, can be considered as the grouping of all cars traveling in the opposite direction. It ensures that there are always a certain number of vehicles on the screen and that two cars are never in the same lane.
- **BotonButton.pde**, creates and implements the different buttons of the graphical interface.

## Errors
An error that aggravated the immersion in the game and that occurred in the first phases of the implementation was the case where a new enemy vehicle was created on lane that was already occupied by another vehicle, the new one leaving with a speed greater than that of the vehicle that was already circulating. This resulted in a visual artifice where one vehicle was mounted on top of the other.
To solve this bug, an ArrayList was created in the Traffic class that contains the values ​​of the currently occupied lanes so that, when a new vehicle is created, it can be verified that the lane that is going to be assigned by the constructor is not occupied. .
This process is reflected in the following code snippet:
      
      int c = (int)random(1,6);
      while(carriles.contains(str(c)))
        c = (int)random(1,6);
      
      addEnemigo(c, (int)random(125, 250) + ((int)abs(tiempo_ini - millis())/1000)*2, (int)random(1, 10));
      carriles.add(str(c));

A new lane "c" is created randomly, and in the event that the Lanes ArrayList, which contains the lanes that are currently occupied, contains the random lane c that was just calculated, one is recalculated randomly until it is not there. occupied.
Subsequently, a new enemy is initialized in lane c, a speed between 125 and 250 plus a value that makes the speed increase a little as the game progresses, that is, as time passes, and a value from 1 to 10 that determines the color of the vehicle.
In addition, the Traffic class is in charge of detecting when an enemy vehicle is off-screen, in that case it is added to a vector of vehicles that must be deleted and, when it is deleted, it is replaced by a new one with different parameters.

Finally, in order to evaluate the performance of the player, a counter for the duration of the game was created that appears in the upper right corner. The value increases throughout the game and, when the player has an accident, stops so that the value can be observed. The longer a game lasts, the faster the enemy vehicles will circulate.

<br>

# Video

[![](https://img.youtube.com/vi/D8mTUEr5Vzs/0.jpg)](https://www.youtube.com/watch?v=D8mTUEr5Vzs)
  
