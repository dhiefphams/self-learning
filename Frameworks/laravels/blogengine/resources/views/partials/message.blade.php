<!-- Show the error -->
@if(count($errors) > 0)
<div class="collection">
  <!-- loop a dict @foreach($vari as $key => $val) -->
  @foreach($errors->all() as $err)
    <li class="collection-item">{{$err}}</li>
  @endforeach
</div>
@endif

@if(session('success'))
  <li class="collection-item">{{session('success')}}</li>
@endif