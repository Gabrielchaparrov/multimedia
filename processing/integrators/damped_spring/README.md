# Damped Spring

In this program, the force that is exerted on the spring when it is displaced with and without damping is calculated. When there is no damping, the spring never reaches a state of equilibrium and keeps in motion indefinitely. However, if damping is enabled, frictional forces are exerted and the spring reaches a state of equilibrium where it stops moving.

## Equations

<img src="https://render.githubusercontent.com/render/math?math=weight= mass * gravity"><br>
<img src="https://render.githubusercontent.com/render/math?math=elongation= actual\:length - rest\:length"><br>
<img src="https://render.githubusercontent.com/render/math?math=(Without\:damping)\:friction= -ks * elongation"><br>
<img src="https://render.githubusercontent.com/render/math?math=(With\:damping)\:friction= -ks * elongation - kd * speed"><br>

<img src="https://render.githubusercontent.com/render/math?math=force= weight %2B friction"><br>
<img src="https://render.githubusercontent.com/render/math?math=acceleration= force / mass"><br>
<img src="https://render.githubusercontent.com/render/math?math=speed= speed %2B acceleration * dt"><br>
<img src="https://render.githubusercontent.com/render/math?math=current\:length = current\:length %2B speed * dt"><br>

<br>

> - **"ks"** is is a measure of the stiffness of the spring. It is different for different springs and materials. The larger the spring constant, the stiffer the spring and the more difficult it is to stretch. <br> 
> - **"kd"** is the damping constant.
> - **"dt"** references the variation in time.
