package com.hienph.phd.fx;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;

public class HomeController implements Initializable {
  public Button submitBtn;

  public void onSubmit() {
    this.submitBtn.setText("DON't TOUCH ME");
  }

  @Override
  public void initialize(URL location, ResourceBundle resources) {
    // like ngOnInit
  }
}
