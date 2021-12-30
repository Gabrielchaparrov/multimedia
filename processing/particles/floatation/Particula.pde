class Particula {
  PVector _v, _s, _a;
  float _ttl;

  Particula(PVector pos) {
    _s = pos.get();
    _v = new PVector(random(-2.5, 2.5), random(-2.5, 0));
    _a = new PVector(0, 0.01);
    _ttl = 255.0;
  }
  
  boolean Muerta() {
    if (_ttl < 0.0) {
      return true;
    } else {
      return false;
    }
  }

  void run() {
    update();
    display();
  }

  void update() {
    _v.add(_a);
    _s.add(_v);
    _ttl -= 1.0;
  }

  void display() {
    noStroke();
    fill(124, 210, 223, _ttl);
    ellipse(_s.x, _s.y, 10, 10);
  }
}
