float dt = 1/6.0;
float g = 9.8;
float masa = 8.0;
float L_reposo;
float L_actual;
float elongacion;
float ks = 0.5; // Constante elasticidad
float kd = 0.5; // Constante amortiguación
float Fk;
float F_peso;
float F_total;
float vel, acel;
Boolean amortiguacion = true;

void setup() {
  size(600, 600);
  
  acel = 0.0;
  vel = 0.0;
  elongacion = 0.0;
  L_reposo = 100.0;
  L_actual = 100.0;   //en reposo
  Fk = 0.0;
  F_peso = 0.0;
  F_total = 0.0;
}

void draw() {
  background(255);
  
  //Linea arriba
  strokeWeight(3);
  stroke(0);
  line(0, 0, width, 0);
  
  
  F_peso = masa * g;
  elongacion = L_actual - L_reposo;
  Fk = -ks * elongacion;
  
  if(amortiguacion)
  {
    Fk -= kd * vel;
  }
  
  textSize(25);
  
  text("Posición: " + (int)L_actual, 10, 400);
  text("Velocidad: " + (int)vel, 10, 425);
  text("Aceleración: " + (int)acel, 10, 450);
  text("Fk: " + (int)Fk, 10, 475);
  text("Fuerza peso: " + (int)F_peso, 10, 500);
  text("Fuerza total: " + (int)F_total, 10, 525);
  
  if(amortiguacion)
    text("<a> Amortiguado", 300, 550);
  else
  text("<a> No amortiguado", 300, 550);
  
  F_total = F_peso + Fk;
  
  acel = F_total / masa;
  vel += acel * dt;
  L_actual += vel * dt;
  
  line(width/2, 0, width/2, L_actual);
  
  if(amortiguacion)
    fill(255, 100, 150);
  else
    fill(100, 200, 255);
  
  rect(-25+width/2, L_actual, 50, 50);
  fill(0);
}

void keyPressed() {
  if (key == ' ') {
    setup();
  }
  
  if (key == 'A' || key == 'a') {
    amortiguacion = !amortiguacion;
  }
}
