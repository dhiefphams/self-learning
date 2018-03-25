@extends('layouts.app')

@section('content')
  <h1>List of messages</h1>
  
  @if(count($messages) > 0)
    <ui class="collection">
    @foreach($messages as $msg)
      <li class="collection-item avatar">
        <i class="material-icons circle">folder</i>
        <span class="title">{{$msg->name}}</span>
        <p>{{$msg->content}}</p>
      </li>
    @endforeach
    </ul>
  @endif
@endsection