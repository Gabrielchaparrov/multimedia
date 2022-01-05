/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package es.uv.eu.LineSketcher.view;

import static es.uv.eu.LineSketcher.view.ColorPanel.cod_color;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionListener;
import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JPanel;

/**
 *
 * @author Gabriel Chaparro y María Navarro
 */
public class AñadirColor extends JPanel{
    
    private JButton Mas, Menos;
    
    /**
     * Constructor por defecto de AñadirColor
     */
    public AñadirColor()
    {
        Mas = new JButton("Añadir color secundario");
        Mas.setActionCommand("Añadir");
        
        Menos = new JButton("Quitar color secundario");
        Menos.setActionCommand("Quitar");
        
        Menos.setEnabled(false);
        
        this.setLayout(new GridLayout(1,2, 10, 10));
        
        this.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        
        Mas.setFont(new Font("Cooper Black",Font.PLAIN ,20));
        Menos.setFont(new Font("Cooper Black",Font.PLAIN ,20));
        
        this.add(Mas);
        this.add(Menos);

    }
    
    /**
     * Desactiva el botón de quitar color, ya que esta en modo color solido. Activa el otro boton
     */
    public void simple()
    {
        
        Menos.setEnabled(false);
        Mas.setEnabled(true);
    }
    
    /**
     * Desactiva el botón de añadir color, ya que esta en modo gradiente. Activa el otro boton
     */
    public void gradiente()
    {
        Menos.setEnabled(true);
        Mas.setEnabled(false);
    }
    
    /**
     * Se asignan los listeners necesarios a los componentes de AñadirColor
     * @param actionListener
     */
    public void setActionListener(ActionListener actionListener ) {
        
        Mas.addActionListener(actionListener);
        Menos.addActionListener(actionListener);
    }     
}