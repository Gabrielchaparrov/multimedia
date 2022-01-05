package es.uv.eu.LineSketcher.controller;

import es.uv.eu.LineSketcher.model.LineSketcherModel;
import es.uv.eu.LineSketcher.view.Autores;
import static es.uv.eu.LineSketcher.view.ColorPanel.cod_color;
import es.uv.eu.LineSketcher.view.Inicio;
import es.uv.eu.LineSketcher.view.LoadImage;
import es.uv.eu.LineSketcher.view.LineSketcherView;
import es.uv.eu.LineSketcher.view.SaveImage;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.WindowAdapter;
import javax.swing.event.ChangeListener;
import java.awt.event.WindowEvent;
import java.io.File;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.imageio.ImageIO;
import javax.swing.JSlider;
import javax.swing.event.ChangeEvent;

/**
 *
 * @author Gabriel Chaparro y María Navarro
 */
public class LineSketcherController {
    
    private LineSketcherModel model;
    private LineSketcherView view;
    private Inicio inicio;

    /**
    * Constructor de LineSketcherController
    * @param model Modelo LineSketcher.
    * @param view Vista LineSketcher.
    */
    public LineSketcherController (LineSketcherModel model, LineSketcherView view){
    this.model = model;
    this.view = view;
    
    view.setVisible(false);
    
    
    view.addWindowListener(new PhotoEditorControllerWindowListener());
    view.setActionListener(new PhotoEditorControllerActionListener ());
    view.setChangeListener(new PhotoEditorControllerChangeListener());
    view.setMouseListener(new PhotoEditorControllerMouseListener());

    }

    // Clases empotrada.
    class PhotoEditorControllerWindowListener extends WindowAdapter {
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
    
    class PhotoEditorControllerActionListener implements ActionListener {
        @Override
        /**
        * Procesa la información recibida de los listeners y actúa en función de ella.
        * @param ae Información del evento.
        */
        public void actionPerformed(ActionEvent ae) {  
            
            String command = ae.getActionCommand();
            
            switch (command) {
                case "Salir":
                    System.out.println(command);
                    System.exit(0);
                break;
                
                case "Cargar":
                    System.out.println(command);
                    
                    LoadImage load = new LoadImage();
                    model.loadImagen(load.getFile());
                    
                    model.ResetLineas();
                    model.Uncolor();
                    view.maslinea(model.GetLineas());
                    
                    view.repaint();
                    
                break;
                
                case "Quitar":
                    System.out.println(command);
                    model.Uncolor(); 
                    
                    view.cambiarSimple();  
                break;
                
                case "Borrar Todo":
                    System.out.println(command);
                    
                    model.ResetLineas();
                    //model.Uncolor();
                    view.maslinea(model.GetLineas());
                    
                    model.borraImagen();
                    view.repaint();  
                break;
                
                case "Añadir":
                    System.out.println(command);
                    model.Gradiente();
                    
                    //view.setVisible(false);
                    //inicio.setVisible(true);
                    view.cambiarGradiente(model.GetColor2());
                    
                break;
                
                case "Empezar":
                    System.out.println(command);
                    
                    view.pintar();
                    
                break;

                
                case "Guardar":
                    System.out.println(command);

                    SaveImage save = new SaveImage();
                    model.saveImagen(save.getFile());
                    
                break;
                
                case "ventana":
                    System.out.println(command);
                    
                    view.ajustes();
                    
                break;
                
                case "Autores":
                    System.out.println(command);
                    
                    view.autoresvisible();
                    
                break;
                
                case "VolverAutores":
                    System.out.println(command);
                    
                    view.autoresinvisible();
                    
                break;
                
                case "Ayuda":
                    System.out.println(command);
                    
                    view.ayudavisible();
                    
                break;
                
                case "VolverAyuda":
                    System.out.println(command);
                    
                    view.ayudainvisible();
                    
                break;
                
                case "Defecto":
                    System.out.println(command);

                    model.SetColor1(9);
                    model.SetColor2(9);
                    view.setRadio(5);
                    view.setFondo1(9);
                    view.setFondo2(9);
                    view.inidefecto();
                    
                    view.cambiarSimple();
                    
                    
                break;
                
                case "01":
                case "11":
                case "21":
                case "31":
                case "41":
                case "51":
                case "61":
                case "71":
                case "81":
                case "91":
                case "101":
                case "111":
                case "121":
                case "131":
                    System.out.println(command);
                    model.SetColor1(Integer.parseInt(command) / 10);
                    view.setFondo1(model.GetColor1());
                    
                break;
                
                case "02":
                case "12":
                case "22":
                case "32":
                case "42":
                case "52":
                case "62":
                case "72":
                case "82":
                case "92":
                case "102":
                case "112":
                case "122":
                case "132":
                    System.out.println(command);
                    model.SetColor2(Integer.parseInt(command) / 10);
                    view.setFondo2(model.GetColor2());
                    
                break;

                default :
                    System.out.println ("EuroConversorController: Comando ’" + command + "’ no reconocido.");
                break;
            }
        }
    }
    
        class PhotoEditorControllerChangeListener implements ChangeListener{
        @Override
        public void stateChanged(ChangeEvent e) {
            JSlider slider = (JSlider)e.getSource();
            if (!slider.getValueIsAdjusting()) {
                int valor = (int)slider.getValue();
                view.setRadio(valor);
                
                System.out.println(valor);
            }
        }
    }
    
    class PhotoEditorControllerMouseListener implements MouseListener{
        @Override
        public void mouseClicked(MouseEvent me){
            if(me.getButton()==MouseEvent.BUTTON1){
                System.out.println("click izquierdo");
                
                if(model.GetInicio())
                {
                    model.SetP1(me.getX(), me.getY());
                    model.SetInicio(!model.GetInicio());
                }
                else
                {
                    model.SetP2(me.getX(), me.getY());
                    model.pintaLinea(model.GetP1x(), model.GetP1y(), model.GetP2x(), model.GetP2y(), view.getRadio(), cod_color[model.GetColor1()], cod_color[model.GetColor2()]);
                    model.SetInicio(!model.GetInicio());
                    view.maslinea(model.GetLineas());
                }
                
                view.repaint();
            }
            
            if(me.getButton()==MouseEvent.BUTTON3){
                System.out.println("click derecho");
                
                if(view.getRadio() <= 95)
                {
                    view.setRadio(view.getRadio() + 5);
                }
            }
        }
        @Override
        public void mouseReleased(MouseEvent arg0) {
        }
   
        @Override
        public void mousePressed(MouseEvent arg0) {
        }

        @Override
        public void mouseExited(MouseEvent arg0) {
        }

        @Override
        public void mouseEntered(MouseEvent arg0) {
        }
    }

}