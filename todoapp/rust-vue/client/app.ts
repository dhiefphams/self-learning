import Vue from "vue";
import HelloComponent from "./component/Hello.vue";

const v = new Vue({
  el: "app",
  template: `
    <div>
      Name: <input v-model="name" type="text">
      <hello-component :name="name" :initialEnthusiasm="5" />
    </div>
  `,
  data: { name: "World" },
  components: {
    HelloComponent,
  },
});
