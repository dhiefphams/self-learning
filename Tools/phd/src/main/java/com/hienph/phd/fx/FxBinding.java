package com.hienph.phd.fx;

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class FxBinding extends Application {

  @Override
  public void start(Stage primaryStage) throws Exception {
    // create the textField
    TextField input = new TextField();
    input.setMaxWidth(200);

    Label firstLabel = new Label("Welcome to QQ ");
    Label secondLabel = new Label();
    // subscribe the text change from input field
    secondLabel.textProperty().bind(input.textProperty());

    HBox bottomText = new HBox(firstLabel, secondLabel);
    bottomText.setAlignment(Pos.CENTER);
    VBox mainLayout = new VBox(10, input, bottomText);
    mainLayout.setAlignment(Pos.CENTER);

    Scene mainScene = new Scene(mainLayout, 500, 500);
    primaryStage.setScene(mainScene);
    primaryStage.show();
  }

  public static void main(String[] args) {
    launch(args);
  }
}
