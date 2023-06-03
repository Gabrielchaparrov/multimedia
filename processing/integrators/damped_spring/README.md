# Damped Spring

In this program, the force that is exerted on the spring when it is displaced with and without damping is calculated. When there is no damping, the spring never reaches a state of equilibrium and keeps in motion indefinitely. However, if damping is enabled, frictional forces are exerted and the spring reaches a state of equilibrium where it stops moving.

## Equations

$weight= mass * gravity$<br>
$elongation= actual\\_length - rest\\_length$<br>
$(Without\\ damping) friction= -ks * elongation$<br>
$(With\\ damping) friction= -ks * elongation - kd * speed$<br>

$force= weight + friction$<br>
$acceleration= force / mass$<br>
$speed= speed + acceleration * dt$<br>
$current\\_length = current\\_length + speed * dt$<br>

<br>

> - **"ks"** is is a measure of the stiffness of the spring. It is different for different springs and materials. The larger the spring constant, the stiffer the spring and the more difficult it is to stretch. <br> 
> - **"kd"** is the damping constant.
> - **"dt"** references the variation in time.

<br>

## Video

<a href="http://www.youtube.com/watch?feature=player_embedded&v=7a0t_Z0XmlA" target="_blank">
 <img src="http://img.youtube.com/vi/7a0t_Z0XmlA/mqdefault.jpg" alt="Watch the video" width="240" height="180" border="10" />
</a>

