/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package es.uv.eu.LineSketcher.view;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionListener;
import javax.swing.BorderFactory;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;

/**
 *
 * @author Gabriel Chaparro y María Navarro
 */
public class LineSketcherMenuBar extends JMenuBar{
    
    private JMenu archivo;
    private JMenuItem cargar, guardar, salir, defecto, ventana, borrar;
    
    /**
     * Constructor de LineSketcherMenu
     */
    public LineSketcherMenuBar()
    {
        archivo = new JMenu("Menú");
        cargar = new JMenuItem("Cargar Imagen");
        cargar.setActionCommand("Cargar");
        guardar = new JMenuItem("Guardar Imagen");
        guardar.setActionCommand("Guardar");
        defecto = new JMenuItem("Valores por defecto");
        defecto.setActionCommand("Defecto");
        salir = new JMenuItem("Salir");
        salir.setActionCommand("Salir");
        borrar = new JMenuItem("Borrar Todo");
        borrar.setActionCommand("Borrar Todo");
        
        ventana = new JMenuItem("Volver a la ventana anterior");
        ventana.setActionCommand("ventana");
        
        cargar.setFont(new Font("Helvetica",Font.BOLD ,20));
        guardar.setFont(new Font("Helvetica",Font.BOLD ,20));
        salir.setFont(new Font("Helvetica",Font.BOLD ,20));
        defecto.setFont(new Font("Helvetica",Font.BOLD ,20));
        ventana.setFont(new Font("Helvetica",Font.BOLD ,20));
        borrar.setFont(new Font("Helvetica",Font.BOLD ,20));
        archivo.setFont(new Font("Helvetica",Font.BOLD ,20));
        archivo.setBorder(BorderFactory.createLineBorder(Color.black));
        
        salir.setBackground(Color.RED);
        salir.setForeground(Color.WHITE);
        
        archivo.add(cargar);
        archivo.add(guardar);
        archivo.add(defecto);
        archivo.add(borrar);
        archivo.add(salir);
        
        add(archivo);
        add(ventana);
    }
    
    /**
     * Se asignan los listeners necesarios a los componentes de LineSketcherMenu
     * @param actionListener
     */
    public void setActionListener(ActionListener actionListener ) {
        cargar.addActionListener(actionListener);
        guardar.addActionListener(actionListener);
        defecto.addActionListener(actionListener);
        salir.addActionListener(actionListener);
        ventana.addActionListener(actionListener);
        borrar.addActionListener(actionListener);
    } 
}
