package com.hienph.phd.fx;

import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.stage.Modality;
import javafx.stage.Stage;

class AlertBox {
  boolean answer = false;

  boolean display(String title, String message) {
    Stage window = new Stage();
    window.initModality(Modality.APPLICATION_MODAL);
    window.setTitle(title);
    window.setMinWidth(200);

    Label greetingText = new Label(message);
    Button closeBtn = new Button("No");
    closeBtn.setOnAction(e -> window.close());

    Button yesBtn = new Button("Yes");
    yesBtn.setOnAction(e -> {
      answer = true;
      window.close();
    });

    VBox alertLayout = new VBox();
    alertLayout.getChildren().addAll(greetingText, closeBtn, yesBtn);
    alertLayout.setAlignment(Pos.CENTER);

    Scene alertScene = new Scene(alertLayout);
    window.setScene(alertScene);
    // show and wait for other actions
    window.showAndWait();
    return answer;
  }
}