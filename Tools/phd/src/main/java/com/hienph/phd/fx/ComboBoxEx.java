package com.hienph.phd.fx;

import java.util.Arrays;
import java.util.List;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class ComboBoxEx extends Application {

  @Override
  public void start(Stage primaryStage) throws Exception {
    ComboBox<String> frontendFrameworksChosen = new ComboBox<>();
    List<String> frontendFrameWorks = Arrays.asList("Angular", "React", "Vue", "Backbone");
    frontendFrameworksChosen.getItems().addAll(frontendFrameWorks);

    // user can also type his own frameworks
    frontendFrameworksChosen.setEditable(true);

    frontendFrameworksChosen.setOnAction(e -> {
      // event will be fired when user chooses from list
      // or type and press enter
      System.out.println(frontendFrameworksChosen.getValue());
    });

    Button closeBtn = new Button("Close");

    // create the main layout
    VBox mainLayout = new VBox();
    mainLayout.getChildren().addAll(frontendFrameworksChosen, closeBtn);

    // create main scene
    Scene mainScene = new Scene(mainLayout, 400, 400);
    primaryStage.setScene(mainScene);
    primaryStage.show();
  }

  public static void main(String[] args) {
    launch(args);
  }
}
