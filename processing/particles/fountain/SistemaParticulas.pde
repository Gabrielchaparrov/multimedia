class SistemaParticulas {
  ArrayList<Particula> particles;
  PVector origin;

  SistemaParticulas(PVector _s) {
    origin = _s.get();
    particles = new ArrayList<Particula>();
  }

  void addParticula() {
    particles.add(new Particula(origin));
  }

  void run() {
    for (int i = particles.size()-1; i >= 0; i--) {

      Particula p = particles.get(i);
      p.run();
      
      if (p.Muerta()) {
        particles.remove(i);
      }
    }
  }
}
