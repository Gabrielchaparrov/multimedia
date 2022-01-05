/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package es.uv.eu.LineSketcher.view;

import java.awt.GridLayout;
import java.awt.event.ActionListener;
import javax.swing.BorderFactory;
import javax.swing.JPanel;

/**
 *
 * @author Gabriel Chaparro y María Navarro
 */
public class SelectPanelInicio extends JPanel{
    private ColorPanel p1, p2;
    private boolean gradiente;
    
    /**
     * Constructor de SelectPanelInicio
     * @param n
     */
    public SelectPanelInicio(boolean n)
    {
        gradiente = n;
        
        setLayout(new GridLayout(1,2, 10, 10));
        this.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        
        
        p1 = new ColorPanel("1");
        add(p1);
        
        if(gradiente)
        {
            p2 = new ColorPanel("2");
            add(p2);
        }
    }
    
    /**
     * Se asignan los listeners necesarios a los componentes de SelectPanelInicio
     * @param actionListener
     */
    public void setActionListener(ActionListener actionListener ) {
        p1.setActionListener(actionListener);
        
        if(gradiente)
            p2.setActionListener(actionListener);
    } 
}