export class Route {
  constructor(
    public name: string,
    public htmlname: string,
    public defaultRoute: string,
  ) {}

  public isActivateRoute(hasPath: string) {
    return hasPath.replace("#", "") === this.name;
  }
}
