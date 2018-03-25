import { Route } from "../../core";

const loginHtml = require("./login.html");

export const login = new Route("login", loginHtml, "login");
