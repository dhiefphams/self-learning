import Vue from "vue";
import Component from "vue-class-component";

import template from "./home.html";

// The @Component decorator indicates the class is a Vue component
@Component({
  // All component options are allowed in here
  template
})
export default class MyComponent extends Vue {
  // Initial data can be declared as instance properties
  public message: string = "Hello!";
  // Component methods can be declared as instance methods
  public onClick(): void {
    window.alert(this.message);
  }
}
