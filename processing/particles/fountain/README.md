# Fountain

The code generates a random number **f** between 3 and 15 that determines the number of arcs the fountaint will have.
The particle emitter emits f particles every 250 milliseconds with the calculated path to form a symmetrical source.
The opacity of the particles is determined by the remaining life time they have, the shorter the time, the greater the transparency.

## Example: 9 arc fountain

To obtain a correct and symmetric trajectory, each particle is assigned a number that increases as new particles are created, starting from 0. 
For each particle, the modulus of its particle number is calculated between the number of arcs to obtain the particle number in the interval (0-8). 
In this way, the first 9 particles, with numbers from 0 to 8, will obtain values from 0 to 8, and the next round, 250 milliseconds later, 
with numbers from 10 to 18, will also obtain values from 0 to 8. Knowing what number in the interval (0-9) has each particle, 
their trajectories are assigned by the cosine for the X axis and the sine for the Y axis of the result of the following equation:

- <img src="https://render.githubusercontent.com/render/math?math=(((\pi/2)/(\_form-1))*n)%2B\pi/4"><br>

Being **_form** the number of arcs and **n** the number from 0 to 9 that corresponds to each particle and that creates the deviation of each arc. 
The objective of the previous function is to divide a quarter of a circumference <img src="https://render.githubusercontent.com/render/math?math=(\pi/2)"> by the number of arcs of the source to obtain the necessary increment to evenly 
distribute all the particles, which obtain their angle by multiplying the increment by their particle number, so it would distribute like the following sequence:<br>

increment\*0, increment\*1 ... up to increment*8, thus completing the entire quarter of a circle, since **8==_form-1**.

<br>

## Video

[![](https://img.youtube.com/vi/dR8lbEgpZK0/0.jpg)](https://www.youtube.com/watch?v=dR8lbEgpZK0)
