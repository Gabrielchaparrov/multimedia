class Particula {
  PVector _s;
  PVector _v;
  PVector _a;
  float _ttl;
  PVector size = new PVector(0, 0);
  PImage textura;

  Particula(PVector l, PImage textura_) {
    _a = new PVector(0, 0);
    float vx = random(-1, 1);
    float vy = random(-3, -4);

    _v = new PVector(vx, vy);
    _s = l.get();
    _ttl = 200.0;
    textura = textura_;
  }

  void run() {
    update();
    display();
  }

  void applyForce(PVector f) {
    _a.add(f);
  }  

  void update() {
    _v.add(_a);
    _s.add(_v);
    _ttl -= 2;
    _a.mult(0);
    
    size.x = _s.y / 20;
    size.y = _s.y / 20;
  }

  void display() {
    
    textura.width = (int)(size.x * 10);
    textura.height = (int)(size.y * 10);
    
    //imageMode(CORNERS);
    tint(255, _ttl);
    
    if(textured){
      image(textura, _s.x-50, _s.y-100);
    }
    else{
      fill(255,_ttl);
      noStroke();
      ellipse(_s.x,_s.y,size.x,size.y);
    }
  }

  boolean isDead() {
    if (_ttl <= 0.0) {
      return true;
    } else {
      return false;
    }
  }
}
