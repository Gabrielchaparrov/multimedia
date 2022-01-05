package es.uv.eu.euroconversor.view;

import es.uv.eu.euroconversor.model.EuroConversorModel;
import java.awt.*;
import java.awt.event.ActionListener;
import javax.swing.*;

public class EuroConversorView extends JFrame {
    public NumberPanel number;
    public ClearPanel clear;
    public OperationPanel operation;
    public DisplayPanel display;
    public EuroConversorMenu menu;
  
    public EuroConversorView(String change, String num){
        
        setLayout(new BorderLayout());
        
        number = new NumberPanel();
        clear = new ClearPanel();
        operation = new OperationPanel();
        display = new DisplayPanel(num, change);
        menu = new EuroConversorMenu();
        
        add(number, BorderLayout.CENTER);
        add(clear, BorderLayout.SOUTH);
        add(operation, BorderLayout.EAST);
        add(display, BorderLayout.NORTH);
        this.setJMenuBar(menu);
        
        setVisible(true);
        setSize(500, 500);
    }
    
    public void setNumber(String number)
    {
        display.setNumber(number);
    }
    
    public void setChange(String change)
    {
        display.setChange(change);
    }
    
    public void setActionListener(ActionListener actionListener ){
        menu.setActionListener(actionListener);
        number.setActionListener(actionListener);
        clear.setActionListener(actionListener);
        operation.setActionListener(actionListener);
    }
}





