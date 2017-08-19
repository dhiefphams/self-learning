const CREATE = "CREATE";
const REMOVE = "REMOVE";
const REPLACE = "REPLACE";
const UPDATE = "UPDATE";
const SET_PROP = "SET_PROP";
const REMOVE_PROP = "REMOVE_PROP";

/// diff
const changed = (node1: JSX.Element, node2: JSX.Element) => {
  return typeof node1 !== typeof node2 ||
    typeof node1 === "string" && node1 !== node2 ||
    node1.type !== node2.type;
};

const diffProps = (newNode: JSX.Element, oldNode: JSX.Element): VDOM.Patches[] => {
  const patches: VDOM.Patches[] = [];
  const props = Object.assign({}, newNode.props, oldNode.props);
  Object.keys(props).forEach((name) => {
    const newVal = newNode.props[name];
    const oldVal = oldNode.props[name];
    if (!newVal) {
      // remove props
      patches.push({ type: REMOVE_PROP, props: { name, value: oldVal } });
    } else if (!oldVal || newVal !== oldVal) {
      patches.push({ type: SET_PROP, props: { name, value: newVal }});
    }
  });
  return patches;
};

const diffChildren = (newNode: JSX.Element, oldNode: JSX.Element): VDOM.Patches[] => {
  const patches: VDOM.Patches[] = [];
  const patchesLength = Math.max(
    newNode.children.length,
    oldNode.children.length
  );
  for (let i = 0; i < patchesLength; ++i) {
    patches[i] = diff(newNode.children[i], oldNode.children[i]);
  }
  return patches;
};

const diff = (newNode: JSX.Element, oldNode: JSX.Element): VDOM.Patches => {
  if (!oldNode) {
    return { type: CREATE, node: newNode };
  }
  if (!newNode) {
    return { type: REMOVE };
  }
  if (changed(newNode, oldNode)) {
    return { type: REPLACE, node: newNode };
  }
  if (newNode.type) {
    return {
      type: UPDATE,
      childrens: diffChildren(newNode, oldNode),
      props: diffProps(newNode, oldNode)
    };
  }
  // nothing changed
  return { type: undefined };
};

/// patch
const createElement = (node: JSX.Element | string): Node => {
  if (typeof node === "string") {
    return document.createTextNode(node);
  }
  const el = document.createElement(node.type);
  setProps(el, node.props);
  node.children
    .map(createElement)
    .forEach(el.appendChild.bind(el));
  return el;
};

const setProp = (target: Element, name: string, value: string) => {
  if (name === "className") {
    target.setAttribute("class", value);
  } else {
    target.setAttribute(name, value);
  }
};

const setProps = (target: Element, props: JSX.Props) => {
  props = props || {};
  Object.keys(props).forEach((name) => {
    setProp(target, name, props[name]);
  });
};

const removeProp = (target: Element, name: string, value: string) => {
  if (name === "className") {
    target.removeAttribute("class");
  } else {
    target.removeAttribute(name);
  }
};

const patchProps = (parent: Element, patches: VDOM.Patches[]) => {
  for (let i = 0; i < patches.length; ++i) {
    let { type, props } = patches[i];
    if (type === SET_PROP) {
      setProp(parent, (props as any).name, (props as any).value);
    }
    if (type == REMOVE_PROP) {
      removeProp(parent, (props as any).name, (props as any).value);
    }
  }
};

const patch = (parent: Element | Node, patches: VDOM.Patches, index = 0) => {
  if (!patches.type) {
    return;
  }
  // child that need to patch
  const el = parent.childNodes[index];
  switch (patches.type) {
    case CREATE: {
      const newEl = createElement(patches.node as JSX.Element);
      return parent.appendChild(newEl);
    }

    case UPDATE: {
      let { childrens, props } = patches;
      childrens = childrens || [];
      props = props || [];
      patchProps(el as Element, props as VDOM.Patches[]);
      for (let i = 0; i < childrens.length; ++i) {
        patch(el, childrens[i], i);
      }
      return;
    }

    case REPLACE: {
      const newEL = createElement(patches.node as JSX.Element);
      return parent.replaceChild(newEL, el);
    }

    case REMOVE:
      // just remove that child
      return parent.removeChild(el);
  }
};

/// our app
const flatten = <T extends {}>(arr: T[]) => [].concat.apply([], arr);

const h = (type: string, props: JSX.Props = {}, ...children: JSX.Element[]) => {
  return { type, props, children: flatten(children) };
};

/** Convert jsx syntax to js tree object or React Element */
const view = (count: number) => {
  const r = Array.from(Array(count).keys());
  return (
    <ul id="cool" className={`foo-${count % 3}`}>
      { r.map((n) => <li>Item { (n * count).toString() }</li>) }
    </ul>
  )
};

const tick = (el: Element, count: number) => {
  const patches = diff(view(count + 1), view(count));
  patch(el, patches);
  console.log(count, patches);
  if (count > 20) {
    return;
  }
  setTimeout(() => tick(el, count + 1), 500);
};

const render = (el: Element) => {
  el.appendChild(createElement(view(0)));
  setTimeout(() => {
    tick(el, 0);
  }, 500);
}

const main = document.querySelector("#main");
if (main) {
  render(main);
}
