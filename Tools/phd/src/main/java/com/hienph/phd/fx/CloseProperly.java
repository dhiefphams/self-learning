package com.hienph.phd.fx;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class CloseProperly extends Application {
  private Stage window;

  @Override
  public void start(Stage primaryStage) {
    window = primaryStage;
    window.setTitle("Hello from Q");
    VBox mainLayout = new VBox();

    Button closeBtn = new Button("Close");
    closeBtn.setOnAction(e -> closeProperly());
    mainLayout.getChildren().addAll(closeBtn);

    // when user clicks the close in window panel
    window.setOnCloseRequest(e -> {
      e.consume(); // tell java that we want to control this event
      closeProperly();
    });

    Scene mainScene = new Scene(mainLayout, 300, 300);
    window.setScene(mainScene);
    window.show();
  }

  private void closeProperly() {
    Boolean result = new AlertBox().display("Are you sure?", "Close the window");
    if (result) {  window.close(); }
  }

  public static void main(String[] args) {
    launch(args);
  }
}
