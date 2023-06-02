# Damped Spring

In this program, the force that is exerted on the spring when it is displaced with and without damping is calculated. When there is no damping, the spring never reaches a state of equilibrium and keeps in motion indefinitely. However, if damping is enabled, frictional forces are exerted and the spring reaches a state of equilibrium where it stops moving.

## Equations

$weight= mass * gravity$<br>
$elongation= actual\:length - rest\:length$<br>
$(Without\:damping)\:friction= -ks * elongation$<br>
$(With\:damping)\:friction= -ks * elongation - kd * speed$<br>

$force= weight %2B friction$<br>
$acceleration= force / mass$<br>
$speed= speed %2B acceleration * dt$<br>
$current\:length = current\:length %2B speed * dt$<br>

<br>

> - **"ks"** is is a measure of the stiffness of the spring. It is different for different springs and materials. The larger the spring constant, the stiffer the spring and the more difficult it is to stretch. <br> 
> - **"kd"** is the damping constant.
> - **"dt"** references the variation in time.

<br>

## Video

[![](https://img.youtube.com/vi/7a0t_Z0XmlA/0.jpg)](https://www.youtube.com/watch?v=7a0t_Z0XmlA)
  
