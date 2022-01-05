package es.uv.eu.euroconversor.view;

import java.awt.Color;
import java.awt.BasicStroke;
import java.awt.Font;
import javax.swing.BorderFactory;
import javax.swing.JPanel;
import javax.swing.JLabel;
import java.awt.BorderLayout;

/**
 *
 * @author
 */
public class DisplayPanel extends JPanel{
    
    JLabel valor;
    JLabel cambio;

    public DisplayPanel(String num, String change){
        
        this.setLayout(new BorderLayout());
        this.setBackground(new Color(166, 143, 69));
        this.setBorder(BorderFactory.createStrokeBorder(new BasicStroke(5.0f)));
        
        valor = new JLabel(num, JLabel.RIGHT);
        cambio = new JLabel("Exchange rate: " + change);
        
        valor.setFont(new Font("Sans", Font.BOLD, 40));

        add(valor, BorderLayout.AFTER_LINE_ENDS);
        add(cambio, BorderLayout.SOUTH);
    }
    
    public void setChange(String change)
    {
        cambio.setText(change);
    }
    
    public void setNumber(String num)
    {
        valor.setText(num);
    }
}


