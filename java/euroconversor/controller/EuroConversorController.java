package es.uv.eu.euroconversor.controller;


import es.uv.eu.euroconversor.model.EuroConversorModel;
import es.uv.eu.euroconversor.view.EuroConversorView;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.swing.JOptionPane;

public class EuroConversorController {
    
    private EuroConversorModel model;
    private EuroConversorView view;

    public EuroConversorController (EuroConversorModel model, EuroConversorView view){
    this.model = model;
    this.view = view;
    
    view.addWindowListener(new EuroConversorControllerWindowListener());
    view.setActionListener(new EuroConversorControllerActionListener ());
    }

    // Clases empotrada.
    class EuroConversorControllerWindowListener extends WindowAdapter {
        @Override
        /**
        * Procesa el cierre de la ventana.
        * @param e Información del evento.
        */
        public void windowClosing(WindowEvent e) {
            System.out.println (" EuroConversorController : Cerrar ventana.");
            System.exit(0);
        }
    }
    
    class EuroConversorControllerActionListener implements ActionListener {
        @Override
        /**
        * Procesa la información recibida de los listeners y actúa en función de ella.
        * @param ae Información del evento.
        */
        public void actionPerformed(ActionEvent ae) {  
            
            String command = ae.getActionCommand();
            
            switch (command) {
                case "Salir":
                    System.out.println ("EuroConversorController: Menu ’Salir ’.");
                    System.exit(0);
                break;
                
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
                case ".":
                case "C":
                    System.out.println(command);
                    view.setNumber(model.addDigit(command));
                break;
                
                case "Convert":
                    System.out.println ("Convert");
                    view.setNumber(model.convert());
                break;
                
                case "Clear":
                    System.out.println ("Clear");
                    view.setNumber(model.reset());
                break;
                
                case "Change":
                    System.out.println ("Change");
                    String rate = JOptionPane.showInputDialog(null,"Enter new exchange rate:");
                    if(rate != null)
                    {
                        view.setChange("Exchange rate: "+ rate);
                        float exrate = Float.parseFloat(rate);
                        model.setExchangeRate(exrate);
                    }
                    
                break;
                
                default :
                    System.out.println ("EuroConversorController: Comando ’" + command + "’ no reconocido.");
                break;
            }
        }
    }
}