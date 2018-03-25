<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Message;

/**
 * MessageController handle the request related to messages
 */
class MessageController extends Controller {
  /**
   * Handle the contact form submit
   */
  public function submit(Request $req) {
    $this->validate($req, [
      'name' => 'required',
      'email' => 'required',
    ]);

    $message = new Message;
    $message->name = $req->input('name');
    $message->email = $req->input('email');
    $message->message = $req->input('content');
    $message->save();
    return redirect('/')->with('success', 'Message sent');
  }

  /**
   * Handle get request to /messages to get list of messages
   */
  public function findAll() {
    $messages = Message::all();
    return view('messages')->with('messages', $messages);
  }
}
