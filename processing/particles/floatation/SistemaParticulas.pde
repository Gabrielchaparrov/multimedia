class SistemaParticulas {
  ArrayList<Particula> particulas;
  PVector origin;

  SistemaParticulas(PVector _s) {
    origin = _s.get();
    particulas = new ArrayList<Particula>();
  }

  void addParticula() {
    particulas.add(new Particula(origin));
  }

  void run() {
    for (int i = particulas.size()-1; i >= 0; i--) {
      Particula p = particulas.get(i);
      p.run();
      if (p.Muerta()) {
        particulas.remove(i);
      }
    }
  }
}
