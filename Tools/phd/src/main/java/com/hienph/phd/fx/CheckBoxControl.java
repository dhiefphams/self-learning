package com.hienph.phd.fx;

import com.jfoenix.controls.JFXButton;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.CheckBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class CheckBoxControl extends Application {
  @Override
  public void start(Stage primaryStage) {
    List<String> programmingLanguages = Arrays.asList("Tensorflow", "Python");
    List<CheckBox> checkBoxes = programmingLanguages
      .stream()
      .map(CheckBox::new)
      .collect(Collectors.toList());
    // create an layout that contains all the checkbox
    VBox mainLayout = new VBox();
    mainLayout.getChildren().addAll(checkBoxes);
    JFXButton closeBtn = new JFXButton("Hello");
    closeBtn.setOnAction(e -> {
      String message = checkBoxes
        .stream()
        .map(box -> box.isSelected() ? box.getText() : "")
        .collect(Collectors.joining(", ")); //higher performance
//        .reduce("", String::concat); O^2
      closeBtn.setText(message);
    });

    mainLayout.getChildren().add(closeBtn);

    // create main scene
    Scene mainScene = new Scene(mainLayout, 500, 600);
    primaryStage.setScene(mainScene);
    primaryStage.show();
  }

  public static void main(String[] args) {
    launch(args);
  }
}
