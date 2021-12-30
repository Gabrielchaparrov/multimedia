PVector origenParticulas;
int n_part = 0;
int _forma;
PVector g = new PVector(0, 9.81);
float dt = 0.1;

int millis = millis();

SistemaParticulas ps;

void setup() {
  size(1000, 1000);
  background(255);
  
  _forma = (int)random(3, 15+1); //forma de la fuente
  
  origenParticulas = new PVector(width/2.0, width/2.0);
  ps = new SistemaParticulas(origenParticulas);
}

void draw() {
  
  if(millis - millis() < -250)
  {
    for (int i = 0; i < _forma; i++) {
      ps.addParticula();
    }
    
    millis = millis();
  }

  background(250);
  
  fill(0);
  textSize(15);
  text("<Espacio> para reiniciar la simulación", 0, 20);
  text("La forma de la fuente se genera de forma aleatoria al reiniciar la simulación (Entre 3 y 15)", 0, 40);
  text("Nº de arcos en la fuente: ", 0, 60);
  textSize(25);
  text(_forma, 185, 65);
  
  fill(0);
  ps.run();
}

void keyPressed() {
  if (key == ' ') {
    setup();
  }
}
