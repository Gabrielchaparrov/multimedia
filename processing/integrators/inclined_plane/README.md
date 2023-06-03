# Inclined Plane

The program generates a cube of random color that slides on a ramp.
When the cube reaches the end of the ramp, the program restarts.

## Equations

$weight\\ x= mass * gravity * cos(\theta)$<br>
$weight\\ y= -mass * gravity * sin(\theta)$<br>
$friction= -k * speed$<br>
$force = weight + friction$<br>


$acceleration= force / mass$<br>
$speed= speed + acceleration * dt$<br>
$position = position + speed * dt$<br>

<br>

## Video

<a href="http://www.youtube.com/watch?feature=player_embedded&v=1ipl-oOQFEw" target="_blank">
 <img src="http://img.youtube.com/vi/1ipl-oOQFEw/mqdefault.jpg" alt="Watch the video" width="240" height="180" border="10" />
</a>
