@extends('layouts.app')

@section('content')
  <h1>Contact me</h1>
  {!! Form::open(['url' => '/contact/submit']) !!}
    <div class="row">
      <div class="input-field col s12">
        {{Form::text('name', '', ['class' => 'validate', 'placeholder' => 'Your name'])}}
        {{Form::label('name', 'Name')}}
      </div>
    </div>

    <div class="row">
      <div class="input-field col s12">
        {{Form::email('email', '', ['class' => 'validate', 'placeholder' => 'abc@exaple.com'])}}
        {{Form::label('email', 'Email')}}
      </div>
    </div>

    <div class="row">
      <div class="input-field col s12">
        {{Form::email('email', '', ['class' => 'validate', 'placeholder' => 'abc@exaple.com'])}}
        {{Form::label('email', 'Retype your email')}}
      </div>
    </div>

    <div class="row">
      <div class="input-field col s12">
        <i class="material-icons prefix">mode_edit</i> 
        {{Form::textarea('content', '', ['class' => "materialize-textarea"])}}
        {{Form::label('content', 'Your message')}}
      </div>
    </div>
    
    <button class="btn waves-effect waves-light" type="submit">
      Send <i class="material-icons right">send</i>
    </button>
  {!! Form::close() !!}
@endsection