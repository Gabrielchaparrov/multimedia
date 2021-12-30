
float densidad = 0.00002;
float KrAire = 0.1; // Constante de rozamiento en el aire
float KrAgua = 0.3; // Constante de rozamiento en el agua
float dt = 1/20.0;
PVector origenPelota, origenParticulas;
PVector Froz = new PVector(0.0, 0.0);
PVector Fb = new PVector(0.0, 0.0);
PVector g = new PVector(0.0, 9.81);

Pelota pelota;
SistemaParticulas ps;

void setup() {
  size(800, 800);
  
  background(250);
  
  origenParticulas = new PVector(width/2.0, width/2.0);
  origenPelota = new PVector(width/2.0, 0.0);  
  
  ps = new SistemaParticulas(origenParticulas);
  pelota = new Pelota(origenPelota);
}

void keyPressed() {
  if (key == ' ') {
    setup();
  }
}

void draw() {
  background(255);
  
  fill(0);
  textSize(15);
  text("<Espacio> para reiniciar la simulación", 0, 20);
  text("Posición de la pelota: " + (int)pelota._s.x + "x, " + (int)pelota._s.y + "y", 0, 40);
  text("Al reiniciar se genera una velocidad inicial aleatoria (Entre 0 y 150) ", 0, 60);
  text("Velocidad inicial de la pelota: ", 0, 80);
  textSize(25);
  text((int)pelota.v_ini, 215, 85);
  
  pelota.run();
  
  //hacer que salpique
  if (pelota._s.y+pelota.radio > height/2.0 && pelota._s.y+pelota.radio < height/10.0*6 && pelota._v.y > 10) {
    ps.addParticula();
  }
  
  ps.run();
  
  noStroke();
  fill(124, 210, 223, 150);
  rect(0, height/2, width, height); // Agua translÃºcida para que se vea la pelota 
}