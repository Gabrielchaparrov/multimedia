/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package es.uv.eu.LineSketcher.view;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.GridLayout;
import javax.swing.BorderFactory;
import javax.swing.event.ChangeListener;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSlider;

/**
 *
 * @author Gabriel Chaparro y María Navarro
 */
public class RadioPanel extends JPanel{
    private JPanel p_slide;
    private JLabel texto;
    private JSlider slider;
    private int radio = 5;
    
    /**
     * Constructor de RadioPanel
     */
    public RadioPanel(){
        this.setLayout(new BorderLayout());
        this.setBorder(BorderFactory.createLineBorder(Color.black));
        
        p_slide = new JPanel();
        slider = new JSlider(0,100,radio);
        slider.setMajorTickSpacing(10);
        slider.setMinorTickSpacing(2);
        slider.setPaintTicks(true);
        slider.setPaintLabels(true);
        p_slide.setLayout(new GridLayout(1,1));
        p_slide.add(slider);
        
        texto = new JLabel("Grosor de la línea");
        texto.setFont(new Font("Helvetica",Font.BOLD, 15));
        
        this.add(texto, BorderLayout.NORTH);
        this.add(p_slide, BorderLayout.CENTER);
    }
    
    /**
     * Actualiza el radio
     * @param r radio
     */
    public void setRadio(int r)
    {
        radio = r;
        slider.setValue(radio);
    }
    
    /**
     * Se asignan los listeners necesarios a los componentes de RadioPanel
     * @param e
     */
    public void setChangeListener(ChangeListener e){
        slider.addChangeListener(e);
    }   
}

