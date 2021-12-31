class ParticulaSystem {

  ArrayList<Particula> Particulas;
  PVector origin;
  PImage textura;

  ParticulaSystem(int num, PVector v, PImage textura_) {
    Particulas = new ArrayList<Particula>();
    origin = v.get();
    textura = textura_;
    for (int i = 0; i < num; i++) {
      Particulas.add(new Particula(origin, textura));
    }
  }

  void run() {
    for (int i = Particulas.size()-1; i >= 0; i--) {
      Particula p = Particulas.get(i);
      p.run();
      if (p.isDead()) {
        Particulas.remove(i);
      }
    }
  }

  void applyForce(PVector dir) {
    for (Particula p : Particulas) {
      p.applyForce(dir);
    }
  }  

  void addParticula() {
    Particulas.add(new Particula(origin, textura));
  }
}
