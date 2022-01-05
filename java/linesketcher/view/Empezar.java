/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package es.uv.eu.LineSketcher.view;

import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JPanel;

/**
 *
 * @author Gabriel Chaparro y María Navarro
 */
public class Empezar extends JPanel{
    
    private JButton empezar;
    
    /**
     * Constructor por defecto de Empezar
     */
    public Empezar()
    {
        empezar = new JButton("Empezar");
        empezar.setActionCommand("Empezar");
        
        this.setLayout(new GridLayout(1,1));
        empezar.setFont(new Font("Helvetica", Font.BOLD ,25));
        
        this.add(empezar);
    }
    
    /**
     * Se asignan los listeners necesarios a los componentes de Empezar
     * @param actionListener
     */
    public void setActionListener(ActionListener actionListener ) {
        
        empezar.addActionListener(actionListener);
    }     
}
