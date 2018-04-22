package com.hienph.phd.fx;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class TextFieldVal extends Application {
  @Override
  public void start(Stage window) {
    TextField usernameInput = new TextField();
    Button submitBtn = new Button("Submit now");
    submitBtn.setOnAction(e -> {
      if (validateDate(usernameInput)) {
       System.out.println("Holla welcome");
      }
    });

    VBox mainLayout = new VBox();
    mainLayout.getChildren().addAll(usernameInput, submitBtn);

    Scene mainScene = new Scene(mainLayout, 300, 300);
    window.setScene(mainScene);
    window.show();
  }

  private boolean validateDate(TextField input) {
    try {
      int age = Integer.parseInt(input.getText());
      return true;
    } catch (NumberFormatException e) {
      return false;
    }
  }

  public static void main(String[] args) {
    launch(args);
  }
}
