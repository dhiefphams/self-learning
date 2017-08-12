import Vue from "vue";
import HomeComponent from "./components/home";

const v = new Vue({
  el: "#app",
  template: `
    <div>
      Name: <input v-model="name" type="text">
      <home />
    </div>
  `,
  data: { name: "World" },
  components: {
    home: HomeComponent,
  },
});
