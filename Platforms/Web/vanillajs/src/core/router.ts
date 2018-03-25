import { fromEvent } from "rxjs/observable/fromEvent";

import { Route } from "./route";

export class Router {
  constructor(
    private routes: Route[],
    private rootEl: HTMLElement,
  ) {}

  public init() {
    fromEvent(window, "hashChange").subscribe(() => {
      this.onHashChanged();
    });
  }

  private onHashChanged() {
    if (window.location.hash.length > 0) {
      this.routes.forEach((route) => {
        if (route.isActivateRoute(window.location.hash.substr(1))) {
          this.goToRoute(route.htmlname);
        }
      });
    } else {
      this.routes.forEach((route) => {
        if (route.defaultRoute) {
          this.goToRoute(route.htmlname);
        }
      });
    }
  }

  private goToRoute(tempalte: string) {
    this.rootEl.innerHTML = tempalte;
  }
}
