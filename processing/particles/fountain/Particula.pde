class Particula {
  PVector _v, _s, _a;
  float _ttl;
  float masa = 10;
  PVector _F = new PVector(0, 0);

  Particula(PVector pos) {

    float n = n_part%_forma;
    
    double angle = (((Math.PI/2)/(_forma-1)) * n) + Math.PI/4;
    
    PVector aux_angle = new PVector((float)Math.cos(angle), (float)Math.sin(angle));
    
    _v = aux_angle;
    
    _v.x = _v.x * 1.5;
    _v.y = _v.y * 2;
    
    _s = pos.get();
    _a = new PVector(0, 0.01);
    _ttl = 550.0;
    
    _v = _v.mult(10);
    
    println(_v);
    
    n_part++;
  }

  void run() {
    update();
    display();
  }

  void update()
  {
    _ttl = _ttl - 1.0;
    applyForce(g);
    _v.sub(PVector.mult(_a, dt));
    _s.sub(PVector.mult(_v, dt));
    _a.set(0,0);
  }
  
  void applyForce(PVector force)
  {
    PVector fuerza = PVector.div(force.get(), masa);
    _a.add(fuerza);
  }

  void display() {
    noStroke();
    fill(124, 210, 223, _ttl);
    ellipse(_s.x, _s.y, 10, 10);
  }
  
  boolean Muerta() {
    if (_ttl < 0.0) {
      return true;
    } else {
      return false;
    }
  }
}
