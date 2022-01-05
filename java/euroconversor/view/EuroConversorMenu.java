package es.uv.eu.euroconversor.view;

import java.awt.event.ActionListener;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JMenuItem;

/**
 *
 * @author EU 
 */
public class EuroConversorMenu extends JMenuBar {
    private JMenu euroconversor;
    private JMenu calculadora;
    private JMenuItem salir;
    private JMenuItem change;

    /**
    * Constructor de PeliculaMenu
    */
    public EuroConversorMenu() {
        euroconversor = new JMenu("EuroConversor");
        calculadora = new JMenu("Calculadora");
        salir = new JMenuItem("Salir");
        salir.setActionCommand("Salir");
        change = new JMenuItem("Change Rate");
        change.setActionCommand("Change");

        euroconversor.add(calculadora);
        calculadora.add(change);
        calculadora.add(salir);

        this.add(euroconversor);
    }
    
    public void setActionListener(ActionListener actionListener ) {
        salir.addActionListener(actionListener);
        change.addActionListener(actionListener);
    } 
}