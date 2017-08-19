declare namespace JSX {
  interface Element {
    type: string;
    children: Element[];
    props: Props;
    [key: string]: any;
  }
  interface IntrinsicElements {
    id: string;
    className: string;
    [prop: string]: any;
  }

  interface Props {
    [key: string]: string;
  }
}


declare namespace VDOM {
  interface Patches {
    type?: string;
    node?: JSX.Element;
    childrens?: Patches[];
    props?: {
      name: string;
      value: string;
    } | Patches[]
  }
}
