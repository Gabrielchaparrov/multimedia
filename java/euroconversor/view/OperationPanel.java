package es.uv.eu.euroconversor.view;

import java.awt.event.ActionListener;
import javax.swing.BorderFactory;
import javax.swing.JPanel;
import javax.swing.JButton;
/**
 *
 * @author EU 
 */
public class OperationPanel extends JPanel{
    private JButton convert;
    
    public OperationPanel(){
        
        convert = new JButton("Convert");
        convert.setActionCommand("Convert");
        
        this.setBorder(BorderFactory.createEmptyBorder(10, 0, 0, 10));
        
        add(convert);
    }
    
    public void setActionListener(ActionListener actionListener ) {
        convert.addActionListener(actionListener);
    } 
}