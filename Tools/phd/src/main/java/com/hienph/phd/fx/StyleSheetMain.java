package com.hienph.phd.fx;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class StyleSheetMain extends Application {
  @Override
  public void start(Stage primaryStage) {

    HBox inputWrapper = new HBox();
    Label inputLabel = new Label("Username");
    TextField input = new TextField();
    inputWrapper.getChildren().addAll(inputLabel, input);

    Button login = new Button("Login");
    login.getStyleClass().addAll("login-btn");
    login.setId("login");

    VBox mainLayout = new VBox();
    mainLayout.getChildren().addAll(inputWrapper, login);

    Scene mainScene = new Scene(mainLayout, 500, 500);

    mainLayout.getStylesheets().addAll("/stylesheets/stylesheet.css");
    primaryStage.setScene(mainScene);
    primaryStage.show();
  }
}