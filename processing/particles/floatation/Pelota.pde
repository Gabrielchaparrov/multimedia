class Pelota {
  PVector _v = new PVector(0, random(0, 150));
  PVector _s, _a;
  float radio = 50;
  float masa = 5.0;
  float Vs;
  float v_ini = _v.y;

  Pelota(PVector pos) {
    _s = pos.get();
    _a = new PVector(0, 0);
  }

  void applyForce(PVector force) {
    PVector f = force.get();
    f.div(masa);
    _a.add(f);
  }

  void update() {
    applyForce(PVector.mult(g, masa));   //se añade posa fuerza peso
    
    if (_s.y > height / 2 - radio && _s.y < height / 2 + radio) {
      //justo en la línea de flotación
      float h = _s.y + radio - height / 2;
      float a = sqrt(2 * h * radio - h * h);
      Vs = (3 * a * a + h * h) * PI * h / 6;
      Froz.y = -KrAgua * _v.y;
      //print("1");
      
    } else if (_s.y > height/2+radio) { 
      //por debajo de la línea de flotación
      Vs = 4 * PI * radio * radio * radio / 3.0;
      Froz.y = -KrAgua * _v.y;
      //print("2");
      
    } else { 
      //por encima de la línea de flotación
      Vs = 0;
      Froz.y = -KrAire * _v.y;
      //print("3");
    }
    
    Fb.y = -densidad * g.y * Vs;    //se calcula la fuerza de flotación
    
    applyForce(Fb);
    applyForce(Froz);
    
    _v = PVector.add(PVector.mult(_a, dt), _v);
    _s = PVector.add(PVector.mult(_v, dt), _s);
    
    _a.set(0.0, 0.0);
  }
  
  void run() {
    update();
    display();
  }

  void display() {
    strokeWeight(5);
    stroke(255, 0, 0);
    fill(255, 50, 50);
    ellipse(_s.x, _s.y, radio, radio);
    
    //Líneas rojas
    line(0, height / 2 - radio, width, height / 2 - radio);
    line(0, height / 2 + radio, width, height / 2 + radio);
  }
}
