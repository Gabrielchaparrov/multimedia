float dt = 1/60.0, masa = 2.0, g = -9.8, k = 0.2;  //k=rozamiento

float ang;

PVector plano1, plano2, inclinado;

PVector pos, vel, acel, F_Rozamiento, F_Peso;

int seed;

void setup() {
  size(600, 600);
  background(200);
  
  seed = (int)random(0, 1000);
  
  ang = 30.0;
  ang = radians(ang);
  
  plano1 = new PVector(0, 0);  //plano1 a plano2 es la línea de abajo
  plano2 = new PVector(width/2, 0);
  inclinado = new PVector(width/2 * cos(ang), -width/2 * sin(ang));
  
  
  //Posición inicial y todas las fuerzas a 0
  pos = new PVector((width/2 -20) * cos(ang), sin(ang)-38);//Se desplaza la caja para que esté encima de la línea
  vel = new PVector(0, 0);
  acel = new PVector(0, 0);
  F_Peso = new PVector(0, 0);
  F_Rozamiento = new PVector(0, 0);
}

void draw() {
  background(255);
  
  pushMatrix();
  
  translate(width/4, height/2);
  
  strokeWeight(3);
  line(plano1.x, plano1.y, plano2.x, plano2.y);
  line(plano1.x, plano1.y, inclinado.x, inclinado.y);
  popMatrix();
  
  //reiniciar cuando el cubo se cae
  if (pos.x <= plano1.x) {
    setup();
  }
  
  //fuerzas
  F_Peso.x = masa * g * cos(ang);
  F_Peso.y = -masa * g * sin(ang);
  F_Rozamiento = PVector.mult(vel, -k);
  F_Peso = PVector.add(F_Peso, F_Rozamiento);
  
  acel = PVector.div(F_Peso, masa);
  vel = PVector.add(PVector.mult(acel, dt), vel);
  pos = PVector.add(PVector.mult(vel, dt), pos);
  
  pushMatrix();
  
  translate(width/4+pos.x, height/2+inclinado.y+pos.y);
  rotate(-ang);
  
  randomSeed(seed);
  fill(random(0, 255), random(0, 255), random(0, 255));
  rect(-40, 0, 40, 40);
  
  popMatrix();
}

void keyPressed() {
  if (key == ' ') {
    setup();
  }
}
