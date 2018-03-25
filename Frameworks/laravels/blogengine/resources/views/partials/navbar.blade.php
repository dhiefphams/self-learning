<nav class="white" role="navigation">
  <div class="nav-wrapper container">
    <a id="logo-container" href="/" class="brand-logo">Q</a>
    <ul class="right hide-on-med-and-down">
      <li class="{{Request::is('contact') ? 'active' : ''}}"><a href="/contact">Contact</a></li>
      <li class="{{Request::is('about') ? 'active' : ''}}"><a href="/about">About Me</a></li>
    </ul>

    <ul id="nav-mobile" class="sidenav">
      <li><a href="/contact">Contact</a></li>
      <li><a href="/about">About Me</a></li>
    </ul>
    <a href="#" data-target="nav-mobile" class="sidenav-trigger"><i class="material-icons">menu</i></a>
  </div>
</nav>