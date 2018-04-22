package com.hienph.phd.fx;

import com.jfoenix.controls.JFXButton;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.ChoiceBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.util.Arrays;
import java.util.List;

public class DropdownMenu extends Application {
  @Override
  public void start(Stage primaryStage) throws Exception {
    // create a choiceBox (aka: dropdown in html)
    ChoiceBox<String> deepLearningFrameworksChoices = new ChoiceBox<>();
    List<String> dlFrameworks = Arrays.asList("TF", "Microsoft", "Facebook", "PyTorch");
    deepLearningFrameworksChoices.getItems().addAll(dlFrameworks);
    // set default value
    deepLearningFrameworksChoices.setValue(dlFrameworks.get(0));

    JFXButton closeBtn = new JFXButton("Close");

    // subscribe the change value event
    deepLearningFrameworksChoices
      .getSelectionModel()
      .selectedItemProperty()
      .addListener((e, oldVal, newVal) -> {
        // e is the ChoiceBox itself.
        System.out.println("Model change" + e.toString() +  " New val " + newVal + " old val " +  oldVal);
      });

    // subscribe the choose event
    deepLearningFrameworksChoices.setOnAction(e -> {
      System.out.println("event " + e.toString());
    });


    closeBtn.setOnAction(e -> {
      String frameworkChosen = deepLearningFrameworksChoices.getValue();
      closeBtn.setText("You chose " + frameworkChosen);
    });

    // create the main layout
    VBox mainLayout = new VBox();
    mainLayout.getChildren().addAll(deepLearningFrameworksChoices, closeBtn);

    // create the main scene
    Scene mainScene = new Scene(mainLayout, 400, 500);
    primaryStage.setScene(mainScene);

    primaryStage.show();
  }

  public static void main(String[] args) {
    launch(args);
  }

}
