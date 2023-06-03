# Flotation

The program generates a particle that falls until it is submerged in the water and floats up.
As the particle passes the waterline, spatter-mimicking particles are mitigated.

## Equations

- **On the waterline:** <br>
$height= position.y + radio - height/2$<br>
$a= sqrt(2 * height * radio - height^2)$<br>
$Vs= (3 * a^2 + height^2) * \pi * height/6$<br>
$friction.y= -Kr_{water} * speed.y$<br>

 

- **Above the waterline:** <br>
$Vs = 0$<br>
$friction.y = -Kr_{air} * speed.y$<br>



- **Below the waterline:** <br>
$Vs = 4 * \pi * radius * radius * radius/3$<br>
$friction.y = -Kr_{water} * speed.y$<br>

$flotation= -density * gravity * Vs$<br>



> - **"kr"** represents the friction coeficient. <br> 

<br>

## Video

<a href="http://www.youtube.com/watch?feature=player_embedded&v=6T2lh71dGA0" target="_blank">
 <img src="http://img.youtube.com/vi/6T2lh71dGA0/mqdefault.jpg" alt="Watch the video" width="240" height="180" border="10" />
</a>
  

