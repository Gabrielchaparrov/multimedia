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
public class MenuInicio extends JMenuBar{
    
    private JMenu archivo;
    private JMenuItem cargar, guardar, salir, defecto, ayuda, autores;
    
    /**
     * Constructor de MenuInicio
     */
    public MenuInicio()
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
        ayuda = new JMenuItem("Ayuda");
        ayuda.setActionCommand("Ayuda");
        autores = new JMenuItem("Autores");
        autores.setActionCommand("Autores");

        cargar.setFont(new Font("Helvetica",Font.BOLD ,20));
        guardar.setFont(new Font("Helvetica",Font.BOLD ,20));
        salir.setFont(new Font("Helvetica",Font.BOLD ,20));
        defecto.setFont(new Font("Helvetica",Font.BOLD ,20));
        ayuda.setFont(new Font("Helvetica",Font.BOLD ,20));
        autores.setFont(new Font("Helvetica",Font.BOLD ,20));
        archivo.setFont(new Font("Helvetica",Font.BOLD ,20));
        
        archivo.setBorder(BorderFactory.createLineBorder(Color.black));

        salir.setBackground(Color.RED);
        salir.setForeground(Color.WHITE);
        
        archivo.add(cargar);
        archivo.add(guardar);
        archivo.add(defecto);
        archivo.add(autores);
        archivo.add(salir);
        
        add(archivo);
        add(ayuda);
        
        

    }
    
    /**
     * Se asignan los listeners necesarios a los componentes de MenuInicio
     * @param actionListener
     */
    public void setActionListener(ActionListener actionListener ) {
        cargar.addActionListener(actionListener);
        guardar.addActionListener(actionListener);
        defecto.addActionListener(actionListener);
        salir.addActionListener(actionListener);

        autores.addActionListener(actionListener);
        ayuda.addActionListener(actionListener);
    } 
}