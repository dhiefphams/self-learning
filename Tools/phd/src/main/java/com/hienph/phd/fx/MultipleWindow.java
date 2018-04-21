package com.hienph.phd.fx;

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.stage.Modality;
import javafx.stage.Stage;

public class MultipleWindow extends Application {
  @Override
  public void start(Stage primaryStage) {
    Stage window = primaryStage;

    Button settingBtn = new Button("Settings");
    Label userAnswer = new Label();

    settingBtn.setOnAction(e -> {
      boolean result = new AlertBox().display("Settings", "Hello from main");
      userAnswer.setText(String.valueOf(result));
    });
    VBox mainLayout = new VBox();
    mainLayout.getChildren().addAll(settingBtn, userAnswer);

    // create the main scene
    Scene mainScene = new Scene(mainLayout, 200, 300);
    window.setScene(mainScene);
    window.show();
  }

  public static void main(String[] args) {
    launch(args);
  }
}