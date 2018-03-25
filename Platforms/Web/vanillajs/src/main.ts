import { Router } from "./core";

import { home } from "./sences/home/home";
import { login } from "./sences/login/login";

const app = new Router(
  [home, login],
  document.querySelector("#app") as HTMLElement,
);
app.init();
