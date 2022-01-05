package es.uv.eu.LineSketcher;

import es.uv.eu.LineSketcher.controller.LineSketcherController;
import es.uv.eu.LineSketcher.model.LineSketcherModel;
import es.uv.eu.LineSketcher.view.Autores;
import es.uv.eu.LineSketcher.view.Inicio;
import es.uv.eu.LineSketcher.view.LineSketcherView;

/**
 *
 * @author Gabriel Chaparro y María Navarro
 */
public class LineSketcher {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        LineSketcherModel model = new LineSketcherModel();
        LineSketcherView view = new LineSketcherView(model);
        
        LineSketcherController controlador = new LineSketcherController(model, view);
    }
}
