package com.hienph.phd.fx;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class MultipleScene extends Application {
  /** Keep track of the current window */
  private Stage window;

  private Scene login, register;

  @Override
  public void start(Stage primaryStage) {
    window = primaryStage;
    window.setTitle("Just Give Q multiple windows");

    setupLoginScene();
    setupRegisterScene();
    window.setScene(login);
    window.show();
  }

  private void setupRegisterScene() {
    Label welcomeTxt = new Label("Welcome to register page");
    Button toGoLoginBtn = new Button("Login");
    toGoLoginBtn.setOnAction(e -> window.setScene(login));

    // layout of register page
    VBox registerLayout = new VBox(20);
    registerLayout.getChildren().addAll(welcomeTxt, toGoLoginBtn);
    register = new Scene(registerLayout,  300, 300);
  }

  private void setupLoginScene() {
    // Setting up the login scene
    Label label = new Label("Welcome to login scene");
    // when user click to register button, go to register page
    Button registerBtn = new Button("Register");
    registerBtn.setOnAction(e -> window.setScene(register));

    // login page
    VBox loginLayout = new VBox(20);
    loginLayout.getChildren().addAll(label, registerBtn);

    login = new Scene(loginLayout, 200, 200);
  }

  public static void main(String[] args) {
    launch(args);
  }
}
