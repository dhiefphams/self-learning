package com.hienph.phd.fx;

import com.jfoenix.controls.JFXButton;
import java.io.File;
import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class EmbeddedLayout extends Application {
  private Stage window;

  @Override
  public void start(Stage primaryStage) {
    window = primaryStage;

    GridPane mainLayout = loginForm();

    Scene mainScene = new Scene(mainLayout, 400, 300);
    // read the styles in src/main/resources
    mainScene.getStylesheets().add("/stylesheets/main.css");
    window.setScene(mainScene);
    window.show();
  }

  private GridPane loginForm() {
    // with grid pane
    GridPane mainLayoutWithGrid = new GridPane();
    mainLayoutWithGrid.setPadding(new Insets(10, 10, 10, 10));
    mainLayoutWithGrid.setVgap(8);
    mainLayoutWithGrid.setHgap(10);

    // create single row with left at the left and login input at the right
    Label login = new Label("Login");
    GridPane.setConstraints(login, 0, 0);
    TextField loginInput = new TextField("@hienph");
    GridPane.setConstraints(loginInput, 1, 0);

    // similar for password
    Label password = new Label("Password");
    GridPane.setConstraints(password, 0, 1);
    TextField passwordInput = new TextField("");
    GridPane.setConstraints(passwordInput, 1, 1);
    passwordInput.setPromptText("Pwd");

    // now the login button
    JFXButton loginBtn = new JFXButton("Login");
    GridPane.setConstraints(loginBtn, 1, 2);

    // now build the grid
    mainLayoutWithGrid.getChildren().addAll(login, loginInput, password, passwordInput, loginBtn);

    return mainLayoutWithGrid;
  }

  private BorderPane borderPane() {
    HBox topMenu = new HBox();
    JFXButton loginBtn = new JFXButton("Login");
    JFXButton registerBtn = new JFXButton("Register");
    topMenu.getChildren().addAll(loginBtn, registerBtn);

    VBox panelLeft = new VBox();
    JFXButton closeBtn = new JFXButton("Close now");
    panelLeft.getChildren().addAll(closeBtn);

    // create the main layout with BorderPane
    BorderPane mainLayout = new BorderPane();
    mainLayout.setTop(topMenu);
    mainLayout.setLeft(panelLeft);
    return mainLayout;
  }

  public static void main(String[] args) {
    launch(args);
  }
}
