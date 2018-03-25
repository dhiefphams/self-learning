<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class PagesController extends Controller {
  /**
   * Handle get request to / index
   */
  public function home() {
    return view('home');
  }

  /**
   * Handle get request to /about
   */
  public function about() {
    return view('about');
  }

  /**
   * Handle get request to /contact
   */
  public function contact() {
    return view('contact');
  }
}
