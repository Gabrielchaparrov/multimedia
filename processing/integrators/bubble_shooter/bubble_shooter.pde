float dt = 1/60.0;

float r = 100.0;

PVector p1, raton;
PVector pos = new PVector(-900, -900);
PVector vel = new PVector();
float mod;

int n_bola = 0;

void setup() {
  size(600, 600);
  
  p1 = new PVector(0, 0);
  raton = new PVector(mouseX, mouseY);
}

void draw() {
  background(255);
  
  translate(width/2, height);
  
  raton.set(mouseX, mouseY);  
  raton.sub(width/2,height/2+300);
  mod = sqrt((raton.x*raton.x)+(raton.y*raton.y));
  raton.x /= mod;
  raton.y /= mod;
  raton.mult(100);
  
  stroke(0);
  strokeWeight(5);
  line(p1.x, p1.y, raton.x, raton.y);
  
  pos = PVector.add(PVector.mult(vel, dt), pos);
  
  randomSeed(n_bola);
  fill(random(0,255), random(0,255), random(0,255));
  ellipse(pos.x, pos.y, 40, 40);
}

void mousePressed() {
    //Comprueba que no haya otra burbuja
    if(pos.x < -width/2 || pos.x > width/2 || pos.y < -height) {
      pos = new PVector(raton.x, raton.y);
      
      vel = PVector.sub(raton, p1);
      vel.normalize();
      vel.mult(500);
      n_bola++;
    }
}
