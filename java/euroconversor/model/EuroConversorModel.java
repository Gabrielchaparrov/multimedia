package es.uv.eu.euroconversor.model;

/**
 *
 * @author EU 
 */
public final class EuroConversorModel {
  
    private float exchangeRate = (float) 1.11253;
    private String numero;
    private boolean nuevoNumero;
    
    
    public EuroConversorModel() {
        reset();
    }

    public String addDigit(String d) {
        
        switch (d) {
            case "0":
            case "1":
            case "2":
            case "3":
            case "4":
            case "5":
            case "6":
            case "7":
            case "8":
            case "9":
                if (nuevoNumero) {
                    numero = d;
                    nuevoNumero = false;
                }
                else {
                    numero += d;
                }
                break;
        
            case ".":
                if (nuevoNumero) {
                    nuevoNumero = false;
                    numero = "0.";
                }
                else if (!numero.contains(".")) {
                    numero += ".";
                }
                break;
                
            case "C":
                if (nuevoNumero) {
                    reset();
                }
                else if (numero.length() > 1) {
                    numero = numero.substring(0, numero.length()-1);
                }
                else if (numero.length() == 1) {
                    nuevoNumero = true;
                    numero = "0";
                }
                break;
            
            default:
                // nada por hacer
                break;
        }
        return numero;
    }
    
    public String convert() {
        float c = Float.parseFloat(numero) * exchangeRate;
        nuevoNumero = true;
        return String.valueOf(c);
    }

    public final String reset() {
        numero = "0";
        nuevoNumero = true;
        return numero;
    }    

    public void setExchangeRate(float exchangeRate) {
        this.exchangeRate = exchangeRate;
    }
    
    public String getExchangeRate() {
        return String.valueOf(exchangeRate);
    }
    
}
