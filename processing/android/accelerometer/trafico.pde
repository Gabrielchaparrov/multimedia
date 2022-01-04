class Trafico 
{
  ArrayList<Enemigo> enemigos;
  ArrayList<Enemigo> borrar;
  ArrayList<String> carriles;

  Trafico() 
  {
    enemigos = new ArrayList<Enemigo>();
    borrar = new ArrayList<Enemigo>();
    carriles = new ArrayList<String>();

    addEnemigo(1, (int)random(100, 150), (int)random(1, 10));
    addEnemigo(2, (int)random(100, 150), (int)random(1, 10));
    addEnemigo(5, (int)random(100, 150), (int)random(1, 10));
    addEnemigo(6, (int)random(100, 150), (int)random(1, 10));
    
    carriles.add("1");
    carriles.add("2");
    carriles.add("5");
    carriles.add("6");
  }
  
  void addEnemigo(int carril, int velocidad, int foto)
  {
    Enemigo e = new Enemigo(carril, velocidad, foto);
    
    enemigos.add(e);
  }
  
  int getNumEnemigos()
  {
    return enemigos.size();
  }
  
  void run()
  {          
    for (int i = 0; i < enemigos.size(); i++)
    {
      Enemigo e = enemigos.get(i);
      e.run();
      
      if(e.y > height + (height/6))
      {        
        borrar.add(e);
        //enemigos.remove(e);
      }
    }    
    
    for (int i = 0; i < borrar.size(); i++)
    {
      Enemigo e = borrar.get(i);
      
      carriles.remove(str(e.carril));
      
      enemigos.remove(e);
      
      int c = (int)random(1,6);
      
      while(carriles.contains(str(c)))
        c = (int)random(1,6);
      
      addEnemigo(c, (int)random(125, 250) + ((int)abs(tiempo_ini - millis())/1000)*2, (int)random(1, 10));
      carriles.add(str(c));
    }
    
    borrar.clear();   
  }
}
