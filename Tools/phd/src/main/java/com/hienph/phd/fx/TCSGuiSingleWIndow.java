package com.hienph.phd.fx;


import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import org.opencv.core.Core;


public class TCSGuiSingleWIndow extends Application implements EventHandler<ActionEvent> {
  private Button button;
  private Text mainText;

  @Override
  public void start(Stage primaryStage) throws Exception {
    // create new stage or window
    primaryStage.setTitle("TCS John Huxley");
    this.button = new Button();
    this.button.setText("Start");
    // using class to handle event
//    button.setOnAction(this);
    button.setOnAction(e -> {
      mainText.setText("Click me");
      System.out.println("Hola");
    });

    // create the text
    mainText = new Text();

    StackPane layout = new StackPane();
    layout.getChildren().add(button);
    layout.getChildren().add(mainText);


    // create the content/scene
    Scene mainScene = new Scene(layout, 300, 250);
    primaryStage.setScene(mainScene);
    primaryStage.show();
  }

  /**
   * Handle the button click event
   */
  @Override
  public void handle(ActionEvent event) {
    // the click button
    if (event.getSource() == button) {
      mainText.setText("Button is now clicked");
    }
  }

  public static void main(String[] args) {
    System.loadLibrary(Core.NATIVE_LIBRARY_NAME);
    launch(args);
  }
}
