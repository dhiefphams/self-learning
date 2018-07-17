const initWegGL = () => {
  const canvas = document.querySelector('#wegsl');
  const webgl = canvas.getContext('webgl') || canvas.getContext('experimental-webgl');

  if (!webgl) { alert('Your browser does not support webgl'); return; }
  // attach image
  //
  webgl.clearColor(0.75, 0.85, 0.8, 1.0);
  webgl.clear(webgl.COLOR_BUFFER_BIT | webgl.DEPTH_BUFFER_BIT);
};

document.addEventListener('DOMContentLoaded', initWegGL, false);
