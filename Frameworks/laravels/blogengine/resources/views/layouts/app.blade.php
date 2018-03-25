<!DOCTYPE html>
<html lang="en">
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8"/>
  <meta name="viewport" content="width=device-width, initial-scale=1"/>
  <title>The Q blog engine</title>

  <!-- CSS  -->
  <link href="/css/app.css" type="text/css" rel="stylesheet" media="screen,projection"/>
</head>
<body>
  @include('partials/navbar')

  @if(Request::is('/'))
    <h1>This is jumpotron</h1>
  @endif

  @include('partials.message')

  @yield('content')
  
  @include('partials.footer')

  <!--  Scripts-->
  <script src="js/app.js"></script>

  </body>
</html>
