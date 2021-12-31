ParticulaSystem ps;

boolean wind_left = false;
boolean wind_right = false;
boolean textured = false;

void setup() {
  
  size(800, 800);
  PImage textura = loadImage("humo.png");
  textura.resize(150, 150);
  
  ps = new ParticulaSystem(0, new PVector(width/2, height-60), textura);
  
}

void draw() {
  background(0);
  
  fill(255);
  textSize(20);
  
  if(!wind_left && !wind_right)
    text("Viento desactivado <Flechas para cambiar>", 50, 50);
  else if(wind_right)
    text("Viento hacia la derecha <Flechas para cambiar> | <w> para desactivar", 50, 50);
  else if(wind_left)
    text("Viento hacia la izquierda <Flechas para cambiar> | <w> para desactivar", 50, 50);
    
  text("<i> Activar/Desactivar textura (No recomendado en navegador)", 50, 100);
  
  float dx = 0;

  if(wind_left)
    dx = -0.15;
  else if(wind_right)
    dx = 0.15;

  PVector wind = new PVector(dx, 0);
  
  ps.applyForce(wind);
  ps.run();
  
  for (int i = 0; i < 1; i++) {
    ps.addParticula();
  }

}

void keyPressed(){
  if(keyCode == RIGHT)
  {
    wind_right = true;
    wind_left = false;
  }
  else if(keyCode == LEFT)
  {
    wind_right = false;
    wind_left = true;
  }
  else if(key == 'w')
  {
    wind_right = false;
    wind_left = false;
  }
  else if(key == 'i')
  {
    textured = !textured;
  }
}
